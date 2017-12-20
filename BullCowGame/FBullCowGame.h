#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); //TODO return value
	int GetMaxTries();
	int GetCurrentTry();
	std::string GetWord();









// ^^ Ignore private things. Focus on above interface
private:
	int CurrentTry;
	int MaxTries;
	
};