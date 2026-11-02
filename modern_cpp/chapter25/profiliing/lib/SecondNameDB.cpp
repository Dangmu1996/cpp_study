#include "SecondNameDB.hpp"
#include <exception>
#include <fstream>

using namespace std;

NameDB::NameDB(string_view nameFile)
{
    // 파일을 읽고 에러가 발생했는지 확인한다.
    ifstream inputFile(nameFile.data());
    if(!inputFile){
        throw invalid_argument("Uable to open file");
    }

    // 이름을 한 번에 하나씩 읽는다.
    string name;
    while(inputFile >> name){
        // 주어진 이름이 데이터베이스에 이미 있는지 확인한다.
        if(!nameExistsAddIncrement(name)){
            // 주어진 이름이 데이터베이스에 이미 있다면 개수를 하나 증가시키고
            // 이 블록을 건너뛴다.
            // 이 블록에 들어왔다면 데이터베이스에 없는 이름이란 뜻이므로 
            // 이름을 추가하고 개수를 하나 증가시킨다.
            addNewName(name);
        }
    }
}

// 데이터베이스에 있는 이름이면 true를, 아니면 false를 리턴한다.
// 데이터베이스에서 이름을 발견했을 때는 개수를 하나 증가시킨다.
bool NameDB::nameExistsAddIncrement(string_view name)
{
    // 주어진 이름을 map에서 찾는다.
    auto res = mNames.find(name.data());
    if(res != end(mNames)){
        res->second++;
        return true;
    }
    return false;
}

// 데이터베이스에 이름을 새로 추가한다.
void NameDB::addNewName(string_view name)
{
    mNames[name.data()] = 1;
}

int NameDB::getNameRank(string_view name) const
{
    // getAboluteNubmer() 메서드로 처리한다.
    int num = getAbsoluteNumber(name);

    // 이름을 찾았는지 확인한다.
    if(num == -1){
        return -1;
    }

    // 주어진 이름보다 수가 많은 이름을 벡터에서 모두 찾는다.
    // 주어진 이름보다 순위가 높은 이름이 없다면 그 이름을 1위로 만든다.
    // 주어진 이름보다 빈도가 낮은 이름의 순위를 1씩 감소한다.
    int rank =1;
    for(auto& entry : mNames){
        if(entry.second > num){
            rank++;
        }
    }
    return rank;
}

int NameDB::getAbsoluteNumber(string_view name) const
{
    auto res = mNames.find(name.data());
    if(res != end(mNames)){
        return res->second;
    }
    return -1;
}