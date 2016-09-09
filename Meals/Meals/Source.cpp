#include <iostream>
#include <string>
using namespace std;
int main(){
	string meals[3][7];
	int breakfastAmount;
	int lunchAmount;
	int dinnerAmount;
	int i;
		cout << "Enter up to 7 things you had for breakfast. Enter nothing to move on to lunch." << endl;
		for (i = 0; i < 7; i++){
			getline(cin, meals[0][i]);
			if (meals[0][i] == ""){
				break;
			}
		}
		breakfastAmount = i;
		cout << "Enter up to 7 things you had for lunch. Enter nothing to move on to dinner." << endl;
		for (i = 0; i < 7; i++){
			getline(cin, meals[1][i]);
			if (meals[1][i] == ""){
				break;
			}
		}
		lunchAmount = i;
		cout << "Enter up to 7 things you had for dinner. Enter nothing to see your results." << endl;
		for (i = 0; i < 7; i++){
			getline(cin, meals[2][i]);
			if (meals[2][i] == ""){
				break;
			}
		}
		dinnerAmount = i;
		cout << "You had";
		if (breakfastAmount == 0){
			cout << " nothing for breakfast." << endl;
		}
		for (i = 0; i < breakfastAmount; i++){
			if (breakfastAmount == 1){
				cout << " " << meals[0][i] << " for breakfast." << endl;
			}
			else if (i == breakfastAmount - 1){
				cout << " and " << meals[0][i] << " for breakfast." << endl;
			}
			else{
				cout << " " << meals[0][i];
				if (breakfastAmount != 2){
					cout << ",";
				}
			}
		}
		cout << "You had";
		if (lunchAmount == 0){
			cout << " nothing for lunch." << endl;
		}
		for (i = 0; i < lunchAmount; i++){
			if (lunchAmount == 1){
				cout << " " << meals[1][i] << " for lunch." << endl;
			}
			else if (i == lunchAmount - 1){
				cout << " and " << meals[1][i] << " for lunch." << endl;
			}
			else{
				cout << " " << meals[1][i];
				if (lunchAmount != 2){
					cout << ",";
				}
			}
		}
		cout << "You had";
		if (dinnerAmount == 0){
			cout << " nothing for dinner." << endl;
		}
		for (i = 0; i < dinnerAmount; i++){
			if (dinnerAmount == 1){
				cout << " " << meals[2][i] << " for dinner." << endl;
			}
			else if (i == dinnerAmount - 1){
				cout << " and " << meals[2][i] << " for dinner." << endl;
			}
			else{
				cout << " " << meals[2][i];
				if (dinnerAmount != 2){
					cout << ",";
				}
			}
		}
	return 0;
}