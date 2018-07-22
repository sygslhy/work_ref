//***************************************************************************************
//
//! \file main.c
//! This is a simple example to use this device driver.
//!
//! \author    Yuan SUN
//! \version   V1.0
//! \date      2018-03-23
//! \copyright DxO Labs
//
//***************************************************************************************

#include "dev.h"

#define CNT_MAX  10  //!< The maxium number of print

//! Simple Device Driver example.
void DEV_Example(void)
{
	int i = 0;

	Dev_Init();

	for (i = 0; i < CNT_MAX; ++i)
	{
		Dev_PrintInt(i);
	}

	Dev_Close();
}

//! Main Function Application Entry
int main(void)
{

	DEV_Example();

	return 0;
}


