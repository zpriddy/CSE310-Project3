/******************************************************************************
* file_io.h
* 
* Date:   2013-11-24 19:09:06
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/
#include <fstream>

#ifndef FILE_IO_H
#define FILE_IO_H

#include "min_heap.h"
#include "vertex.h"

using namespace std;

int** ReadInputFile(string file_name);
void make_new_output(string filename);
void print_to_output_file(string filename, VERTEX_TREE_T tree, HEAP &i_heap, EDGE_T* mst_set, int run, int mst_size);

#endif