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
	make_new_output(output_file);
	//Read the data file into a 2D array
	int count = 0;
	int outputmode;
	int** data = ReadInputFile(input_file);
	int data_set_size = data[0][1];
	EDGE_T* mst_set = new EDGE_T[data_set_size];
	VERTEX_T* vertex_set = new VERTEX_T[data[0][0]];
	VERTEX_TREE_T vertex_tree = make_vertex_tree(data_set_size);
	EDGE_T* edge_set = build_edge_set(vertex_tree, vertex_set, data);
	HEAP min_heap = InitializeHeap(data_set_size);
	BuildHeap(min_heap, edge_set, data_set_size, min_heap_t);

	int*  old_vertex_root_id = new int [data_set_size];
	int* current_vertex_root_id = new int[data_set_size];


	print_to_output_file(output_file, vertex_tree, min_heap, mst_set, 0, vertex_tree.number_in_tree);
	set_vertex_set_id_array(vertex_tree, old_vertex_root_id);
	while(!vertex_mst(vertex_tree))
	{
		
		EDGE_T TEMP = DeleteTopAndSetRoot(min_heap, vertex_tree, min_heap_t);
		set_vertex_set_id_array(vertex_tree, current_vertex_root_id);
		if(arrays_same(old_vertex_root_id, current_vertex_root_id, data_set_size))
		{
			outputmode = 2;

		}
		else
		{
			mst_set[count] = TEMP;
			count++;
			outputmode = 1;
		}
		
		
		print_to_output_file(output_file, vertex_tree, min_heap, mst_set, outputmode, count);
		set_vertex_set_id_array(vertex_tree, old_vertex_root_id);
		
	}

	cout << "Done! \nOutput File: " << output_file.c_str() << "\n";


}



