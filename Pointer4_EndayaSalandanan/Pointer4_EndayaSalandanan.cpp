/*
Name         : Carlie Endaya
			   Christian Salandanan
Student ID   : 2022153105
			   2022153519
Section      : A54
Date         : 07/09/23
Program File : Pointer4_EndayaSalandanan
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
	int *sloTs, raNge, i, j;
	char opTion;
	bool isActive = true; bool isValid = true;

	system("pause");
	system("cls");

	while (isActive)
	{
		cout << "Enter an integer from 1 - 12: ";
		cin >> raNge;

		if (raNge > 12 || raNge < 1)
		{
			cout << "Invalid range!" << endl;

			Sleep(500);
			system("cls");
			continue;
		}
		else
		{
			Sleep(500);
			system("cls");

			sloTs = new int[raNge]; 

			for (i = 0; i < raNge; i++)
			{
				cout << "Enter value for slot " << i + 1 << " : ";
				cin >> sloTs[i];
			}

			cout << "\nArray Values: " << endl;

			for (j = 0; j < raNge; j++)
			{
				cout << sloTs[j] << ", ";
			}

			cout << "\n\nSlot 1 Value   : " << *sloTs << endl;
			cout << "Slot 1 Address : " << sloTs << endl;

			delete[] sloTs;

			do
			{
				cout << "\n\nWould you like to exit the program? [Y/N] " << endl;
				opTion = _getch();

				switch (opTion)
				{
				case 'Y':
				case 'y': isValid = true; isActive = false; break;
				case 'N':
				case 'n': isValid = true; isActive = true; Sleep(500); system("cls"); break;
				default: cout << "Invalid input!"; isValid = false;  break;
				}
			} while (!isValid);

		}
	}
	return 0;
}