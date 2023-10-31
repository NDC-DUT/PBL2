template <class DATA_T1, class DATA_T2>
PAIR<DATA_T1, DATA_T2>::PAIR(const PAIR &p)
    : first{p.first}, second{p.second} {}

template <class DATA_T1, class DATA_T2>
PAIR<DATA_T1, DATA_T2>::PAIR(PAIR &&p)
    : first{std::move(p.first)}, second{std::move(p.second)} {}

template <class DATA_T1, class DATA_T2>
PAIR<DATA_T1, DATA_T2>::PAIR(const DATA_T1 &first, const DATA_T2 &second)
    : first{first}, second{second} {}

template <class DATA_T1, class DATA_T2>
PAIR<DATA_T1, DATA_T2>::PAIR(DATA_T1 &&first, DATA_T2 &&second)
    : first{std::move(first)}, second{std::move(second)} {}

template <class DATA_T1, class DATA_T2>
PAIR<DATA_T1, DATA_T2> PAIR<DATA_T1, DATA_T2>::operator=(const PAIR &p)
{
    first = p.first;
    second = p.second;
    return *this;
}

template <class DATA_T1, class DATA_T2>
PAIR<DATA_T1, DATA_T2> PAIR<DATA_T1, DATA_T2>::operator=(PAIR &&p)
{
    first = std::move(p.first);
    second = std::move(p.second);
    return *this;
}

template <class DATA_T1, class DATA_T2>
bool PAIR<DATA_T1, DATA_T2>::operator<(const PAIR &p)
{
    if (first < p.first)
        return true;
    if (first > p.frist)
        return false;
    return second < p.second;
}
