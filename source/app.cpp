//------------------------------------------------------------------------------
// app.cpp : LinkedList class demo
//------------------------------------------------------------------------------
#include <iostream>

#include "LinkedList.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void displayNodeData(LinkedList& dataList);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// local LinkedList class instance declaration allocates stack memory
	LinkedList myList;
	// for testing
	bool deleted;

	// add some list items, each one becomes the new list head

	myList.addNode(1);
	myList.addNode(2);
	myList.addNode(3);
	myList.addNode(4);
	myList.addNode(5);

	// show initial list data
	displayNodeData(myList);

	// check all four cases deleteNode() must handle
	// for thorough list test check all four
	// several times in different orders
	
	// delete node in the middle of the list
	deleted = myList.deleteNode(3);
	// delete node at list end
	deleted = myList.deleteNode(1);
	// delete node at list head
	deleted = myList.deleteNode(5);
	// delete node that isn't in the list
	deleted = myList.deleteNode(100);

	// show remaining list data
	displayNodeData(myList);

	// release all node memory
	myList.makeEmpty();

	// good c++itizen
	return 0;
}

//------------------------------------------------------------------------------
// display each data item in the passed list
//------------------------------------------------------------------------------
void displayNodeData(LinkedList& dataList) {
	
	//--------------------------------------------------------------------------
	// _always check list status before walking the list!
	//--------------------------------------------------------------------------
	if (dataList.isEmpty()) {
		cout << "empty list\n";
		return;
	}

	// reset list position pointer to list head
	//-----------------------------------------------------------------------------
	// You have to do this because 
	//		a) each .putItem() call changes myList's Position pointer, and
	//		b) .getCurrentNodeData() uses that same Position pointer.
	// 
	// When reusing someone else's class, you must understand it how to use
	// the public methods. Ideally class methods are declared in a way that
	// makes it pretty obvious how to use the class. Here it's not obvious,
	// you have to look closely at LinkedList class code to effectively use
	// its methods.
	// 
	// This LinkedList class offers easy list traversal with gotoHead() and
	// gotoNext(), plus it gives you a bookmark pointer to the current node.
	// The Position pointer is that bookmark.
	// 
	// Bottom line: when you post code to GitHub, make it easy to use.
	//		- briefly explain each function in its comment header, then
	//		- copy/paste those into README.MD file bullet items.
	// 
	//--------------------------------------------------------------------------
	// reset list position pointer to list head
	dataList.gotoHead();
	
	std::cout << "\nat head of list";
	// walk the list, get each node data item, display it
	do {
		// "bucket" for receiving node data in reference parameter
		int intDataBucket;
		if (dataList.getCurrentNodeData(intDataBucket)) {
			std::cout << '\n' << intDataBucket;
		}
		else {
			std::cout << "\nat end of list\n";
		}
	} while (dataList.gotoNext());
	//-----------------------------------------------------------------------------
	// gotoNext() advances the Position pointer to the next list item
	//-----------------------------------------------------------------------------
}