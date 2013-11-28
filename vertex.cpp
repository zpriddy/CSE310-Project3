/******************************************************************************
* vertex.cpp
* 
* Date:   2013-11-27 22:02:47
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


using namespace std;

#include "vertex.h"
#include "data_ops.h"


VERTEX_T make_vertex_node(int ID)
{
	VERTEX_T RETURN_VERTEX;

	RETURN_VERTEX.ID = ID;
	RETURN_VERTEX.ROOT = 0;
	RETURN_VERTEX.DEPTH = 0;

	return RETURN_VERTEX;
}

void find_depth(VERTEX_T leaf_vertex)
{
	int depth = 0;
	VERTEX_T * ptr = &leaf_vertex;
	while(ptr->DEPTH == 0 && ptr->ROOT != 0)
	{
		//cout << "DEPTH : " << depth << "\n";
		depth--;
		ptr = ptr->ROOT;
	}
	if(ptr->DEPTH > depth)
		ptr->DEPTH = depth;
}

void set_vertex_root(VERTEX_T &vertex, VERTEX_T &root)
{
	vertex.ROOT = &root;


	if(root.ROOT == 0)
	{
		root.DEPTH = -1;
	}
	if(vertex.DEPTH != 0)
	{
		vertex.ROOT->DEPTH = vertex.DEPTH-1;
		vertex.DEPTH = 0;

	}


}

void set_vertex_root(VERTEX_TREE_T &tree , int vertex, int root)
{
	set_vertex_root(*find_vertex_by_id(tree, vertex), *find_vertex_by_id(tree, root));
}

void set_vertex_root(EDGE_T USE THE V1 and V2 from EDGE TO MAKE ROOT)

VERTEX_TREE_T make_vertex_tree(int number_of_vertex)
{
	VERTEX_TREE_T TREE;
	TREE.TREE = new VERTEX_T*[number_of_vertex];
	TREE.number_in_tree = 0;


	return TREE;
}

void insert_to_vertex_tree(VERTEX_TREE_T &tree, VERTEX_T &vertex)
{
	tree.TREE[tree.number_in_tree] = &vertex;
	tree.number_in_tree++;
}

void print_tree(VERTEX_TREE_T tree)
{
	for(int i = 0 ; i < tree.number_in_tree ; i++)
	{
		find_depth(*tree.TREE[i]);
	}
	for(int i = 0 ; i < tree.number_in_tree ; i++)
	{
		if(tree.TREE[i]->DEPTH < 0)
		{
			cout << tree.TREE[i]->DEPTH << ", ";
		}
		else if (tree.TREE[i]->ROOT == 0)
		{
			cout << 0 << ", ";
		}
		else 
		{
			cout << tree.TREE[i]->ROOT->ID << ", "; 
		}
	}
}


VERTEX_T* find_vertex_by_id(VERTEX_TREE_T &tree ,int ID)
{
	for(int i=0 ; i < tree.number_in_tree ; i++)
	{
		if(tree.TREE[i]->ID == ID)
			return tree.TREE[i];
	}
	return NULL;
}


void print_vertex_tree(VERTEX_T &leaf_vertex)
{
	
	if(leaf_vertex.ROOT > 0 )
	{
		print_vertex_tree(*leaf_vertex.ROOT);
	}
	else
	{
		cout << "PRINT VERTEX\n";
		cout << "     ^\n" << "     |\n";
	}

	cout << "ID : " << leaf_vertex.ID << "  DEPTH : " << leaf_vertex.DEPTH <<  "\n";
}



