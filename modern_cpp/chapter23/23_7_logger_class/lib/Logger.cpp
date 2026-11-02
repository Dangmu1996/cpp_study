#include "Logger.hpp"

using namespace std;

Logger::Logger()
{
    // 백그라운드 스레드를 구동한다.
    mThread = thread{ &Logger::processEntries, this};
}

Logger::~Logger()
{
    {
        unique_lock lock(mMutex);
        
        // mExit를 true로 설정하고 스레드에 알림을 보내서 스레드를 정상 종료시킨다.
        mExit = true;

        // 스레드를 깨우도록 조건 변수에 알림을 보낸다.
        mCondVar.notify_all();
    }

    // 스레드가 종료될 때까지 기다린다. 이 부분은 앞에 나온 블록 밖에 둬야 한다.
    // join()을 호출하기 전에 반드시 락을 해제해야 하기 때문이다.
    mThread.join();
}

void Logger::log(string_view entry)
{
    // 뮤텍스에 락을 걸고 큐에 항목을 추가한다.
    unique_lock lock(mMutex);
    mQueue.push(string(entry));

    // 스레드를 깨우는 조건 변수에 알림을 보낸다.
    mCondVar.notify_all();
}

void Logger::processEntries()
{
    // 로그 파일을 연다.
    ofstream logFile("../data/log.txt");
    if(logFile.fail()){
        cerr<< "Failed to open log" << endl;
        return;
    }

    // 큐를 처리하는 루프를 시작한다.
    unique_lock lock(mMutex);
    while(true){
        if (!mExit){ // 종료 상황이 아니면 알림을 기다린다.
            // 알람이 오기를 기다린다.
            mCondVar.wait(lock);
        }
        

        // 큐에 뭔가 변화가 있어서 조건 변수에 알림이 도착할 경우
        lock.unlock();
        while(true){
            lock.lock();
            if(mQueue.empty()){
                break;
            }else{
                logFile << mQueue.front() << endl;
                mQueue.pop();
            }
            lock.unlock();
        }
        if(mExit){
            break;
        }
    }
}