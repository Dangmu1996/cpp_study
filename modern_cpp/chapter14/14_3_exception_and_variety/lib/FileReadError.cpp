#include "FileReadError.hpp"

FileReadError::FileReadError(std::string_view fileName, size_t lineNumber)
: FileError(fileName), mLineNumber(lineNumber)
{
    std::ostringstream ostr;
    ostr << "Error reading" << fileName << " at line " << lineNumber;
    setMessage(ostr.str());
}

size_t FileReadError::getLineNumber() const noexcept
{
    return mLineNumber;
}