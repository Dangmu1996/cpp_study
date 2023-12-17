#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
#include <iostream>

using namespace std;

using VotersMap = map<string, vector<string>>;
using DistricPair = pair<const string, vector<string>>;


set<string> getDuplicates(const VotersMap& votersByDistrict)
{
    // 모든 vector에 동시에 나오는 이름에 대한 set을 리턴한다.
    vector<string> allNames;
    for(auto& district : votersByDistrict){
        allNames.insert(end(allNames), begin(district.second),
            end(district.second));
    }

    // 이 vector를 정렬한다.
    sort(begin(allNames), end(allNames));

    // 이렇게 vector를 정렬하면 중복된 이름이 연달아 나온다.
    // adjacent_find()로 똑같은 이름이 두 개 이상 나오는 부분을 찾는다.
    // adjacent_find()가 끝 반복자를 리턴할 때까지 루프를 돈다.
    set<string> duplicates;
    for(auto lit = cbegin(allNames); lit != cend(allNames); ++lit){
        lit = adjacent_find(lit, cend(allNames));
        if(lit == cend(allNames)){
            break;
        }
        duplicates.insert(*lit);
    }
    return duplicates;
}

// 지역구 이름을 표현하는 string과 
// 각 지역구마다 등록된 선거인 명부를 담은 vector<string>를 맵핑하는 맵응 인수로 받는다.
// 그런 다음 이 맵의 각 vector에서 convictedFelons 벡터와 다른 벡터에 잇는 이름을 제거한다.
void auditVoterRolls(VotersMap& votersByDistrict, const vector<string>& convictedFelons)
{
    // 중복된 이름을 찾는다.
    set<string> toRemove = getDuplicates(votersByDistrict);

    // 중복된 등록자와 범죄자 목록을 합친다. 이 목록에 있는 이름을 모두 선거인 명부에서 삭제한다.
    toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

    // 이름을 삭제하는 작업은 다음과 같이 람다 표현식으로 
    // remove 후 erase 패턴에 따라 처리한다.
    for_each(begin(votersByDistrict), end(votersByDistrict), [&toRemove](DistricPair& district){
        auto it = remove_if(begin(district.second),
            end(district.second), [&toRemove](const string& name){
                return (toRemove.count(name)>0);
            }
        );
        district.second.erase(it, end(district.second));
    }
    );
}

int main()
{
    VotersMap voters = {
        {"Orange", {"Amy Aardvark", "Bob Buffalo",
                    "Charles Cat", "Dwayne Dog"}},
        {"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo",
                        "Amy Aardvark"}},
        {"San Diego", {"George Goose", "Heidi Hen", "Fred Flamingo"}}
    };

    vector<string> felons = {"Bob Buffalo", "Charles Cat"};

    // 지역구를 출력하는 로컬 람다 표현식
    auto printDistrict = [](const DistricPair& district){
        cout << district.first << ":";
        for(auto & str : district.second){
            cout<<" {" << str << "}";
        }
        cout<<endl;
    };

    cout<< "Before Audit" << endl;
    for(const auto& district : voters){ printDistrict(district);}
    cout<<endl;

    auditVoterRolls(voters, felons);
    cout<<"After Audit: "<<endl;
    for(const auto& district : voters){ printDistrict(district);}
    cout<<endl;
}