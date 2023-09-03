#pragma once

#include "FileError.hpp"

class FileReadError : public FileError
{
public:
    FileReadError(std::string_view fileName, size_t lineNumber);
    size_t getLineNumber() const noexcept;

private:
    size_t mLineNumber;
};