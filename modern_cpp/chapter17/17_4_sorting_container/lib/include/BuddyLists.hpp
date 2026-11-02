#pragma once

#include <map>
#include <string>
#include <vector>

class BuddyLists final
{
    public:
        // buddy를 name으로 지정한 사람의 친구로 추가한다.
        void addBuddy(const std::string& name, const std::string& buddy);
        // buddy를 name으로 지정한 사람의 친구에서 제거한다.
        void removeBuddy(const std::string& name, const std::string& buddy);
        // buddy가 name으로 지정한 사람의 친구라면 true를, 아니면 false를 리턴한다.
        bool isBuddy(const std::string& name, const std::string& buddy) const;
        // name으로 지정한 사람의 친구 목록을 가져온다.
        std::vector<std::string> getBuddies(const std::string& name) const;
    private:
        std::multimap<std::string, std::string> mBuddies;
};