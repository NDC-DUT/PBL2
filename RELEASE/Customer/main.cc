// #include "welcome.h"
// #include "login.h"
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;
int main()
{
    std::ifstream fd;
    fd.open("test2.txt", ios::in);
    string str;
    while (fd >> str)
    {
        cout << str << endl;
    }
    return 0;
}