/*
 * main.cpp
 *
 *  Created on: 26 juin 2018
 *      Author: Administrator
 */
#include "LinkedList.cpp"
#include "Swap.cpp"
#include "Object.h"
#include "Family.h"
#include "CmdInput.h"
#include "CmdParser.h"
#include "CmdInterpreter.h"
#include "Luatest.h"

#include <iostream>
#include <string.h>


int main(int argc, char** args){

#if 0
	float a = 1.1;
	float b = 2.2;
	swap(a,b);
	std::cout << a << "-" << b << std::endl;

	int x = 1;
	int y = 2;
	swap(x,y);
	std::cout << x << "-" << y << std::endl;

	LinkedList<int> *list1 = new LinkedList<int>(0);
	list1->display();
	list1->insertElement(list1->head, 1);
	list1->display();
	list1->insertElement(list1->head, 2);
	list1->display();
	Node<int> *p = list1->findElement(2);
	std::cout << p->value << std::endl;
	list1->removeElement(list1->head);
	list1->display();
	std::cout << "---------" << std::endl;
	LinkedList<int> list2(*list1);
	list2.display();
	delete list1;
	std::cout << "---------" << std::endl;
	Object obj(1,2,3,4);

	obj.display();

	Father f;
	f.display();

	Father* pf = new Son(1,2);
	pf->display();
	delete pf;

	std::cout << "----Interface implement---" << std::endl;
	CmdInput cmdin;
	CmdParser cmdparser;
	cmdin.SetHandler(&cmdparser);
	cmdin.Run();


	std::cout << "----custom CLI implement---" << std::endl;

	const int cmd_array_m = 8;
	const int cmd_array_n = 32;
	int argc_t = 0;
	char* args_t[cmd_array_m];
	for(int i=0; i<cmd_array_m; i++){
		args_t[i] = new char[cmd_array_n];
	}
	std::string cmd;
	fflush(stdin);
	while(1){
		getline(std::cin, cmd);
		std::cout << "cmd=" << cmd << std::endl;
		if(cmd=="exit"){
			printf("exit\n");
			break;
		}else{
			char* cmd_t = new char [cmd.size()+1];
			strcpy(cmd_t, cmd.c_str());
			printf("cmd_t %s\n", cmd_t);
			split_main_cmd(cmd_t, strlen(cmd_t), &argc_t, args_t);
			printf("arc_t=%d, *args_t=%s\n",argc_t, args_t[0] );
			argc_t = 0;
			delete cmd_t;
			main_cmd(argc_t, args_t);
			for(int i=0; i<cmd_array_m; i++){
				memset(args_t[i], 0, cmd_array_n);
			}
		}
	}

	for(int i=0; i<cmd_array_m; i++){
		delete [] args_t[i];
	}
#endif
	//--------------Lua intergration--------------
	Lua_init();
	std::cout << "test print "<<std:: endl;
	return 0;
}
