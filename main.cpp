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

// User Variables
string input_file  = "data.txt";
string output_file = "output.txt";


int main(int argc, char** argv) 
{

	//Read the data file into a 2D array
	int** data = ReadInputFile(input_file);
	printTable(data, data[0][1]+1, 3);
	int data_set_size = data[0][1];
	EDGE_T* edge_set = build_edge_set(data);
	HEAP min_heap = InitializeHeap(data_set_size);
	BuildHeap(min_heap, edge_set, data_set_size, min_heap_t);
	cout << "PRINT HEAP : \n";
	print_heap(min_heap);
	//for(int i = 0 ; i < data_set_size ; i ++ )
	//{
	//	cout << edge_set[i].cost << "\n";
	//}
	//cout << "HEAP SIZE : " << min_heap.get_size() << "\n";

	
	

}



