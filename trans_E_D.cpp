#include <iostream>
#include <string>
#include <map>
using namespace std;

// Key for Columnar Transposition
string key;
map<char, int> keyMap;

void setPermutationOrder(const string &key)
{
	// Clear the keyMap before setting new values
	keyMap.clear();

	// Add the permutation order into map
	for (int i = 0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}
}

// Encryption
string encryptMessage(const string &msg)
{
	int row, col, j;
	string cipher = "";

	/* calculate column of the matrix */
	col = key.length();

	/* calculate maximum row of the matrix */
	row = (msg.length() + col - 1) / col;

	char matrix[row][col];

	for (int i = 0, k = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (k < msg.length())
				matrix[i][j] = msg[k++];
			else
				matrix[i][j] = ' ';
		}
	}

	for (map<char, int>::const_iterator it = keyMap.begin(); it != keyMap.end(); ++it)
	{
		j = it->second;

		// Getting cipher text from matrix column-wise using permuted key
		for (int i = 0; i < row; i++)
		{
			cipher += matrix[i][j];
		}
	}

	return cipher;
}

// Decryption
string decryptMessage(const string &cipher)
{
	/* calculate row and column for cipher matrix */
	int col = key.length();
	int row = cipher.length() / col;

	char matrix[row][col];

	/* Arrange the matrix column-wise according
	   to permutation order by adding into new matrix */
	int index = 0;
	for (map<char, int>::const_iterator it = keyMap.begin(); it != keyMap.end(); ++it)
	{
		int j = it->second;
		for (int i = 0; i < row; i++)
		{
			matrix[i][j] = cipher[index++];
		}
	}

	/* getting message using matrix */
	string msg = "";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			msg += matrix[i][j];
		}
	}

	return msg;
}

int main()
{
	/* message */
	string msg;

	cout << "Enter the key: ";
	getline(cin, key);

	cout << "Enter the message: ";
	getline(cin, msg);

	setPermutationOrder(key);

	// Calling encryption function
	string cipher = encryptMessage(msg);
	cout << "Encrypted Message: " << cipher << endl;

	// Calling Decryption function
	string decryptedMsg = decryptMessage(cipher);
	cout << "Decrypted Message: " << decryptedMsg << endl;

	return 0;
}
