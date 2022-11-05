//------------------------------------------------------------------------------
// app.cpp : LinkedList class driver
//------------------------------------------------------------------------------
#include <iostream>

#include "LinkedList.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr bool ADD = false;
constexpr bool INS = !ADD;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void testAdd(LinkedList &myList);
void testInsert(LinkedList& myList);
void testDelete(LinkedList& myList);

// delete node, show remaining list data
inline bool _zapNshow(LinkedList& list, int data);

// insert (true) or add (false) new node and show list data
inline void _newNshow(LinkedList& list, int data, bool insert = INS);

void displayNodeData(LinkedList& dataList);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// local LinkedList class instance declaration allocates stack memory
	LinkedList myList;

	//--------------------------------------------------------------------------
	// add some list items, on add each one becomes the new list head
	//--------------------------------------------------------------------------
	testAdd(myList);

	//--------------------------------------------------------------------------
	// insert some list items in ascending sort order
	//--------------------------------------------------------------------------
	//testInsert(myList);

	//--------------------------------------------------------------------------
	// delete list items
	//--------------------------------------------------------------------------
	testDelete(myList);

	// END TEST release all node memory
	myList.makeEmpty();

	// good c++itizen
	return 0;
}

//------------------------------------------------------------------------------
// exercise addNode()
//
// add some list items, on add each one becomes the new list head
//------------------------------------------------------------------------------
void testAdd(LinkedList& myList) {

	_newNshow(myList, 1, ADD);
	_newNshow(myList, 2, ADD);
	_newNshow(myList, 3, ADD);
	_newNshow(myList, 4, ADD);
	_newNshow(myList, 5, ADD);
}

//------------------------------------------------------------------------------
// exercise insertNode()
//
// check all four cases insertNode() must handle
// for a thorough list test check all cases
// several times in different orders
//
//	case 1: new data node is first list node
//	case 2: new data node becomes new head of list
//	case 3: new data node added after tail, becomes new tail of list
//	case 4: new data node inserted between nodes
//------------------------------------------------------------------------------
void testInsert(LinkedList& myList) {

	// case 1: new data node is first list node
	_newNshow(myList, 3, INS);
	// case 2: new data node becomes new head of list
	_newNshow(myList, 1, INS);
	// case 4: new data node inserted between nodes
	_newNshow(myList, 2, INS);
	// case 3: new data node added after tail, becomes new tail of list
	_newNshow(myList, 5, INS);
	// case 4: new data node inserted between nodes
	_newNshow(myList, 4, INS);
	// case 3: new data node added after tail, becomes new tail of list
	_newNshow(myList, 5, INS);
}

//------------------------------------------------------------------------------
// exercise deleteNode()
//
// check all four cases deleteNode() must handle
// for a thorough list test check all cases
// several times in different orders
//------------------------------------------------------------------------------
void testDelete(LinkedList& myList) {

	// for testing deleteNode() return value
	bool deleted;

	// case 1: delete node in the middle of the list
	deleted = _zapNshow(myList, 3);

	// case 2: delete node at list head
	deleted = _zapNshow(myList, 1);

	// case 3: delete node at list tail
	deleted = _zapNshow(myList, 5);

	// delete node at list tail again
	deleted = _zapNshow(myList, 5);

	// case 4: delete node that's not in the list
	deleted = _zapNshow(myList, 100);
}

//------------------------------------------------------------------------------
// delete node, show remaining list data
//------------------------------------------------------------------------------
inline bool _zapNshow(LinkedList& list, int data) {

	cout << "\ndeleting " << data << "...";

	bool deleted = list.deleteNode(data);

	if (!deleted) {
		cout << "not found";
	}
	else {
		cout << "ok";
	}

	displayNodeData(list);

	return deleted;
}

//------------------------------------------------------------------------------
// add or insert node then show list data
// 
// inserts node when insert is true, adds node otherwise
//------------------------------------------------------------------------------
inline void _newNshow(LinkedList& list, int data, bool insert) {

	if (insert) {
		cout << "\ninserting sorted " << data;
		list.insertNode(data);
	}
	else {
		cout << "\nadding unsorted " << data;
		list.addNode(data);
	}

	displayNodeData(list);
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
	
	//cout << "\nat list head";
	// walk the list, get each node data item, display it
	do {
		// "bucket" for receiving node data in reference parameter
		int intDataBucket;
		if (dataList.getCurrentNodeData(intDataBucket)) {
			cout << '\n' << intDataBucket;
		}
		else {
			//cout << "\nat list tail\n";
			cout << '\n';
		}
	} while (dataList.gotoNext());
	//-----------------------------------------------------------------------------
	// gotoNext() advances the Position pointer to the next list item
	//-----------------------------------------------------------------------------
}