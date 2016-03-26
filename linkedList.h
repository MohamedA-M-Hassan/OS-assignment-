#ifndef linkedlist_l
#define linkedlist_l
#include "node.h"
class linkedList
{
private:
	node* head;

public:
	linkedList();
	node* getHead();
	bool isEmpty();
	void Add(processes item);


};
#endif