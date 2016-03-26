#include "linkedList.h"

linkedList::linkedList()
{
	head = nullptr;
}
node* linkedList::getHead()
{
	return head;
}
bool linkedList::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}
void linkedList::Add(processes item)
{
	if (isEmpty())
	{
		node* nw = new node(item);
		nw->next = head;
		head = nw;

	}
	else
	{
		node* tmp = head;
		while (tmp->getNext() != nullptr)
		{
			tmp = tmp->getNext();
		}
		node* nw = new node(item);
		tmp->setNext(nw);
	}
}
/*void printAll()
{
Node* tmp = head;
while (tmp != nullptr)
{
std::cout << tmp->data <<std::endl;
tmp = tmp->getNext();
}
}*/


