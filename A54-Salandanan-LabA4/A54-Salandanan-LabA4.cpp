//Language: C++ 
//Binary Search Tree
//Student Name : Salandanan, Christian Kerby T.
//Course / Section: BSIT - A54
//Program File : A54 - Salandanan - LabA4
//Date / Time: 09/11/2023 / 10:58
//Algorithm : Pseudocode
//C++ Program

#include <iostream>

using namespace std;

struct node 
{
	int key;
	struct node* left, * right;
};

struct node* NewNode(int item) {
	struct node* temp = new struct node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* Insert(struct node* root, int key) 
{

	if (root == NULL)
		return NewNode(key);

	if (key < root->key)
		root->left = Insert(root->left, key);
	else if (key > root->key)
		root->right = Insert(root->right, key);

	return root;
}

struct node* Search(struct node* root, int key) 
{
	if (root == NULL || root->key == key)
		return root;

	if (key > root->key)
		return Search(root->right, key);

	return Search(root->left, key);
}

int main() 
{
	bool active = true;
	int choice;
	struct node* root = nullptr; 

	do {
		cout << "MENU\n\n1.) INSERT ELEMENT\n2.) SEARCH FOR AN ELEMENT\n3.) EXIT\n\nChoice: ";
		cin >> choice;

		switch (choice) 
		{

		case 1:

			int key;

			cout << "\nEnter value to be inserted: ";
			cin >> key;

			root = Insert(root, key); 
			cout << key << " has been inserted in a newly created node.\n" << endl;

			break;

		case 2:

			cout << "\nEnter value to be searched: ";
			cin >> key;

			if (Search(root, key) == nullptr)
				cout << key << " cannot be found, it seems that the value does not exists in the Binary Search Tree.\n" << endl;
			else
				cout << key << " exists in the Binary Search Tree.\n" << endl;

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
