#include <iostream>
#include <string>
using namespace std;
int main(){
	while (true){
		int userInput;
		int stepCount = 0;
		string stepOrSteps;
		cout << "Enter an integer greater than 1." << endl;
		cin >> userInput;

		if (userInput <= 1){
			cout << "Invalid number." << endl;
			continue;
		}
		else{
			while (userInput > 1){
				if (userInput % 2 == 1){
					userInput = 3 * userInput + 1;
				}
				else{
					userInput = userInput / 2;
				}
				cout << "Current number: " << userInput << endl;
				stepCount++;
			}
		}
		if (stepCount == 1){
			stepOrSteps = "step";
		}
		else{
			stepOrSteps = "steps";
		}
		cout << "It took " << stepCount << " " << stepOrSteps << " to complete this process." << endl;
		stepCount = 0;
	}
}