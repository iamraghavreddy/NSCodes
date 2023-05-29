#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = 0;
    string password;
    string passin = "admin";
    cout << "Password:\n";

    char ch;
    while ((ch = cin.get()) != '\n')
    {
        password.push_back(ch);
        cout << "*";
    }
    cout << endl;

    for (i = 0; i < 6; i++)
    {
        if (passin[i] != password[i])
            break;
    }

    if (i == 6)
    {
        cout << "Correct password\n";
    }
    else
    {
        cout << "Wrong password\n";
    }

    return 0;
}
