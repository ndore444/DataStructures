#include "dictionary.h"

dictionary::dictionary()
{
	//intentionally blank
}

dictionary::dictionary(string _fileName)
{
	dictionary tempDict;
	DictEntry tempEntry;
	string next;
	wordType nextWord;
	vector<string> wordList;

	//connecting to file
	ifstream fin(_fileName);
	if (fin.fail())
		cout << "\nerror connecting to instream file for dictionary\n";

	//creating a vector from contents of file
	fin >> next;
	while (fin)
	{
		tempEntry.setWord(next);
		dictList.insert(myPosition, tempEntry);
		fin >> next;
	}
	fin.close();
}

int dictionary::searchForward(wordType & findString)
{
	int counter = 1;
	list<DictEntry>::iterator myPosition = dictList.begin();

	while ((myPosition != dictList.end()) && (myPosition->getWord() != findString))
	{
		++myPosition;
		counter++;
	}

	if ((myPosition != dictList.end()) && (myPosition->getWord() == findString))
	{
		if (counter == 1)
			cout << "\nThe word " << findString << " was found in 1 search.\n";
		else
			cout << "\nThe word " << findString << " was found in " << counter << " searches.\n";
		return counter;
	}

	else
	{
		cout << "\nThe word " << findString << " was not found.\n";
		return -1;
	}
}

void dictionary::searchForward(vector<wordType>& _searchList)
{
	for (int i = 0; i < _searchList.size(); i++)
		searchForward(_searchList[i]);
}

int dictionary::searchBackward(wordType & findString)
{
	int counter = 1;
	list<DictEntry>::reverse_iterator myPosition = dictList.rbegin();

	while ((myPosition != dictList.rend()) && (myPosition->getWord() != findString))
	{
		++myPosition;
		counter++;
	}

	if ((myPosition != dictList.rend()) && (myPosition->getWord() == findString))
	{
		if (counter == 1)
			cout << "\nThe word " << findString << " was found in 1 search.\n";
		else
			cout << "\nThe word " << findString << " was found in " << counter << " searches.\n";
		return counter;
	}

	else
	{
		cout << "\nThe word " << findString << " was not found.\n";
		return -1;
	}
}

void dictionary::searchBackward(vector<wordType>& _searchList)
{
	for (int i = 0; i < _searchList.size(); i++)
		searchBackward(_searchList[i]);
}

void dictionary::revPrintList(string _filename)
{
	ofstream fout(_filename);
	if (fout.fail())
		cout << "\nfailed to connect to outfile in printlist\n";

	dictList.sort();

	list<DictEntry>::reverse_iterator myPosition = dictList.rbegin();
	while (myPosition != dictList.rend())
	{
		fout << myPosition->getWord() << " ";
		++myPosition;
	}

	fout.close();
}

ostream & operator<<(ostream & outs, const dictionary & _dictionary)
{
	dictionary tempDict = _dictionary;
	tempDict.myPosition = tempDict.dictList.begin();

	while (tempDict.myPosition != tempDict.dictList.end())
	{
		outs << tempDict.myPosition->getWord() << endl;
		++tempDict.myPosition;
	}

	return outs;
}
