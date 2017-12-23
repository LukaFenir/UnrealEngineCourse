#include "FBullCowGame.h"

void FBullCowGame::Reset() {
	return;
}

int FBullCowGame::GetMaxTries() {
	return MaxTries;
}

int FBullCowGame::GetCurrentTry() {
	return 0;
}

bool FBullCowGame::IsGameWon() {
	return false;
}

bool FBullCowGame::IsGuessValid(std::string s) {
	return false;
}
