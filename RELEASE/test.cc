#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>
using namespace std;

int main()
{
    // ifstream DHP;
    // ofstream out;
    // DHP.open("DHP.txt");
    // out.open("thankyou.txt");
    // string str;
    // while (DHP >> str)
    // {
    //     for (char &ch : str)
    //         out << int(ch) << ' ';
    //     out << '\n';
    // }
    // DHP.close();
    // out.close();
    ifstream DHP;
    DHP.open("thankyou.txt");
    string str;
    while (getline(DHP, str))
    {
        stringstream ss;
        ss.str(str);
        int x;
        while (ss >> x)
            cout << char(x);
        cout << '\n';
    }
    DHP.close();
    return 0;
    return 0;
}