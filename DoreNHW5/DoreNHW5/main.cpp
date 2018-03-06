/* 
 *Name: Nathaniel Dore
 *Class: CSCI 2421
 *Lab Partner: N/A
 *Status: development complete: final release build 
 */

#include <iostream>
#include "DictEntry.h"
#include "dictionary.h"

using namespace std;

//function declarations
vector<wordType> parseSearchWords(string _fileName);

int main( )
{
	dictionary dict("dictionary.txt");
	vector<wordType> searchList;

	cout << dict;
	dict.sort();
	cout << endl << dict;

	wordType cat = "cat";
	wordType boar = "boar";

	searchList = parseSearchWords("findwords.txt");

	dict.searchForward(searchList);
	cout << "\n\n";
	dict.searchBackward(searchList);

	dict.revPrintList("revsorted.txt");

    return 0;
}

vector<wordType> parseSearchWords(string _fileName)
{
	vector<wordType> searchList;
	string next;

	ifstream fin(_fileName);
	if (fin.fail())
		cout << "failed to connect to the instream of search words";

	fin >> next;
	while (fin)
	{
		searchList.push_back(next);
		fin >> next;
	}

	fin.close();

	return searchList;
}
