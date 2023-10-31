ITEM::ITEM(const ITEM &RHS)
    : _sku{RHS._sku},
      _name{RHS._name},
      _priname{RHS._priname},
      _classify{RHS._classify},
      _nreview{RHS._nreview},
      _medscore{RHS._medscore}
{
}
ITEM::ITEM(ITEM &&RHS)
    : _sku{std::move(RHS._sku)},
      _name{std::move(RHS._name)},
      _priname{std::move(RHS._priname)},
      _origin_priname{std::move(RHS._origin_priname)},
      _classify{std::move(RHS._classify)},
      _nreview{RHS._nreview},
      _medscore{RHS._medscore}
{
}
ITEM::ITEM(const std::string &_sku,
           const std::string &_name,
           const std::string &_priname,
           const std::string &_origin_priname,
           const VECTOR<ITEMPROP> &_classify,
           const short unsigned &_nreview,
           const float &_medscore)
    : _sku{_sku},
      _name{_name},
      _priname{_priname},
      _origin_priname{_origin_priname},
      _classify{_classify},
      _medscore{_medscore},
      _nreview{_nreview}
{
}
ITEM::ITEM(std::string &&_sku,
           std::string &&_name,
           std::string &&_priname,
           std::string &&_origin_priname,
           VECTOR<ITEMPROP> &&_classify,
           short unsigned &&_nreview,
           float &&_medscore)
    : _sku{std::move(_sku)},
      _name{std::move(_name)},
      _priname{std::move(_priname)},
      _origin_priname{std::move(_origin_priname)},
      _classify{std::move(_classify)},
      _nreview{_nreview},
      _medscore{_medscore}
{
}

bool ITEM::operator<(const ITEM &RHS) const { return this->_sku < RHS._sku; }
bool ITEM::operator==(const ITEM &RHS) const { return this->_sku == RHS._sku; }
bool ITEM::operator>(const ITEM &RHS) const { return this->_sku > RHS._sku; }

ITEM &ITEM::operator=(const ITEM &RHS)
{
    this->_sku = RHS._sku;
    this->_name = RHS._name;
    this->_priname = RHS._priname;
    this->_origin_priname = RHS._origin_priname;
    this->_classify = RHS._classify;
    this->_nreview = RHS._nreview;
    this->_medscore = RHS._medscore;
    return *this;
}
ITEM &ITEM::operator=(ITEM &&RHS)
{
    this->_sku = std::move(RHS._sku);
    this->_name = std::move(RHS._name);
    this->_priname = std::move(RHS._priname);
    this->_origin_priname = std::move(RHS._origin_priname);
    this->_classify = std::move(RHS._classify);
    this->_nreview = RHS._nreview;
    this->_medscore = RHS._medscore;
    return *this;
}

std::istream &operator>>(std::istream &is, ITEM &_it)
{
    is >> _it._sku;
    is.ignore(1);
    std::getline(is, _it._name);
    std::getline(is, _it._priname);
    std::getline(is, _it._origin_priname);

    short unsigned nUnit;
    is >> nUnit;
    if (nUnit != 0)
    {
        _it._classify = std::move(VECTOR<ITEMPROP>(nUnit));
        for (ITEMPROP &Ip : _it._classify)
            is >> Ip;
    }
    return is >> _it._nreview >> _it._medscore;
}
std::ostream &operator<<(std::ostream &os, const ITEM &_it)
{
    os << _it._sku << ' ' << _it._name << '\n';
    os << _it._priname << ' ' << _it._origin_priname.substr(9, _it._origin_priname.length() - 9) << '\n';
    os << _it._classify.size() << '\n';
    for (ITEMPROP &Ip : _it._classify)
        os << Ip;

    os << _it._nreview << ' ' << _it._medscore << '\n';

    return os << '\n';
}
std::string ITEM::name() const
{
    return this->_name;
}
void ITEM::name(std::string &&mv_name)
{
    this->_name = std::move(mv_name);
}
void ITEM::priname(std::string &&mv_priname)
{
    this->_priname = std::move(mv_priname);
}
void ITEM::origin_priname(std::string &&mv_origin_priname)
{
    this->_origin_priname = std::move(mv_origin_priname);
}
std::string ITEM::priname() const
{
    return this->_priname;
}
std::string ITEM::origin_priname() const
{
    return this->_origin_priname;
}
std::string ITEM::sku() const
{
    return this->_sku;
}
size_t ITEM::ntype() const
{
    return _classify.size();
}
void ITEM::addITEMPROP(ITEMPROP &&ip)
{
    _classify.push_back(std::move(ip));
    std::sort(_classify.begin(), _classify.end());
}
const VECTOR<ITEMPROP> &ITEM::classify() const
{
    return _classify;
}
void ITEM::rmITEMPROP(const unsigned short &idx)
{
    _classify.remove(idx);
}
void ITEM::addQUANTITY(const short unsigned &thType, const size_t &_quantity)
{
    _classify[thType].quantity(_classify[thType].quantity() + _quantity);
}
void ITEM::cost(const short unsigned &thType, const size_t &_ncost)
{
    _classify[thType].cost(_ncost);
}
void ITEM::price(const short unsigned &thType, const size_t &_nprice)
{
    _classify[thType].price(_nprice);
}
void ITEM::promoprice(const short unsigned &thType, const size_t &_npromoprice)
{
    _classify[thType].promoprice(_npromoprice);
}

bool ITEM::checkValidNewType(const std::string &_newType) const
{
    for (int &&i{0}; i < _classify.size(); ++i)
    {
        if (_classify[i].unit() == _newType)
            return false;
    }
    return true;
}