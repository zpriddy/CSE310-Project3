/******************************************************************************
* min_heap.h
* 
* Date:   2013-11-24 19:13:42
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/

#include <climits>


#include "data_ops.h"

#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

typedef enum
{
	min_heap_t = 0,
	max_heap_t = 1
}heap_type;

class HEAP
{
	public:
		HEAP(int h_capacity, int h_size); //Make Heap with capacity


		//Functions To Read Values
		int get_size() {return size;}
		int get_capacity(){ return capacity;}
		EDGE_T get_edge(int pos){return edges[pos-1];}

		//Larger Functions
		int get_right_child_pos(int pos)
		{
			if(2*pos+1 <= this->size)
				return 2*pos+1;
			else
				return INT_MAX;

		}
		EDGE_T get_right_child_edge(int pos)
		{
			return this->get_edge(2*pos+1);
		}
		int get_left_child_pos(int pos)
		{
			if(2*pos <= this->size)
				return 2*pos;
			else
				return INT_MAX;

		}
		EDGE_T get_left_child_edge(int pos)
		{
			return this->get_edge(2*pos);
		}


		//Functions To Set Values
		void set_size(int n) {size = n;}
		void inc_size() {size++;}
		void dec_size() {size--;}

		//Larget Functions
		void set_heap_element(int position, EDGE_T edge_element)
		{
			this->edges[position-1] = edge_element;
		}


	private:
		int capacity;
		int size;
		EDGE_T *edges;
};

HEAP InitializeHeap(int h_capacity); //Initalize New Heap
void BuildHeap(HEAP &i_heap, EDGE_T Edge_set[], int Set_Size, heap_type type);
void InsertToHeap(HEAP &i_heap, EDGE_T i_edge, heap_type type);
void Heapify(HEAP &i_heap, int pos, heap_type type);
void print_heap(HEAP &i_heap);
EDGE_T DeleteTopElement(HEAP &i_heap, heap_type type);
#endif