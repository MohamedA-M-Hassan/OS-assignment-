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
	void printAll();
    void sort(int type);
	void print_as_FCFS();
	static void print_as_RR(linkedList &l);



};
#endif