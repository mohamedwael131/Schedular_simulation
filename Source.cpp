#include <iostream>
#include "simulation.h" 
using namespace std;

int main() {
	simulation test; //initiate a simulation object;
	Process arr[4]; //initiate an array of processes; 
	arr[0].arrival_time = 0; arr[0].execution_time = 3; arr[0].priority = 3;
	arr[1].arrival_time = 0; arr[1].execution_time = 2; arr[1].priority = 2;
	arr[2].arrival_time = 3; arr[2].execution_time = 1; arr[2].priority = 5;
	arr[3].arrival_time = 30; arr[3].execution_time = 4; arr[3].priority = 32;
	test.get_input(arr, 4); // configuring the simulation object with the input array or processes; 
	test.FCFS(); //running first come first serve;
	//test.RR(#num) //Round robin with quantum time of #num
	//test.sjf_pri_non(#num) non-preemption shortest job first or priority (#num == 1) --> priority , (#num == 2) -->sjf
	//test.sjf_pri_pre(#num) preemptive shortest job first or priority     (#num == 1) --> priority , (#num == 2) -->sjf
	test.get_result(); // getting the result in the form of a doubly linked list which can be looped over for the values within

}