/*
 * CmdParser.cpp
 *
 *  Created on: 30 juin 2018
 *      Author: Administrator
 */

#include "CmdParser.h"
#include <string.h>
#include <iostream>
#include <sstream>

void A(void){
	std::cout << "AAA" << std::endl;
}//������

void B(void){
	std::cout << "BBB" << std::endl;
}//����B

void C(void){
	std::cout << "CCC" << std::endl;
}//����C

const func_t func_sel[]=  //ƥ������
{
        {"wrl",A},
		{"why",B},
        {"hy", C},
        {0,0},
};

const func_t* func_find(const std::string& name)//ƥ�亯��
{
        int num = sizeof(func_sel)/sizeof(func_sel[0]);
        std::cout << num << std::endl;
        for(int j=0; j < num-1; j++){
        	if(strcmp(func_sel[j].name, name.c_str())==0){
        		return &func_sel[j];//�ҵ��ͷ���
        	}
        	std::cout << j << std::endl;
        }

        return (const func_t*)0;//�Ҳ������أ�
}

std::string CmdParser::getcmd(const std::string& cmdline){
	std::stringstream sin(cmdline);
	std::string cmd;
	sin >> cmd;
	return cmd;
}

CmdParser::CmdParser(){}

void CmdParser::OnCommand(const std::string& cmdline){

	if(cmdline=="wrl"){
		std::cout << "bijin" << std::endl;
	}else if(cmdline=="why"){
		std::cout << "koujiao" << std::endl;
	}else if(cmdline=="hy"){
		std::cout << "rujiao" << std::endl;
	}else{
		std::cout << "pochu" << std::endl;
	}

	std::string str=getcmd(cmdline);

	std::cout << str << std::endl;

	const func_t* pfunc = func_find(cmdline);
	if(pfunc){
		pfunc->func();
	}else{
		std::cout << "Invalid param"<< std::endl;
	}

}


