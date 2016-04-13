#ifndef process_p
#define process_p
#include <string>
#include <iostream>
class linkedList;
class processes
{
private:
	std::string name;
	int arrival_time;
	int burst;
	int priority;
public:

	void set_name_of_process(std::string n);
	std::string get_name_of_process();
	void set_arrival_time(int t);
	int get_arrival_time();
	void set_burst(int b);
	int get_burst();
	void set_priority(int pri);
	int get_priority();
	static void create_Process(linkedList &l);
	static void FCFS(linkedList &l);
	static void shortJobNon(linkedList &l);
	static void shortJobPre(linkedList &l);
	static void PriorityNon(linkedList &l);
	static void PriorityPre(linkedList &l);
	static void RoundRobin(linkedList &l);



};
#endif