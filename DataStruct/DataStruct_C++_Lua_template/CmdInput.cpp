/*
 * CmdInput.cpp
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */


#include "CmdInput.h"

#include <sstream>
#include <iostream>

CmdInput::CmdInput(){
	m_handler = 0;
}

void CmdInput::SetHandler(CmdHandler* h){
	m_handler = h;
}

void CmdInput::Run(){
	std::string cmd;
	while(1){
		getline(std::cin, cmd);
		if(cmd=="exit"){
			std::cout << "exit" << std::endl;
			break;
		}
		if(m_handler){
			m_handler->OnCommand(cmd);
		}
	}
}
