#include <thread>
/*
이건 그냥 document editor 예제, 새로운 document 열고, 
thread detached document 여러게 여는 애제 정도
detach()는 스레드가 끝날때까지 기다리지 않고, 객체와 실행 스레드의 연결을 끊음*/

void edit_document(std::string const& filename)
{
    open_document_and_display_gui(filename);
    while(!done_editing())
    {
        user_command cmd =get_user_input();
        if(!cmd.type()==open_new_document)
        {
            std::string const new_name=get_filename_from_user();
            std::thread t(edit_document, new_name);
            t.detach();
        }else
        {
            process_user_input(cmd);
        }
    }
}