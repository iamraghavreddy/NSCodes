//Name: Kaushik Shroff
//Batch: K-8
//Roll No: 32418
//Experiment No: 2

//Code for encryption using transposition cipher
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string key;
	int key_size;
	cout<<"Enter the key"<<endl;
	getline(cin,key);
	key_size=key.length();
	char keyer[key_size];
	string message;
	cout<<"Enter the message"<<endl;
	getline(cin,message);
	int messagesize=message.length();
	int n=0,arrheight=0;
	string rand="ashgftdhdghtdhd";
	while(n<messagesize)
	{
		n=n+key_size;
		arrheight++;
	}
	string base;
	if(n!=messagesize)
	{
		message.append(base.assign(rand,0,n-messagesize));
	}
	string enco[arrheight];
	n=0;
	for(int i=0;i<arrheight;i++)
	{
		for(int j=0;j<key_size;j++)
		{
			enco[i]=enco[i]+message.at(n);
			n++;
		}
		cout<<endl;
	}
	int arr_of_cipher[key_size];
	char arr_of_char[key_size];
	for(int i=0;i<key_size;i++)
	{
		arr_of_cipher[i]=(int)key.at(i);
		arr_of_char[i]=key.at(i);
	}
	for(int i=0;i<key_size;i++)
	{
		for(int j=0;j<key_size-1;j++)
		{
			if(arr_of_cipher[j]>arr_of_cipher[j+1])
			{
				int temp=arr_of_cipher[j];
				arr_of_cipher[j]=arr_of_cipher[j+1];
				arr_of_cipher[j+1]=temp;
				char emp=arr_of_char[j];
				arr_of_char[j]=arr_of_char[j+1];
				arr_of_char[j+1]=emp;
			}
		}
	}
	string encrypted_message="";
	n=0;
	for(int i=0;i<key_size;i++)
	{
		for(int j=0;j<key_size;j++)
		{
			if(key.at(j)==arr_of_char[i])
			{
				for(int k=0;k<arrheight;k++)
				{
					encrypted_message=encrypted_message+enco[k].at(j);
				}
			}
		}
	}
	cout<<"Encrypted message \n"<<encrypted_message<<endl;
}
