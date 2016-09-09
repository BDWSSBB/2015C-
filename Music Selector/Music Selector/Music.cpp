#include <iostream>
using namespace std;
int main(){
	int menuSelect = 0;
		
	menuSelect = menuSelect + 1;

	//Prompt user to select a genre and introduces genres.
	cout << "Enter 1-3 to pick a genre of music." << endl;
	cout << "1. Something Generic" << endl;
	cout << "2. Another Generic Genre" << endl;
	cout << "3. Lame Poop" << endl;
	
	//User Input
	cin >> menuSelect;

	//Check the input
	cout << "Menu Select: " << menuSelect << endl;
	if (menuSelect == 1)
	{
		cout << "You selected \"Something Generic\"" << endl;
		cout << "Recommended Artists:" << endl;
		cout << "1. Mike Tyson" << endl;
		cout << "2. Mic Check" << endl;
		cout << "3. I can't make up any more" << endl;
	}
	else if (menuSelect == 2)
	{
		cout << "You selected \"Another Generic Genre\"" << endl;
		cout << "Recommended Artists:" << endl;
		cout << "1. A computer" << endl;
		cout << "2. A Wii U" << endl;
		cout << "3. ID Tech" << endl;
	}
	else if (menuSelect == 3)
	{
		cout << "You selected \"Lame Poop\"" << endl;
		cout << "Recommended Artists:" << endl;
		cout << "1. Potty Scotty" << endl;
		cout << "2. The Digestive System" << endl;
		cout << "3. What am I typing?" << endl;
	}
	else
	{
		cout << "I do not know such genre." << endl;
	}

	return 0;
}