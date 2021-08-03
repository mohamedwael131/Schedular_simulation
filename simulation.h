#pragma once
#include "queue.h" 

struct status {
	short id; float start_time, end_time;
	status(int a = 0) {}
};

class simulation
{
	queue arrival_queue;
	queue running_queue; //mood depends on the simulation we are running 
	float TIMENOW; float CPU_TIME;
	Process CPU;
	DLL <float> windows;
	DLL <status> result; 
public:
	simulation();
	void get_input(Process *, short);
	void FCFS();
	void RR(float q);
	void sjf_pri_non(short);
	void sjf_pri_pre(short);
	DLL <status> get_result();
};

