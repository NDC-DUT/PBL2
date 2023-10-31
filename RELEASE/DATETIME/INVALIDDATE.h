#pragma once
#include <exception>
class INVALIDDATE : public std::exception
{
public:
    INVALIDDATE() = default;
    ~INVALIDDATE() = default;
    const char *what() const noexcept override
    {
        return "Ngày không hợp lệ!";
    }
};