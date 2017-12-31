#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetWordLength() const { return HiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return FBullCowGame::bGameIsWon; }


EGuessStatus FBullCowGame::IsGuessValid(FString Guess) const { 
	if (false) {
		return EGuessStatus::Invalid_Status;
	}
	else if (false) {//TODO If guess isn't isogram, error
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {//TODO If guess isn't lowercase, error
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != HiddenWord.length()) {//TODO If guess length is wrong, error
		return EGuessStatus::Wrong_Length;
	}
	else { //Otherwise, all fine
		return EGuessStatus::OK;
	}
	
	
	 //TODO Make actual error
}




void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "plan";

	CurrentTry = 0;
	HiddenWord = HIDDEN_WORD;
	MaxTries = MAX_TRIES;
	bGameIsWon = false;

	return;
}


//revieved VALID guess, increment turn, return bull/cow count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

	CurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = HiddenWord.length(); //assuming same length as guess
											
	//loop through all letters in hidden word
	for (int32 i = 0; i < WordLength; i++) {
		//compare letters against guess word
		for (int32 j = 0; j < WordLength; j++) {
			//If letter in Guess is in HiddenWord
			if (HiddenWord[i] == Guess[j]) {
				//If in right place
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	return BullCowCount;
}

