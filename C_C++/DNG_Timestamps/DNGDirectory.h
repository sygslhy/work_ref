#ifndef DNG_DIRECTORY_H
#define DNG_DIRECTORY_H

typedef struct {
	char FileName[12];
	char Timestamp[32];

} stTimeStamp;

void TimeStamps_fifo_init();

int IsTimeStamps_fifo_empty();

int IsTimeStamps_fifo_full();

int TimeStamps_fifo_push( stTimeStamp timestamp);

int TimeStamps_fifo_pop( stTimeStamp *pTimestamp);

#endif
