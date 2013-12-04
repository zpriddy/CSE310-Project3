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

int vertex_find(VERTEX_T &vertex)
{
	int ID = vertex.ID;

	if(vertex.ROOT != 0)
		ID = vertex_find(*vertex.ROOT);

	return ID;
}

// DO union(v1, v2)
void vertex_union(VERTEX_TREE_T &tree, VERTEX_T &vertex_v1, VERTEX_T &vertex_v2)
{
	VERTEX_T *v1_root = find_vertex_by_id(tree, vertex_find(vertex_v1));
	VERTEX_T *v2_root = find_vertex_by_id(tree, vertex_find(vertex_v2));

	if(v1_root == v2_root)
	{
		return;
	}

	if(v1_root->DEPTH > v2_root->DEPTH)
	{
		v1_root->ROOT = v2_root;

	}
	else if (v1_root->DEPTH < v2_root->DEPTH)
	{
		v2_root->ROOT = v1_root;
	}
	else
	{
		v1_root->ROOT = v2_root;
		v2_root->DEPTH--;

		v1_root = find_vertex_by_id(tree, vertex_find(vertex_v1));
		v2_root = find_vertex_by_id(tree, vertex_find(vertex_v2));

		if( vertex_v1.ROOT->DEPTH != v1_root->DEPTH)
		{
			if(vertex_v1.DEPTH == vertex_v2.DEPTH)
			{
				vertex_v1.ROOT = vertex_v1.ROOT->ROOT;
				vertex_v2.ROOT = vertex_v2.ROOT->ROOT;
			}
			else
				vertex_v2.ROOT = v2_root;
		}
	}
}



void set_vertex_root(VERTEX_TREE_T &tree , int vertex, int root)
{
	vertex_union(tree, *find_vertex_by_id(tree, vertex), *find_vertex_by_id(tree, root));
}

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
		if(tree.TREE[i]->ROOT == 0 && tree.TREE[i]->DEPTH < 0)
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
	cout << "\n";
	for(int i = 0 ; i < tree.number_in_tree ; i++)
	{
		cout << tree.TREE[i]->DEPTH << ", ";
	}
	cout << "\n";
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

bool vertex_mst(VERTEX_TREE_T tree)
{
	int root_count = 0;
	int mst_tree_count = 0;
	bool result = true;

	for(int i=0 ; i < tree.number_in_tree ; i++)
	{
		if(tree.TREE[i]->ROOT == 0 && tree.TREE[i]->DEPTH < 0)
		{
			mst_tree_count++;
			root_count++;
			if(root_count > 1)
				result = false;
		}
		else if (tree.TREE[i]->ROOT == 0)
		{
			result = false;
		}
		else
			mst_tree_count++;
	}
	tree.mst_count = mst_tree_count;
	

	return result;

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

void set_vertex_set_id_array(VERTEX_TREE_T tree, int* &array)
{
	for(int i=0 ; i < tree.number_in_tree ; i++)
	{
		if(tree.TREE[i]->ROOT == 0 && tree.TREE[i]->DEPTH < 0)
		{
			array[i] = tree.TREE[i]->DEPTH ;
		}
		else if (tree.TREE[i]->ROOT == 0)
		{
			array[i] = 0;
		}
		else 
		{
			array[i] = tree.TREE[i]->ROOT->ID; 
		}
	}

}

bool arrays_same(int* &array1, int* &array2, int size)
{
	for(int i=0 ; i < size ; i++)
	{	
		if(array1[i] != array2[i])
		{
			return false;
		}
	}
	
	return true;
}

