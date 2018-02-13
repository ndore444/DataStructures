/* 
 *Name: Nathaniel Dore
 *Class: CSCI 2421
 *Description: A file re-formater using my_string instead of STL string
 *Lab Partner: N/A
 *Status: development complete: final release build 
 */

#include <iostream>		//cout
#include <fstream>		//file input
#include <algorithm>	//replace
#include <vector>

using namespace std;

//function declarations

void formatInput(ifstream& _fin, ofstream& _fout, int _charPerLine);

int main( )
{

	ifstream fin;
	ofstream fout;
	int max = 0;

	//User input
	cout << "Greetings. How many characters would you like per line?\nMax Characters(1 - 100):";
	do
	{
		cin >> max;
		if (max < 1 || max > 100)
			cout << "\nNot within the range 1-100. Try again\n";
	} while (max < 1 || max > 100); //ensuring the user's number is within the acceptable range.

	formatInput(fin, fout, max);

    return 0;
}

//function definitions

void formatInput(ifstream& _fin, ofstream& _fout, int _charPerLine)
{
	vector<char> inputVector;
	char next, newChar, oldChar;
	int counter = 0, maxChar = _charPerLine;

	//opening the ifstream 
	//no overload for my_string with fstream .open unfortunatly. 
	_fin.open("data.txt");
	if (_fin.fail())
		cout << "\nfailed to connect the instream to data.txt\n";

	//collecting data from data file into one big vector
	while (!_fin.eof())
	{
		_fin.get(next);
		inputVector.push_back(next);
	}

	_fin.close();

	//replace all new line characters with spaces. Since the original newlines are not really needed. 
	replace(inputVector.begin(), inputVector.end(), '\n', ' ');

	//connecting to the outfile
	_fout.open("data.out");
	if (_fout.fail())
		cout << "\nError connecting to the ofstream of the data file\n";

	//placing data into file formatted 
	oldChar = inputVector[0];
	for (int i = 0; i < inputVector.size(); i++) // for all the data collected
	{
		newChar = inputVector[i];

		if (((i + 1) % maxChar) == 0) // if the characters from the data have reached the max number per line
		{
			if (inputVector[i] == ' ') // if the current character is in-between words 
			{
				_fout.put('\n');							//Now moves the space to the next line
				inputVector.erase(inputVector.begin() + i); //Deletes said space from the list, as to have the list
				_fout.put(inputVector[i]);					//Begin with a letter and be at proper spacing.
			}

			else if (inputVector[i] != ' ' && oldChar == ' ') // if a word is just beginning as the cut-off is met 
			{
				_fout.put('\n');
				_fout.put(inputVector[i]);
			}
			else // if the current character is in a word then break it off with a '-' before a new line is started.
			{
				_fout.put('-');
				_fout.put('\n');
				_fout.put(inputVector[i]);
			}
		}

		else //The characters are not yet at the max characters per line limit.
			_fout.put(inputVector[i]);

		oldChar = newChar;
	}

	_fout.close();

	//displaying the newly formatted data
	_fin.open("data.out");
	while (_fin)
	{
		_fin.get(next);
		cout << next;
	}
	_fin.close();
}
