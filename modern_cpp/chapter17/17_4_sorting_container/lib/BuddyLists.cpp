#include "BuddyLists.hpp"

using namespace std;

void BuddyLists::addBuddy(const string& name, const string& buddy)
{
    // 여기에 전달된 buddy가 중복되지 않도록 확인한다.
    if(!isBuddy(name, buddy))
    {
        mBuddies.insert({name, buddy}); // Using initializer_list
    }
}

void BuddyLists::removeBuddy(const string& name, const string& buddy)
{
    // 'name' 키로 구한 원소의 범위(시작과 끝)를 구한다.
    // lower_bound()와 upper_bound()르 사용하는 방식으로 작성했지만,
    // 실전에서는 equal_range()로 구현하는 것이 더 효율 적이다.
    auto begin = mBuddies.lower_bound(name); // 범위의 시작
    auto end = mBuddies.upper_bound(name); // 범위의 끝

    // 키가 'name'인 원소에 대해 반복하면서 값이 'buddy'인 원소를 찾는다.
    // 키가 'name'인 원소가 없다면 begin과 end가 같으므로 루프가 실행되지 않는다.
    for(auto iter = begin; iter != end; ++iter){
        if(iter->second == buddy){
            //일치하는 원소를 찾았다. 이 원소를 맵에서 제거한다.
            mBuddies.erase(iter);
            break;
        }
    }
}

bool BuddyLists::isBuddy(const string& name, const string & buddy) const
{
    // equal_range()로 'name' 키에 대한 원소 범위의 시작과 끝을 구한다.
    // 그리고 C++17에 추가된 구조적 바인딩을 적용한다.
    auto [begin, end] = mBuddies.equal_range(name);

    // 'name' 키에 대한 원소에 대해 반복하며 값이 'buddy'인 원소를 찾는다.
    for(auto iter = begin; iter!=end; ++iter){
        if(iter->second == buddy){
            // 원소 발견
            return true;
        }
    }
    // 발견하지 못한 경우
    return false;
}

vector<string> BuddyLists::getBuddies(const string& name) const
{
    // equal_range()로 'name' 키에 대한 원소 범위의 시작과 끝을 구한다.
    // 그리고 C++17에 추가된 구조적 바인딩을 적용한다.
    auto [begin, end] = mBuddies.equal_range(name);

    // 앞에서 구한 범위에 속한 이름을 모두 담은 vector을 생성한다.
    vector<string> buddies;
    for(auto iter = begin; iter!=end; ++iter){
        buddies.push_back(iter->second);
    }
    return buddies;
}