#include <iostream>
#include <string>
#include "FBullCowGame.h"

//YOLO SWAG

FBullCowGame BCGame; //instantiate a new game

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
	//ask user for guess
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

//Repeat guess back to them
void PrintGuess(std::string GuessIn) {
	std::cout << "You guessed: " << GuessIn << "\n";
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << "\n";
	return;
}

bool WillPlayAgain() {
	std::cout << "Play again? y/n \n";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	//TODO Make valid guess checker
	for (int i = 0; i < MaxTries; i++) {

		//Submit value guess to the game
		//Return bulls/cows
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
	//TODO Summarise game at the end
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