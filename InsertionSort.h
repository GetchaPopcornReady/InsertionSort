#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <string>

class InsertionSort {
private:
	int size;
	struct Node {
		int value;
		Node *next;
	};
	Node *head;
	Node *tail;
	void append(int x);
	bool input(std::string);
	bool output(std::string);
	void sort();
public:
	InsertionSort();
	void filesort(std::string, std::string);
};

#endif
