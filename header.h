#ifndef HEADER_H
#define HEADER_H
using namespace std;

struct NODE{
	string name;
	NODE* next;
};

struct dual_node{
	struct NODE* tail = NULL;
	
	void insert(string n);
	void delete_last();
	void print();
};
#endif
