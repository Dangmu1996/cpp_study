#include <iostream>
#include "employee.h"

using namespace std;

namespace Records{
    Employee::Employee(const std::string& firstName,
                        const std::string& lastName)
        : mFirstName(firstName), mLastName(lastName)
    {}

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire()
    {
        mHired = true;
    }

    void Employee::fire()
    {
        mHired = false;
    }

    void Employee::display() const
    {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "----------------------------" << endl;
        cout << (isHired() ? "Current Emplotee" : "Former Employee") << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;  
    }

    void Employee::setFirstName(const string& firstName)
    {
        mFirstName = firstName;
    }

    const string& Employee::getFirstName() const
    {
        return mFirstName;
    }

    void Employee::setLastName(const string& lastName)
    {
        mLastName = lastName;
    }

    const string& Employee::getLastName() const
    {
        return mLastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber)
    {
        mEmployeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const
    {
        return mEmployeeNumber;
    }

    void Employee::setSalary(int newSalary)
    {
        mSalary = newSalary;
    }

    int Employee::getSalary() const
    {
        return mSalary;
    }

    bool Employee::isHired() const
    {
        return mHired;
    }
}