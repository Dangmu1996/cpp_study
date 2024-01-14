#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <initializer_list>
#include <functional>
#include <iostream>

namespace ProCpp
{
    template <typename T>
    class hash
    {
    public:
        size_t operator()(const T& key) const;
    };

    template <>
	class hash<std::string>
	{
	public:
		size_t operator()(const std::string& key) const;
	};

    template<typename HashMap>
    class const_hash_map_iterator
    {
        friend HashMap;
    public:
        using value_type = typename HashMap::value_type;
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;
        using pointer = value_type*;
        using reference = value_type&;
        using list_iterator_type = typename HashMap::ListType::const_iterator;
        // 양방향 반복자는 반드시 기본 생성자를 제공해야 한다.
        // 기본 생성자로 만든 반복자를 사용하는 방법은 특별히 정해진 겂이 없으므로 
        // 원하는 방식으로 초기화하면 된다.
        const_hash_map_iterator() = default;
        const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* hashmap);
        // 복제 생성자나 operator=을 정의할 필요는 없다.
        // 기본 동작으로만 충분하기 때문이다.
        // 소멸자 역시 기본 동작(mHashmap을 삭제하지 않는 것)으로 충분하므로 
        // 별도로 정의할 필요 없다.
        const value_type& operator*() const;
        // ->연산자를 적용할 수 있는 타입을 리턴해야 한다.
        // pair<const Key, T>에 대한 포인터를 리턴한다.
        // 그러면 컴파일러는 여기에 ->를 다시 적용한다.
        const value_type* operator->() const;
        const_hash_map_iterator<HashMap>& operator++();
        const_hash_map_iterator<HashMap> operator++(int);
        const_hash_map_iterator<HashMap>& operator--();
        const_hash_map_iterator<HashMap> operator--(int);
        // 멥버 함수를 다음과 같이 정의해도 된다.
        // 다양한 타입과 비교하는 기능을 지원하지 않기 때문이다.
        bool operator==(const const_hash_map_iterator<HashMap>& rhs) const;
        bool operator!=(const const_hash_map_iterator<HashMap>& rhs) const;
    
    protected:
        size_t mBucketIndex = 0;
        list_iterator_type mListIterator;
        const HashMap* mHashmap = nullptr;
        // operator++와 operator--에 대한 헬퍼 메서드
        void increment();
        void decrement();
    };

    template<typename HashMap>
    class hash_map_iterator : public const_hash_map_iterator<HashMap>
    {
        friend HashMap;
    public:
        using value_type = typename const_hash_map_iterator<HashMap>::value_type;
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;
        using pointer = value_type*;
        using reference = value_type&;
        using list_iterator_type = typename HashMap::ListType::iterator;
        hash_map_iterator() = default;
        hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap);
        value_type& operator*();
        value_type* operator->();
        hash_map_iterator<HashMap>& operator++();
        hash_map_iterator<HashMap> operator++(int);
        hash_map_iterator<HashMap>& operator--();
        hash_map_iterator<HashMap> operator--(int);
    };

    template <typename Key, typename T, typename KeyEqual = std::equal_to<>, typename Hash = hash<Key>>
    class hash_map
    {
    public:
        using key_type = Key;
		using mapped_type = T;
		using value_type = std::pair<const Key, T>;
		using hasher = Hash;
		using key_equal = KeyEqual;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using hash_map_type = hash_map<Key, T, KeyEqual, Hash>;
		using iterator = hash_map_iterator<hash_map_type>;
		using const_iterator = const_hash_map_iterator<hash_map_type>;

    private:
        using ListType = std::list<value_type>;
    public:
        using local_iterator = typename ListType::iterator;
		using const_local_iterator = typename ListType::const_iterator;

        friend class hash_map_iterator<hash_map_type>;
		friend class const_hash_map_iterator<hash_map_type>;

        virtual ~hash_map() = default; // virtual destructor

        // 잘못된 버킷 수가 전달되면 invalid argument 익셉션을 던진다.
        explicit hash_map(const KeyEqual& equal = KeyEqual(), size_t numBuckets = 101, const Hash& hash = Hash());

        // 버킷 수가 맞지 않으면 invalid_argument 익셉션을 던진다.
        template<typename InputIterator>
        hash_map(InputIterator first, InputIterator last,
            const KeyEqual& equal = KeyEqual(),
            size_type numBuckets = 101, const Hash& hash=Hash());
        
        // initializer_list 생성자
        // 버킷 수가 맞지 않으면 invalid_argument 익셉션을 던진다.
        explicit hash_map(std::initializer_list<value_type> il,
            const KeyEqual& equal = KeyEqual(), size_type numBuckets = 101,
            const Hash& hash = Hash());
        
        // 복제 생성자
        hash_map(const hash_map<Key, T, KeyEqual, Hash>& src) = default;

        // 이동 생성자
        hash_map(hash_map<Key, T, KeyEqual, Hash>&& src) noexcept = default;
        // 복제 대입 연산자
        hash_map<Key, T, KeyEqual, Hash>& operator=(
            const hash_map<Key, T, KeyEqual, Hash>& rhs);
        
        // 이동 대입 연산자
        hash_map<Key, T, KeyEqual, Hash>& operator=(
            hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept;
        
        // initializer_list 대입 연산자
        hash_map_type& operator=(std::initializer_list<value_type> il);

        // 반복자 메서드
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        // 크기 관련 메서드
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        // 원소 추가 메서드
        T& operator[](const key_type& k);
        std::pair<iterator, bool> insert(const value_type& x);
        iterator insert(const_iterator hint, const value_type& x);
        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last);
        void insert(std::initializer_list<value_type> il);

        // 원소 삭제 메서드
        size_type erase(const key_type& k);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);

        // 그 밖에 다른 수정 유틸리티
        // 두 해시를 맞바꾼다.
        void swap(hash_map<Key, T, KeyEqual, Hash>& other) noexcept;
        // 모든 원소를 삭제한다.
        void clear() noexcept;

        // 표준 라이브러리 조건에 맞추기 위한 접근 메서드
        key_equal key_eq() const;
        hasher hash_function() const;

        // 룩업 메서드
        iterator find(const key_type& k);
        const_iterator find(const key_type& k) const;
        std::pair<iterator, iterator> equal_range(const key_type& k);
        std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
        size_type count(const key_type& k) const;


        size_type bucket_count() const;
		size_type max_bucket_count() const;
		size_type bucket(const Key& k) const;
		size_type bucket_size(size_type n) const;
		local_iterator begin(size_type n);
		const_local_iterator begin(size_type n) const;
		const_local_iterator cbegin(size_type n) const;
		local_iterator end(size_type n);
		const_local_iterator end(size_type n) const;
		const_local_iterator cend(size_type n) const;
        /* for the hash_map_iterator
        // x라는 키/값 쌍을 추가한다.
        void insert(const value_type& x);
        // k라는 키에 대한 원소가 있다면 그 원소를 삭제한다.
        void erase(const key_type& k);
        
        // k라는 키에 대한 원소의 포인터를 찾아서 리턴한다.
        // 그 키에 대한 원소가 없으면 nullptr를 리턴한다.
        value_type* find(const key_type& k);
        const value_type* find(const key_type& k) const;
        // operator[]는 k라는 키에 대한 원소를 찾는다.
        // 그 키에 대한 원소가 없다면 새로 추가한다.
        // 그런 다음 그 키의 값에 대한 레퍼런스를 리턴한다.
        T& operator[] (const key_type& k);           
        */
        
    private:
        std::pair<typename ListType::iterator, size_t> findElement(const key_type& k);

		std::vector<ListType> mBuckets;
		size_type mSize = 0;
		KeyEqual mEqual;
		Hash mHash;
    };
}

#include "hash_map.inl"