/******************************************************************************
* data_ops.h
* 
* Date:   2013-11-26 22:38:28
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/

#ifndef DATA_OPS_H_
#define DATA_OPS_H_

#include "vertex.h"

struct EDGE_T
{
	VERTEX_T* v1; //From vertex
	VERTEX_T* v2; //To Vertex
	int cost; //Cost of edge
	EDGE_T* root; //Root of set structure
};

EDGE_T make_edge(VERTEX_TREE_T &tree , int v1, int v2, int cost);
void set_edge_root(EDGE_T edge, EDGE_T root);
EDGE_T* build_edge_set(VERTEX_TREE_T &tree, VERTEX_T* vertex_set, int** set_table);
void print_edge_set(EDGE_T* &set, int size);



#endif