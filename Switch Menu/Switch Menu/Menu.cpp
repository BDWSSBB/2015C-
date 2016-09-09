#include <iostream>
using namespace std;

int main()
{
	int userSelect;

	//Ask the user what he/she would like to eat.
	cout << "Enter what you would like to eat:" << endl;
	cout << "1. Waffles" << endl;
	cout << "2. Pancakes" << endl;
	cout << "3. Eggs" << endl;
	cin >> userSelect;

	//Switch checking the answer
	switch (userSelect)
	{
		case 1:
			cout << "Waffle Rofls." << endl;
			break;
		case 2:
			cout << "Lemme plancke you up!" << endl;
			break;
		case 3:
			cout << "They're meant for throwing." << endl;
			break;
		default:
			cout << "Invalid input" << endl;
	}

	return 0;
}