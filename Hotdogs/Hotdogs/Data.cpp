#include <iostream>
#include <string>
using namespace std;
int main(){
	int hamburgers[7];
	double hamburgerAverage = 0;

	for (int i = 0; i < 7; i++){
		cout << "Enter the amount of hamburgers you eat per day." << endl;
		cin >> hamburgers[i];
	}
	for (int i = 0; i < 7; i++){
		hamburgerAverage += hamburgers[i];
	}
	hamburgerAverage /= 7;
	cout << "You eat an average of " << hamburgerAverage << " hamburgers per day." << endl;
	return 0;
}