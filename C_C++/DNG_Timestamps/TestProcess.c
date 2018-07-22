/*
 * TestProcess.c
 *
 *  Created on: 23 oct. 2017
 *      Author: Administrator
 */
#include "DNGDirectory.h"
#include <stdio.h>
#include <string.h>

static stTimeStamp timestampsSequence1[8] =
{
			{"0001", "12:32:33"}
		,	{"0002", "12:32:34"}
		,	{"0003", "12:32:35"}
		,	{"0004", "12:32:37"}
		,   {"0005", "12:32:38"}
		,	{"0006", "12:32:39"}
		, 	{"0007", "12:33:40"}
		,	{"0008", "12:33:43"}
};

static stTimeStamp DNGtimestamps[4];

void getDNGTimestamps( char *FileName, stTimeStamp *pDNGtimestamp)
{
	do
	{
		TimeStamps_fifo_pop(pDNGtimestamp);
	} while (strcmp(FileName, pDNGtimestamp->FileName));
	//printf("get DNG: [%s, %s]\n", pDNGtimestamp->FileName, pDNGtimestamp->Timestamp);
}

void setJPGTimestamps(stTimeStamp JPGtimestamp)
{
	TimeStamps_fifo_push(JPGtimestamp);
	//printf("set JPG: [%s, %s]\n", JPGtimestamp.FileName, JPGtimestamp.Timestamp);
}

int main()
{


	TimeStamps_fifo_init();

	setJPGTimestamps( timestampsSequence1[0] );
	setJPGTimestamps( timestampsSequence1[1] );
	setJPGTimestamps( timestampsSequence1[2] );

	//getDNGTimestamps("0003", &DNGtimestamps[0]);

	setJPGTimestamps( timestampsSequence1[3] );
	setJPGTimestamps( timestampsSequence1[4] );
	setJPGTimestamps( timestampsSequence1[5] );

	//getDNGTimestamps("0004", &DNGtimestamps[1]);
	//getDNGTimestamps("0005", &DNGtimestamps[2]);

	setJPGTimestamps( timestampsSequence1[6] );
	setJPGTimestamps( timestampsSequence1[7] );



	printf("Is fifo full: %d\n", IsTimeStamps_fifo_full());

	getDNGTimestamps("0008", &DNGtimestamps[3]);

	printf("DNG Timestamps:");
	for (int i=0; i<4; i++)
	{
		printf("[%s, %s] ", DNGtimestamps[i].FileName, DNGtimestamps[i].Timestamp);
	}

	printf("Is fifo empty: %d\n", IsTimeStamps_fifo_empty());
	return 0;
}
