#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "InsertionSort.h"

using namespace std;

/*
 * Constructor.
 */
InsertionSort::InsertionSort()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

/*
 * Appends an integer to the end of the list.
 */
void InsertionSort::append(int x)
{
	if (head == NULL) //If list is empty, set head and tail.
	{
		tail = new Node;
		tail->value=x;
		tail->next=NULL;
		head = tail;
		size++;
		return;
	} //Otherwise, append data to tail.
	tail->next= new Node;
	tail = tail->next;
	tail->value=x;
	tail->next=NULL;
	size++;
	return;
}

/*
 * Read list from a file.
 */
bool InsertionSort::input(std::string filename)
{
	std::ifstream infile(filename.c_str()); //Open file.

	if (!infile.is_open()) //Check if file opened.
	{
		std::cout << filename  << " could not be opened." << std::endl;
		return false;
	}

	std::string line;
	while(getline(infile, line)) //Read lines from file and append each integer.
	{
		int value = std::atoi(line.c_str());
		InsertionSort::append(value);
	}

	infile.close(); //Close the file.

	return true;
}

/*
 * Print list to file.
 */
bool InsertionSort::output(std::string filename)
{
	std::ofstream outfile(filename.c_str()); //Open file.

	if (!outfile.is_open()) //Check if file opened.
	{
		std::cout << filename  << " could not be opened." << std::endl;
		return false;
	}
	
	Node *current = head;
	if (current == NULL) //If list is empty, do nothing.
	{
		return true;
	}

	while(current != NULL) //Otherwise, print list to file line by line.
	{
		outfile << current->value << std::endl;
		current = current->next;
	}
	
	outfile.close(); //Close the file.
	
	return true;
}

/*
 * This insertion sort, starts at the head rather than tail as the linked list is singly linked only. 
 * Sorting from the back to the front is not necessary as a linked list does not require the same inplace
 * sorting that arrays require.
 */
void InsertionSort::sort()
{
	if (size > 1) { //If size less than two, no sorting necessary.
		Node *unsorted = head->next; //Head of unsorted values.
		Node *sorted = head; //Head of sorted values.
		sorted->next= NULL;

		while(unsorted != NULL) //Insertion sort
		{
			Node *temp = unsorted;
			unsorted = temp->next;
			temp->next = NULL;
			
			if (temp->value < sorted->value) //Check temp value replaces first sorted value.
			{
				temp->next = sorted;
				sorted = temp;
			} else { //Otherwise read through the list until insertion point is found.
				Node *current = sorted;

				while (current->next != NULL && current->next->value < temp->value)
				{
					current = current->next;
				}
				temp->next = current->next; //Insert.
				current->next = temp;
			}
		}
		head = sorted; //Set new head.

		Node *current = head; //Find new tail.
		while (current->next != NULL)
			current = current->next;
		tail = current; //Set tail.
	}
	return;
}

/*
 * Read data from a file, sort it in increasing order, and output to a file.
 */
void InsertionSort::filesort(std::string filein, std::string fileout)
{
	if(!InsertionSort::input(filein)) //Input.
	{
		std::cout << "Sort failed." << std::endl;
		return;
	}
	
	InsertionSort::sort(); //Sort.

	if(!InsertionSort::output(fileout)) //Output.
	 {
		std::cout << "Sort failed." << std::endl;
		return;
	}

	cout << "Sort complete." << endl;
	return;
}

