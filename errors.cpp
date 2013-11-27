/******************************************************************************
* errors.cpp
* 
* Date:   2013-11-24 19:33:29
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
#include <fstream>
#include <iostream>



// Files Includes
#include "errors.h"

using namespace std;

void error(int error_type, string error_message)
{
	cout << "*******************************************************************************\n";
	switch(error_type)
	{
		case 0: //FILE IO ERROR
			cout << "FILE IO ERROR: ";
			cout << error_message.c_str() << "\n";
			break;

		default:
			cout << "UNKNOWN ERROR";
			break;
	}
	cout << "*******************************************************************************\n";


}