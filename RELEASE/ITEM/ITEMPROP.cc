
ITEMPROP::ITEMPROP(std::string &&_unit,
                   size_t &_cost,
                   size_t &_price,
                   size_t &_promoPrice,
                   size_t &_quantity)
    : _unit{std::move(_unit)},
      _cost{_cost},
      _price{_price},
      _promoPrice{_promoPrice},
      _quantity{_quantity}
{
}

std::istream &operator>>(std::istream &is, ITEMPROP &ip)
{
    is.ignore(1);
    std::getline(is, ip._unit);
    return is >> ip._cost >> ip._price >> ip._promoPrice >> ip._quantity;
}
std::ostream &operator<<(std::ostream &os, const ITEMPROP &ip)
{
    return os << ip._unit << '\n'
              << ip._cost << ' '
              << ip._price << ' '
              << ip._promoPrice << ' '
              << ip._quantity << '\n';
}
// setter
void ITEMPROP::unit(const std::string &u)
{
    _unit = u;
}
void ITEMPROP::cost(const size_t &c)
{
    _cost = c;
}
void ITEMPROP::price(const size_t &p)
{
    _price = p;
}
void ITEMPROP::promoprice(const size_t &p)
{
    _promoPrice = p;
}
void ITEMPROP::quantity(const size_t &q)
{
    _quantity = q;
}
// getter
const std::string &ITEMPROP::unit() const
{
    return _unit;
}
const size_t &ITEMPROP::cost() const
{
    return _cost;
}
const size_t &ITEMPROP::price() const
{
    return _price;
}
const size_t &ITEMPROP::promoprice() const
{
    return _promoPrice;
}
const size_t &ITEMPROP::quantity() const
{
    return _quantity;
}

bool ITEMPROP::operator<(const ITEMPROP &_ip)
{
    return this->_unit < _ip._unit;
}
ITEMPROP &ITEMPROP::operator=(const ITEMPROP &_ip)
{
    this->_unit = _ip._unit;
    this->_cost = _ip._cost;
    this->_price = _ip._price;
    this->_promoPrice = _ip._promoPrice;
    this->_quantity = _ip._quantity;
    return *this;
}
void RemoveVietnameseTone(std::string &text)
{
    text = std::regex_replace(text, std::regex("À|Á|Ạ|Ả|Ã|Â|Ầ|Ấ|Ậ|Ẩ|Ẫ|Ă|Ằ|Ắ|Ặ|Ẳ|Ẵ|à|á|ạ|ả|ã|â|ầ|ấ|ậ|ẩ|ẫ|ă|ằ|ắ|ặ|ẳ|ẵ|/g"), "a");
    text = std::regex_replace(text, std::regex("Ì|Í|Ị|Ỉ|Ĩ|ì|í|ị|ỉ|ĩ|/g"), "i");
    text = std::regex_replace(text, std::regex("Ù|Ú|Ụ|Ủ|Ũ|Ư|Ừ|Ứ|Ự|Ử|Ữ|ù|ú|ụ|ủ|ũ|ư|ừ|ứ|ự|ử|ữ|/g"), "u");
    text = std::regex_replace(text, std::regex("È|É|Ẹ|Ẻ|Ẽ|Ê|Ề|Ế|Ệ|Ể|Ễ|è|é|ẹ|ẻ|ẽ|ê|ề|ế|ệ|ể|ễ|/g"), "e");
    text = std::regex_replace(text, std::regex("Ò|Ó|Ọ|Ỏ|Õ|Ô|Ồ|Ố|Ộ|Ổ|Ỗ|Ơ|Ờ|Ớ|Ợ|Ở|Ỡ|ò|ó|ọ|ỏ|õ|ô|ồ|ố|ộ|ổ|ỗ|ơ|ờ|ớ|ợ|ở|ỡ|/g"), "o");
    text = std::regex_replace(text, std::regex("Ỳ|Ý|Ỵ|Ỷ|Ỹ|ỳ|ý|ỵ|ỷ|ỹ|/g"), "y");
    text = std::regex_replace(text, std::regex("Đ|đ|/g"), "d");
}
void lowercaseStr(std::string &text)
{
    text.erase(std::remove_if(text.begin(),
                              text.end(),
                              [](const char &x)
                              { return !isdigit(x) && !isalpha(x) && !isspace(x) && (x > 0); }),
               text.end());
    transform(text.begin(), text.end(), text.begin(), ::tolower);
}
bool IsVietNameseString(const std::string &text)
{
    bool flag = false;
    std::string chk(text);
    for (const char &ch : chk)
        if (ch < 0)
        {
            flag = true;
            break;
        }
    if (!flag)
        return false;
    RemoveVietnameseTone(chk);
    for (const char &ch : chk)
        if (ch < 0)
            return false;
    return true;
}
void LowercaseVietNameseCharacter(std::string &text)
{
    for (int &&i(0); i < text.length(); ++i)
    {
        if (text[i] < 0)
        {
            switch (text[i])
            {
            case -31:
            {
                if ((text[i + 2] & 1) == 0)
                    ++text[i + 2];
                i += 2;
                continue;
            }
            case -58:
                switch (text[i + 1])
                {
                case -81:
                    ++text[i + 1];
                    break;
                case -96:
                    ++text[i + 1];
                    break;
                }
                ++i;
                continue;
            case -59:
                if (text[i + 1] == -88)
                    ++text[i + 1];
                ++i;
                continue;
            case -60:
                if ((text[i + 1] & 1) == 0)
                    ++text[i + 1];
                ++i;
                continue;
            case -61:
                if (text[i + 1] < -98)
                    text[i + 1] += 32;
                ++i;
                continue;
            }
        }
    }
}