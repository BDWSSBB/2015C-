#include <iostream>
using namespace std;
int main(){
	int userInput;
	int modulusChecker;
	int primeOrNot;
	while (true){
		cout << "Enter an integer greater than 2 to check if it is a prime number." << endl;
		cin >> userInput;
		if (userInput <= 2){
			cout << "Invalid number." << endl;
			continue;
		}
		else{
			for (modulusChecker = 2; modulusChecker < userInput; modulusChecker++){
				if (userInput % modulusChecker == 0){
					primeOrNot = 1;
					break;
				}
				else{
					primeOrNot = 0;
				}
			}
		}
		if (primeOrNot == 1){
			cout << userInput << " is not a prime number." << endl;
		}
		else{
			cout << userInput << " is a prime number." << endl;
		}
	}
}