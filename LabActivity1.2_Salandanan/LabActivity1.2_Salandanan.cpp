/*
 Name         : Christian Kerby T. Salandanan
 Student ID   : 2022153519
 Section      : BSIT A54
 Date         : 20/09/2023
 Program File : LabActivity1.2_Salandanan
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char equivalentValues[10] = { 'O','n','E','M','a','L','@','Y','A','N' }, studentID[11], terminateOption;
	bool isActive = true, isValid;
	int index, studentIDLen;
	string studentName;

	while (isActive)
	{
		cout << "Enter Student Name (Last Name / First Name / Middle Initial) : ";
		getline(cin, studentName);

		cout << "Enter Student ID : (##########): ";
		cin >> studentID;

		cout << "\nStudent Name           : " << studentName << endl;
		cout << "Student Generated Code : ";

		studentIDLen = strlen(studentID);

		for (index = 0; index < studentIDLen; index++)
		{
			switch (studentID[index])
			{
			case '0': cout << equivalentValues[0]; break;
			case '1': cout << equivalentValues[1]; break;
			case '2': cout << equivalentValues[2]; break;
			case '3': cout << equivalentValues[3]; break;
			case '4': cout << equivalentValues[4]; break;
			case '5': cout << equivalentValues[5]; break;
			case '6': cout << equivalentValues[6]; break;
			case '7': cout << equivalentValues[7]; break;
			case '8': cout << equivalentValues[8]; break;
			case '9': cout << equivalentValues[9]; break;
			}
		}

		cout << "\n\nThe Address Value of Student ID Array is        :" << &studentID << endl;
		cout << "The Address Value of Equivalent Values Array is :" << &equivalentValues;

		do 
		{
			cout << "\n\nWould you like to EXIT the Program? [Y/N]: ";
			cin >> terminateOption;

			switch (terminateOption)
			{
			case 'y':
			case 'Y': cout << "\nThank You and Good Bye!"; isValid = false; isActive = false; break;
			case 'n':
			case 'N': isValid = false; isActive = true; break;
			default: cout << "Invalid Input!\nPlease Enter a VALID Choice."; isValid = true; break;
			}
		} while (isValid);

		cout << "\n";
		cin.ignore();
	}
}

