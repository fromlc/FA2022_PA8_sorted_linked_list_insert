//------------------------------------------------------------------------------
// LinkedList.cpp : class definition
// 
// Author: unknown book example, unknown author
// 
// This code is intended as an example for students in my classes.
//------------------------------------------------------------------------------
#include "LinkedList.h"

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
LinkedList::LinkedList() {
	_head = nullptr;

	// set _Position pointer to list _head
	gotoHead();
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
LinkedList::~LinkedList() { makeEmpty(); }

//------------------------------------------------------------------------------
// new item becomes list _head
//------------------------------------------------------------------------------
void LinkedList::addNode(int data) {

	Node* pNode = new Node(data);

	pNode->next = _head;
	_head = pNode;

	// before first item is added _Position is nullptr
	if (_Position == nullptr)
		gotoHead();
}

//------------------------------------------------------------------------------
// insert list node containing passed data value
// 
// handles 4 cases:
//		1. new data node is first list node
//		2. new data node becomes new _head of list
//		3. new data node added after tail, becomes new tail of list
//		4. new data node inserted between nodes
// 
// inserts duplicate data _before existing node with same data value
// 
// updates _Position pointer to new node
// 
//------------------------------------------------------------------------------
void LinkedList::insertNode(int data) {

	Node* pNode = new Node(data);

	// case 1: new data node is first list node
	if (_head == nullptr) {
		_head = pNode;
		gotoHead();
		return;
	}

	//-----------------------------------------------------------------------------
	// working pointers preserve _head pointer, traverse the list
	//		- p starts off pointing to list _head, follows each node's next pointer
	//		- pPrev starts off nullptr, follows one node behind p
	//-----------------------------------------------------------------------------
	Node* p = _head;
	Node* pPrev = nullptr;

	//-----------------------------------------------------------------------------
	// traverse the list with a while loop
	// 
	// the values of p and pPrev after this while loop
	// determine which case passed data presents
	//-----------------------------------------------------------------------------

	while (p && p->data < data) {
		pPrev = p;
		p = p->next;
	}
	
	// case 2: new data node becomes new _head of list
	if (pPrev == nullptr) {
		pNode->next = _head;
		_head = pNode;

		// update _Position pointer
		gotoHead();
		return;
	}

	//-----------------------------------------------------------------------------
	// case 3: new data node added after tail, becomes new tail of list
	// and
	// case	4. new data node inserted between nodes
	//-----------------------------------------------------------------------------
	pPrev->next = pNode;
	pNode->next = p;

	// update internal list pointers
	_Position = pNode;
	_prevPosition = pPrev;
}

//------------------------------------------------------------------------------
// delete list node containing passed data value
//------------------------------------------------------------------------------
bool LinkedList::deleteNode(int matchData) {

	_setPosition(matchData);

	// data not found
	if (_Position == nullptr)
		return false;

	// data found, _Position points to the containing node
	Node* pNode = _Position;

	// data at list end
	if (pNode->next == nullptr) {
		_prevPosition->next = nullptr;
		_Position = _prevPosition;
	}
	// nodes before and after data
	else if (_prevPosition != nullptr) {
		_prevPosition->next = pNode->next;
		_Position = _prevPosition->next;
	}
	// data at list _head
	else {
		_head = pNode->next;
		gotoHead();
	}

	// release node memory
	delete pNode;

	return true;
}

//------------------------------------------------------------------------------
// reset _Position to list _head
//------------------------------------------------------------------------------
void LinkedList::gotoHead() {
	_Position = _head;
	_prevPosition = nullptr;
}

//------------------------------------------------------------------------------
// advances _Position pointer to the next node on the list, if possible
// 
// returns 
//		- new _Position, when _Position did in fact advance
//		- nullptr, when _Position is at list end and cannot advance
//------------------------------------------------------------------------------
bool LinkedList::gotoNext() {

	if (_Position != nullptr) {
		// advance
		_Position = _Position->next;
		return true;
	}

	// can't advance when _Position is 0
	return false;
}

//------------------------------------------------------------------------------
// return the list item pointed to by _Position in reference param
//------------------------------------------------------------------------------
bool LinkedList::getCurrentNodeData(int& fillWithData) {

	if (_Position != nullptr) {
		fillWithData = _Position->data;
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------
// sets _Position pointer to node containing passed data value (private)
//------------------------------------------------------------------------------
void LinkedList::_setPosition(int matchData) {

	gotoHead();

	bool found = false;
	while (_Position != nullptr && !found) {

		if (_Position->data == matchData) {
			found = true;
			break;
		}

		// keep previous position for easy deleteNode
		_prevPosition = _Position;

		// advance _Position to next node on the list
		gotoNext();
	}
}

//------------------------------------------------------------------------------
// returns true if list is empty, false otherwise
//------------------------------------------------------------------------------
bool LinkedList::isEmpty() {

	return (_head == nullptr) ? true : false;
}

//------------------------------------------------------------------------------
// traverse list to release all Nodes
//		- shallow memory release only - ok for original int data in Node
//		- #TODO MEMORY LEAK if LinkedList carries pointer data in Node
//------------------------------------------------------------------------------
void LinkedList::makeEmpty() {

	if (isEmpty())
		return;

	gotoHead();

	while (_Position != nullptr) {
		// save each _Position value
		Node* pNode = _Position;

		// then gotoNext() advances _Position to next node on the list
		gotoNext();

		// now our _Position is the next node, we can
		// delete previous _Position's memory
		// the memory deleted is every Node instance
		delete pNode;
	}

	_head = nullptr;
	_Position = nullptr;
}

//------------------------------------------------------------------------------
// return data value at node# index 
//------------------------------------------------------------------------------
bool LinkedList::at(int index, int& data) {

	if (!_head)	return false;

	Node* p = _head;
	int i = 0;

	while (p && i < index) {
		p = p->next;
		++i;
	}

	if (!p) return false;

	data = p->data;
	return true;
}
