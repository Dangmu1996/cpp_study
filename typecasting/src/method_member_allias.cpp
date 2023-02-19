#include <iostream>
#include "Employee.hpp"

using namespace Records;
using namespace std;

int main(int argc, char ** argv)
{
    Employee employee;
    int (Employee::*methodPtr) () const = &Employee::getSalary;
    cout<<(employee.*methodPtr)()<<endl;

    using PtrToGet=int (Employee::*)() const;
    PtrToGet methodPtr2 = &Employee::getSalary;
    cout<<(employee.*methodPtr2)()<<endl;

    auto methodPtr3=&Employee::getSalary;
    cout<<(employee.*methodPtr3)() <<endl;



    return 0;
}