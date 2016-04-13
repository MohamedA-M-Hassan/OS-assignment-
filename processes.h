#ifndef process_p
#define process_p
#include <string>
#include <iostream>
class linkedList;
class processes
{
private:
	std::string name;
	float arrival_time;
	float burst;
	float priority;
	float dep ;
	float timeTaked;
public:

	void set_name_of_process(std::string n);
	std::string get_name_of_process();
	void set_arrival_time(float t);
	float get_arrival_time();
	void set_burst(float b);
	float get_burst();
	void set_priority(float pri);
	float get_priority();
	void set_dep(float d);
	float get_dep();
	void set_timeTaked(float t);
	float get_timeTaked();
	static void create_Process(linkedList &l);
	static void waitingpre(linkedList &l);
	static void waitingNon(linkedList &l);
	static void FCFS(linkedList &l);
	static void shortJobNon(linkedList &l);
	static void shortJobPre(linkedList &l);
	static void PriorityNon(linkedList &l);
	static void PriorityPre(linkedList &l);
	static void RoundRobin(linkedList &l);



};
#endif