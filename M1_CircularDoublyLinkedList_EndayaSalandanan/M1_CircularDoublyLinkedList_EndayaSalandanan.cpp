/*
Name         : Carlie Endaya
               Christian Salandanan
Student ID   : 2022153105
               2022153519
Section      : A54
Date         : 26/09/23
Program File : M1_CircularDoublyLinkedList_EndayaSalandanan
*/

#include <iostream>
#include <cctype>
#include <climits>

using namespace std;

struct Node
{
    int dataField;
    Node* prevPtrField;
    Node* nextPtrField;
};

Node* headPtr = nullptr;
Node* tailPtr = nullptr;

void InsertNode()
{
    try
    {
        Node* newNodePtr = new Node();
        int value;

        if (newNodePtr == nullptr)
        {
            cout << "\n! O V E R F L O W !\n\nAllocating Memory Location for New Node Failed.\n";
        }
        else
        {
            do
            {
                cout << "Enter Desired value for Node: ";
                cin >> value;

                if (cin.fail() && value > INT_MAX)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n! E R R O R !\n\nInvalid Input for Node Value.\n";
                }
                else
                {
                    break;
                }

            } while (true);

            newNodePtr->dataField = value;

            if (headPtr == nullptr)
            {
                newNodePtr->nextPtrField = newNodePtr;
                newNodePtr->prevPtrField = newNodePtr;
                headPtr = newNodePtr;
                tailPtr = newNodePtr;
                cout << "\nThe NODE has been Inserted.\n" << endl;
            }
            else
            {
                Node* currentPtr = headPtr;

                while (currentPtr->dataField < value)
                {
                    if (currentPtr == tailPtr)
                    {
                        break;
                    }
                    currentPtr = currentPtr->nextPtrField;
                }

                if (currentPtr == headPtr && currentPtr->dataField >= value)
                {
                    newNodePtr->nextPtrField = currentPtr;
                    newNodePtr->prevPtrField = currentPtr->prevPtrField;
                    currentPtr->prevPtrField->nextPtrField = newNodePtr;
                    currentPtr->prevPtrField = newNodePtr;
                    headPtr = newNodePtr;
                    cout << "\nThe NODE has been Inserted.\n" << endl;
                }

                else if (currentPtr->dataField >= value)
                {
                    newNodePtr->nextPtrField = currentPtr;
                    newNodePtr->prevPtrField = currentPtr->prevPtrField;
                    currentPtr->prevPtrField->nextPtrField = newNodePtr;
                    currentPtr->prevPtrField = newNodePtr;
                    cout << "\nThe NODE has been Inserted.\n" << endl;
                }

                else if (currentPtr == tailPtr)
                {
                    newNodePtr->nextPtrField = headPtr;
                    newNodePtr->prevPtrField = tailPtr;
                    headPtr->prevPtrField = newNodePtr;
                    tailPtr->nextPtrField = newNodePtr;
                    tailPtr = newNodePtr;
                    cout << "\nThe NODE has been Inserted.\n" << endl;
                }
            }
        }
    }
    catch (...)
    {
        cerr << "\nAn unexpected E R R O R occured.\n";
    }
}

void DeleteNode()
{
    try
    {
        Node* currentPtr = headPtr;
        int value = 0;

        if (headPtr == nullptr)
        {
            cout << "\n! U N D E R F L O W !\n\nThe list is E M P T Y.\n\n";
        }
        else if (currentPtr == tailPtr)
        {
            headPtr = nullptr;
            tailPtr = nullptr;
            delete currentPtr;
            cout << "\nNODE has been Deleted.\n" << endl;
        }
        else
        {
            do
            {
                cout << "Enter Value for Node Deletion: ";
                cin >> value;

                if (cin.fail() && value > INT_MAX)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n! E R R O R !\n\nInvalid Input for Node Value.\n";
                }
                else
                {
                    break;
                }

            } while (true);

            while (currentPtr->dataField != value)
            {
                currentPtr = currentPtr->nextPtrField;

                if (currentPtr->nextPtrField == headPtr && currentPtr->dataField != value)
                {
                    cout << "\nNODE with Value " << value << " cannot be found.\n" << endl;
                    return;
                }
            }

            if (currentPtr == headPtr && currentPtr->dataField == value)
            {
                currentPtr->nextPtrField->prevPtrField = tailPtr;
                tailPtr->nextPtrField = currentPtr->nextPtrField;
                headPtr = currentPtr->nextPtrField;
                delete currentPtr;
                currentPtr = headPtr;
                headPtr = tailPtr->nextPtrField;
                cout << "\nHEAD NODE with Value " << value << " has been Deleted.\n" << endl;

            }
            else if (currentPtr == tailPtr && currentPtr->dataField == value)
            {
                currentPtr->prevPtrField->nextPtrField = headPtr;
                headPtr->prevPtrField = currentPtr->prevPtrField;
                delete currentPtr;
                currentPtr = headPtr;
                tailPtr = headPtr->prevPtrField;
                cout << "\nTAIL NODE with Value " << value << " has been Deleted.\n" << endl;

            }
            else if (currentPtr->dataField == value)
            {
                currentPtr->prevPtrField->nextPtrField = currentPtr->nextPtrField;
                currentPtr->nextPtrField->prevPtrField = currentPtr->prevPtrField;
                delete currentPtr;
                currentPtr = headPtr;
                cout << "\nNODE with Value " << value << " has been Deleted.\n" << endl;
            }
        }
    }
    catch (...)
    {
        cerr << "\nAn unexpected E R R O R occured.\n";
    }
}

void SearchNode()
{
    try
    {
        int value, location = 0;

        if (headPtr == nullptr)
        {
            cout << "\n! U N D E R F L O W !\n\nThe list is E M P T Y.\n" << endl;
            return;
        }
        else
        {
            do
            {
                cout << "Enter Value: ";
                cin >> value;

                if (cin.fail() && value > INT_MAX)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n! E R R O R !\n\nInvalid Input for Node Value.\n";
                }
                else
                {
                    break;
                }

            } while (true);

            Node* headSearchPtr = headPtr;
            Node* tailSearchPtr = tailPtr;

            while (headSearchPtr != tailSearchPtr)
            {
                if (headSearchPtr->dataField == value)
                {
                    cout << "\nNODE with value of " << value << " was found near at Head Pointer Position.\n" << endl;
                    return;
                }

                if (tailSearchPtr->dataField == value)
                {
                    cout << "\nNODE with value of " << value << " was found near at Tail Pointer Position.\n" << endl;
                    return;
                }

                headSearchPtr = headSearchPtr->nextPtrField;
                tailSearchPtr = tailSearchPtr->prevPtrField;
                ++location;
            }

            if (headSearchPtr == tailSearchPtr && headSearchPtr->dataField == value)
            {
                cout << "\nNODE with value of " << value << " was found at index " << location << "\n" << endl;
            }
            else
            {
                cout << "\nNODE with value of " << value << " does not exist in the list.\n" << endl;
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
        if (headPtr == nullptr)
        {
            cout << "\n! U N D E R F L O W !\n\nThe list is E M P T Y.\n\n";
            return;
        }
        else
        {
            cout << "\nCIRCULAR DOUBLY LINKED-LIST NODES\n" << endl;
            Node* currentPtr = headPtr;

            do
            {
                cout << '[' << currentPtr->dataField << ']' << " ";
                currentPtr = currentPtr->nextPtrField;

            } while (currentPtr != headPtr);
            

        }
        cout << "\n" << endl;
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

        while (choice != 5)
        {
            cout << "MAIN MENU\n\n1.INSERT NODE\n2.DELETE A SPECIFIC NODE\n3.SEARCH A SPECIFIC NODE VALUE\n4.DISPLAY LIST OF NODES\n5.EXIT CODE\n";
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (cin.fail() || choice > 5 || choice <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n! E R R O R !\n\nPlease Enter a Valid Input.\n\n";
                continue;
            }

            switch (choice)
            {
            case 1: InsertNode(); break;
            case 2: DeleteNode(); break;
            case 3: SearchNode(); break;
            case 4: DisplayList(); break;
            case 5: exit(0); break;
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
    try
    {
        ProgramBody();
        return 0;
    }
    catch (...)
    {
        cerr << "\nAn unexpected E R R O R occured.\n";
    }
}