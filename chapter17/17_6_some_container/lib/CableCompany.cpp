#include "CableCompany.hpp"

using namespace std;

void CableCompany::addPackage(string_view packageName, const bitset<kNumChannels>& channels)
{
    mPackages.emplace(packageName, channels);
}

void CableCompany::removePackage(string_view packageName)
{
    mPackages.erase(packageName.data());
}

const bitset<kNumChannels>& CableCompany::getPackage(string_view packageName) const
{
    // 지정된 패키지에 대한 레퍼런스를 구한다.
    auto it = mPackages.find(packageName.data());
    if(it == end(mPackages))
    {
        //지정된 패키지가 존재하지 않는 경우 익셉션을 던진다.
        throw out_of_range("Invalid package");
    }
    return it->second;
}

void CableCompany::newCustomer(string_view name, string_view package)
{
    // 지정한 패키지에 속한 채널을 가져온다.
    auto& packageChannels = getPackage(package);
    // 가입자가 선택한 패키지가 표현된 bitset으로 설정된 계정을 생성한다.
    newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(string_view name, const bitset<kNumChannels>& channels)
{
    // 가입자 맵에 가입자를 추가한다.
    auto result = mCustomers.emplace(name, channels);
    if(!result.second){
        //가입자가 이메 데이터베이스에 존재하는 경우 변경하지 않는다.
        throw invalid_argument("Duplicate customer");
    }
}

void CableCompany::addChannel(string_view name, int channel)
{
    // 지정한 가입자가 현재 가입한 채널을 조회한다.
    
}