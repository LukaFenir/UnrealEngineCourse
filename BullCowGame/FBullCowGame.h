#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//DO NOT use "using namespace" in a header file

//all values initialised to 0
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {

public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const; //Was an EXTRA
	bool IsGameWon() const;
	EGuessStatus IsGuessValid(FString) const;

	void Reset(); //TODO return value

	FBullCowCount SubmitValidGuess(FString);

	

// ^^ Ignore private things. Focus on above interface
private:
	//initialised in constructor
	int32 CurrentTry;
	int32 MaxTries;
	FString HiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const; 
	bool IsLowerCase(FString) const;
};