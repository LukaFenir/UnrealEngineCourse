#include <iostream>
#include <string>
#include "FBullCowGame.h"

//YOLO SWAG

//Introduce the game
void PrintIntro() {
	constexpr int WORD_LENGTH = 4;
	std::cout << "Welcome to Bulls and Cows, a boring word game.\n"
		<< "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

//Get guess from user in cmd line
std::string GetGuess() {
	std::string Guess = "";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

//Repeat guess back to them
void PrintGuess(std::string GuessIn) {
	std::cout << "You guessed: " << GuessIn << "\n";
	return;
}

bool WillPlayAgain() {
	std::cout << "Play again? y/n \n";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PlayGame() {
	FBullCowGame BCGame; //instantiate a new game
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	for (int i = 0; i < MaxTries; i++) {
		std::string Guess = GetGuess();
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