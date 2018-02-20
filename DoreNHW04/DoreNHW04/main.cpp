/*
*Name: Nathaniel Dore
*Class: CSCI 2421
*Description: program allows the user to search through an input file for specific words and place them into a list.
*Lab Partner: N/A
*Status: development complete: final release build
*/

#include <iostream>		//cin/cout
#include <vector>		//vector
#include <string>		//string & replace
#include <fstream>		//ifstream
#include <sstream>		//buffer operations
#include <algorithm>	//remove

#include "node1.h"

using namespace std;
using namespace main_savitch_5;

//function definitions

//creates a vector string list of each word in the passed string 
vector<string> createWordList(string _s);
//dynamically parses text from _fileName into a list of words disregarding punctuation and capitalization
vector<string> parseFile(string _fileName);
//
void searchNodes(vector<string> _wordList);



int main() 
{
	string userInput;
	vector<string> wordList;
	wordList = parseFile("input.txt");

	//User input
	cout << "Welcome! Please type the words you would like to search for\n"
		 << "Enter the words all on one line seperated by a space between each.\n";
	getline(cin, userInput);

	node* newList = new node;

	wordList = createWordList(userInput);

	addList(newList, wordList);

	system("Pause");
	return 0;
}

//function definitions
vector<string>  createWordList(string _s)
{
	vector<string> wordList;
	char removeList[5] = { '.',',','-','?','\'' };
	string s = _s;

	//eliminating punctuation
	for (int i = 0; i < sizeof(removeList); i++)
		s.erase(remove(s.begin(), s.end(), removeList[i]), s.end());
	//elininating newlines
	replace(s.begin(), s.end(), '\n', ' ');
	//eliminating capitalization
	for (unsigned int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);

	//seperating the buffer into a vector list w/ each word an element.
	string delimiter = " ";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos)
	{
		token = s.substr(0, pos);
		wordList.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	//last remaining word pushed
	token = s.substr(0, pos);
	wordList.push_back(token);

	return wordList;
}

vector<string> parseFile(string _fileName)
{
	stringstream buffer;
	string s;

	//opening input file
	ifstream file(_fileName);
	if (file.fail())
		cout << "failure to connect to input file";

	if (file)
	{
		buffer << file.rdbuf(); //entire file is now in buffer
		s = buffer.str(); //buffer transfered into a string
	}

	else
		cout << "\nempty input file.\n";

	file.close();

	return createWordList(s);
}
