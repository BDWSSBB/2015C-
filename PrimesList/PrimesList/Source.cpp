#include <iostream>
using namespace std;
int main(){
	while (true){
		int userInput;
		cout << "Enter a number greater than 2 to see all the primes between 2 and itself." << endl;
		cin >> userInput;
		if (userInput <= 2){
			cout << "Invalid number." << endl;
			continue;
		}
		else{
			cout << "2 is a prime number." << endl;
			for (int primeTest = 3; primeTest <= userInput; primeTest++){
				bool itIsPrime = true;
				for (int modulusDivisor = 2; modulusDivisor < primeTest; modulusDivisor++){
					if (primeTest % modulusDivisor == 0){
						itIsPrime = false;
						break;
					}
				}
				if (itIsPrime == true){
					cout << primeTest << " is a prime number." << endl;
				}
			}
		}
	}
	return 0;
}