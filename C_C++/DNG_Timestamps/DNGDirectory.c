/*
 * DNGDirectory.c
 *
 *  Created on: 23 oct. 2017
 *      Author: Administrator
 */

#include "DNGDirectory.h"
#include <stdio.h>
#include <string.h>

static stTimeStamp timestampsFifo[8];
static int Rdid;
static int Wrid;
static int cnt;
void TimeStamps_fifo_init()
{
	memset(timestampsFifo, 0, sizeof(timestampsFifo)*8);
	Rdid = 0;
	Wrid = 0;
	cnt = 0;
}

int IsTimeStamps_fifo_empty()
{
	return cnt == 0 ? 1 : 0;
}

int IsTimeStamps_fifo_full()
{
	return cnt == 8 ? 1 : 0;
}

int TimeStamps_fifo_push(stTimeStamp timestamp)
{
	if (IsTimeStamps_fifo_full())
	{
		printf("FIFO is FULL, won't push R=%d W=%d \n", Rdid, Wrid);
		return -1;
	}
	timestampsFifo[Wrid] = timestamp;
	printf("fifo push: [%s, %s] R=%d W=%d cnt=%d\n", timestamp.FileName, timestamp.Timestamp, Rdid, Wrid,  cnt);
	Wrid = (Wrid+1) % 8;
	cnt ++;
	return 0;
}

int TimeStamps_fifo_pop( stTimeStamp *pTimestamp)
{
	if (IsTimeStamps_fifo_empty())
	{
		printf("FIFO is Empty, won't pop R=%d W=%d \n", Rdid, Wrid);
		return -1;
	}
	*pTimestamp = timestampsFifo[Rdid];
	printf("fifo pop: [%s, %s] R=%d W=%d cnt=%d\n", pTimestamp->FileName, pTimestamp->Timestamp,  Rdid, Wrid, cnt);
	Rdid = (Rdid+1) % 8;
	cnt --;
	return 0;
}
