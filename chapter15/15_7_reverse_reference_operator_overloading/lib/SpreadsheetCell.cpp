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

SpreadsheetCell SpreadsheetCell::operator-() const
{
    return SpreadsheetCell(-getValue());
}

SpreadsheetCell& SpreadsheetCell::operator++()
{
    setValue(getValue()+1);
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int)
{
    auto oldCell(*this); //증가 전의 값을 저장한다
    ++(*this); //선행 증가 연산으로 값을 증가시킨다.
    return oldCell; //증가 전의 값을 리턴한다.
}

SpreadsheetCell& SpreadsheetCell::operator--()
{
    setValue(getValue()-1);
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int)
{
    auto oldCell(*this);
    --(*this);
    return oldCell;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    return lhs.getValue() == rhs.getValue();
}

std::ostream& operator<<(std::ostream& ostr, const SpreadsheetCell& cell)
{
    ostr<<cell.getValue();
    return ostr;
}

std::istream& operator>>(std::istream& istr, SpreadsheetCell& cell)
{
    double value;
    istr>>value;
    cell.setValue(value);
    return istr;
}