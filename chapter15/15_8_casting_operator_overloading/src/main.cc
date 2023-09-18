#include "SpreadsheetCell.hpp"

int main()
{
    // SpreadsheetCell cell(1.23);
    // double d1 = cell;

    // std::string str = cell;
    SpreadsheetCell cell = 6.6;
    std::string str = cell;
    double d1 = static_cast<double>(cell);
    // double d2 = static_cast<double>(cell);

    return 0;
}