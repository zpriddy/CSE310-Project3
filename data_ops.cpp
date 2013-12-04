/******************************************************************************
* data_ops.cpp
* 
* Date:   2013-11-26 22:38:18
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/
#include <iostream>
#include <iomanip>

#include "data_ops.h"
#include "vertex.h"



using namespace std;



EDGE_T make_edge(VERTEX_TREE_T &tree , int v1, int v2, int cost)
{
	EDGE_T RETURN_EDGE;


	RETURN_EDGE.v1   = find_vertex_by_id(tree, v1);
	RETURN_EDGE.v2   = find_vertex_by_id(tree, v2);
	RETURN_EDGE.cost = cost;
	RETURN_EDGE.root = 0;

	return RETURN_EDGE;
}

void set_edge_root(EDGE_T edge, EDGE_T root)
{
	edge.root = &root; //Pointer to the root edge
}

EDGE_T* build_edge_set(VERTEX_TREE_T &tree, VERTEX_T* vertex_set, int** set_table)
{
	EDGE_T* EDGE_SET = new EDGE_T[set_table[0][1]];

	for(int i = 1 ; i <= set_table[0][0] ; i++)
	{
		vertex_set[i-1] = make_vertex_node(i);
		insert_to_vertex_tree(tree, vertex_set[i-1]);
	}


	for(int i = 1 ; i <= set_table[0][1] ; i++)
	{
		EDGE_SET[i-1] = make_edge(tree, set_table[i][0], set_table[i][1], set_table[i][2]);
	}

	return EDGE_SET;
}

void print_edge_set(EDGE_T* &set, int size)
{
	cout << "|--------------------|\n";
	cout << "|  V1  |  V2  | COST |\n";
	cout << "|--------------------|\n";
	for(int i = 0 ; i < size ; i++)
	{

		cout << "|" << setw(4) << set[i].v1->ID << "  |" << setw(4) << set[i].v2->ID << "  |" << setw(4) << set[i].cost << "  |\n";
		cout << "|--------------------|\n";
	}
}

