//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"


ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE) // ***Note that I changed this, was originally the undifined "(DEFAULT_ArrayBAG_SIZE)"
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if

	return hasRoomToAdd;
}  // end add

void ArrayBag::addList(vector<int> newEntryList)
{
	bool hasRoomToAdd = ((itemCount + newEntryList.size())< maxItems);

	if (hasRoomToAdd)
	{
		for (int i = 0; i < newEntryList.size(); i++)
			add(newEntryList[i]);
		hasRoomToAdd = (itemCount < maxItems);
	}

}

bool ArrayBag::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int searchIndex = 0;
	while (searchIndex < itemCount)
	{
		if (items[searchIndex] == anEntry)
		{
			frequency++;
		}  // end if

		searchIndex++;
	}  // end while

	return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains



std::vector<ItemType> ArrayBag::toVector() const
{
	std::vector<ItemType> ArrayBagContents;
	for (int i = 0; i < itemCount; i++)
		ArrayBagContents.push_back(items[i]);
	return ArrayBagContents;
}  // end toVector

   // private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	// if the ArrayBag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  // end if
	}  // end while

	return result;
}  // end getIndexOf

ArrayBag operator+(ArrayBag & _bag1, ArrayBag & _bag2)
{
	//create a temporary vector, identical to the passed in _bag1 and _bag2
	vector<int> bag1Vector = _bag1.toVector();
	vector<int> bag2Vector = _bag2.toVector();

	//for the amount of contents in bag2,
	for (int i = 0; i < bag2Vector.size(); i++)
	{
		//add bag2's contents onto the end of bag1
		bag1Vector.push_back(bag2Vector[i]);
	}
	//returns the newly combined bag
	ArrayBag newBag;
	newBag.addList(bag1Vector);
	return newBag;
}

ArrayBag operator-(ArrayBag & _bag1, ArrayBag & _bag2)
{
	//create a temporary vector, identical to the passed in _bag1 and _bag2
	vector<int> bag1Vector = _bag1.toVector();
	vector<int> bag2Vector = _bag2.toVector();

	//find duplicates and delete them.
	for (int i = 0; i < bag1Vector.size(); i++)
	{
		for (int n = 0; n < bag2Vector.size(); n++)
		{
			if (bag1Vector[i] == bag2Vector[n])
			{
				//note that both vectors have the duplicate index deleted, that way you dont get multiple deletions from the same bag 2 element :) 
				bag1Vector.erase(bag1Vector.begin() + i);
				bag2Vector.erase(bag2Vector.begin() + n);
			}
		}
	}

	//returns the newly formulated bag, rid of duplicates.
	ArrayBag newBag;
	newBag.addList(bag1Vector);
	return newBag;
}
