#include "VECTOR.h"
#include <iostream>
using namespace std;
void func(int a[])
{
    cout << "a[0] = ";
    cout << a[0];
}
void func(int *a)
{
    cout << "*a = ";
    cout << *a;
}
int main()
{
    func({1, 2, 3, 4, 5});
    // VECTOR<int> v = {1, 2, 3, 4, 5};
    // for (const auto &x : v)
    //     cout << x << ' ';
    // cout << endl;
    // v = {4, 5, 6};
    // for (const auto &x : v)
    //     cout << x << ' ';
    return 0;
}