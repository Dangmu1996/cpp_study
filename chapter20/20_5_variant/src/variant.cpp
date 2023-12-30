#include <variant>
#include <string>
#include <iostream>

using namespace std;

// 주어진 타입 집합 중에서 어느 한 타입의 값을 가지는 값
class Foo{public : Foo() = delete; Foo(int){}};
class Bar{public: Bar() = delete; Bar(int){}};

class MyVisitor
{
    public:
        void operator()(int i){cout<<"int "<< i <<endl;}
        void operator()(const string& s){cout<<"string " << s <<endl;}
        void operator()(float f){ cout << "float "<< f <<endl;}
};

int main()
{
    //첫 번째 타입을 monostate로 지정하면 error가 안나옴
    variant<monostate, Foo, Bar> v;

    variant<int, string, float> v_2;
    v_2=12;
    v_2=12.5f;
    v_2="An std::string"s;

    // 현재 저장된 값이 타입에 대한 인덱스를 알고 싶다면 index()
    // holds_alternative() 함수 템플릿을 이용하면 variant가 인수로 지정한 타입의 값을 답고 있는지 확인 할 수 있다.
    cout<<"Type index: "<<v_2.index()<<endl;
    cout<<"Contains an int: " << holds_alternative<int>(v_2)<<endl;

    // std::get<index>나 std::get<T>를 이용하면 variant에 담긴 값을 가져올 수 있음.
    cout<<std::get<string>(v_2)<<endl;
    try{
        cout << std::get<0>(v_2)<<endl;
    }catch(const bad_variant_access& ex){
        cout << "Exception: "<<ex.what()<<endl;
    }

    // 익셉션이 발생하지 않게 하려면 get_if<index>()나 std::get_if<T>() 헬퍼 함수를 사용한다.
    // 이 함수는 variant에 대한 포인터를 인수로 받아서 요청한 값에 대한 포인터를 리턴한다. 에러가 발생하면 nullptr를 리턴한다.
    string* theString = std::get_if<string>(&v_2);
    int* theInt = std::get_if<int>(&v_2);
    cout << "retrieved string: " << (theString ? *theString : "null") << endl;
    cout << "retrieved int: " << (theInt ? *theInt : 1) << endl;

    // std::visit() 헬퍼 함수도 있는데, variant에 대한 비지터 패턴을 적용할 때 사용한다.
    visit(MyVisitor(), v_2);

    return 0;
}
 