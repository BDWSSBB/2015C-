#include <iostream>
#include <string>
using namespace std;
int main(){
	string story = "Once upon a time, there was a person named charname. charname would always keep appearing in my text, like this: charname, charname, charname!";

	string charName;
	cout << "What is your name?" << endl;
	getline(cin, charName);

	int index = story.find("charname");
	
	while (index != -1){
		story.replace(index, 8, charName);
		index = story.find("charname");
	}
	cout << story << endl;

	return 0;
}