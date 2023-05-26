//Name: Kaushik Shroff
//Batch: K-8
//Roll No: 32418
//Experiment No: 1

#include <iostream>
using namespace std;

int main()
{
	string password="admin1234";
	cout<<"Enter the default password"<<endl;
	string passin;
	getline(cin,passin);
	if(passin==password)
	{
		cout<<"Correct password"<<endl;
	}
	else
	{
		cout<<"Wrong password"<<endl;
	}
}
