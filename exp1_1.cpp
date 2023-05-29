#include <iostream>
using namespace std;

int main()
{
	string password = "admin1234";
	cout << "Enter the default password" << endl;
	string passin;
	getline(cin, passin);
	if (passin == password)
	{
		cout << "Correct password" << endl;
	}
	else
	{
		cout << "Wrong password" << endl;
	}
}
