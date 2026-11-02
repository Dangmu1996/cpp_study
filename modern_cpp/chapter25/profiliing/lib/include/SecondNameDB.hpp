# pragma once
#include <string_view>
#include <string>
#include <map>
// 두 번째 버전에서는 map을 써서 찾는 탐색의 성능 O(logn)

class NameDB
{
    public:
        NameDB(std::string_view nameFile);
        int getNameRank(std::string_view name) const;
        int getAbsoluteNumber(std::string_view name) const;
    private:
        std::map<std::string, int> mNames;
        bool nameExistsAddIncrement(std::string_view name);
        void addNewName(std::string_view name);
};
