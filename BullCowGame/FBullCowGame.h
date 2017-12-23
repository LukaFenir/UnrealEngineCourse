#pragma once
#include <string>

//DO NOT use "using" in a header file

class FBullCowGame {
public:
	void Reset(); //TODO return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool IsGuessValid(std::string s);



// ^^ Ignore private things. Focus on above interface
private:
	int CurrentTry;
	int MaxTries = 5;
	
};