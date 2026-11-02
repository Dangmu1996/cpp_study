#include "Muffin.hpp"

using namespace std;

string_view Muffin::getDescription() const
{
    return mDescription;
}

void Muffin::setDescription(string_view description)
{
    mDescription = description;
}

int Muffin::getSize() const
{
    return mSize;
}

void Muffin::setSize(int size)
{
    mSize = size;
}

void Muffin::setHasChocolateChips(bool hasChips)
{
    mHasChocolateChips = hasChips;
}

bool Muffin::hasChoclateChips() const
{
    return mHasChocolateChips;
}

void Muffin::output() const
{
    printf(" %s, Size is %d, %s\n", getDescription().data(), getSize(), (hasChoclateChips() ? "has chips" : "no chips"));
}