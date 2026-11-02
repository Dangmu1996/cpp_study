#pragma once
#include <iostream>
#include <string>

class SpreadsheetCell
{
    public:
        SpreadsheetCell() = default;
        SpreadsheetCell(double val);
        void setValue(double inValue);
        double getValue() const;
        SpreadsheetCell operator-() const; // - 단항 연산자

        // 후행 연산자는 변수의 값을 증가하기 전에 연산자에 적용해서 리턴한 뒤 그 변수의 값을 증가시킴
        SpreadsheetCell& operator++(); //선행 증가 선행연산 버전의 리턴값은 피연산자의 최종 결과와 같음. 따라서 선행 증가 및 감소 연산의 호출 대상 객체는 레퍼런스로 리턴됨
        SpreadsheetCell operator++(int); // 후행 연산자는 int 타입의 인수를 하나만 받음
        SpreadsheetCell& operator--(); // 선행 감소
        SpreadsheetCell operator--(int); // 후행 감소
        explicit operator double() const;
        operator std::string() const;

    private:
        double mValue=0;
};

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
std::ostream& operator<<(std::ostream& ostr, const SpreadsheetCell& cell);
std::istream& operator>>(std::istream& istr, SpreadsheetCell& cell);