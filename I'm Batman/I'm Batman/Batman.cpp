
#include <iostream>
using namespace std;

int main()
{
	int pointsUser = 0;
	int pointsBatman = 0;
	int userInput;

	//Ask user about strength.
	cout << "Who would win in a fight, you or the Batman?" << endl;
	cout << "On a scale of 1 to 10, how strong are you?" << endl;
	cin >> userInput;

	//See who wins, and if it's a tie, Batman always wins.  He is the Batman.
	if (userInput > 7)
	{
		pointsUser++;
	}
	else
	{
		pointsBatman++;
	}

	//Ask the user about tactics.
	cout << "On a scale of 1 to 10, how tactical of a planner are you?" << endl;
	cin >> userInput;

	//See who wins, this time, using a less than or equal to conditional.
	if (userInput <= 8)
	{
		pointsBatman++;
	}
	else
	{
		pointsUser++;
	}

	//Ask the user about the giant bat.
	cout << "Would you be scared of a giant bat flying at you? (y/n)" << endl;
	char userInputChar;
	cin >> userInputChar;

	//Check if scared or not.
	if (userInputChar != 'n')
	{
		pointsBatman++;
	}
	else
	{
		pointsUser++;
	}

	//Determine the overall winner.
	if (pointsUser > pointsBatman)
	{
		cout << "You would win against Batman!" << endl;
		cout << "Are you sure you are not the Batman?" << endl;
	}
	else
	{
		cout << " Batman would win!  There is no shame in that." << endl;
	}
	return 0;
}