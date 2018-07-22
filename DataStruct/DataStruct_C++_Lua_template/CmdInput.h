/*
 * CmdInput.h
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */

#ifndef CMDINPUT_H_
#define CMDINPUT_H_

#include "CmdHandler.h"
class CmdInput {

public:
	CmdInput();
	void SetHandler(CmdHandler* h);
	void Run();
private:
	CmdHandler* m_handler;
};



#endif /* CMDINPUT_H_ */
