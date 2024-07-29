/*
Name         : Carlie Endaya
		       Christian Salandanan
Student ID   : 2022153105
		       2022153519
Section      : A54
Date         : 08/09/23
Program File : Pointer5_EndayaSalandanan
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
	int a, b, * uno = &a, * dos = &b;
	string opTion;
	bool isActive = true;

	cout << "Welcome to swapping values!" << endl; cout << "Press any key to start..." << endl;

	_getch();

	Sleep(600);
	system("cls");

	while(isActive)
	{
		cout << "Enter value for Pointer Variable Uno: ";
		cin >> a;

		cout << "Enter value for Pointer Variable Dos: ";
		cin >> b;


		cout << "Value of Pointer Variable Uno before swap : " << a << "\n" << "Value of Pointer Variable Dos before swap : " << b << endl;
		cout << " " << endl;

		*uno = *uno + *dos;
		*dos = *uno - *dos;
		*uno = *uno - *dos;

		cout << "Value of Uno after swapping: " << *uno << "\n" << "Address: " << uno << endl;
		cout << " " << endl;
		cout << "Value of Dos after swapping: " << *dos << "\n" << "Address: " << dos << endl;

		cout << "\nWould you like to try again? [Yes/No]: ";
		cin >> opTion;

		if (opTion._Equal("Yes")) 
		{
			continue;
		}
		else if (opTion._Equal("No"))
		{
			isActive = false;
		}
	}

	return 0;
}