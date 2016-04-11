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
	int choice, Arrivetime, BrustTime,priorityy,type;
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
	if (choice == 2 || choice == 3)
	{
		std::cout << "1.Non pre-emptive" << std::endl;
		std::cout << "2.pre-emptive" << std::endl;
		std::cin >> type;
	}
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
		l.Add(p);
		std::cin>> lock;
		if (lock=='s') { break; }	}
	 if(choice==1)
	 {;//FCFS
	 }
	 else if (choice == 2)
	 {
		 switch (type)
		 {
		 case 1: { shortJobNon(l); }
		 case 2: { shortJobPre(l); }
		 }
	 }
	 else if(choice== 3) 
	{
		switch (type)
		{
		case 1: { PriorityNon(l); }
		case 2: { PriorityPre(l); }
		}
	}
	else if(choice== 4)
	{
		;//RR
	}
	else std::cout << "Error !" << std::endl;
		}
 void processes::shortJobNon(linkedList &l)
 {
	 l.sort(1);
	 l.sort(2);
	 l.printAll();
 }
 void processes::shortJobPre(linkedList &l)
 {

	 node* tmp;
	 node* n;
	 int remaining, clock,count;
	 l.sort(1);
	 l.sort(2);
	 clock = l.getHead()->get_Data().get_arrival_time();
	 for (tmp = l.getHead(); tmp != nullptr; tmp = tmp->getNext())
	 {
		 count = 1;
		 remaining = tmp->get_Data().get_burst();
	 loop:
		 for (n = l.getHead(); n != nullptr; n = n->getNext())
		 {
			 if (tmp->get_Data().get_burst() > n->get_Data().get_burst() && (clock == n->get_Data().get_arrival_time() || n->get_Data().get_arrival_time() < clock) && n->get_Data().get_burst() != 0)
			 {
				 processes p = n->get_Data();
				 n->setData(tmp->get_Data());
				 tmp->setData(p);
				 remaining = tmp->get_Data().get_burst();
				 std::cout << tmp->get_Data().get_name_of_process() << std::endl;
				 count++;
			 }
		 }
		 
		 while (remaining != 0)
		 {
			 if(count ==1 ){
				 std::cout << tmp->get_Data().get_name_of_process() << std::endl;
				 count++;
			 }
			 remaining--;
			 tmp->get_Data().set_burst(remaining);
			 clock++;
			 goto loop;
		 }
	 }
 }
 void processes::PriorityNon(linkedList &l)
	 {
		 l.sort(1);
		 l.sort(3);
		 l.printAll();
	 }
 void processes::PriorityPre(linkedList &l)
 {
	 node* tmp;
	 node* n;
	 int remaining, clock, count;
	 l.sort(1);
	 l.sort(2);
	 clock = l.getHead()->get_Data().get_arrival_time();
	 for (tmp = l.getHead(); tmp != nullptr; tmp = tmp->getNext())
	 {
		 count = 1;
		 remaining = tmp->get_Data().get_burst();
	 loop:
		 for (n = l.getHead(); n != nullptr; n = n->getNext())
		 {
			 if (tmp->get_Data().get_priority() > n->get_Data().get_priority() && (clock == n->get_Data().get_arrival_time() || n->get_Data().get_arrival_time() < clock) && (n->get_Data().get_burst() != 0))
			 {
				 processes p = n->get_Data();
				 n->setData(tmp->get_Data());
				 tmp->setData(p);
				 remaining = tmp->get_Data().get_burst();
				 std::cout << tmp->get_Data().get_name_of_process() << std::endl;
				 count++;
			 }
		 }

		 while (remaining != 0)
		 {
			 if (count == 1) 
			 {  
				 std::cout << tmp->get_Data().get_name_of_process() << std::endl;
				 count++;
			 }
			 remaining--;
			 tmp->get_Data().set_burst(remaining);
			 clock++;
			 goto loop;
		 }
	   }
 }