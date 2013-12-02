/******************************************************************************
* vertex.h
* 
* Date:   2013-11-27 22:02:56
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/


#ifndef VERTEX_H_
#define VERTEX_H_

//#include "data_ops.h"


struct VERTEX_T
{
	int ID;
	struct VERTEX_T *ROOT;
	int DEPTH;
};

struct VERTEX_TREE_T
{
	VERTEX_T* (*TREE);
	int number_in_tree;
};


VERTEX_T make_vertex_node(int ID);
void set_vertex_root(VERTEX_T &vertex, VERTEX_T &root);
void set_vertex_root(VERTEX_TREE_T &tree , int vertex, int root);
//void set_vertex_root_from_edge(EDGE_T edge);
void print_vertex_tree(VERTEX_T &leaf_vertex);
VERTEX_TREE_T make_vertex_tree(int number_of_vertex);
void insert_to_vertex_tree(VERTEX_TREE_T &tree, VERTEX_T &vertex);
void print_tree(VERTEX_TREE_T tree);
VERTEX_T* find_vertex_by_id(VERTEX_TREE_T &tree ,int ID);
bool vertex_mst(VERTEX_TREE_T tree);


#endif