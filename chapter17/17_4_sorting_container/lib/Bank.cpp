#include "Bank.hpp"

using namespace std;

bool BankDB::addAccount(const BankAccount& acct)
{
    // 지정된 계좌 번호를 키로 사용해서 실제로 추가하는 연산을 수행한다.
    auto res = mAccounts.emplace(acct.getAcctNum(), acct);
    // 또는 다음과 같이 작성해도 된다.
    // auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

    // 연산의 성공과 실피 여부를 표현하는 pair의 bool 필드를 리턴한다.
    return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
    mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum)
{
    // find()에 지정한 키로 원소를 찾는다.
    auto it = mAccounts.find(acctNum);
    if(it == end(mAccounts))
    {
        throw out_of_range("No account with that number.");
    }

    // map에 대한 반복자는 키/값 pair를 가리킨다는 점을 명심한다.
    return it->second;
}

BankAccount& BankDB::findAccount(string_view name)
{
    // 키 없이 원소를 찾으려면 원소를 순차적으로 탐색해야 한다.
    // 이때 c++17부터 추가된 구조적 바인딩을 활용한다.
    for(auto& [acctNum, account]: mAccounts)
    {
        if(account.getClientName() == name)
        {
            return account; // 원소를 찾은 경우
        }
    }
    // C++17의 구조적 바인딩을 지원하지 않는 컴파일러를 사용할 때는 다음과 같이 구현한다.
    // for(auto &p: mAccounts)
    //{
    //  if(p.second.getClientName() == name) { reutrn p.second; }
    //}
    throw out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB& db)
{
    // C++17에 추가된 merge()를 사용한다.
    mAccounts.merge(db.mAccounts);

    // 또는 다음과 같이 작성한다.
    // mAccounts.insert(begin(db.mAccounts), end(db.mAccounts));

    // 이제 원본 데이터베이스를 삭제한다,
    db.mAccounts.clear();
}