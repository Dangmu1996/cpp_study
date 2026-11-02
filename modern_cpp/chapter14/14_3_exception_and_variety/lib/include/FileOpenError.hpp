#pragma once
#include "FileError.hpp"

class FileOpenError : public FileError
{
public:
    FileOpenError(std::string_view fileName);
};