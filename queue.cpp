#include "queue.h"
queue::queue(short m) :mood(m){}

void queue::push(Process data) {
	if (que[0] == NULL) {
		que.add(data);
	}
	else {
		temp_ptr = que[0];
		int index = 0;
		while (temp_ptr != NULL && data[mood] >= temp_ptr->data[mood]) {
			temp_ptr = temp_ptr->next_ptr;
			index++;
		}
		que.insertAt(index, data);
	}
}

Process queue::pop() {
	return que.removeAt(0);
}

void queue::set_mood(short a) {
	mood = a;
}

Process queue::peek(bool head) {
	return que.peek(head);
}

bool queue::isempty() {
	return !que.get_size();
}