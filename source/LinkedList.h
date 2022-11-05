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
	Node* head;
	Node* Position;
	Node* _prevPosition;				// internal use: simplifies node delete

public:
	LinkedList();
	~LinkedList();

	// manage nodes
	void addNode(int data);				// add new node at head of list
	void insertNode(int data);			// #TODO implement for sorted list
	bool deleteNode(int matchData);

	// manage Position pointer to current node

	// reset Position to head of list
	void gotoHead();
	// advance Position to next node in list
	bool gotoNext();
	// return data at current Position
	bool getCurrentNodeData(int& fillWithData);

private:
	// internal use: set Position pointer to found data node
	void _setPosition(int matchData);

public:
	// manage list 
	bool isEmpty();
	void makeEmpty();	// release each Node's memory
};
#endif