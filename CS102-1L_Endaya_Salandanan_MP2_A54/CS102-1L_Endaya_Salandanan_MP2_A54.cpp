/*
Name         : Carlie Endaya
               Christian Salandanan
Student ID   : 2022153105
               2022153519
Section      : A54
Date         : 21/11/2023
Program File : Machine_Problem2_EndayaSalandanan
Description  : The C++ application provides input validation for efficient staff ID management and student ID management
               1. STAFF SECTION: Enlist, delete, search, and display staff ID numbers using a circular doubly linked list
               2. STUDENT SECTION: Enqueue, dequeue, and display student ID numbers using a queue structure
               3. EXIT PROGRAM
*/

#include <iostream>
#include <cctype>
#include <climits>
#include <string>

using namespace std;

struct node
{
    int data;
    struct node* next;
};
struct node* front;
struct node* rear;

void DisplayStudNum() {
    cout << "Student number list: ";
    for (node* ptr = front; ptr; ptr = ptr->next)
    {
        cout << ptr->data << " ";
    }
    cout << endl;
}

void Enqueue()
{
    struct node* ptr;
    int item = 0;
    bool isAlreadyInQueue = false;

    ptr = new struct node;
    if (ptr == nullptr)
    {
        cout << "\nOVERFLOW\n";
        return;
    }
    else
    {
        do {
            cout << "Enter student number (e.g. 2022153105): ";
            string input;
            cin >> input;

            try {
                item = stoi(input);

                if (input.length() == 10 && item > 0) {
                    for (node* checkPtr = front; checkPtr; checkPtr = checkPtr->next)
                    {
                        if (checkPtr->data == item)
                        {
                            isAlreadyInQueue = true;
                            cout << "\nInvalid input. Student ID already in the queue.\n\n";
                            break;
                        }
                    }
                    break;
                }
                else { cout << "\nInvalid input. Student ID must have 10 positive digits.\n\n"; }
            }
            catch (const invalid_argument& e) {
                cout << "\nInvalid input. Inputted value must have positive integers.\n\n";
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
            }
            catch (const out_of_range& e) {
                cout << "\nInvalid input. Inputted value is out of range.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (true);

        if (!isAlreadyInQueue) {
            ptr->data = item;
            if (front == nullptr)
            {
                front = ptr;
                rear = ptr;
                front->next = nullptr;
                rear->next = nullptr;
            }
            else
            {
                rear->next = ptr;
                rear = ptr;
                rear->next = nullptr;
            }
        }
    }
    DisplayStudNum();
}

void Dequeue()
{
    struct node* ptr;
    if (front == nullptr)
    {
        cout << "\nUNDERFLOW\n";
    }
    else if (front->next == nullptr)
    {
        ptr = front;
        delete ptr;
        cout << "\nDeleted the only student ID. Empty queue\n";
        front = nullptr;
    }
    else
    {
        ptr = front;
        front = front->next;
        delete ptr;
        cout << "\nDeleted the first student ID. The new first student ID is: " << front->data << endl;
    }
}

void DisplayFront()
{
    struct node* ptr;
    ptr = front;
    if (front == nullptr) { cout << "\nCannot display the first student ID. Empty queue.\n"; }
    else if (front->next == nullptr) { DisplayStudNum(); cout << "\n\nThere is only one student ID in the queue: " << front->data << endl; }
    else { DisplayStudNum(); cout << "\n\nThe first student ID of the queue is: " << front->data << endl; }
}

void DisplayRear()
{
    struct node* ptr;
    ptr = rear;
    if (rear == nullptr) { cout << "\nCannot display the last student ID. Empty queue.\n"; }
    else if (front->next == nullptr) { DisplayStudNum(); cout << "\n\nThere is only one student ID in the queue: " << front->data << endl; }
    else { DisplayStudNum(); cout << "\n\nThe last student ID of the queue is: " << rear->data << endl; }
}

void programBody()
{
    int choice = 0;
    while (choice != 5)
    {
        cout << "\n************ Main Menu ************\n";
        cout << "1. ADD STUDENT ID NUMBER\n2. DELETE THE FIRST STUDENT ID NUMBER\n3. DISPLAY FIRST STUDENT ID NUMBER\n4. DISPLAY LAST STUDENT ID NUMBER\n5. RETURN TO MAIN MENU\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail() || cin.peek() != '\n')
        {
            cout << "Invalid choice. Must be an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try
        {
            switch (choice)
            {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: DisplayFront(); break;
            case 4: DisplayRear(); break;
            case 5: return; break;
            default: cout << "Invalid choice.\n"; break;
            }
        }
        catch (const exception& e)
        {
            cerr << "\nError: " << e.what() << endl; continue;
        }
    }
}

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
                cout << "Enter Staff ID Number: ";
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
                cout << "\nSTAFF ID NUMBER HAS BEEN RECORDED.\n" << endl;
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
                    cout << "\nSTAFF ID NUMBER HAS BEEN RECORDED.\n" << endl;
                }

                else if (currentPtr->dataField >= value)
                {
                    newNodePtr->nextPtrField = currentPtr;
                    newNodePtr->prevPtrField = currentPtr->prevPtrField;
                    currentPtr->prevPtrField->nextPtrField = newNodePtr;
                    currentPtr->prevPtrField = newNodePtr;
                    cout << "\nSTAFF ID NUMBER HAS BEEN RECORDED.\n" << endl;
                }

                else if (currentPtr == tailPtr)
                {
                    newNodePtr->nextPtrField = headPtr;
                    newNodePtr->prevPtrField = tailPtr;
                    headPtr->prevPtrField = newNodePtr;
                    tailPtr->nextPtrField = newNodePtr;
                    tailPtr = newNodePtr;
                    cout << "\nSTAFF ID NUMBER HAS BEEN RECORDED.\n" << endl;
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
            cout << "\nThe Entire Staff Record list has been Cleared.\n" << endl;
        }
        else
        {
            do
            {
                cout << "Enter Staff ID Number to be Deleted: ";
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
                    cout << "\nRECORD OF STAFF ID NUMBER: " << value << " cannot be found.\n" << endl;
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
                cout << "\nRECORD OF STAFF ID NUMBER: " << value << " has been Deleted.\n" << endl;

            }
            else if (currentPtr == tailPtr && currentPtr->dataField == value)
            {
                currentPtr->prevPtrField->nextPtrField = headPtr;
                headPtr->prevPtrField = currentPtr->prevPtrField;
                delete currentPtr;
                currentPtr = headPtr;
                tailPtr = headPtr->prevPtrField;
                cout << "\nRECORD OF STAFF ID NUMBER: " << value << " has been Deleted.\n" << endl;

            }
            else if (currentPtr->dataField == value)
            {
                currentPtr->prevPtrField->nextPtrField = currentPtr->nextPtrField;
                currentPtr->nextPtrField->prevPtrField = currentPtr->prevPtrField;
                delete currentPtr;
                currentPtr = headPtr;
                cout << "\nRECORD OF STAFF ID NUMBER: " << value << " has been Deleted.\n" << endl;
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
                cout << "STAFF ID NUMBER: ";
                cin >> value;

                if (cin.fail() && value > INT_MAX)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n! E R R O R !\n\nInvalid Input for Staff ID Number.\n";
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
                    cout << "\nSTAFF ID NUMBER: " << value << " was found near at the Start Section of the List.\n" << endl;
                    return;
                }

                if (tailSearchPtr->dataField == value)
                {
                    cout << "\nSTAFF ID NUMBER: " << value << " was found near at the Last Section of the List.\n" << endl;
                    return;
                }

                headSearchPtr = headSearchPtr->nextPtrField;
                tailSearchPtr = tailSearchPtr->prevPtrField;
                ++location;
            }

            if (headSearchPtr == tailSearchPtr && headSearchPtr->dataField == value)
            {
                cout << "\nSTAFF ID NUMBER: " << value << " was found at index " << location << "\n" << endl;
            }
            else
            {
                cout << "\nSTAFF ID NUMBER: " << value << " does not exist in the list.\n" << endl;
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
            cout << "\nMMCL STAFF ID NUMBER LIST\n" << endl;
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
            cout << "MMCL STAFF DASHBOARD\n\n1.ENLIST NEW STAFF ID NUMBER\n2.DELETE EXISTING STAFF ID NUMBER\n3.SEARCH STAFF ID NUMBER\n4.DISPLAY STAFF LIST\n5.RETURN TO MENU\n";
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
            case 5: return; break;
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
        int choice = 0;

        while (choice != 3)
        {
            cout << "MMCL DATABASE\n\n1.STAFF SECTION\n2.STUDENT SECTION\n3.EXIT PROGRAM\n";
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (cin.fail() || choice > 3 || choice <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n! E R R O R !\n\nPlease Enter a Valid Input.\n\n";
                continue;
            }

            switch (choice)
            {
            case 1: ProgramBody(); break;
            case 2: programBody(); break;
            case 3: exit(0); break;
            }
        }

        return 0;
    }
    catch (...)
    {
        cerr << "\nAn unexpected E R R O R occured.\n";
    }
}