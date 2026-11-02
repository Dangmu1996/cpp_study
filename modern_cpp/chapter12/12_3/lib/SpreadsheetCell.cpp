#include "SpreadsheetCell.hpp"

SpreadsheetCell::SpreadsheetCell(double val)
{
    mValue = val;
}

void SpreadsheetCell::setValue(double inValue)
{
    mValue = inValue;
}

double SpreadsheetCell::getValue() const
{
    return mValue;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return lhs.getValue() == rhs.getValue();
}