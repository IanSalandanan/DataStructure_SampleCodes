/*
Name         : Carlie Endaya
			   Christian Salandanan
Student ID   : 2022153105
			   2022153519
Section      : A54
Date         : 08/09/23
Program File : ArrayCode_EndayaSalandanan
*/

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	char barCode[12], codeLength;
	int i;
	string opTion;
	bool isActive = true;
	do 
	{
		system("pause");
		cout << "Enter Barcode Number: ";
		cin >> barCode;

		codeLength = strlen(barCode);
		cout << "\nEncoded Value: ";

		for (i = 0; i < codeLength; i++)
		{
			if (barCode[i] == '0')
			{
				cout << "X"; Sleep(400);
			}
			else if (barCode[i] == '1')
			{
				cout << "C"; Sleep(400);
			}
			else if (barCode[i] == '2')
			{
				cout << "O"; Sleep(400);
			}
			else if (barCode[i] == '3')
			{
				cout << "M"; Sleep(400);
			}
			else if (barCode[i] == '4')
			{
				cout << "P"; Sleep(400);
			}
			else if (barCode[i] == '5')
			{
				cout << "U"; Sleep(400);
			}
			else if (barCode[i] == '6')
			{
				cout << "T"; Sleep(400);
			}
			else if (barCode[i] == '7')
			{
				cout << "E"; Sleep(400);
			}
			else if (barCode[i] == '8')
			{
				cout << "R"; Sleep(400);
			}
			else if (barCode[i] == '9')
			{
				cout << "S"; Sleep(400);
			}
			else if (barCode[i] == '.')
			{
				cout << "."; Sleep(400);
			}
			else
			{
				cout << "Invalid!";
			}
		}

		cout << "\nWould you like to exit? [Yes/No]: ";
		cin >> opTion;

		if (opTion._Equal("Yes"))
		{
			isActive = false;
		}
		else if (opTion._Equal("No"))
		{
			continue;
		}
	} while (isActive);
	return 0;
}