#ifndef node_n
#define node_n
#include "processes.h"

class node
{
private:
	processes proc;
	node* next;

public:
	node(processes d);
	void setData(processes d);
	processes& get_Data();
	void setNext(node* n);
	node* getNext();
	friend class linkedList;


};
class processes;
#endif