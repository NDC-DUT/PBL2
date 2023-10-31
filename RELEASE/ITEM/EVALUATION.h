#pragma once
#include "../DATETIME/DATE.h"
#include <string>
class EVALUATION
{
private:
    std::string _sku;
    float _point;
    std::string _username;
    std::string _content;
    DATE _evadate;

public:
    EVALUATION() = default;
    ~EVALUATION() = default;
    EVALUATION(std::string &&_sku, float &&_point, std::string &&_username, std::string &&_content, DATE &&_evadate)
        : _sku{_sku}, _point{_point}, _username{_username}, _content{_content}, _evadate{_evadate} {}
};