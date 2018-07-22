/*
 * CmdHandler.h
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */

#ifndef CMDHANDLER_H_
#define CMDHANDLER_H_

#include <string>

class CmdHandler {
public:
	virtual void OnCommand(const std::string& cmdline) = 0;
};



#endif /* CMDHANDLER_H_ */
