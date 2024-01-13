#include <cstddef>
#include <string>
#include <stdexcept>

namespace ProCpp
{
    template<typename T>
    size_t hash<T>::operator()(const T& key) const
    {
        const size_t bytes = sizeof(key);
        size_t sum = 0;
        for(size_t i = 0; i<bytes; ++i){
            unsigned char b = *(reinterpret_cast<const unsigned char*>(&key)+i);
            sum += b;
        }
        return sum;
    }

    size_t hash<std::string>::operator()(const std::string& key) const
    {
        size_t sum=0;

        for(auto c : key){
            sum += static_cast<unsigned char>(c);
        }
        return sum;
    }

    /*----------------------const_map_iterator 구현---------------------------------*/

    template<typename HashMap>
    const_hash_map_iterator<HashMap>::const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* hashmap)
    : mBucketIndex(bucket), mListIterator(listIt), mHashmap(hashmap)
    {
    }

    // 실제 원소에 대한 레퍼런스를 리턴한다.
    template<typename HashMap>
    const typename const_hash_map_iterator<HashMap>::value_type& const_hash_map_iterator<HashMap>::operator*() const
    {
        return *mListIterator;
    }    

    // 실제 원소에 대한 포인터를 리턴한다. 그러면 컴파일러는 이 포인터에 ->를 적용해서 
    // 원하는 필드에 접근한다.
    template<typename HashMap>
    const typename const_hash_map_iterator<HashMap>::value_type* const_hash_map_iterator<HashMap>::operator->() const
    {
        return &(*mListIterator);
    }

    // 구체적인 작업은 increment() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator++()
    {
        increment();
        return *this;
    }

    // 구체적인 작업은 increment() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator++(int)
    {
        auto oldIt = *this;
        increment();
        return *oldIt;
    }

    // 구체적인 작업은 decrement() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator--()
    {
        decrement();
        return *this;
    }

    // 구체적인 작업은 decrement() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator--(int)
    {
        auto oldIt = *this;
        decrement();
        return oldIt;
    }


    

    /*-----------------------hash_map 구현---------------------------------*/

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    bool hash_map<Key, T, KeyEqual, Hash>::empty() const
    {
        return mSize == 0;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::size_type hash_map<Key, T, KeyEqual, Hash>::size() const
    {
        return mSize;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T ,KeyEqual, Hash>::size_type hash_map<Key, T, KeyEqual, Hash>::max_size() const
    {
        return mBuckets[0].max_size();
    }

    // 버킷 수에 맞게 mBuckets를 생성한다.
    template<typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>::hash_map(
        const KeyEqual& equal, size_t numBuckets, const Hash& hash)
        : mBuckets(numBuckets), mEqual(equal), mHash(hash)
    {
        if(numBuckets == 0){
            throw std::invalid_argument("Number of buckets must be positive");
        }
    }
    

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<typename hash_map<Key, T, KeyEqual, Hash>::ListType::iterator, size_t> hash_map<Key, T, KeyEqual, Hash>::findElement(const key_type& k)
    {
        // 주어진 키로 해시를 계산해서 버킷을 가져온다.
        size_t bucket = mHash(k) % mBuckets.size();

        // 버킷에서 키를 검색한다.
        auto iter = find_if(begin(mBuckets[bucket]),
                            end(mBuckets[bucket]),
                            [this, &k](const auto &element){return mEqual(element.first, k); });

        // 반복자와 버킷 인덱스로 구성된 pair를  리턴한다.
        return std::make_pair(iter, bucket);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k)
    {
        // findElement() 헬퍼와 c++17에 추가된 구조적 바인딩을 적용한다.
        auto[it, bucket] = findElement(k);

        if(it == end(mBuckets[bucket])){
            //원소를 찾지 못한 경우 nullptr을 리턴.
            return nullptr;
        }

        // 원소를 찾은 경우 그 원소에 대한 포인터를 리턴한다.
        return &(*it);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    const typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key,T, KeyEqual, Hash>::find(const key_type& k) const
    {
        return const_cast<hash_map<Key, T, KeyEqual, Hash>*>(this)->find(k);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    T& hash_map<Key, T, KeyEqual, Hash>::operator[] (const key_type& k)
    {
        // 원소를 겁색한다. 없다면 추가한다.
        auto[it, bucket] = findElement(k);
        if(it == end(mBuckets[bucket])){
            mSize++;
            mBuckets[bucket].push_back(std::make_pair(k, T()));
            return mBuckets[bucket].back().second;
        }else{
            return it->second;
        }
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::insert(const value_type& x)
    {
        // 원소를 검색한다.
        auto[it, bucket] = findElement(x.first);
        if(it != end(mBuckets[bucket])){
            // 원소가 이미 존재한다.
            return ;
        }else{
            // 원소가 없으므로 새로 추가한다.
            mSize++;
            mBuckets[bucket].push_back(x);
        }
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::erase(const key_type& k)
    {
        // 먼저 원소를 검색한다.
        auto[it, bucket] = findElement(k);
        if(it != end(mBuckets[bucket])){
            // 원소가 있다면 삭제한다.
            mBuckets[bucket].erase(it);
            mSize--;
        }
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::clear() noexcept
    {
        // 모든 버킷에 대해 clear()를 호출한다.
        for(auto &bucket : mBuckets){
            bucket.clear();
        }
        mSize = 0;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::swap(hash_map<Key, T ,KeyEqual, Hash> &other) noexcept
    {
        using std::swap;

        swap(mBuckets, other.mBuckets);
        swap(mSize, other.mSize);
        swap(mEqual, other.mEqual);
        swap(mHash, other.mHash);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void swap(hash_map<Key, T, KeyEqual, Hash>& first, hash_map<Key, T, KeyEqual, Hash>& second) noexcept
    {
        first.swap(second);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(const hash_map<Key, T, KeyEqual, Hash>& rhs)
    {
        // 자기 자신을 대입하는지 검사한다.
        if(this == &rhs){
            return *this;
        }

        // 복제 후 맞바꾸기 패턴
        auto copy = rhs; // 모든 작업을 임시 인스턴스에서 처리한다.
        swap(copy); // 작업 과정에 익셉션이 발생하지 않고 나온 최종 결과를 반영한다.
        return *this;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept
    {
        swap(rhs);
        return *this;
    }
}