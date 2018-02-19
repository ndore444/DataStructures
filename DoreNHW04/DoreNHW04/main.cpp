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

using namespace std;

//function definitions

//dynamically parses correctly formated data from input.txt into a list of words
vector<string> parseInStrings(string _fileName);
//vector<string> parseInput(string _fileName);

int main() 
{
	vector<string> wordList;
	wordList = parseInStrings("input.txt");

	system("Pause");
	return 0;
}

//function definitions
vector<string>  parseInStrings(string _fileName)
{
	vector<string> wordList;
	stringstream buffer;
	ifstream file(_fileName);
	string s;

	///collecting data 

	//opening input file

	if (file)
	{
		buffer << file.rdbuf(); //entire file is now in buffer
		
		file.close();

		/// operations on the buffer...

		s = buffer.str(); //buffer transfered into a string

		///elimination of unwanteds
		//eliminating punctuation
		s.erase(remove(s.begin(), s.end(), '.'), s.end());
		s.erase(remove(s.begin(), s.end(), ','), s.end());
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
		s.erase(remove(s.begin(), s.end(), '?'), s.end());
		s.erase(remove(s.begin(), s.end(), '\''), s.end());
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

	}
	return wordList;
}
