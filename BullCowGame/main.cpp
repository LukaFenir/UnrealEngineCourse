/*
	This is the console executable that makes use of FBullCowGame class.
	This acts as the view in an MVC pattern. Is responsible for all user interaction.
	For game logic, see FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//YOLO SWAG

FBullCowGame BCGame;

/*
	Introduce the game
*/
void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a boring word game.\n"
		<< "             .=     ,        =.\n"
		<< "     _  _   /'/    )\\,/,/(_   \\ \\ \n"
		<< "      `//-.|  (  ,\\\\)\\//\\)\\/_  ) |\n"
		<< "      //___\\   `\\\\\\/\\\\/\\/\\\\///'  /\n"
		<< "   ,-\"~`-._ `\"- - '_   `\"\"\"`  _ \`'\"~-,_\n"
		<< "   \\       `-.  '_`.      .'_` \\ ,-\"~`/\n"
		<< "    `.__.-'`/   (-\\        /-) |-.__,'\n"
		<< "      ||   |     \\O)  /^\\ (O/  |\n"
		<< "      `\\\\  |         /   `\\    /\n"
		<< "        \\\\  \\       /      `\\ /\n"
		<< "         `\\\\ `-.  /' .---.--.\\ \n"
		<< "           `\\\\/`~(, '()      ('\n"
		<< "            /(O) \\\\   _,.-.,_)\n"
		<< "           //  \\\\ `\\'`      /\n"
		<< "          / |  ||   `\"\"\"\"~\"`\n"
		<< "        /'  |__||\n"
		<< "              `o \n"
		<< "Can you guess my " << BCGame.GetWordLength() << " letter isogram in " << BCGame.GetMaxTries()
		<< " attempts?\n";
	return;
}

/*
	Ask for and get user input
	Check for validity and display potential error
	Loop until user enters valid guess
*/
FText GetValidGuess() {
	//Ask user for guess
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". "
		<< "Enter your guess: ";
	do {
		//Get user guess
		std::getline(std::cin, Guess);

		//Check guess validity
		Status = BCGame.IsGuessValid(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (a word without repeating letters).\n";
			break;	
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your guess in lowercase.\n";
			break;
		default:
			//assume guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);

	return Guess;
}

/*
	Echo guess back to them
*/
void PrintCurrentTry(FText GuessIn) {
	std::cout << "You guessed: " << GuessIn << "\n";

	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << "\n";
	return;
}

/*
	Ask user if they'll play again
*/
bool WillPlayAgain() {
	std::cout << "Try to guess this word again? y/n \n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

/*
	Print whether they won or lost the game
*/
void PrintGameEnd() {
	if (BCGame.IsGameWon()) {
		std::cout << "CONGRATS! You did- *burp* -it!\n";
	}
	else {
		std::cout << "Woops! You ran out of tries. Better luck next time, dummy!\n";
	}
	return;
}

/*
	Setup and run the game
*/
void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	while ((!BCGame.IsGameWon()) && (BCGame.GetCurrentTry() <= MaxTries)){

			//Submit value guess to the game & return bulls/cows count
			FText Guess = GetValidGuess();
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << " Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}
	PrintGameEnd();
}




/*
	Entry point for application
*/
int main() {

	bool bPlayAgain = false;

	PrintIntro();

	do {
		PlayGame();
		bPlayAgain = WillPlayAgain();
	} while (bPlayAgain);
	
	return 0;
}