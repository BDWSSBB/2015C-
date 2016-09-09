#include <iostream>
using namespace std;
int main(){
	int userSelection;

	while (true){
		cout << "Enter a number to choose a selection." << endl;
		cout << "1. Wreck It Ralph" << endl;
		cout << "2. Frozen" << endl;
		cout << "3. How To Train Your Dragon 2" << endl;
		cout << "4. Quit Program" << endl;

		cin >> userSelection;

		switch (userSelection){
		case 1:
			cout << "I'm gonna wreck it!" << endl;
			continue;
		case 2:
			cout << "Let it go, let it go!" << endl;
			continue;
		case 3:
			cout << "To be honest, I can't think of anything to put in this text." << endl;
			continue;
		case 4:
			return 0;
		default:
			cout << "I'm sorry, please type in a different number." << endl;
			continue;
		}
	}
}