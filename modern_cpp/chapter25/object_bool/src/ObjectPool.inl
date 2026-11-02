#include "ObjectPool.hpp"

template <typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
    if(mFreeList.empty())
    {
        mFreeList.emplace(std::make_unique<T>());
    }

    // 다음 차례에 제공할 가용 객체를 큐에서 빼서 로컬 unique_ptr로 옮긴다.
    std::unique_ptr<T> obj(std::move(mFreeList.front()));
    mFreeList.pop();

    // 객체 포인터를 Object(커스텀 딜리터를 갖춘 shared_ptr)로 반환한다.
    Object smartObject(obj.release(), [this](T* t){
        // 커스텀 딜리터는 메모리를 직접 해제하지 않고, 객체를 풀에 반환하기만 한다.
        mFreeList.emplace(t);
    });

    // 객체를 리턴한다.
    return smartObject;
}