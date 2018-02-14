#include "Guess.h"



Guess::Guess()
{
	displayRules();
	gatherUserInput();
}

Guess::Guess(int _rounds, int _maxNumber):
	rounds(_rounds),
	maxNumber(_maxNumber)
{
	srand(time(0));
	int randNumber;

	//based on user input, adds a random # for each round the user wants to play, w/ the rand. number capped at the user's max # range
	for (int i = 0; i < rounds; i++)
	{
		randNumber = ((rand() % maxNumber) + 1);  
		numberList.push_back(randNumber);
	}

	play();
	
}

void Guess::displayRules()
{
	//Intro for the player
	cout << "Welcome to the number guessing game!\n\n"
		<< "RULES: You'll provide a max number range. I'll generate a random number within\nyour given range."
		<< " You have " << maxAttempts << " guesses to get the right number. If you don't \nguess it within the limit, you lose!\n";
}

void Guess::gatherUserInput()
{
	//user input
	cout << "\nHow many rounds would you like to play?\n"
		<< "Rounds:";
	cin >> rounds;
	cout << "\nHow large do you want the range to be? \n"
		<< "(enter the max number e.g. for 1-10 enter 10)\n"
		<< "Max Number:";
	cin >> maxNumber;
	cout << endl << endl;

	//utilize user input to set up the game
	srand(time(0));
	int randNumber;

	//based on user input, adds a random # for each round the user wants to play, w/ the rand. number capped at the user's max # range
	for (int i = 0; i < rounds; i++)
	{
		randNumber = ((rand() % maxNumber) + 1);
		numberList.push_back(randNumber);
	}
}

void Guess::play()
{
	int userGuess = 0, attempts = 0;
	//guess correct is condition that will end the round if met
	bool guessCorrect = false;

	system("cls");
	cout << "Okay I've got my number(s). Make your guesses!\n";

	//Runs until the round limit has been met
	for (int i = 0; i < rounds; i++)
	{
		//at beginning of each round, attempts and the bool correct answer are reset 
		attempts = 0;
		guessCorrect = false;

		do //this loop binds the round to the allowed # of guesses
		{
			cout << "\nRound " << (i + 1)  
				<< "\n\nEnter your guess for this round\n"
				<< "Guess:";
			cin >> userGuess;
			cout << endl;

			//checking the user's guess

			//Guess correct
			if (userGuess ==  numberList[i])
			{
				cout << "Congrats! " << userGuess << " was the correct answer! :)\n";
				guessCorrect = true;
			}

			//Guess incorrect
			else if (!(userGuess == numberList[i]))
			{
				cout << "Oh no, " << userGuess << " wasn't the correct answer.\n" 
					<< "\nYou have " << (maxAttempts - (attempts + 1)) << " guesses remaining.\n";
				attempts++;
			}

			system("pause");
			system("cls");
		} while ((attempts < maxAttempts) && (!guessCorrect));// ends the round when either the answer was guessed or the max attempts is reached.

	}//rounds played
}
