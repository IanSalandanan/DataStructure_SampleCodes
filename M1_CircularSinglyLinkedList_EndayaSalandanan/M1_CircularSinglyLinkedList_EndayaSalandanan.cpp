/*
Name         : Carlie Endaya
			   Christian Salandanan
Student ID   : 2022153105
			   2022153519
Section      : A54
Date         : 26/09/23
Program File : M1_CircularSinglyLinkedList_EndayaSalandanan
*/

#include <iostream>
#include <cctype>

using namespace std;

struct Node 
{
	int data;
	struct Node* nextPtrField;
};

struct Node* headPtr;

void InsertFront()
{
	try 
	{
		struct Node* ptrNew;
		int value;

		ptrNew = new Node();

		if (ptrNew == nullptr)
		{
			cout << "\n! O V E R F L O W !\n\nProviding Memory Allocation for Creating a New Node Failed.\n";
		}
		else
		{
			do
			{
				cout << "\nEnter Desired Value: ";
				cin >> value;

				if (!cin.fail() && value <= 2147483647)
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n! E R R O R !\nInvalid Input!\n";
					continue;
				}

			} while (true);

			ptrNew->data = value;

			if (headPtr == nullptr)
			{
				headPtr = ptrNew;
				ptrNew->nextPtrField = headPtr;
			}
			else
			{
				struct Node* currentPtr = headPtr;

				while (currentPtr->nextPtrField != headPtr)
				{
					currentPtr = currentPtr->nextPtrField;
				}

				ptrNew->nextPtrField = headPtr;
				currentPtr->nextPtrField = ptrNew;
				headPtr = ptrNew;
			}
			cout << "\nThe NODE has been INSERTED.\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void InsertRear()
{
	try
	{
		struct Node* ptrNew;
		int value;

		ptrNew = new Node();

		if (ptrNew == nullptr)
		{
			cout << "\n! O V E R F L O W !\n\nProviding Memory Allocation for Creating a New Node Failed.\n";
		}
		else
		{

			do
			{
				cout << "\nEnter Desired Value: ";
				cin >> value;

				if (!cin.fail() && value <= 2147483647)
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n! E R R O R !\nInvalid Input!\n";
					continue;
				}

			} while (true);

			ptrNew->data = value;

			if (headPtr == nullptr)
			{
				headPtr = ptrNew;
				ptrNew->nextPtrField = headPtr;
			}
			else
			{
				struct Node* currentPtr = headPtr;
				while (currentPtr->nextPtrField != headPtr)
				{
					currentPtr = currentPtr->nextPtrField;
				}

				ptrNew->nextPtrField = headPtr;
				currentPtr->nextPtrField = ptrNew;
			}
			cout << "\nThe NODE has been INSERTED.\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void InsertInBetween()
{
	try
	{
		struct Node* ptrNew;
		int value, location, iterator;

		ptrNew = new Node();

		if (ptrNew == nullptr)
		{
			cout << "\n! O V E R F L O W !\n\nProviding Memory Allocation for Creating a New Node Failed.\n";
		}
		else
		{
			do
			{
				cout << "\nEnter Desired Value: ";
				cin >> value;

				if (!cin.fail() && value <= 2147483647)
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n! E R R O R !\nInvalid Input!\n";
					continue;
				}

			} while (true);

			ptrNew->data = value;

			if (headPtr == nullptr)
			{
				headPtr = ptrNew;
				ptrNew->nextPtrField = headPtr;
			}
			else
			{
				do
				{
					cout << "\nEnter the position (index) after which you want to insert the new node: ";
					cin >> location;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n! E R R O R !\nInvalid Input!\n";
						continue;
					}
					else
					{break;}

				} while (true);

				struct Node* currentPtr = headPtr;

				for (iterator = 0; iterator < location; iterator++)
				{
					currentPtr = currentPtr->nextPtrField;

					if (currentPtr->nextPtrField == headPtr)
					{
						cout << "\nCannot Insert Value.\n";
						return;
					}
				}
				ptrNew->nextPtrField = currentPtr->nextPtrField;
				currentPtr->nextPtrField = ptrNew;
			}
			cout << "\nThe NODE has been INSERTED.\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occurred.\n";
	}
}

void DeleteFront()
{
	try
	{
		struct Node* currentPtr;

		if (headPtr == nullptr)
		{
			cout << "\n! U N D E R F L O W !\n\nThe List is EMPTY.\n";
		}
		else if (headPtr->nextPtrField == headPtr)
		{
			headPtr = nullptr;
			delete headPtr;
			cout << "\nNODE TERMINATED.\n";
		}
		else
		{
			currentPtr = headPtr;
			while (currentPtr->nextPtrField != headPtr)
			{
				currentPtr = currentPtr->nextPtrField;
			}
			currentPtr->nextPtrField = headPtr->nextPtrField;
			delete headPtr;
			headPtr = currentPtr->nextPtrField;
			cout << "\nNODE TERMINATED.\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void DeleteRear()
{
	try
	{
		struct Node* currentPtr, * delayedPtr;

		if (headPtr == nullptr)
		{
			cout << "\n! U N D E R F L O W !\n\nThe List is EMPTY.\n";
		}
		else if (headPtr->nextPtrField == headPtr)
		{
			delete headPtr;
			headPtr = nullptr;
			cout << "\nNODE TERMINATED.\n";
		}
		else
		{
			currentPtr = headPtr;
			delayedPtr = headPtr;
			while (currentPtr->nextPtrField != headPtr)
			{
				delayedPtr = currentPtr;
				currentPtr = currentPtr->nextPtrField;
			}
			delayedPtr->nextPtrField = headPtr;
			delete currentPtr;
			cout << "\nNODE TERMINATED.\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void DeleteInBetween()
{
	try
	{
		struct Node* currentPtr = headPtr;
		struct Node* delayedPtr = headPtr;
		int value;

		if (headPtr == nullptr)
		{
			cout << "\n! U N D E R F L O W !\n\nThe List is EMPTY.\n";
		}

		else if (currentPtr->nextPtrField == headPtr)
		{
			headPtr = nullptr;
			delete headPtr;
			cout << "\nNODE TERMINATED.\n";
		}
		else
		{
			do
			{
				cout << "\nEnter the value of the node you wish to DELETE: ";
				cin >> value;

				if (!cin.fail() && value <= 2147483647)
				{
					break;
				}

				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n! E R R O R !\nInvalid Input!\n";
					continue;
				}

			} while (true);

			if (currentPtr->data == value)
			{
				cout << "\nCannot Delete FIRST Node.\n"; return;
			}

			while (currentPtr->data != value)
			{
				delayedPtr = currentPtr;
				currentPtr = currentPtr->nextPtrField;

				if (currentPtr->nextPtrField == headPtr)
				{
					cout << "\nCannot Delete LAST Node.\n"; return;
				}
			}
			delayedPtr->nextPtrField = currentPtr;
			delayedPtr->nextPtrField = currentPtr->nextPtrField;
			delete currentPtr;
			currentPtr = headPtr;
			cout << "\nNODE TERMINATED.\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void SearchValue()
{
	try
	{
		struct Node* currentPtr = headPtr;
		int value, location = 0, flag = 1;

		if (headPtr == nullptr)
		{
			cout << "\n! U N D E R F L O W !\n\nThe List is EMPTY.\n";
		}
		else
		{
			do
			{
				cout << "\nEnter Desired Value: ";
				cin >> value;

				if (!cin.fail() && value <= 2147483647)
				{
					break;
				}
				else
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n! E R R O R !\nInvalid Input!\n";
					continue;
				}

			} while (true);

			if (headPtr->data == value)
			{
				cout << "\n" << value << " found at " << location + 1 << endl;
				flag = 0;
			}
			else
			{
				while (currentPtr->nextPtrField != headPtr)
				{
					if (currentPtr->data == value)
					{
						cout << "\n" << value << " found at location " << location + 1 << endl;
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
					}
					location++;
					currentPtr = currentPtr->nextPtrField;
				}

				if (currentPtr->data == value)
				{
					cout << "\n" << value << " found at location " << location + 1 << endl;
					flag = 0;
				}
				if (flag == 1)
				{
					cout << "\n" << value << " cannot be found." << endl;
				}
			}
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void DisplayList()
{
	try
	{
		struct Node* currentPtr = headPtr;

		if (headPtr == nullptr)
		{
			cout << "\nThe List is E M P T Y.\n";
		}
		else
		{
			cout << "\nCircular Singly-Linked List Values:\n\n";

			while (currentPtr->nextPtrField != headPtr)
			{
				cout << currentPtr->data << " ";
				currentPtr = currentPtr->nextPtrField;
			}
			cout << currentPtr->data << "\n";
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

void ProgramBody()
{
	try
	{
		int choice = 0;
		cout << "\n*********Main Menu*********\n";
		cout << "\nChoose one option from the following list ...\n";
		cout << "\n===============================================\n";

		while (choice != 9)
		{
			cout << "\n1.INSERT NODE IN BEGINNING\n2.INSERT NODE AT LAST\n3.INSERT NODE IN BETWEEN\n4.DELETE NODE FROM BEGINNING\n5.DELETE NODE FROM LAST\n6.DELETE NODE IN BETWEEN\n7.SEARCH FOR VALUE\n8.DISPLAY LIST\n9.EXIT CODE\n";
			cout << "\nEnter your choice: ";
			cin >> choice;

			if (cin.fail() || choice > 9 || choice <= 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n! E R R O R !\nPlease Enter a Valid Input.\n";
				continue;
			}

			switch (choice)
			{
			case 1: InsertFront(); break;
			case 2: InsertRear(); break;
			case 3: InsertInBetween(); break;
			case 4: DeleteFront(); break;
			case 5: DeleteRear(); break;
			case 6: DeleteInBetween(); break;
			case 7: SearchValue(); break;
			case 8: DisplayList(); break;
			case 9: exit(0); break;
			}
		}
	}
	catch (...)
	{
		cerr << "\nAn unexpected E R R O R occured.\n";
	}
}

int main()
{
	ProgramBody();
	return 0;
}