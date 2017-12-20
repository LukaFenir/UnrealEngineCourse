#include <iostream>
#include <string>

using namespace std;

//YOLO SWAG

//Introduce the game
void PrintIntro() {
	constexpr int WORD_LENGTH = 4;
	cout << "Welcome to Bulls and Cows, a boring word game.\n"
		<< "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

//Get guess from user in cmd line
string GetGuess() {
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	return Guess;
}

//Repeat guess back to them
void PrintGuess(string GuessIn) {
	cout << "You guessed: " << GuessIn << "\n";
	return;
}

bool WillPlayAgain() {
	cout << "Play again? y/n \n";
	string Response = "";
	getline(cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

void PlayGame() {
	constexpr int TURNS = 5;
	for (int i = 0; i < TURNS; i++) {
		string Guess = GetGuess();
		PrintGuess(Guess);
	}
}

//Entry point for application
int main() {
	bool bPlayAgain = false;
	//introduce the game
	PrintIntro();
	do {
		PlayGame();
		bPlayAgain = WillPlayAgain();
	} while (bPlayAgain);
	
	return 0;
}