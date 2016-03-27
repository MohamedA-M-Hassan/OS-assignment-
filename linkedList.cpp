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
void linkedList:: printAll()
{
	node* tmp = head;
	while (tmp != nullptr)
	{
	std::cout << tmp->proc.get_name_of_process() <<std::endl;
	tmp = tmp->getNext();
	}
}
void linkedList::sort(int type)
{
	node* ptr;
	node* s;
	processes value;
	if (head == NULL)
	{
		std::cout << "The List is empty" << std::endl;
		return;
	}
	ptr = head;
	while (ptr != NULL)
	{
		for (s = ptr->next; s != NULL; s = s->next)
		{
			switch (type)
			{
			case 1:
				if (ptr->proc.get_arrival_time() > s->proc.get_arrival_time())
				{
					value = ptr->proc;
					ptr->proc = s->proc;
					s->proc = value;
				}

			case 2:

				if (ptr->get_Data().get_arrival_time() == s->get_Data().get_arrival_time())
				{
					if (ptr->proc.get_burst() > s->proc.get_burst())
					{
						value = ptr->proc;
						ptr->proc = s->proc;
						s->proc = value;
					}
				}
			case 3:
				if (ptr->proc.get_priority() > s->proc.get_priority())
				{
					value = ptr->proc;
					ptr->proc = s->proc;
					s->proc = value;
				}

			}
		}
		ptr = ptr->next;
	}

}
