#pragma once

#include <string>
#include <string_view>
#include <cstdio>

class Muffin
{
    public:
        virtual ~Muffin() = default;

        std::string_view getDescription() const;
        void setDescription(std::string_view description);

        int getSize() const;
        void setSize(int size);

        void output() const;

        bool hasChoclateChips() const;
        void setHasChocolateChips(bool hasChips);
    private:
        std::string mDescription;
        int mSize=0;
        bool mHasChocolateChips = false;

};