#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	string name;
	string story = "Once upon a time there was a insert named charname, and everyday, charname would go to the insert insert to insert. Until one day, a pack of wild insert came and insert all of the insert. This made charname feel insert, so they went to the insert to insert. charname was sucessful, and was named the insert of insert.";
	cout << "Enter the name of your main character:" << endl;
	getline(cin, name);
	story.find("charname");

	while (story.find("charname") != -1){
		story.replace(story.find("charname"), 8, name);
		story.find("charname");
	}
	cout << "Now enter a noun, adjective, noun, verb, plural noun, past tense verb, plural occupation, adjective, location, verb, noun, town name" << endl;;

	while (story.find("insert") != -1){
		getline(cin, word);
		cout << "You entered \"" << word << "\"." << endl;
		story.replace(story.find("insert"), 6, word);
		story.find("insert");
	}

	cout << story << endl;
	return 0;

}
