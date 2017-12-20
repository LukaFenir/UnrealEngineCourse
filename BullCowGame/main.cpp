#include <iostream>
#include <string>

using namespace std;

//YOLO SWAG

//Introduce the game
void PrintIntro(int WordLength) {
	
	cout << "Welcome to Bulls and Cows, a boring word game.\n"
		<< "Can you guess the " << WordLength << " letter isogram I'm thinking of?\n";
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

//Entry point for application
int main() {
	constexpr int NUM = 4;
	//introduce the game
	PrintIntro(NUM);
	for (int i = 0; i <= NUM; i++) {
		PrintGuess(GetGuess());
	}
	return 0;
}