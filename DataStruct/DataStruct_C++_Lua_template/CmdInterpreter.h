/*
 * CmdInterpreter.h
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */

#ifndef CMDINTERPRETER_H_
#define CMDINTERPRETER_H_

typedef void (*cmd_func)(int argv, char** args);
typedef void (*cmd_help)(void);

typedef struct {
        const char* cmd; //ÃüÁîÃû
        cmd_func func; //ÃüÁîº¯ÊıÖ¸Õë
        cmd_help help_func;
} stfunc;

void split_main_cmd(char* cmd, int size, int* argc, char* args[]);
void main_cmd(int argc, char* args[]);

#endif /* CMDINTERPRETER_H_ */
