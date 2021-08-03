#include "DLL.h"

template <typename dataType> 
DLL<dataType>::DLL()
{
	start_ptr = end_ptr = NULL;
	size = NULL;
}

template <typename dataType>
void DLL<dataType>::add(dataType data, bool end = 1) {
	if (end_ptr == NULL) {
		end_ptr = start_ptr = new node <dataType>;
		end_ptr->data = data;
	}
	else {
		if (end) {
			end_ptr->next_ptr = new node <dataType>;
			end_ptr->next_ptr->prev_ptr = end_ptr;
			end_ptr = end_ptr->next_ptr;
			end_ptr->data = data;
		}
		else {
			start_ptr->prev_ptr = new node <dataType>;
			start_ptr->prev_ptr->next_ptr = start_ptr;
			start_ptr = start_ptr->prev_ptr;
			start_ptr->data = data;
		}
	}
	size++;
}

template <typename dataType>
dataType DLL<dataType>::pop(bool end) {
	dataType val = NULL;
	if (size > 1) {
		if (end) {
			val = end_ptr->data;
			end_ptr = end_ptr->prev_ptr;
			delete end_ptr->next_ptr;
			end_ptr->next_ptr = NULL;
		}
		else {
			val = start_ptr->data;
			start_ptr = start_ptr->next_ptr;
			delete start_ptr->prev_ptr;
			start_ptr->prev_ptr = NULL;
		}
	}
	else if (size == 1) {
		val = end_ptr->data;
		delete end_ptr;
		end_ptr = start_ptr = NULL;
	}
	size--;
	return val;
}

template <typename dataType>
void DLL<dataType>::insertAt(int index, dataType data) {
	if (index >= size) {
		add(data);
	}
	else if (index <= 0) {
		add(data, 0);
	}
	else {
		temp_ptr = start_ptr;
		node <dataType> *new_ptr = new node <dataType>;
		new_ptr->data = data;
		int i = 0;
		while (i < index) {
			temp_ptr = temp_ptr->next_ptr;
			i++;
		}
		temp_ptr = temp_ptr->prev_ptr;
		new_ptr->next_ptr = temp_ptr->next_ptr;
		new_ptr->prev_ptr = temp_ptr;
		temp_ptr->next_ptr = new_ptr;
		new_ptr->next_ptr->prev_ptr = new_ptr;
		size++;
	}
}

template <typename dataType>
dataType DLL<dataType>::removeAt(int index) {
	dataType val;
	if (index >= size - 1) {
		return pop(1);
	}
	else if (index <= 0) {
		return pop(0);
	}
	else {
		if (index <= size / 2) {
			temp_ptr = start_ptr;
			for (int i = 0; i < index; i++) {
				temp_ptr = temp_ptr->next_ptr;
			}
		}
		else {
			temp_ptr = end_ptr;
			for (int i = 0; i < size - index; i++) {
				temp_ptr = temp_ptr->prev_ptr;
			}
		}
		val = temp_ptr->data;
		temp_ptr->prev_ptr->next_ptr = temp_ptr->next_ptr;
		temp_ptr->next_ptr->prev_ptr = temp_ptr->prev_ptr;
		delete temp_ptr;
		size--;
		return val;
	}
}

template <typename dataType>
int DLL<dataType>::get_size() {
	return size;
}

template <typename dataType>
dataType DLL<dataType>::peek(bool head) {
	if (end_ptr != NULL) {
		if (head) {
			return end_ptr->data;
		}
		else {
			return start_ptr->data;
		}
	}
	else {
		return NULL;
	}
}

template <typename dataType>
node <dataType>* &DLL<dataType>::operator[](int n) {
	temp_ptr = start_ptr;
	int i = 0, end;
	if (n < size) {
		end = n;
	}
	else {
		end = size - 1;
	}
	while (i < end) {
		temp_ptr = temp_ptr->next_ptr;
		i++;
	}
	return temp_ptr;
}

template <typename dataType>
void DLL<dataType>::clear() {
	while (get_size()) {
		DLL::pop(1); 
	}
}
