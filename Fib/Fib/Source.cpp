#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
	while (true) {
		int a; // Returned value
		int b = 1; // n
		int c = 0; // n-1
		int d; // Holds b so c knows
		int userInput;
		cout << "Type in an integer to run through the fibonacci sequence." << endl;
		cin >> userInput;
		if (userInput == 0){
			cout << "The number is 0." << endl;
		}
		else if (userInput == 1){
			cout << "The number is 1." << endl;
		}
		else{
			for (int i = 1; i < userInput; i++){
				d = b;
				b = b + c;
				c = d;
				a = b;
			}
			cout << "The number is "<< a << "." << endl;
		}
	}
	return 0;
}