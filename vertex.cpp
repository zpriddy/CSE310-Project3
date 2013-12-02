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
		cout << "DEPTH : " << depth << "\n";
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
	//cout << "VERTEX ROOT " << vertex.ID << "\n";
	if(vertex.ROOT != 0)
		ID = vertex_find(*vertex.ROOT);

	return ID;
}

// DO union(v1, v2)
void vertex_union(VERTEX_TREE_T &tree, VERTEX_T &vertex_v1, VERTEX_T &vertex_v2)
{
	cout << "UNION : " << vertex_v1.ID << " & " << vertex_v2.ID << "\n";
	VERTEX_T *v1_root = find_vertex_by_id(tree, vertex_find(vertex_v1));
	cout << "V1 ROOT ID: " << v1_root->ID << "\n";
	VERTEX_T *v2_root = find_vertex_by_id(tree, vertex_find(vertex_v2));

	
	cout << "V2 ROOT ID: " << v2_root->ID << "\n";

	if(v1_root == v2_root)
	{
		cout << "SKIP\n";
		/*
		if(vertex_v1.DEPTH > vertex_v2.DEPTH)
		{
			cout << "CASE 1\n";
			vertex_v2.ROOT = vertex_v1.ROOT;
			vertex_v1.DEPTH--;
		}
		else if (vertex_v1.DEPTH < vertex_v2.DEPTH)
		{
			cout << "CASE 2\n";
			vertex_v1.ROOT = vertex_v2.ROOT;
			//if(vertex_v1.DEPTH < vertex_v2.DEPTH)
				//vertex_union(tree, vertex_v1, vertex_v2);
			vertex_v2.DEPTH--;
		}
		
		if( vertex_v1.ROOT->DEPTH > vertex_v2.ROOT->DEPTH )
		{
			cout << "DO SOMETHING\n";
			vertex_v1.ROOT = vertex_v2.ROOT;
		}
		*/
		return;
	}

	if(v1_root->DEPTH > v2_root->DEPTH)
	{
		cout << "CASE 3\n";
		v1_root->ROOT = v2_root;
		//v2_root->DEPTH--;
		
	}
	else if (v1_root->DEPTH < v2_root->DEPTH)
	{
		cout << "CASE 4\n";
		v2_root->ROOT = v1_root;
		//v1_root->DEPTH--;

	}
	else
	{


		v1_root->ROOT = v2_root;
		v2_root->DEPTH--;
		cout << "CASE 5\n";
		print_tree(tree);
		v1_root = find_vertex_by_id(tree, vertex_find(vertex_v1));
		v2_root = find_vertex_by_id(tree, vertex_find(vertex_v2));

		cout << "V1 ROOT ID: " << v1_root->ID << "\n";
		cout << "V2 ROOT ID: " << v2_root->ID << "\n";

		if( vertex_v1.ROOT->DEPTH != v1_root->DEPTH)
		{
			cout << "DO SOMETHING!!!!!\n";
			//vertex_v2.ROOT = v2_root;
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
/*
void set_vertex_root_from_edge(EDGE_T edge)
{
	set_vertex_root(*edge.v1, *edge.v2);
}
*/
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
		//find_depth(*tree.TREE[i]);
	}
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
	bool result = true;

	for(int i=0 ; i < tree.number_in_tree ; i++)
	{
		if(tree.TREE[i]->ROOT == 0 && tree.TREE[i]->DEPTH < 0)
		{
			root_count++;
			if(root_count > 1)
				result = false;
		}
		else if (tree.TREE[i]->ROOT == 0)
		{
			result = false;
		}
	}

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



