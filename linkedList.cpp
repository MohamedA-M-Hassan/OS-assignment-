#include "linkedList.h"
#include <string>
using namespace std;

extern int x_quantum;

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
void linkedList::printAll()
{
	node* tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->proc.get_name_of_process() << endl;
		tmp = tmp->getNext();
	}
}
void linkedList::print_as_FCFS()
{

	node* tmp = head;
	cout << endl << endl;
	cout << "the Gannt chart of excuting the processes " << endl;
	while (tmp != nullptr)
	{
		//to draw >> |process1
		cout << "[" << tmp->proc.get_name_of_process();
		// to draw >> |process1______________|
		int number_of_burst_to_use_in_draw = tmp->proc.get_burst();
		for (int i = 0; i < number_of_burst_to_use_in_draw; i++)
		{
			cout << "_";
		}
		cout << "]";
		tmp = tmp->getNext();
	}
	cout << endl << endl;
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
				// type 1 >> arrival time
			case 1:
				if (ptr->proc.get_arrival_time() > s->proc.get_arrival_time())
				{
					value = ptr->proc;
					ptr->proc = s->proc;
					s->proc = value;
				}
				// type 2 >> burst
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
				// type 3  >> priority
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

void linkedList::print_as_RR()

{
	cout << endl << endl;
	cout << "the Gannt chart of excuting the processes " << endl;
	loop : node* tmp = head;

	while (tmp != nullptr)
	{
		//cout << "[" << tmp->proc.get_name_of_process();               //to draw >> |process1
		int number_of_burst_to_use_in_draw = tmp->proc.get_burst();  // to draw >> |process1______________|

		if (number_of_burst_to_use_in_draw >= x_quantum && number_of_burst_to_use_in_draw != 0)
		{
			cout << "[" << tmp->proc.get_name_of_process();               //to draw >> |process1
			for (int i = 0; i < x_quantum; i++)
			{
				cout << "_";
			}
			tmp->proc.set_burst(number_of_burst_to_use_in_draw - x_quantum);
			cout << "]";

		}
		else if (number_of_burst_to_use_in_draw <= x_quantum && number_of_burst_to_use_in_draw != 0)
		{
			cout << "[" << tmp->proc.get_name_of_process();               //to draw >> |process1
			for (int i = 0; i < number_of_burst_to_use_in_draw; i++)
			{
				cout << "_";
				//tmp == nullptr;
			}
			tmp->proc.set_burst(0);
			//number_of_burst_to_use_in_draw = 0;
			cout << "]";

		}
		else { 
			//tmp = tmp->getNext();
		     }
	//	cout << "]";
		tmp = tmp->getNext();
	}
	goto loop;

}