#pragma once

class SpreadsheetCell
{
    public:
        SpreadsheetCell(double val);
        void setValue(double inValue);
        double getValue() const;

    private:
        double mValue=0;
};

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);