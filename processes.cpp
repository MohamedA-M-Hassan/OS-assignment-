#include "linkedList.h"
#include "processes.h"
void processes::set_name_of_process(std::string n)
{
	name = n;
}
std::string processes::get_name_of_process()
{
	return name;
}
void processes::set_arrival_time(int t)
{
	arrival_time = t;
}
int processes::get_arrival_time()
{
	return arrival_time;
}
void processes::set_burst(int b)
{
	burst = b;
}
int processes::get_burst()
{
	return burst;
}
void processes::set_priority(int pri)
{
	priority = pri;
}
int processes::get_priority()
{
	return priority;
}
 void processes:: create_Process(linkedList &l)
{
	std::string process_name;
	int choice, Arrivetime, BrustTime,priorityy;
	char lock='a';
	processes p;
	std::cout << std::endl << "---------------------------------" << std::endl;
	std::cout << std::endl << "Types of schedulers supported:" << std::endl;
	std::cout << std::endl << "---------------------------------" << std::endl;
	std::cout << "1.FCFS" << std::endl;
	std::cout << "2.SJF (Preemptive and Non Preemptive)" << std::endl;
	std::cout << "3.Priority (Preemptive and Non Preemptive) (the smaller the priority number the higher the priority)" << std::endl;
	std::cout << "4.Round Robin" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Enter your choice : ";
	std::cin >> choice;
	std::cout << "enter S to stop adding process or A to continue" << std::endl << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	while (1)
	{
		std::cout << "enter process name" << std::endl;
		std::cin >> process_name;
		std::cout << "enter arriving time" << std::endl;
		std::cin >> Arrivetime;
		std::cout << "enter brust time" << std::endl;
		std::cin >> BrustTime;
		if (choice == 3)
		{
			std::cout << "enter priority" << std::endl;
			std::cin >> priorityy;
			p.set_priority(priorityy);
		}
		p.set_name_of_process(process_name);
		p.set_arrival_time(Arrivetime);
		p.set_burst(BrustTime);
		p.set_priority(0);
		l.Add(p);
		std::cin>> lock;
		if (lock=='s') { break; }	}
		switch (choice)
		{
		case 1:;//FCFS
		 case 2:
			 shortJobNon(l);
		 case 3:;//RR
		 case 4:;//priority
		}
		}
  void processes::shortJobNon(linkedList &l)
 {
	 node* tmp;
	 l.sort(1);
	 for (tmp = l.getHead(); tmp->getNext() != nullptr; tmp = tmp->getNext())
	 {
		 if ((tmp->get_Data().get_arrival_time()) == (tmp->getNext()->get_Data().get_arrival_time()))
		 {
			 if ((tmp->get_Data().get_burst()) > (tmp->getNext()->get_Data().get_burst()))
			 {
				 processes tmp1 = tmp->get_Data();
				 tmp->get_Data() = tmp->getNext()->get_Data();
				 tmp->get_Data() = tmp1;

			 }
		 }
	 }
 }

