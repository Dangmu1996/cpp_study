#pragma once

#include <vector>
#include <string_view>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>

class FileError : public std::exception
{
public:
    FileError(std::string_view fileName);
    virtual const char* what() const noexcept override;
    std::string_view getFileName() const noexcept;

protected:
    void setMessage(std::string_view message);

private:
    std::string mFileName;
    std::string mMessage;
};