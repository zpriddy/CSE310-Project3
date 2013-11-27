/******************************************************************************
* 2d-array.cpp
* 
* Date:   2013-11-26 17:15:20
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

int** makeTable(int rows, int colums)
{
	int** table = new int*[rows];
	for(int i = 0 ; i < rows; i++ )
	{
		table[i] = new int[colums];

		//Set all elements to -1 
		for(int j=0 ; j< colums ; j++)
		{
			table[i][j] = -1;
		}
	}

	return table;
}

void freeTable(int** table, int rows)
{
    if(table)
    {
        for(int i = 0; i < rows; i++)
    	{ 
    		if(table[i])
			{ 
				delete[] table[i]; 
        	} 
	   	}
        delete[] table;    
    }
}

void printTable(int** table, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("(%d,%d) -> %d\n", i, j, table[i][j]);
        }    
    }
}
