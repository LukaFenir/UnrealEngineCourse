#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetWordLength() const { return HiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return false; }
EGuessStatus FBullCowGame::IsGuessValid(FString Guess) const { 
	if (false) {
		return EGuessStatus::Invalid_Status;
	}
	else if (false) {//If guess isn't isogram, error
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {//If guess isn't lowercase, error
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != HiddenWord.length()) {//If guess length is wrong, error
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

	return;
}


//revieved valid guess, increment turn, return bull/cow count
FBullCowCount FBullCowGame::submitGuess(FString Guess) {
	//increment turn number
	CurrentTry++;
	//set up return variable
	FBullCowCount BullCowCount;
	//loop through all letters in guess
	int32 HiddenWordLength = HiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		//compare letters against hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
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
			//if match
				//increment bulls if in same place
				//increment cows if in different place

		}
	}
	return BullCowCount;
}

