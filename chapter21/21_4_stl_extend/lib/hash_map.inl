#include <stdexcept>
#include <algorithm>
#include <utility>

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
		size_t sum = 0;
		for (auto c : key) {
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
    const typename const_hash_map_iterator<HashMap>::value_type& 
        const_hash_map_iterator<HashMap>::operator*() const
    {
        return *mListIterator;
    }    

    // 실제 원소에 대한 포인터를 리턴한다. 그러면 컴파일러는 이 포인터에 ->를 적용해서 
    // 원하는 필드에 접근한다.
    template<typename HashMap>
    const typename const_hash_map_iterator<HashMap>::value_type* 
        const_hash_map_iterator<HashMap>::operator->() const
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

    //mListIterator가 이미 마지막 원소 바로 다음을 가리키고 있다면 비정상적으로 작동하거나
    //유효하지 않은 결과가 나온다.
    template<typename HashMap>
    void const_hash_map_iterator<HashMap>::increment()
    {
        // mListIterator는 한 버킷에 대한 반복자다. 이를 하나 증가시킨다.
        ++mListIterator;

        // 현재 버킷의 끝에 있다면 다음 버킷으로 이동한다.
        auto& buckets = mHashmap->mBuckets;
        if(mListIterator == end(buckets[mBucketIndex])){
            for(size_t i = mBucketIndex + 1; i<buckets.size(); i++){
                if(!buckets[i].empty()){
                    // 비어 있지 않은 버킷을 바견한 경우
                    // mListIterator가 이 버킷의 첫 번째 원소를 가리키게 한다.
                    mListIterator = begin(buckets[i]);
                    mBucketIndex = i;
                    return ;
                }
            }
            // 더 이상 비어 있지 않은 버킷이 없으면
            // mListIterator가 마지막 리스트의 끝 반복자를 가리키도록 설정한다.
            mBucketIndex = buckets.size() -1;
            mListIterator = end(buckets[mBucketIndex]);
        }
    }

    template<typename HashMap>
    void const_hash_map_iterator<HashMap>::decrement()
    {
        // mListIterator는 한 버킷에 대한 반복자다.
        // 현재 버킷의 시작 지점에 있다면 감소시키면 안 되고,
        // 현재 지점보다 앞에 있는 버킷 중 비어 있지 않은 것을 찾아야 한다.
        auto& buckets = mHashmap->mBuckets;
        if(mListIterator == begin(buckets[mBucketIndex])){
            for(int i = mBucketIndex - 1; i>=0; --i){
                if(!buckets[i].empty()){
                    mListIterator = --end(buckets[i]);
                    mBucketIndex = i;
                    return ;
                }
            }
            // 더 이상 비어 있지 않은 버킷이 없는 경우 감소시키면 문제가 된다.
            // mListIterator가 마지막 리스트의 끝 반복자를 가리키도록 설정한다.
            mBucketIndex = buckets.size() - 1;
            mListIterator = end(buckets[mBucketIndex]);
        }else{
            // 버킷의 시작에 도달하지 않았기 때문에 한 칸씩 앞으로 이동한다.
            --mListIterator;
        }
    }

    template<typename HashMap>
    bool const_hash_map_iterator<HashMap>::operator==(const const_hash_map_iterator<HashMap>& rhs) const
    {
        // 반목자가 가리키는 hash_map을 비록한 모든 필드가 같아야 한다.
        return (mHashmap == rhs.mHashmap &&
            mBucketIndex == rhs.mBucketIndex &&
            mListIterator == rhs.mListIterator);
    }

    template<typename HashMap>
    bool const_hash_map_iterator<HashMap>::operator!=(const const_hash_map_iterator<HashMap>& rhs) const
    {
        return !(*this == rhs);
    }
    
    /*-----------------------hash_map_iterator 클래스---------------------------------*/
    template<typename HashMap>
    hash_map_iterator<HashMap>::hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap)
    : const_hash_map_iterator<HashMap>(bucket, listIt, hashmap)
    {
    }

    // 실제 원소에 대한 레퍼런스를 리턴한다.
    template<typename HashMap>
    typename hash_map_iterator<HashMap>::value_type& hash_map_iterator<HashMap>::operator*()
    {
        return const_cast<value_type&>(*this->mListIterator);
    }

    // 실제 원소에 대한 포인터를 리턴한다.
    // 그래야 컴파일러가 그 원소에 -> 연산을 적용해서 원하는 필드에 접근할 수 있다.
    template<typename HashMap>
    typename hash_map_iterator<HashMap>::value_type* hash_map_iterator<HashMap>::operator->()
    {
        return const_cast<value_type*>(&(*this->mListIterator));
    }

    // 구체적인 작업은 베이스 클래스에 있는 increment() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator++()
    {
        this->increment();
        return *this;
    }

    template<typename HashMap>
    hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator++(int)
    {
        auto oldIt = *this;
        this->increment();
        return oldIt;
    }

    // 구체적인 작업은 베이스 클래스에 있는 decrement() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator--()
    {
        this->decrement();
        return *this;
    }

    // 구체적인 작업은 베이스 클래스에 있는 decrement() 헬퍼 메서드로 처리한다.
    template<typename HashMap>
    hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator--(int)
    {
        auto oldIt = *this;
        this->decrement();
        return oldIt;
    }

    /*-----------------------hash_map 구현---------------------------------*/
    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::begin()
    {
        if(mSize == 0){
            // 특수한 경우: 원소가 없으면 곧 반복자를 리턴한다.
            return end();
        }

        // 원소가 최소 하나라도 있다면 첫 번째 원소를 검색한다.
        for(size_t i = 0; i < mBuckets.size(); ++i)
        {
            if(!mBuckets[i].empty()){
                return hash_map_iterator<hash_map_type>(i, std::begin(mBuckets[i]), this);
            }
        }

        // 여기까지 올 일은 없지만 혹시라도 오게 되면 끝 반복자를 리턴한다.
        return end();
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::end()
    {
        // 여기가 끝 반보갖는 마지막 버킷에 있는 리스트의 끝 반복자다.
        size_t bucket = mBuckets.size() - 1;
        return hash_map_iterator<hash_map_type>(bucket, std::end(mBuckets[bucket]), this);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::begin() const
    {
        return const_cast<hash_map_type*>(this)->begin();
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::end() const
    {
        return const_cast<hash_map_type*>(this)->end();
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::cbegin() const
    {
        return begin();
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T , KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::cend() const
    {
        return end();
    }
    
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
        auto iter = find_if(std::begin(mBuckets[bucket]),
                            std::end(mBuckets[bucket]),
                            [this, &k](const auto &element){return mEqual(element.first, k); });

        // 반복자와 버킷 인덱스로 구성된 pair를  리턴한다.
        return std::make_pair(iter, bucket);
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

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    template<typename InputIterator>
    hash_map<Key, T, KeyEqual, Hash>::hash_map(
        InputIterator first, InputIterator last, const KeyEqual& equal,
        size_type numBuckets, const Hash& hash)
        : hash_map(equal, numBuckets, hash)
    {
        insert(first, last);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>::hash_map(
        std::initializer_list<value_type> il,
        const KeyEqual& equal, size_type numBcukets, const Hash& hash)
        : hash_map(equal, numBcukets, hash)
    {
        insert(std::begin(il), std::end(il));
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(
        std::initializer_list<value_type> il)
    {
        // 모든 작업을 임시 인스턴스에서 처리한다.
        hash_map_type newHashMap(il, mEqual, mBuckets.size(), mHash);
        swap(newHashMap); // 익셉션이 발생하지 않은 최종 결과를 반영한다.
        return *this;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<typename hash_map<Key, T, KeyEqual, Hash>::iterator, bool>
        hash_map<Key, T, KeyEqual, Hash>::insert(const value_type& x)
    {
        // 원소를 찾는다.
        auto[it, bucket] = findElement(x.first);
        bool inserted = false;

        if(it == std::end(mBuckets[bucket])){
            // 원소를 찾지 못했다면 새로 추가한다.
            it = mBuckets[bucket].insert(it, x);
            inserted = true;
            mSize++;
        }
        return std::make_pair(hash_map_iterator<hash_map_type>(bucket, it, this), inserted);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::insert(
        const_iterator /*hint*/, const value_type& x)
    {
        // 위치를 완전히 무시한다.
        return insert(x).first;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    template<typename InputIterator>
    void hash_map<Key, T, KeyEqual, Hash>::insert(
        InputIterator first, InputIterator last)
    {
        //insert_iterator 어뎁터를 이용하여 주어진 범위에 있는 원소를 모두 복제한다.
        //주어진 begin()의 위치는 큰 의미가 없다. insert 메서드는 어차피 이 값을 무시한다.
        std::insert_iterator<hash_map_type> inserter(*this, begin());
        std::copy(first, last, inserter);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::insert(
        std::initializer_list<value_type> il)
    {
        insert(std::begin(il), std::end(il));
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::size_type hash_map<Key, T, KeyEqual, Hash>::erase(const key_type& k)
    {
        // 먼저 원소를 검색한다.
        auto[it, bucket] = findElement(k);
        if(it != std::end(mBuckets[bucket])){
            // 원소를 찾았다면 삭제한다.
            mBuckets[bucket].erase(it);
            mSize--;
            return 1;
        }else{
            return 0;
        }
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::erase(iterator position)
    {
        iterator next = position;
        ++next;
        // 해당 버킷에 있는 원소를 삭제한다.
        mBuckets[position.mBucketIndex].erase(position.mListIterator);
        mSize--;
        return next;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator 
        hash_map<Key, T, KeyEqual, Hash>::erase(iterator first, iterator last)
    {
        // 주어진 범위에 있는 원소를 모두 삭제한다.
        for(iterator next = first; next != last;){
            next = erase(next);
        }
        return last;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T ,KeyEqual, Hash>::key_equal
        hash_map<Key, T, KeyEqual, Hash>::key_eq() const
    {
        return mEqual;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::hasher
        hash_map<Key, T, KeyEqual, Hash>::hash_function() const
    {
        return mHash;
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator
        hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k)
    {
        // findElement() 헬퍼와 c++17 구조적 바인딩을 사용한다.
        auto[it, bucket] = findElement(k);
        if(it==std::end(mBuckets[bucket])){
            // 원소가 없다면 끝 반복자를 리턴한다.
            return end();
        }
        // 원소를 찾았다면 버킷 / 반복자를 hash_map_iterator로 변환한다.
        return hash_map_iterator<hash_map_type>(bucket, it, this);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key,T, KeyEqual, Hash>::const_iterator
        hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k) const
    {
        return const_cast<hash_map_type*>(this)->find(k);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<
        typename hash_map<Key, T, KeyEqual, Hash>::iterator,
        typename hash_map<Key, T, KeyEqual, Hash>::iterator>
        hash_map<Key, T, KeyEqual, Hash>::equal_range(const key_type& k)
    {
        auto it = find(k);
        return std::make_pair(it, it);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<
        typename hash_map<Key, T, KeyEqual, Hash>::const_iterator,
        typename hash_map<Key, T, KeyEqual, Hash>::const_iterator>
        hash_map<Key, T, KeyEqual, Hash>::equal_range(const key_type& k) const
    {
        auto it = find(k);
        return std::make_pair(it, it);
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::size_type
        hash_map<Key, T, KeyEqual, Hash>::count(const key_type& k) const
    {
        // 주어진 k에 일치하는 원소는 1개 아니면 0개다.
        // 원소를 찾으면 1을 , 그렇지 않으면 0을 리턴한다.
        if(find(k)== end()){
            return 0;
        }else{
            return 1;
        }
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    T& hash_map<Key, T, KeyEqual, Hash>::operator[](const key_type& k)
    {
        // 코드가 다소 난해하지만, 실제로 하는 일은
        // k라는 키에 대해 새로운 키/값 쌍을 추가하고 0으로 초기화하는 것이다.
        // insert 연산의 성공 여부에 관계없이 interator와 bool로 구성된 쌍을 리턴한다.
        // 여기에 있는 반복자는 key/value 쌍을 가리키며, 두 번째 원소가 리턴해야 할 값이다.
        return ((insert(std::make_pair(k, T()))).first)->second;
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::bucket_count() const
	{
		return mBuckets.size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::max_bucket_count() const
	{
		return mBuckets.max_size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::bucket(const Key& k) const
	{
		return const_cast<hash_map_type*>(this)->findElement(k).second;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::bucket_size(size_type n) const
	{
		return mBuckets[n].size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::local_iterator
		hash_map<Key, T, KeyEqual, Hash>::begin(size_type n)
	{
		return mBuckets[n].begin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::begin(size_type n) const
	{
		return mBuckets[n].begin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::cbegin(size_type n) const
	{
		return mBuckets[n].cbegin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::local_iterator
		hash_map<Key, T, KeyEqual, Hash>::end(size_type n)
	{
		return mBuckets[n].end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::end(size_type n) const
	{
		return mBuckets[n].end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::cend(size_type n) const
	{
		return mBuckets[n].cend();
	}

    

    /* for the hash map iterator
    template<typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::insert(const value_type& x)
    {
        // 원소를 검색한다.
        auto[it, bucket] = findElement(x.first);
        if(it != std::end(mBuckets[bucket])){
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
        if(it != std::end(mBuckets[bucket])){
            // 원소가 있다면 삭제한다.
            mBuckets[bucket].erase(it);
            mSize--;
        }
    }

    template<typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k)
    {
        // findElement() 헬퍼와 c++17에 추가된 구조적 바인딩을 적용한다.
        auto[it, bucket] = findElement(k);

        if(it == std::end(mBuckets[bucket])){
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
        if(it == std::end(mBuckets[bucket])){
            mSize++;
            mBuckets[bucket].push_back(std::make_pair(k, T()));
            return mBuckets[bucket].back().second;
        }else{
            return it->second;
        }
    }
    */

}



