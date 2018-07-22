/*
 * CmdInterpreter.cpp
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */

#include "CmdInterpreter.h"
#include "stdio.h"
#include "string.h"
/*
#include "rtc.h"
#include "usb.h"
#include "audio.h"
*/

void (rtc_cmd_help)(void){
	printf("rtc_cmd_help\n");
}


void rtc_cmd(int argc, char** args){
	if(argc>1){
		printf("rtc_cmd\n");
	}else{
		rtc_cmd_help();
	}
}

const stfunc cmd_table[]=  //Æ¥ÅäÊý×é
{
        {"rtc",rtc_cmd, rtc_cmd_help},
        {0,0,0},
};


const stfunc* main_cmd_select(const char* cmd){
	const stfunc* p = cmd_table;
	while(p->cmd){
		if(strcmp(p->cmd, cmd)==0){
			return p;
		}
		p++;
	}
	return p;
}

void split_main_cmd(char* cmd, int size, int* argc, char* args[]){
	const char *d = " ";
	char* p;
	p = strtok(cmd,d);
	while(p)
	{
		printf("%s\n",p);
		strcpy(*args, p);
		p=strtok(NULL,d);
		args++;
		(*argc)++;
	}
}

void main_cmd_help(void){
	printf("main_cmd_help\n");
}

void main_cmd(int argc, char* args[]){
	if(argc>1){
		printf("main_cmd\n");
		const stfunc* pfunc = main_cmd_select(args[0]);
		pfunc->func(argc-1, args+1);
	}else{
		main_cmd_help();
	}
}
