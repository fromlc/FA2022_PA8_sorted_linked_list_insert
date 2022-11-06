# LinkedList class

 - Modified code, original author unknown
 - Singly-linked list nodes contain integer data
 - List can be sorted or unsorted
     - for sorted list, use insertNode() only
     - for unsorted list, use addNode()
     - calling addNode() on sorted list destroys sort order!
## LinkedList class methods
 // create list nodes at list head

 void addNode(int data);
 
 // create and insert list nodes in sorted (ascending) order:

 void insertNode(int data);

 // check for empty list (returns true on empty list)
 bool isEmpty();

 // traverse the list from head to tail
 
 // first, set bookmark pointer to head
 void gotoHead();
 
 // then call gotoNext() in a loop (returns false at end of list)
 bool gotoNext();

 // get data from bookmarked node (returns false on error)
 bool getCurrentNodeData(int& fillWithData);

 // release all node memory
 void makeEmpty();
