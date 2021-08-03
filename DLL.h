#pragma once
#define NULL 0
template <typename dataType>
struct node {
	dataType data;
	node <dataType> *next_ptr, *prev_ptr;
	node() {
		next_ptr = prev_ptr = NULL;
		data = NULL;
	}
};

template <typename dataType>
class DLL
{
private:
	node <dataType> *start_ptr, *end_ptr, *temp_ptr;
	int size;
public:
	DLL();
	node <dataType>* &operator[](int);
	void add(dataType, bool end = 1);
	dataType peek(bool head);
	dataType pop(bool end);
	void insertAt(int, dataType);
	dataType removeAt(int);
	void clear(); 
	int get_size();
};
