/******************************************************************************
* file_io.cpp
* 
* Date:   2013-11-24 19:08:53
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
#include <sstream>

using namespace std;

#include "errors.h"
#include "2d_array.h"
#include "min_heap.h"
#include "vertex.h"


int** ReadInputFile(string file_name)
{
	string read_line;
	int** data;

	ifstream inputfile(file_name.c_str());
	if(inputfile.is_open())
	{
		int nV, nE;

		nV = nE = 0L; //Sets nV and nE to NULL;

		inputfile >> nV >> nE;
		if(inputfile.fail())
		{
			error(0, "Expecting Numbers on First Line of Input File");
			exit(0);
		}
		data = makeTable(nE+1, 3);

		data[0][0] = nV;
		data[0][1] = nE;

		int a, b, c;
		for(int i = 1 ; i <= nE ; i++)
		{
			a = b = c = 0L; //Set to null

			if(inputfile.eof())
			{
				error(0, "Expecting More Lines in Input File");
				exit(0);
			}
			inputfile >> a >> b >> c;


			if(inputfile.fail())
			{
				error(0, "Expecting Numbers not Letters in Data Section of Input File");
				exit(0);
			}
			else
			{
				//Set The Values in the Array
				data[i][0] = a;
				data[i][1] = b;
				data[i][2] = c;
			}
		}
		return data;
	}
	else
	{
		error(0, "Can Not Open Input File");
		exit(0);
	}
}

void make_new_output(string filename)
{
	ofstream outputfile(filename.c_str() , ios_base::trunc);
	if(outputfile.is_open())
	{

	}
	else
	{
		error(0, "Can Not Make Output File");
		exit(0);
	}
}

void print_to_output_file(string filename, VERTEX_TREE_T tree, HEAP &i_heap, EDGE_T* mst_set, int run, int mst_size)
{
	ofstream outputfile(filename.c_str() , ios_base::app);
	if(outputfile.is_open())
	{
		int i;
		if(run == 0 )
		{
			outputfile << "Set Structure:\n";

			for(i = 0 ; i < tree.number_in_tree ; i++)
			{
				if(tree.TREE[i]->ROOT == 0 && tree.TREE[i]->DEPTH < 0)
				{
					outputfile << tree.TREE[i]->DEPTH;
				}
				else if (tree.TREE[i]->ROOT == 0)
				{
					outputfile << 0;
				}
				else 
				{
					outputfile << tree.TREE[i]->ROOT->ID ; 
				}
				if(i < tree.number_in_tree-1)
					outputfile << ", ";
			}
			outputfile << "\n\n";

			if(!vertex_mst(tree))
			{
				outputfile << "Heap Structure:\n";
				for(i = 1 ; i <= i_heap.get_size() ; i++)
				{
					outputfile << i_heap.get_edge(i).cost;
					if(i < i_heap.get_size())
						outputfile << ", ";
				}
				outputfile << "\n\n";

			}
		}
		else if (run == 1)
		{

			//if(!vertex_mst(tree))
			{
				outputfile << "Heap Structure:\n";
				for(i = 1 ; i <= i_heap.get_size() ; i++)
				{
					outputfile << i_heap.get_edge(i).cost;
					if(i < i_heap.get_size())
						outputfile << ", ";
				}
				outputfile << "\n\n";

			}
			outputfile << "Set Structure:\n";

			for(i = 0 ; i < tree.number_in_tree ; i++)
			{
				if(tree.TREE[i]->ROOT == 0 && tree.TREE[i]->DEPTH < 0)
				{
					outputfile << tree.TREE[i]->DEPTH;
				}
				else if (tree.TREE[i]->ROOT == 0)
				{
					outputfile << 0;
				}
				else 
				{
					outputfile << tree.TREE[i]->ROOT->ID ; 
				}
				if(i < tree.number_in_tree-1)
					outputfile << ", ";
			}
			outputfile << "\n\n";
		}
		else if (run == 2)
		{
			outputfile << "Heap Structure:\n";
			for(i = 1 ; i <= i_heap.get_size() ; i++)
			{
				outputfile << i_heap.get_edge(i).cost;
				if(i < i_heap.get_size())
					outputfile << ", ";
			}
			outputfile << "\n\n";
		}

		if(vertex_mst(tree))
		{
			outputfile << "MST:\n";
			int sum = 0;
			for(int i = 0 ; i < mst_size ; i++)

			{
				outputfile << mst_set[i].v1->ID << " " << mst_set[i].v2->ID << " " << mst_set[i].cost << "\n";
				sum += mst_set[i].cost;
			}
			 outputfile << "\nTotal Cost: " << sum << "\n";
		}



	}
	else
	{
		error(0, "Can Not Open Output File");
		exit(0);
	}

}
