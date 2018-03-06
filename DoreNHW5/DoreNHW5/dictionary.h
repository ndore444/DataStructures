/* Dr. Augustine
dictionary.h
Last Updated:02/14/2016
Status: Compiles and all requirements met*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include "DictEntry.h"

using namespace std;

class dictionary
{
public:
	//typedef string wordType;
	dictionary();
	//takes in a filename linking to a file containing a list of words. Parses the file data into a stl list of type dictionary
	dictionary(string _fileName);
	
	//sorts the dictList contained in the dictionary using the stl list sort function.
	void sort() { dictList.sort(); }

	/*Searches the list starting at the front of the list and moving to the back
	Returns the number of searches it took to find the findString, or a -1 if not found*/
	int searchForward(wordType &findString);
	void searchForward(vector<wordType> &_searchList);

	/*Searches the list starting at the back of the list and moving to the front
	Returns the number of searches it took to find the findString, or a -1 if not found*/
	int searchBackward(wordType &findString);
	void searchBackward(vector<wordType> &_searchList);

	//displays the list held within the dictionary
	friend ostream& operator <<(ostream& outs, const dictionary& _dictionary);

	/*Prints the list of words in reverse alphabetic order to a file*/
	void revPrintList(string _filename);

private:
	list<DictEntry> dictList;
	list<DictEntry>::iterator myPosition = dictList.begin();
	DictEntry entry;
};

/*******************************/



#endif /* dictionary_h */