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

struct EDGE_T
{
	int v1; //From vertex
	int v2; //To Vertex
	int cost; //Cost of edge
	EDGE_T* root; //Root of set structure
};

EDGE_T make_edge(int v1, int v2, int cost);
void set_edge_root(EDGE_T edge, EDGE_T root);
EDGE_T* build_edge_set(int** set_table);



#endif