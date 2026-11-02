#include <map>
#include <iostream>

using namespace std;

class Data final
{
    public:
        explicit Data(int value =0)
            : mValue(value)
        {}

        int getValue() const
        {
            return mValue;
        }

        void setValue(int value)
        {
            mValue = value;
        }

    private:
        int mValue;
};

int main()
{
    map<int, Data> dataMap;

    auto ret = dataMap.insert({1, Data(4)}); //initializer_list 사용
    if(ret.second)
    {
        cout<<"Insert succeeded!"<<endl;
    }
    else
    {
        cout<<"Insert failed"<<endl;
    }

    ret = dataMap.insert(make_pair(1, Data(6))); // pair 객체 사용
    if(ret.second)
    {
        cout<<"Inser succeeded!"<<endl;
    }
    else
    {
        cout<<"Insert failed"<<endl;
    }

    if(auto result = dataMap.insert({1, Data(4)}); result.second)
    {
        cout<<"Insert Succeeded!"<<endl;
    }
    else
    {
        cout<<"Insert failed!"<<endl;
    }

    if(auto[ iter, success]=dataMap.insert({1,Data(4)}); success)
    {
        cout<<"Insert succeeded!"<<endl;
    }
    else
    {
        cout<<"Insert failed!"<<endl;
    }
    // insert의 return 은 pair임.

    // insert or assign()은 있으면 새 값으로 덮어쓴다.
    ret = dataMap.insert_or_assign(1, Data(7));
    if(ret.second)
    {
        cout<<"Inserted."<<endl;
    }
    else
    {
        cout<<"Overwrittten."<<endl;
    }

    //operator[]
    map<int, Data> newMap;
    newMap[1] = Data(4);
    newMap[1] = Data(6); // 키가 1인 원소의 값이 바뀐다.

    for(auto iter = cbegin(dataMap); iter != cend(dataMap); ++iter)
    {
        cout<<iter -> second.getValue()<<endl;
    }

    for(const auto& p : dataMap)
    {
        cout<<p.second.getValue()<<endl;
    }

    for(const auto& [key, data] : dataMap)
    {
        cout<<data.getValue()<<endl;
    }

    //값이 있는지 확인하고, 있으면 set하는 방법
    auto it = dataMap.find(1);
    if(it != end(dataMap))
    {
        it->second.setValue(100);
    }

    //원소 삭제하기
    cout<<"There are "<<newMap.count(1)<<" elements with key 1"<<endl;
    newMap.erase(1);
    cout<<"There are "<<newMap.count(1)<<" elements with key 1"<<endl;

    map<int, Data> dataMap2;
    auto extractedNode = dataMap.extract(1);
    dataMap2.insert(std::move(extractedNode));

    return 0;
}