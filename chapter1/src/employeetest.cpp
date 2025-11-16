#include <iostream>
#include "employee.h"

using namespace std;
using namespace Records;

int main()
{
    cout << "Testing the Employee class." << endl;
    Employee emp;
    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setEmployeeNumber(71);
    emp.setSalary(500000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();

    return 0;
}