#include "FileOpenError.hpp"

FileOpenError::FileOpenError(std::string_view fileName) 
: FileError(fileName)
{
    std::string a = "Unable to open ";
    setMessage(a + fileName.data());
}