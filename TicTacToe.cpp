/*
Tic Tac Toe Game
Author: Reese Fairchild
Last Updated: 4/4/24 1:49 PM
*/
#include <iostream>
using namespace std;

class Tic_Tac_Toe_Game {
	char game_board[3][3]; //3x3 game board
	char player; //tracks current player (used for win validation)
	int turn; //tracks current turn (used for tie validation)

	//private input verifcation functions
	//verifies input is 1,2,or 3, input is passed and updated by reference
	void input_verify(int& num) {
		while (num <= 0 || num > 3) {
			cout << "Number must be 1, 2, or 3. ";
			cin >> num;
		}
	}
	//verifies input is an empty space
	bool verify_empty(int row, int col) {
		if (game_board[row - 1][col - 1] != '*') {
			cout << "Selected location is not empty. Please enter a new location.\n";
			return false;
		}
		else
			return true;
	}

public:

	//constructor - sets default values
	Tic_Tac_Toe_Game() {
		for (int row = 0; row <= 2; row++) {
			for (int col = 0; col <= 2; col++)
				game_board[row][col] = '*';
		}
		player = 'X';
		turn = 0;
	}

	//outputs whole game board
	void display_board() {
		for (int row = 0; row <= 2; row++) {
			for (int col = 0; col <= 2; col++) {
				cout << game_board[row][col];
			}
			cout << endl;
		}
	}
	
	//Controls whole turn for player X
	void X_play() {
		int row, col;

		player = 'X'; //updates current player 
		turn++; //increases turn number 

		cout << "PLAYER 1 (X) TURN\n";
		do {
			cout << "What row would you like to play in? ";
			cin >> row;
			input_verify(row); //call private verification function
			cout << "What column would you like to play in? ";
			cin >> col;
			input_verify(col);
		} while (verify_empty(row,col) == false); //verify spot is empty or loops for re-input

		game_board[row - 1][col - 1] = 'X'; //sets array value to correct char
	}

	//control player O turn - near identical to X_play()
	void O_play() {
		int row, col;

		player = 'O';
		turn++;

		cout << "PLAYER 2 (O) TURN\n";
		do {
			cout << "What row would you like to play in? ";
			cin >> row;
			input_verify(row);
			cout << "What column would you like to play in? ";
			cin >> col;
			input_verify(col);
		} while (verify_empty(row, col) == false);
		game_board[row - 1][col - 1] = 'O';
	}

	/*check for win or tie, returns int values that represent Xwin,Owin, tie, or no result
	 RETURN VALUES:
		no win or tie yet =0
		player X win = 1
		player O win = 2
		tie = 3 */
	int check_win() {
		//check rows
		if ((game_board[0][0] == player && game_board[0][1] == player && game_board[0][2] == player) ||
			(game_board[1][0] == player && game_board[1][1] == player && game_board[1][2] == player) ||
			(game_board[2][0] == player && game_board[2][1] == player && game_board[2][2] == player)) {
			if (player == 'X')
				return 1;
			else
				return 2;
		}
		//check columns
		else if ((game_board[0][0] == player && game_board[1][0] == player && game_board[2][0] == player) ||
			(game_board[0][1] == player && game_board[1][1] == player && game_board[2][1] == player) ||
			(game_board[0][2] == player && game_board[1][2] == player && game_board[2][2] == player)) {
			if (player == 'X')
				return 1;
			else
				return 2;
		}
		//check diags
		else if ((game_board[0][0] == player && game_board[1][1] == player && game_board[2][2] == player) ||
			(game_board[0][2] == player && game_board[1][1] == player && game_board[2][0] == player)) {
			if (player == 'X')
				return 1;
			else
				return 2;
		}
		//check tie
		else if (turn >= 9)
			return 3;
		else
			return 0;
	}

	//clears board and sets turn number to 0 to prepare for new game
	void clear_board() {
		for (int row = 0; row <= 2; row++) {
			for (int col = 0; col <= 2; col++)
				game_board[row][col] = '*';
		}
		turn = 0;
	}
};

//main function demonstrating class
	int main(){
		Tic_Tac_Toe_Game mygame; //declare object
		int result = 0; //recieve win/tie/no result integer
		char play_again = 'Y'; //used for repeating games

		cout << "Welcome to Tic-Tac-Toe!\n";
		cout << "Here is your game board: \n";

		while (play_again == 'Y') { //while statement restarts game if player chooses
			do {
				//X turn - display board, play, check win, clear screen, leave loop if win
				mygame.display_board();
				mygame.X_play();
				result = mygame.check_win();
				system("cls");
				if (result != 0)
					continue;

				//O turn
				mygame.display_board();
				mygame.O_play();
				result = mygame.check_win();
				system("cls");

			} while (result == 0); //loops if no win or tie reached
			cout << endl;

			//gives game result to player
			switch (result) {
			case 1: cout << "Player 1 (X) wins!"; break;
			case 2: cout << "Player 2 (O) wins!"; break;
			case 3: cout << "Tie game!"; break;
			}

			//ask if players want to play again
			cout << endl;
			cout << "Would you like to play again? ";
			cout << "Type \" Y \" to play again or any other character to exit: ";
			cin >> play_again;

			mygame.clear_board();
			system("cls");
		}
		return 0;
	}