/******************************************************************************
* 2d-array.h
* 
* Date:   2013-11-26 17:15:34
*
* Zachary Priddy
* zpriddy@asu.edu
* www.zpriddy.com
*
* DESCRIPTION:
*
*
******************************************************************************/

#ifndef _2D_ARRAY_H_
#define _2D_ARRAY_H_

int** makeTable(int rows, int colums);
void freeTable(int** table, int rows);
void printTable(int** table, int rows, int columns);

#endif