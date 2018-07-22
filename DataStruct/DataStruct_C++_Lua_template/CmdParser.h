/*
 * CmdParser.h
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */

#ifndef CMDPARSER_H_
#define CMDPARSER_H_
#include "CmdHandler.h"
#include <iostream>
#include <string>
typedef void (*call_back)(void);



typedef struct func_
{
        const char* name; //ÃüÁîÃû
        call_back func; //ÃüÁîº¯ÊıÖ¸Õë
} func_t;



class CmdParser: public CmdHandler {

public:
	CmdParser();
	std::string getcmd(const std::string& cmdline);
	std::string getsubcmd(const std::string& cmdline);
	void OnCommand(const std::string& cmdline);

};

#endif /* CMDPARSER_H_*/
