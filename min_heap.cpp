/******************************************************************************
* min_heap.cpp
* 
* Date:   2013-11-24 19:13:32
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/
#include <cmath>
#include <stdio.h>
#include <iostream>
//#include <cstdlib>

using namespace std;

#include "min_heap.h"
#include "data_ops.h"

HEAP::HEAP(int h_capacity, int h_size)
{
	capacity = h_capacity;
	edges = new EDGE_T[h_capacity];
	size = h_size;
}


HEAP InitializeHeap(int h_capacity)
{

    HEAP return_heap(h_capacity, 0);
    return return_heap;
}

/******************************************************************************
* FUNCTION: BuildHeap(HEAP &i_heap, EDGE_T Edge_set[], int Set_Size, heap_type type)
* 
* DESC: Builds the heap with the inputed array of Elements
*
* Calls: InsertToHeap(HEAP, Element, heap_type)
******************************************************************************/
void BuildHeap(HEAP &i_heap, EDGE_T Edge_set[], int Set_Size, heap_type type)
{
	
	int init_size = i_heap.get_size();


	//Insert the elements into the Heap in the way that they were given
	for (int i = init_size ; i < Set_Size+init_size && i < i_heap.get_capacity() ; i++ )
	{

		InsertToHeap(i_heap, Edge_set[i - init_size], type);
	}

	//Sort the heap
	for(int i=floor(i_heap.get_size()/2); i>= 1 ; i--)
	{
		cout << "i = " << i << "\n";
		Heapify(i_heap, i, type);
	}

}

/******************************************************************************
* FUNCTION: InsertToHeap(HEAP &i_heap, EDGE_T i_edge, heap_type type)
*
* DESC: Inserts the Element into the array and calls Heapify
*
* Calls: 
******************************************************************************/
void InsertToHeap(HEAP &i_heap, EDGE_T i_edge, heap_type type)
{
	i_heap.inc_size();
	//i_heap.set_heap_element(i_heap.get_size(), i_edge);
	if(i_heap.get_size() >= 1)
	{
	for(int i = i_heap.get_size() ; i > 0 ; i--)
	{
		i_heap.set_heap_element(i, i_heap.get_edge(i-1));
	}
	i_heap.set_heap_element(1, i_edge);
	}
	else
		i_heap.set_heap_element(1, i_edge);
	cout << i_edge.cost << "\n"; 
}

/******************************************************************************
* FUNCTION: Heapify(HEAP &i_heap, int element)
*
* DESC: Heapifys the heap starting at the element# provided 
*
* Calls: Heapify(HEAP, element#)
******************************************************************************/
void Heapify(HEAP &i_heap, int pos, heap_type type)
{
	int left_key, right_key, largest_pos, smallest_pos;
	int current_key = i_heap.get_edge(pos).cost;
	int left_pos = i_heap.get_left_child_pos(pos);
	int right_pos = i_heap.get_right_child_pos(pos);

	switch(type)
	{
		case min_heap_t:

			smallest_pos = pos;

			if(right_pos <= i_heap.get_size())
			{
				right_key = i_heap.get_right_child_edge(pos).cost;
				left_key = i_heap.get_left_child_edge(pos).cost;

				if(right_key < i_heap.get_edge(smallest_pos).cost)
					smallest_pos = right_pos;
				if(left_key < i_heap.get_edge(smallest_pos).cost)
					smallest_pos = left_pos;

			}	
/*
			if(left_pos <= i_heap.get_size())
			{
				left_key = i_heap.get_left_child_edge(pos).cost;

				if(left_key < i_heap.get_edge(smallest_pos).cost)
					smallest_pos = left_pos;
			}
*/








			if(smallest_pos != pos)
			{
				EDGE_T smallest_edge = i_heap.get_edge(smallest_pos);
				i_heap.set_heap_element(smallest_pos, i_heap.get_edge(pos));
				i_heap.set_heap_element(pos, smallest_edge);
				Heapify(i_heap, smallest_pos, type);
			}


		/****************************
		* END OF MIN HEAP
		****************************/
		break;

		case max_heap_t:
		


			if(left_pos <= i_heap.get_size())
			{
				left_key = i_heap.get_left_child_edge(pos).cost;

				if(left_key > current_key)
					largest_pos = left_pos;
				else
					largest_pos = pos;
			}
			else
				largest_pos = pos;
			if(right_pos <= i_heap.get_size())
			{
				right_key = i_heap.get_right_child_edge(pos).cost;

				if(right_key > i_heap.get_edge(largest_pos).cost)
					largest_pos = right_pos;
			}

			if(largest_pos != pos)
			{
				EDGE_T largest_edge = i_heap.get_edge(largest_pos);
				i_heap.set_heap_element(largest_pos, i_heap.get_edge(pos));
				i_heap.set_heap_element(pos, largest_edge);
				Heapify(i_heap, largest_pos, type);
			}
		

		/****************************
		* END OF MAX HEAP
		****************************/
		break;
	}
}

void print_heap(HEAP &i_heap)
{
	for(int i = 1 ; i <= i_heap.get_size() ; i++)
	{
		cout << i_heap.get_edge(i).cost << "\n";
	}
}