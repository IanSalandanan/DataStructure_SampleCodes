/*Name       : Carlie Endaya
               Christian Salandanan
Student ID   : 2022153105
               2022153519
Section      : A54
Date         : 26/09/23
Program File : M1_DoublyLinkedList_EndayaSalandanan*/

#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

struct node {
    struct node* prevPtrField;
    struct node* nextPtrField;
    int data;
};

node* headPtr = nullptr;

void InsertStart()
{
    struct node* ptr = new node();
    int value;

    if (ptr == nullptr)
    {
        cout << "Allocating Memory Failed\n\n!OVERFLOW!";
    }
    else
    {
        do
        {
            cout << "Enter value for new node: ";
            cin >> value;

            if (cin.fail() || cin.peek() != '\n')
            {
                cout << "\nInvalid input. Must be an integer." << endl;
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input                 
            }
            else
            {
                break;
            }
        } while (true);

        ptr->data = value;

        if (headPtr == nullptr)
        {
            ptr->nextPtrField = nullptr;
            ptr->prevPtrField = nullptr;
            headPtr = ptr;
            cout << "\nHEAD node INSERTED in the list.\n";
        }
        else //insert at start
        {
            ptr->prevPtrField = nullptr;
            ptr->nextPtrField = headPtr;
            headPtr->prevPtrField = ptr;
            headPtr = ptr;
            cout << "\nNode with value " << value << " INSERTED at the START of the list.\n";
        }
    }
}

void InsertEnd()
{
    struct node* ptr = new node(), * temp;
    int value;

    if (ptr == nullptr)
    {
        throw runtime_error("Allocating Memory Failed\n\n!OVERFLOW!");
    }
    else {
        do
        {
            cout << "Enter value: ";
            cin >> value;

            if (cin.fail() || cin.peek() != '\n')
            {
                cout << "\nInvalid input. Must be an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        } while (true);
        ptr->data = value;

        if (headPtr == nullptr)
        {
            ptr->nextPtrField = nullptr;
            ptr->prevPtrField = nullptr;
            headPtr = ptr;
            cout << "\nList is empty. HEAD node is INSERTED in the list.\n";
        }
        else //insert at the end
        {
            temp = headPtr;
            while (temp->nextPtrField != nullptr)
            {
                temp = temp->nextPtrField; //traverse
            }
            temp->nextPtrField = ptr;
            ptr->prevPtrField = temp;
            ptr->nextPtrField = nullptr;
            cout << "\nNode with value '" << value << "' inserted at the end of the list.\n";
        }
    }
}

void InsertInBetween()
{
    struct node* ptr = new node(), * temp;
    int value, location, i;

    if (ptr == nullptr)
    {
        throw runtime_error("Allocating Memory Failed\n\n!OVERFLOW!");
    }
    else
    {
        temp = headPtr;
        cout << "Enter the position(INDEX) where you want to insert the new node\n(NOTE: The value will be inserted AFTER the specified position.): ";
        cin >> location;

        for (i = 0; i < location; i++)
        {
            temp = temp->nextPtrField;
            if (temp == nullptr)
            {
                cout << "There are less than " << location << " elements.";
                return;
            }
        }
        do
        {
            cout << "Enter value of new node: ";
            cin >> value;

            if (cin.fail() || cin.peek() != '\n')
            {
                cout << "\nInvalid input. Must be an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else
            {
                break;
            }
        } while (true);

        ptr->data = value;
        ptr->nextPtrField = temp->nextPtrField;
        ptr->prevPtrField = temp;
        temp->nextPtrField = ptr;
        temp->nextPtrField->prevPtrField = ptr;
        cout << "\nNode with value " << value << " inserted at position(INDEX) " << location + 1 << ".\n";
    }
}

void BeginDelete()
{
    struct node* ptr;

    if (headPtr == nullptr)
    {
        throw runtime_error("!UNDERFLOW! Nothing to delete. List is EMPTY.\n");
    }
    else if (headPtr->nextPtrField == nullptr)
    {
        headPtr = nullptr;
        delete headPtr;
        cout << "\nHEAD node of the list is DELETED.\n\n";
    }
    else
    {
        ptr = headPtr;
        headPtr = headPtr->nextPtrField;
        headPtr->prevPtrField = nullptr;
        delete ptr;
        cout << "\nFIRST node of the list is DELETED. Next node is the new HEAD node.\n";
    }

}

void LastDelete()
{
    struct node* ptr;
    if (headPtr == nullptr)
    {
        throw runtime_error("!UNDERFLOW! Nothing to delete. List is EMPTY.\n");
    }
    else if (headPtr->nextPtrField == nullptr)
    {
        headPtr = nullptr;
        delete headPtr;
        cout << "\nHEAD node is DELETED from the list.\n";
    }
    else
    {
        ptr = headPtr;
        if (ptr->nextPtrField != nullptr)
        {
            ptr = ptr->nextPtrField;
        }
        ptr->prevPtrField->nextPtrField = nullptr;
        delete ptr;
        cout << "\nLAST node is DELETED from the list.\n";
    }
}

void InBetweenDelete()
{
    struct node* ptr=headPtr;
    int value;

    if (headPtr == nullptr)
    {
        throw runtime_error("!UNDERFLOW! Nothing to delete. List is EMPTY.\n");
    }
    else 
    {
        if (ptr->nextPtrField == nullptr && ptr->prevPtrField == nullptr)
        {
            headPtr = nullptr;
            delete ptr;
            cout << "Node Deleted.";
        }
        else 
        {
            cout << "Enter the value after which the node is to be deleted: ";
            cin >> value;

            if (ptr->data == value)
            {
                cout << "Cannot delete the FIRST NODE.";
            }
            else 
            {
                while (ptr->data != value)
                {
                    ptr = ptr->nextPtrField;

                    if (ptr->nextPtrField == nullptr)
                    {
                        cout << "Cannot delete the LAST NODE.";
                        return;
                    }
                }
                ptr->prevPtrField->nextPtrField = ptr->nextPtrField;
                ptr->nextPtrField->prevPtrField = ptr->prevPtrField;
                delete ptr;
                ptr = headPtr;
                cout << "Node Deleted.";
            }
        }
    }
}

void SearchValue()
{
    struct node* ptr;
    int value, i = 0, flag;
    ptr = headPtr;
    if (ptr == nullptr)
    {
        throw runtime_error("!UNDERFLOW! Nothing to delete. List is EMPTY.\n");
    }
    else
    {
        cout << "\nEnter the VALUE which you want to SEARCH: ";
        cin >> value;
        while (ptr != nullptr)
        {
            if (ptr->data == value)
            {
                cout << "\nValue of the element found at position (index): " << i << "\n";
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->nextPtrField;
        }
        if (flag == 1)
        {
            cout << "\nValue NOT found in the list.\n";
        }
    }

}

void DisplayList()
{
    struct node* ptr;
    ptr = headPtr;

    cout << "\nPrinting values in the list...";
    while (ptr != nullptr)
    {
        cout << "\n" << ptr->data;
        ptr = ptr->nextPtrField;
    }
}

void ProgramBody()
{
    int choice = 0;
    while (choice != 9)
    {
        cout << "\n*********Double Linked List Main Menu*********\n" << endl;
        cout << "Choose a NUMBER from the following list." << endl;
        cout << "1. Insert at the start\n2. Insert at the last\n3. Insert in between \n4. Delete at the start\n5. Delete at the end\n6. Delete node in between\n7. Search for a value\n8. Display List\n9. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1: InsertStart(); break;
            case 2: InsertEnd(); break;
            case 3: InsertInBetween(); break;
            case 4: BeginDelete(); break;
            case 5: LastDelete(); break;
            case 6: InBetweenDelete(); break;
            case 7: SearchValue(); break;
            case 8: DisplayList(); break;
            case 9: cout << "Goodbye!\n"; break;
            default: cout << "Invalid Choice.\n"; break;
            }
        }
        catch (const exception& e)
        {
            cerr << "\nError: " << e.what() << endl;
            continue;
        }
    }
}

int main()
{
    ProgramBody();
    return 0;
}