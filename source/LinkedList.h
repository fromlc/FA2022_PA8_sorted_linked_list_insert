//------------------------------------------------------------------------------
// LinkedList class declaration, Node class declaration and definition
//------------------------------------------------------------------------------
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//------------------------------------------------------------------------------
// Node
//------------------------------------------------------------------------------
class Node {
public:
	int data;
	Node* next;

	// constructors
	Node() : Node(0) {}

	Node(int input) {
		data = input;
		next = nullptr;
	}
};

//------------------------------------------------------------------------------
// LinkedList : contains Node as composition
//------------------------------------------------------------------------------
class LinkedList {
private:
	Node* _head;						// internal use: first node in list
	Node* _Position;					// internal use: current node
	Node* _prevPosition;				// internal use: simplifies node delete

public:
	LinkedList();
	~LinkedList();

	// manage nodes
	void addNode(int data);				// add new node at head of list
	void insertNode(int data);			// add new node in sorted order
	bool deleteNode(int matchData);

	// manage _Position pointer to current node

	// reset _Position to _head of list
	void gotoHead();
	// advance _Position to next node in list
	bool gotoNext();
	// return data at current _Position
	bool getCurrentNodeData(int& fillWithData);

private:
	// internal use: set _Position pointer to found data node
	void _setPosition(int matchData);

public:
	// manage list 
	bool isEmpty();
	// release each Node's memory
	void makeEmpty();
	// return data value at node# index
	bool at(int index, int& data);	// return data value at node# index
};
#endif