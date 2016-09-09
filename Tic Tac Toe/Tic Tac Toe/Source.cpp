#include <iostream>
#include <string>
using namespace std;
int main(){
	while (true){
		int userSquareSelection;
		char squareSymbol[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Records what each square has.
		int xOrO = 0; // Even = O (Player 1)'s turn, Odd = X (Player 2)'s turn.
		int playerNumber;
		bool someoneWon = false;
		while (true){
			cout << squareSymbol[0] << "|" << squareSymbol[1] << "|" << squareSymbol[2] << endl;
			cout << "-+-+-" << endl;
			cout << squareSymbol[3] << "|" << squareSymbol[4] << "|" << squareSymbol[5] << endl;
			cout << "-+-+-" << endl;
			cout << squareSymbol[6] << "|" << squareSymbol[7] << "|" << squareSymbol[8] << endl;
			if (squareSymbol[0] == squareSymbol[1] && squareSymbol[1] == squareSymbol[2]){ // Top row
				someoneWon = true;
			}
			else if (squareSymbol[3] == squareSymbol[4] && squareSymbol[4] == squareSymbol[5]){ // Middle row
				someoneWon = true;
			}
			else if (squareSymbol[6] == squareSymbol[7] && squareSymbol[7] == squareSymbol[8]){ // Bottom row
				someoneWon = true;
			}
			else if (squareSymbol[0] == squareSymbol[3] && squareSymbol[3] == squareSymbol[6]){ // Left column
				someoneWon = true;
			}
			else if (squareSymbol[1] == squareSymbol[4] && squareSymbol[4] == squareSymbol[7]){ // Middle column
				someoneWon = true;
			}
			else if (squareSymbol[2] == squareSymbol[5] && squareSymbol[5] == squareSymbol[8]){ // Right column
				someoneWon = true;
			}
			else if (squareSymbol[0] == squareSymbol[4] && squareSymbol[4] == squareSymbol[8]){ // \ Diagonal
				someoneWon = true;
			}
			else if (squareSymbol[2] == squareSymbol[4] && squareSymbol[4] == squareSymbol[6]){ // / Diagonal
				someoneWon = true;
			}
			if (someoneWon == true){
				if (xOrO % 2 == 1){
					cout << "Player 1 won!" << endl;
				}
				else{
					cout << "Player 2 won!" << endl;
				}
				break;
			}
			if (xOrO == 9){ // 9 = 9 turns have passed.
				cout << "It's a tie!" << endl;
				break;
			}
			if (xOrO % 2 == 0){
				playerNumber = 1;
			}
			else{
				playerNumber = 2;
			}
			cout << "It is player " << playerNumber << "'s turn. Select a numbered square." << endl;
			while (true){
				cin >> userSquareSelection;
				if (userSquareSelection < 1){
					cout << "Invalid selection." << endl;
					continue;
				}
				else if (userSquareSelection > 9){
					cout << "Invalid selection." << endl;
					continue;
				}
				else if (squareSymbol[userSquareSelection - 1] == 'X'){
					cout << "Invalid selection." << endl;
					continue;
				}
				else if (squareSymbol[userSquareSelection - 1] == 'O') {
					cout << "Invalid selection." << endl;
					continue;
				}
				if (playerNumber == 1){
					squareSymbol[userSquareSelection - 1] = 'O';
				}
				else{
					squareSymbol[userSquareSelection - 1] = 'X';
				}
				xOrO++;
				break;
			}
		}
	}
}