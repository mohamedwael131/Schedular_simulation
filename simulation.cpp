#include "simulation.h"



simulation::simulation()
{
	arrival_queue.set_mood(0); //explicitly setting the arrival_queue's mood to FCFS
}

void simulation::get_input(Process *arr, short size) {
	float max_time = 0;
	for (int i = 0; i < size; i++) {
		arr[i].id = i;
		windows.add(arr[i + 1].arrival_time - arr[i].arrival_time);
		arrival_queue.push(arr[i]);
		max_time += arr[i].execution_time;
	}
	CPU_TIME = max_time;
	windows.pop(1);
	windows.add(float(unsigned long(-1)));
}

void simulation::FCFS() {
	result.clear();
	TIMENOW = arrival_queue.peek(0).arrival_time;
	running_queue.set_mood(0);
	status temp;
	float cpu_time = 0;
	while (cpu_time < CPU_TIME) {
		while (TIMENOW >= arrival_queue.peek(0).arrival_time && !arrival_queue.isempty()) {
			running_queue.push(arrival_queue.pop());
		}
		if (!running_queue.isempty()) {
			CPU = running_queue.pop();
			TIMENOW = (CPU.arrival_time > TIMENOW) ? CPU.arrival_time : TIMENOW;
			temp.id = CPU.id;
			temp.start_time = TIMENOW;
			TIMENOW += CPU.execution_time; cpu_time += CPU.execution_time;
			temp.end_time = TIMENOW;
			result.add(temp); 
		}
		else {
			TIMENOW = arrival_queue.peek(0).arrival_time;
		}
	}
}

void simulation::RR(float q) {
	result.clear();
	running_queue.set_mood(0);
	float cpu_time = 0;
	status temp; float t;
	TIMENOW = arrival_queue.peek(0).arrival_time;
	while (cpu_time < CPU_TIME) {
		while (TIMENOW >= arrival_queue.peek(0).arrival_time && !arrival_queue.isempty()) {
			running_queue.push(arrival_queue.pop());
		}
		if (!running_queue.isempty()) {
			CPU = running_queue.pop();
			TIMENOW = (CPU.arrival_time > TIMENOW) ? CPU.arrival_time : TIMENOW;
			temp.start_time = TIMENOW;
			temp.id = CPU.id;
			t = (CPU.execution_time < q) ? CPU.execution_time : q;
			TIMENOW += t; CPU.execution_time -= t;
			cpu_time += t;
			temp.end_time = TIMENOW;
			result.add(temp); 
			if (CPU.execution_time > 0) {
				CPU.arrival_time = TIMENOW;
				running_queue.push(CPU);
			}
		}
		else {
			TIMENOW = arrival_queue.peek(0).arrival_time;
		}
	}
}

//select == 1 priority , select == 2 SJF
void simulation::sjf_pri_non(short select) {
	result.clear();
	running_queue.set_mood(select);
	float cpu_time = 0;
	status temp;
	TIMENOW = arrival_queue.peek(0).arrival_time;
	while (cpu_time < CPU_TIME) {
		while (TIMENOW >= arrival_queue.peek(0).arrival_time && !arrival_queue.isempty()) {
			running_queue.push(arrival_queue.pop());
		}
		if (!running_queue.isempty()) {
			CPU = running_queue.pop();
			TIMENOW = (CPU.arrival_time > TIMENOW) ? CPU.arrival_time : TIMENOW;
			temp.id = CPU.id;
			temp.start_time = TIMENOW;
			TIMENOW += CPU.execution_time; cpu_time += CPU.execution_time;
			temp.end_time = TIMENOW;
			result.add(temp);
		}
		else {
			TIMENOW = arrival_queue.peek(0).arrival_time;
		}
	}
}

//select == 1 priority , select == 2 SJF
void simulation::sjf_pri_pre(short select) {
	result.clear();
	float window_size = windows.pop(0);
	while (window_size == 0) {
		window_size = windows.pop(0);
	}
	running_queue.set_mood(select);
	float cpu_time = 0;
	status temp; float t;
	TIMENOW = arrival_queue.peek(0).arrival_time;
	while (cpu_time < CPU_TIME) {
		while (TIMENOW >= arrival_queue.peek(0).arrival_time && !arrival_queue.isempty()) {
			running_queue.push(arrival_queue.pop());
		}
		if (!running_queue.isempty()) {
			CPU = running_queue.pop();
			TIMENOW = (CPU.arrival_time > TIMENOW) ? CPU.arrival_time : TIMENOW;
			temp.start_time = TIMENOW;
			temp.id = CPU.id; 
			t = (CPU.execution_time > window_size) ? window_size : CPU.execution_time;
			TIMENOW += t; CPU.execution_time -= t; window_size -= t;
			while (window_size == 0) {
				window_size = windows.pop(0);
			}
			cpu_time += t;
			temp.end_time = TIMENOW;
			result.add(temp); 
			if (CPU.execution_time > 0) {
				CPU.arrival_time = TIMENOW;
				running_queue.push(CPU);
			}
		}
		else {
			TIMENOW = arrival_queue.peek(0).arrival_time;
		}
	}
}

DLL <status> simulation::get_result() {
	return result; 
}