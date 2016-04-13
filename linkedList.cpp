#include "linkedList.h"
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
				if (ptr->get_Data().get_arrival_time() == s->get_Data().get_arrival_time())
				{
					if (ptr->proc.get_priority() > s->proc.get_priority())
					{
						value = ptr->proc;
						ptr->proc = s->proc;
						s->proc = value;
					}
				}
			}
		}
		ptr = ptr->next;
	}

}
void linkedList:: print_as_FCFS()
{

	int arr_sum = 0,no_p = 0;
	float burst = 0 ,arr=0 ,aw =0,count=1;
	node* tmp = head;
	std::cout << std::endl <<std:: endl;
	std::cout << "the Gannt chart of excuting the processes "<< std::endl;
	while (tmp != nullptr)
	{
		//to draw >> |process1
	std::cout <<"["<< tmp->proc.get_name_of_process() ;
	// to draw >> |process1______________|
	int number_of_burst_to_use_in_draw = tmp->proc.get_burst();
		for (int i = 0; i < number_of_burst_to_use_in_draw; i++)
		{
			std::cout << "_";
		}
	std::cout<< "]";
	no_p++;
	arr_sum = arr_sum + tmp->proc.get_arrival_time();
	tmp = tmp->getNext();
	}

	int no_p2 = no_p;
	int z=0;
	node* ta = head;
	while (ta != nullptr && no_p2 !=0)
	{
		int k = ta->proc.get_burst();
		int h = k * (no_p2-1);
		 z = z + h;
		no_p2--;
		//arr_sum = arr_sum + ta->proc.get_arrival_time();
		ta = ta->getNext();
	}

	std::cout <<std::endl<<std::endl;
	std::cout << "avg waiting time "  << aw << std::endl; // *****************
	// std::cout << no_p << "\n" << arr_sum << "\n";
	// std::cout << z << "\n" ;
	float q;
	q = (float)(z-arr_sum)/no_p ;
	std::cout << "Avg Waiting Time = " << q << "\n";
}
void linkedList::print_as_RR()
{
	std::cout << std::endl << std::endl;
	std::cout << "the Gannt chart of excuting the processes " << std::endl;
loop:
	node* tmp = head;

	while (tmp != nullptr)
	{
		int number_of_burst_to_use_in_draw = tmp->proc.get_burst();  // to draw >> |process1______________|

		if (number_of_burst_to_use_in_draw >= x_quantum && number_of_burst_to_use_in_draw != 0)
		{
			std::cout << "[" << tmp->proc.get_name_of_process();               //to draw >> |process1
			for (int i = 0; i < x_quantum; i++)
			{
				std::cout << "_";
			}
			tmp->proc.set_burst(number_of_burst_to_use_in_draw - x_quantum);
			std::cout << "]";

		}
		else if (number_of_burst_to_use_in_draw <= x_quantum && number_of_burst_to_use_in_draw != 0)
		{
			std::cout << "[" << tmp->proc.get_name_of_process();               //to draw >> |process1
			for (int i = 0; i < number_of_burst_to_use_in_draw; i++)
			{
				std::cout << "_";
				//tmp == nullptr;
			}
			tmp->proc.set_burst(0);
			//number_of_burst_to_use_in_draw = 0;
			std::cout << "]";

		}
		else {
			//tmp = tmp->getNext();
		}
		//	cout << "]";
		tmp = tmp->getNext();
	}
	for (tmp = head; tmp != nullptr; tmp = tmp->getNext())

	{
		if (tmp->proc.get_burst()) goto loop;
	}
}