#pragma once
#include <string>

//DO NOT use "using" in a header file

class FBullCowGame {

public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO return value
	bool IsGuessValid(std::string s); //TODO return value
	//provide method for counting bulls/cows and incrementing turn number


// ^^ Ignore private things. Focus on above interface
private:
	//initialised in constructor
	int CurrentTry;
	int MaxTries;
	
};