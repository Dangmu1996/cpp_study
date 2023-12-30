#include <filesystem>
#include <iostream>
#include <string>

using namespace std::filesystem;
using namespace std;


void processPath(const path& p)
{
    if(!exists(p)){
        return;
    }

    auto begin = recursive_directory_iterator(p);
    auto end = recursive_directory_iterator();
    for(auto iter = begin; iter!=end; ++iter){
        const string spacer(iter.depth()*2, ' ');

        auto& entry = *iter;

        if(is_regular_file(entry)){
            cout << spacer << "File: " << entry;
            cout << " (" << file_size(entry) << " bytes)" << endl;
        }else if(is_directory(entry)){
            cout << spacer << "Dir: " << entry << endl;
        }
    }
}

int main()
{
    path p1(LR"(/home/dangmu/cpp_study/chapter20/20_8_filesystem)");
    path p2(L"/home/dangmu/cpp_study/chapter20/20_8_filesystem");
    path p3(LR"(../data)");

    p1.append("data");
    p1 /= "data";

    p2.concat("data");
    p2+="data";

    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;

    for(const auto & component : p1){
        cout << component << endl;
    }

    p1.append("test.txt");
    directory_entry dirEntry(p1);
    if(dirEntry.exists() && dirEntry.is_regular_file()){
        cout << "File size: " << dirEntry.file_size() << endl;
    }

    space_info s = space("/");
    cout << "Capacity: " << s.capacity << endl;
    cout << "Free: " << s.free << endl;

    path p(LR"(/home/dangmu/cpp_study/chapter20/20_8_filesystem)");
    processPath(p);

    return 0;
}