#include <iostream>
#include "Employee.hpp"

using namespace Records;
using namespace std;

int main(int argc, char ** argv)
{
    /*역참조 하는거*/
    Employee employee;
    int (Employee::*methodPtr) () const = &Employee::getSalary;
    cout<<(employee.*methodPtr)()<<endl;

    /*타입 엘리어스*/
    using PtrToGet=int (Employee::*)() const;
    PtrToGet methodPtr2 = &Employee::getSalary;
    cout<<(employee.*methodPtr2)()<<endl;

    /*auto로 하면 더 간단함*/
    auto methodPtr3=&Employee::getSalary;
    cout<<(employee.*methodPtr3)() <<endl;


    return 0;
}