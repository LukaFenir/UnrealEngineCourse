#include "FBullCowGame.h"
FBullCowGame::FBullCowGame() {
	Reset();
}

int FBullCowGame::GetMaxTries() const {
	return MaxTries;
}
int FBullCowGame::GetCurrentTry() const {
	return CurrentTry;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}



void FBullCowGame::Reset() {
	CurrentTry = 0;
	constexpr int MAX_TRIES = 8;
	MaxTries = MAX_TRIES;
	return;
}

bool FBullCowGame::IsGuessValid(std::string s) {
	return false;
}

