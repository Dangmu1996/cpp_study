#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Logger
{
public:
    static void enableLogging(bool enable){msLoggingEnabled = enable;}
    static bool isLoggingEnabled(){return msLoggingEnabled;}

    template<typename... Args>
    static void log(const Args&... args)
    {
        if(!msLoggingEnabled)
            return;
        
        ofstream logfile(msDebugFileName, ios_base::app);
        if(logfile.fail()){
            cerr << "Unable to open debug file!" << endl;
            return;
        }

        ((logfile<<args),...);
        logfile << endl;
    }

private:
    static const std::string msDebugFileName;
    static bool msLoggingEnabled;
};

const std::string Logger::msDebugFileName = "debugfile.out";
bool Logger::msLoggingEnabled = false;

#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)

bool isDebugSet(int argc, char* argv[])
{
    for(int i = 1; i<argc; i++){
        if(strcmp(argv[i], "-d")==0){
            return true;
        }
        return false;
    }
}

class ComplicatedClass{/*...*/};
ostream& operator<<(ostream& ostr, const ComplicatedClass& src)
{
    ostr << "ComplicatedClass";
    return ostr;
}

class UserCommand{/*...*/};
ostream& operator<<(ostream& ostr, const UserCommand& src)
{
    ostr << "UserCommand";
    return ostr;
}

UserCommand getNextCommand(ComplicatedClass* /* obj */)
{
	UserCommand cmd;
	return cmd;
}




