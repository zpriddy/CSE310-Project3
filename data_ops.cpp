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


#include "data_ops.h"


EDGE_T make_edge(int v1, int v2, int cost)
{
	EDGE_T RETURN_EDGE;

	RETURN_EDGE.v1   = v1;
	RETURN_EDGE.v2   = v2;
	RETURN_EDGE.cost = cost;
	RETURN_EDGE.root = 0;

	return RETURN_EDGE;
}

void set_edge_root(EDGE_T edge, EDGE_T root)
{
	edge.root = &root; //Pointer to the root edge
}

EDGE_T* build_edge_set(int** set_table)
{
	EDGE_T* EDGE_SET = new EDGE_T[set_table[0][1]];


	for(int i = 1 ; i <= set_table[0][1] ; i++)
	{
		EDGE_SET[i-1] = make_edge(set_table[0][0], set_table[i][1], set_table[i][2]);
	}

	return EDGE_SET;
}