#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        string str;
        cin >> str;
        if(str == "***") break;

        for(int i = str.length(); i <= 0; i--) cout << str[i];
        cout << endl;
    }

    return 0;
}