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

    return 0;
}