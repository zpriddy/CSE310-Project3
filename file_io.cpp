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
		
	
		
		{
			data = makeTable(nE+1, 3);
		
			data[0][0] = nV;
			data[0][1] = nE;
		}
		
		
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
