/*
*Name: Nathaniel Dore
*Class: CSCI 2421
*Description: program allows the user to search through an input file for specific words and place them into a list.
*Lab Partner: N/A
*Status: development complete: final release build
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//function definitions

//this is about to get crazy... dynamically parses correctly formated data from input.txt into a list of bags
vector<string> parseInputStrings();

int main()
{


	system("Pause");
	return 0;
}

//function definitions
vector<string>  parseInputStrings()
{
	ifstream fin; 
	vector< vector<string> > MatrixOfStr;
	vector<string> listOfLines, tempStrVector;
	int numberOfLines = 0, nextInt = 0;
	string nextString;

	//opening input file
	fin.open("input.txt");
	if (fin.fail())
	{
		cout << "error connecting instream to input file. \n";
	}

	///collecting data 
	std::ifstream file("input.txt");

	if (file)
	{
		stringstream buffer;

		//entire file is now in buffer
		buffer << file.rdbuf();

		file.close();

		/// operations on the buffer...

		//seperating the input into a vector list w/ each line an element.
		string s;
		//buffer transfered into a string
		s = buffer.str();
		//1st Delimiter
		string delimiter = "\n";

		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos)
		{
			token = s.substr(0, pos);
			listOfLines.push_back(token);
			s.erase(0, pos + delimiter.length());
		}

		//sperating the vector list of lines into a vector list of individual numbers
		for (int i = 0; i < listOfLines.size(); i++)
		{
			string s = listOfLines[i];
			//2nd delimiter
			string delimiter = " ";

			size_t pos = 0;
			string token;
			tempStrVector.clear();
			while ((pos = s.find(delimiter)) != string::npos)
			{
				token = s.substr(0, pos);
				tempStrVector.push_back(token);
				s.erase(0, pos + delimiter.length());
			}
			MatrixOfStr.push_back(tempStrVector);
		}

	}

	//converting the string matrix into an int matrix

	for (int i = 0; i < MatrixOfStr.size(); i++)
	{
		for (int n = 0; n < MatrixOfStr[i].size(); n++)
		{
			tempIntVector.push_back(stoi(MatrixOfStr[i][n]));
		}
		MatrixOfInt.push_back(tempIntVector);
	}

	//parse matrix of ints into bags
	for (int i = 0; i < MatrixOfInt.size(); i++)
	{
		tempBag.clear();
		tempBag.addList(MatrixOfInt[i]);
		bagList.push_back(tempBag);
	}

	return bagList;
}