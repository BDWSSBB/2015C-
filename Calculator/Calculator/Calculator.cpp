#include <iostream>
using namespace std;

int main()
{
	//Ask for what kind of operation
	int operationChoice;
	cout << "Enter 1 for addition, 2 for subtraction, 3 for multiplication, or 4 for division" << endl;
	cin >> operationChoice;

	//Ask for variables
	double x, y;
	cout << "Enter the first number: " << endl;
	cin >> x;
	cout << "Enter the second number: " << endl;
	cin >> y;

	//Calculate result based on what operation was selected and variables
	double result;
	if (operationChoice == 1)
		result = x + y;
	if (operationChoice == 2)
		result = x - y;
	if (operationChoice == 3)
		result = x * y;
	if (operationChoice == 4)
		result = x / y;

	return 0;
}