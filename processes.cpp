#include "linkedList.h"
#include "processes.h"
int x_quantum;
void processes::set_name_of_process(std::string n)
{
	name = n;
}
std::string processes::get_name_of_process()
{
	return name;
}
void processes::set_arrival_time(float t)
{
	arrival_time = t;
}
float processes::get_arrival_time()
{
	return arrival_time;
}
void processes::set_burst(float b)
{
	burst = b;
}
float processes::get_burst()
{
	return burst;
}
void processes::set_priority(float pri)
{
	priority = pri;
}
float processes::get_priority()
{
	return priority;
}
void processes::set_dep(float d)
{
	dep = d;
}
float processes::get_dep()
{
	return dep;
}
void processes::set_timeTaked(float t)
{
	timeTaked = t;
}
float processes::get_timeTaked()
{
	return timeTaked;
}
void processes:: create_Process(linkedList &l)
{
	std::string process_name;
	float  Arrivetime, BrustTime, priorityy;
    int type, choice;
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
		p.set_timeTaked(BrustTime);
		l.Add(p);
		std::cin>> lock;
		if (lock=='s' || lock == 'S') {
			if (choice == 4)
			{
				std::cout << "enter quantum" << std::endl;
				std::cin >> x_quantum;
			}
			break; }	}
	 if(choice==1)
	 {
		 FCFS(l);
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
		RoundRobin(l);
	}
	else std::cout << "Error !" << std::endl;
		}
void processes::waitingpre(linkedList &l)
{
	node* wait = l.getHead();
	float dep = 0, arr = 0, burst = 0, counter = 0;
	while (wait != nullptr)
	{
		dep += wait->get_Data().get_dep();
		arr += wait->get_Data().get_arrival_time();
		burst += wait->get_Data().get_timeTaked();
		counter++;
		wait = wait->getNext();
	}
	std::cout << (dep - arr - burst) / counter << std::endl;
}
void processes::waitingNon(linkedList &l)
{
	l.printAll();
	int arr_sum = 0, no_p = 0;
	float burst = 0, arr = 0, aw = 0;
	int z = 0;
	node* tmp = l.getHead();
	while (tmp != nullptr)
	{
		no_p++;
		arr_sum += tmp->get_Data().get_arrival_time();
		tmp = tmp->getNext();
	}
	node* ta = l.getHead();
	int no_p2 = no_p;

			while (ta != nullptr && no_p2 != 0)
			{
				int k = ta->get_Data().get_burst();
				int h = k * (no_p2 - 1);
				z = z + h;
				no_p2--;
				ta = ta->getNext();
			}

			std::cout << std::endl;
			float q;
			q = (float)(z - arr_sum) / no_p;
			std::cout << "Avg Waiting Time = " << q << "\n";
		
}
void processes::FCFS(linkedList &l)
 {
	 l.sort(1);
	 l.print_as_FCFS();
	 
 }
 void processes::shortJobNon(linkedList &l)
 {
	 l.sort(1);
	 l.sort(2);
	 waitingNon(l);
 }
 void processes::shortJobPre(linkedList &l)
 {
	 node* tmp;
	 node* n;
	 float remaining, clock;
	 int count;
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
			 clock++;
			 tmp->get_Data().set_burst(remaining);
			 if (tmp->get_Data().get_burst() == 0)
			 {
				 tmp->get_Data().set_dep(clock);
			 }
			 goto loop;
		 }
	 }
	 waitingpre(l);
 }
 void processes::PriorityNon(linkedList &l)
	 {
		 l.sort(1);
		 l.sort(3);
		 //l.printAll();
		 waitingNon(l);

	 }
 void processes::PriorityPre(linkedList &l)
 {
	 node* tmp;
	 node* n;
	 float remaining, clock;
	 int count;
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
			 clock++;
			 tmp->get_Data().set_burst(remaining);
			 if (tmp->get_Data().get_burst() == 0)
			 {
				 tmp->get_Data().set_dep(clock);
			 }

			 goto loop;
		 }
	   }
	 waitingpre(l);

 }
 void processes::RoundRobin(linkedList &l)
 {
	 l.sort(1);
	 linkedList::print_as_RR(l);
 }
