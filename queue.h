#pragma once
#include "DLL.h" 
#include "DLL.cpp" 

struct Process {
	float arrival_time, execution_time;
	short priority, id;
	Process(int a = 0) {}
	float operator [](short a) {
		switch (a) {
		case 0:return arrival_time;
		case 1:return priority;
		case 2:return execution_time;
		case 3:return id;
		default:return 100; //constant filler, means it will not order 
		}
	}
};

class queue
{
	DLL <Process> que;
	node <Process> *temp_ptr;
	short mood; //0 == FCFS , 1 == priority , 2 == shortest job
public:
	queue(short m = 0);
	void push(Process);
	Process pop(); 
	void set_mood(short a);
	Process peek(bool head);
	bool isempty(); 
};

