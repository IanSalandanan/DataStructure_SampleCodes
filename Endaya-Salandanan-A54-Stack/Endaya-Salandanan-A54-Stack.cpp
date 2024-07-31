/*
 Name: Carlie Shaye C. Endaya & Christian Kerby T. Salandanan
 Course/Section: CS102-1L/A54
 Program File: Endaya-Salandanan-A54-Stack.cpp
 Date: 20/10/23 10:08
 Description: "Hard-Coded Stack simulation using struct."
*/

#include <iostream>
using namespace std;

struct Stack 
{
	int top; //Integer var to hold the top of the stack
	unsigned capacity; //maximum capacity of the stack
	char* array; //ptrVar to hold the values of each char
};

Stack* CreateStack(unsigned capacity) 
{
	Stack* stackPtr = new Stack(); //Create a stack struct by malloc

	if (!stackPtr) return nullptr; //If failed, return nullptr

	stackPtr->top = -1; //setting the top value to -1 to indicate that the stack is empty
	stackPtr->capacity = capacity; //assigning maximum capacity
	stackPtr->array = new char[stackPtr->capacity]; //creating new char array with the capacity as limit

	return stackPtr; 
}

int IsEmpty(Stack* stackPtr) 
{return stackPtr->top == - 1;} //A condition checking if the top is empty by checking the value of int top

char CheckTop(Stack* stackPtr)
{return stackPtr->array[stackPtr->top];} //checks the elements of the array using top as index, returns the char value element.

char Pop(Stack* stackPtr) 
{if (!IsEmpty(stackPtr)) return stackPtr->array[stackPtr->top--]; return '$';} //checks if the stack is not empty, if not, it will return the char val from array using top as index
                                                                                    //decrement top to check the next values each pop. returns '$' if the array is empty.
void Push(Stack* stackPtr, char op)
{stackPtr->array[++stackPtr->top] = op;} //Push the passed element to the array, using top as index and increment to fill the stack because the value of top is -1.

int IsOperand(char ch)
{return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');} //condition to check if the scanned item is in the range of operands, returns int

int Precedence(char chOperator) //checks for precedence, returns an integer value to compare the operator on the top of stack and the scanned infixEx
{
	switch (chOperator)
	{
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3;
	} return -1; //returns -1 if the scanned character is not an operator
}

int InfixToPostFix(char* infixExpression) 
{
	int i, j;

	Stack* stackPtr = CreateStack(int(strlen(infixExpression))); //method invoke to create stack struct
	if (!stackPtr) return -1; //if failed malloc, the ptrvar is null and if null it returns -1 

	for (i = 0, j = -1; i < infixExpression[i]; i++)
	{
		if (IsOperand(infixExpression[i])) 
		{infixExpression[++j] = infixExpression[i];} //if operand then overwrite the infixarray, in a logical explanation, this line pushes the operand to the postfix string.
		                                             //the ++j starts from -1 index which is the last index of array, this code is about replacing the current infix.
		else if (infixExpression[i] == '(')          
		{Push(stackPtr, infixExpression[i]);}        //if ( then invoke the push method and pass the character as an argument.

		else if (infixExpression[i] == ')')          //This condition needs pop action
		{
			while (!IsEmpty(stackPtr) && CheckTop(stackPtr) != '(') //while stack is not empty and top is not (,
			{infixExpression[++j] = Pop(stackPtr);}                 //Continuosly pop the char from array and overwrite it to the infix soon to be postfix array

			if (!IsEmpty(stackPtr) && CheckTop(stackPtr) != '(')    //This line is to check if the first process of popping is successful, this is to avoid popping all the elements of the array.
			{return -1;}

			else Pop(stackPtr); 
		}

		else
		{
			while (!IsEmpty(stackPtr) && Precedence(infixExpression[i]) <= Precedence(CheckTop(stackPtr))) //Compares the prec of scaned item to the item in top of stack
			{infixExpression[++j] = Pop(stackPtr);} //if the first operator is lower than the top operator then pop until the condition is satisfied.
			Push(stackPtr,infixExpression[i]); //else if scanned is higher or an operand, the while will be ignore because of false value and this line will be executed.
			                                   //continue to push the item to the stack
		}
	}

	while (!IsEmpty(stackPtr))
	{infixExpression[++j] = Pop(stackPtr);} //this while block is to pop all remaining items in array and trnasfer to infix array

	infixExpression[++j] = '\0'; //this element is the indication of end string, this is added to indicate that the expression is done

	cout << '\n' << "Converted PostFix Expression: " << infixExpression << endl; //printing of array

	return 0;

}

int main()
{
	char infixExpression[30]; //array char to store the input
	string exitOption; bool active = true, isValid = false;

	while (active)
	{
		cout << "Enter Infix Expression: ";
		cin.getline(infixExpression, 30); //setting a limit for cin

		InfixToPostFix(infixExpression);

		do 
		{
			cout << "\nWould you like to exit the program? [ YES | NO ]: ";
			cin >> exitOption;

			if (exitOption == "YES") {active = false; isValid = true;} 
			else if (exitOption == "NO") {active = true; isValid = true;}
			else {cout << "\nInvalid Choice.\n"; isValid = false;}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //prevents to loop immaturely, clears the input stream.

		} while (!isValid);
		cout << endl;
	}

	return 0;
}

