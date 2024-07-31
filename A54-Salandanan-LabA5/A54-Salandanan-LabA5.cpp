//#Language : C++ 
//#Hashing Data Structure
//#Student Name : Salandanan, Christian Kerby T.
//#Course / Section: BSIT - A54
//#Program File : A54 - Salandanan - LabA5
//#Date / Time: 10/11/2023 / 9:49
//#Algorithm : Pseudocode
//C++ Program

#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;  

struct Node 
{
    int key;
    int data;
};

struct HashTable 
{
    Node table[TABLE_SIZE];
};

int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

void Insert(HashTable& ht, int key, int data) 
{
    int index = hashFunction(key);
    ht.table[index].key = key;
    ht.table[index].data = data;
}

int Search(HashTable& ht, int key) 
{
    int index = hashFunction(key);

    if (ht.table[index].key == key) 
    {
        return ht.table[index].data;
    }
    else 
    {
        return -1; 
    }
}

int main() 
{
    bool active = true;
    int choice;
    HashTable hashTable;
    int result = -1;  

    do 
    {
        cout << "MENU\n\n1.) INSERT ELEMENT\n2.) SEARCH FOR AN ELEMENT\n3.) EXIT\n\nChoice: ";
        cin >> choice;

        switch (choice) 
        {

        case 1:

            int key, data;

            cout << "\nEnter key: ";
            cin >> key;

            cout << "Enter data: ";
            cin >> data;

            Insert(hashTable, key, data);
            cout << "Key " << key << " has been inserted with data " << data << endl;

            break;

        case 2:

            cout << "\nEnter key to search: ";
            cin >> key;

            result = Search(hashTable, key);

            if (result != -1)
            {
                cout << "Key " << key << " found, data: " << result << endl;
            }
            else 
            {
                cout << "Key " << key << " not found.\n" << endl;
            }
            break;

        case 3:

            cout << "\nFarewell!\n";
            active = false;
            break;

        default:

            cout << "\nInvalid input.\n";
            active = true;
            break;
        }
    } while (active);

    return 0;
}

