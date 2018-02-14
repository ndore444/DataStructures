#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Guess
{
public:
	//constructors

	//default constructor
	//since you're giving it no info in this case, it'll auto display the game's rules and gather the required user info 
	Guess();
	
	//this constructor could be useful for testing, as it skips the rule display and user input 
	Guess(int _rounds, int _maxNumber);

	//Member Functions

	//displays the rules of the guessing game
	void displayRules();

	//collects nessesary input from user to begin game including number of rounds and max number for the randomizer
	void gatherUserInput();

	//Has the user play the guessing game for as many rounds as requested
	void play();

private:
	//here is where you can change the max # of allowed guesses
	static int maxAttempts = 3;
	int rounds, maxNumber;
	//list to store the rand numbers
	vector<int> numberList;
};

