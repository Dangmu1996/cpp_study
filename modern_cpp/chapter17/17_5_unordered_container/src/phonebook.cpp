#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

template<class T>
void printMap(const T & m)
{
    for(auto& [key, value] : m)
    {
        cout<<key<<"(Phone: "<<value<<")"<<endl;
    }
    cout<<"-------"<<endl;
}

int main()
{
    //해시 테이블을 생성한다.
    unordered_map<string, string> phoneBook = {
        {"Marc G.", "123-456789"},
        {"Scott K.", "654-987321"}
    };
    printMap(phoneBook);

    // 전화번호를 추가 삭제한다.
    phoneBook.insert(make_pair("John D.","321-987654"));
    phoneBook["John G."] = "963-258147";
    phoneBook["Freddy K."] = "999-256256";
    phoneBook.erase("Freddy K.");
    printMap(phoneBook);

    // 주어진 키의 버킷 인덱스를 검색한다.
    const size_t bucket = phoneBook.bucket("Marc G.");
    cout<<"Marc G. is in bucket"<<bucket
        <<" which contains the following "
        << phoneBook.bucket_size(bucket)<<" elements:"<<endl;
    //버킷에 있는 원소에 대한 begin과 end 반복자를 가져온다.
    //여기서는 타입을 'auto'로 지정했다. 컴파일러는 두 반복자의 타입을
    //unordered_map<string, string>::const_local_iterator로 추론한다.
    auto localBegin = phoneBook.cbegin(bucket);
    auto localEnd = phoneBook.cend(bucket);
    for(auto iter = localBegin; iter!=localEnd; ++iter)
    {
        cout<<"\t"<<iter->first<<" (Phone: "
            << iter->second<<")"<<endl;
    }

    cout<<"------"<<endl;

    //해시 테이블에 대한 통계를 화면에 출력한다.
    cout<<"There are"<<phoneBook.bucket_count()<<"buckets."<<endl;
    cout<<"Average number of elements in a bucket is"
        <<phoneBook.load_factor()<<endl;
    
    return 0;
}