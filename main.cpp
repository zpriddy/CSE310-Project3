/******************************************************************************
* main.cpp
* 
* Date:   2013-11-24 19:07:37
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/

// General Includes
 #include <stdio.h>
 #include <fstream>
 #include <iostream>
 #include <cstdlib>

using namespace std;

#include "file_io.h"
#include "2d_array.h"
#include "data_ops.h"
#include "min_heap.h"
#include "vertex.h"

// User Variables
string input_file  = "data.txt";
string output_file = "output.txt";


int main(int argc, char** argv) 
{

	//Read the data file into a 2D array
	int** data = ReadInputFile(input_file);
	printTable(data, data[0][1]+1, 3);
	int data_set_size = data[0][1];
	VERTEX_T* vertex_set = new VERTEX_T[data[0][0]];
	VERTEX_TREE_T vertex_tree = make_vertex_tree(data_set_size);
	EDGE_T* edge_set = build_edge_set(vertex_tree, vertex_set, data);

	HEAP min_heap = InitializeHeap(data_set_size);
	BuildHeap(min_heap, edge_set, data_set_size, min_heap_t);
	cout << "PRINT HEAP : \n";
	print_heap(min_heap);
	//print_edge_set(edge_set, data_set_size);

/*
	VERTEX_T v1 = make_vertex_node(1);
	VERTEX_T v2 = make_vertex_node(2);
	VERTEX_T v3 = make_vertex_node(3);
	VERTEX_T v4 = make_vertex_node(4);
	VERTEX_T v5 = make_vertex_node(5);

	
	insert_to_vertex_tree(vertex_tree, v1);
	insert_to_vertex_tree(vertex_tree, v2);
	insert_to_vertex_tree(vertex_tree, v3);
	insert_to_vertex_tree(vertex_tree, v4);
	insert_to_vertex_tree(vertex_tree, v5);

	set_vertex_root(v1, v2);
	set_vertex_root(v3, v2);
	set_vertex_root(v4, v2);
*/
	//set_vertex_root(*find_vertex_by_id(vertex_tree, 1), *find_vertex_by_id(vertex_tree, 2));
	//set_vertex_root(vertex_tree, 1, 3);
	while(!vertex_mst(vertex_tree))
	{
		DeleteTopAndSetRoot(min_heap, vertex_tree, min_heap_t);
		print_heap(min_heap);
		print_tree(vertex_tree);
	}
	cout << "DONISH";
	while(min_heap.get_size() >= 1)
	{
		DeleteTopAndSetRoot(min_heap, vertex_tree, min_heap_t);
		print_heap(min_heap);
		print_tree(vertex_tree);
	}

	//DeleteTopAndSetRoot(min_heap, vertex_tree, min_heap_t);
	print_heap(min_heap);
	print_tree(vertex_tree);
	
	//for(int i = 0 ; i < data_set_size ; i ++ )
	//{
	//	cout << edge_set[i].cost << "\n";
	//}
	//cout << "HEAP SIZE : " << min_heap.get_size() << "\n";

	
	

}



