#include "linkedList.h"
#include "processes.h"
using namespace std;
int x_quantum;
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
void processes::create_Process(linkedList &l)
{
	std::string process_name;
	int choice, Arrivetime, BrustTime, priorityy, type;
	char lock = 'a';
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
	std::cout << endl;
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
		cout << endl << "press 'S' to stop .. or  any button to insert another process" << endl;
		std::cin >> lock;
		
		std::cout << "------------------------------------" << std::endl;
		if (lock == 's' || lock == 'S') 
		{
			if (choice == 4)
			{
				std::cout << "enter quantum" << std::endl;
				std::cin >> x_quantum;
			}
			break;
			
		}
	}
	switch (choice)
	{
	case 1:
		FCFS(l);
	case 2:
		shortJobNon(l);
	case 3:;//priority
	case 4:
		RoundRobin(l);//RR
	}
}
void processes::shortJobNon(linkedList &l)
{
	node* tmp;
	node* n;
	processes value;
	l.sort(1);
	l.sort(2);


}
void processes::FCFS(linkedList &l)
{
	l.sort(1);
	l.print_as_FCFS();
}

void processes::RoundRobin(linkedList &l)
{
	l.sort(1);
	l.print_as_RR();
}
