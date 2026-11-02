#include "FileError.hpp"


FileError::FileError(std::string_view fileName)
: mFileName(fileName)
{}

const char* FileError::what() const noexcept
{
    return mMessage.c_str();
}

std::string_view FileError::getFileName() const noexcept
{
    return mFileName;
}


void FileError::setMessage(std::string_view message)
{
    mMessage = message;
}