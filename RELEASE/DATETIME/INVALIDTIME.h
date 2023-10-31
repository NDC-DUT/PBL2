#pragma once
#include <exception>
class INVALIDTIME : public std::exception
{
public:
    INVALIDTIME() = default;
    ~INVALIDTIME() = default;
    const char *what() const noexcept override
    {
        return "Thời gian không hợp lệ!";
    }
};