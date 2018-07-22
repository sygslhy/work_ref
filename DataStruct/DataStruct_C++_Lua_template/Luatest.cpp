/*
 * Luatest.cpp
 *
 *  Created on: 2 juil. 2018
 *      Author: Administrator
 */
#include "Luatest.h"
#include <iostream>



//
// 初始化Lua环境.
//
lua_State* initLuaEnv()
{
	/* the Lua interpreter */
	lua_State* luaEnv = lua_open();
	luaopen_base(luaEnv);
	luaL_openlibs(luaEnv);

	return luaEnv;
}



//
// 加载Lua文件到Lua运行时环境中.
//
bool loadLuaFile(lua_State* luaEnv, const std::string& fileName)
{
	int result = luaL_loadfile(luaEnv, fileName.c_str());
	if (result)
	{
		return false;
	}

	result = lua_pcall(luaEnv, 0, 0, 0);
	return result == 0;
}


//
// 获取全局函数.
//
lua_CFunction getGlobalProc(lua_State* luaEnv, const std::string& procName)
{
	lua_getglobal(luaEnv, procName.c_str());
	if (!lua_iscfunction(luaEnv, 1))
	{
		return 0;
	}

	return lua_tocfunction(luaEnv, 1);
}


int Lua_init ()
{
	lua_State* luaEnv = initLuaEnv();
	if (!luaEnv){
		return -1;
	}

	// 加载脚本到Lua环境中.
	if (!loadLuaFile(luaEnv, "module.lua")){
		std::cout<<"Load Lua File FAILED!"<< std::endl;
		return -1;
	}

	// 将要调用的函数和函数调用参数入栈.
	int a = 1;
	int b = 2;
	lua_getglobal(luaEnv, "func4");
	lua_pushnumber(luaEnv, a);
	lua_pushnumber(luaEnv, b);

	// 调用Lua函数（2个参数,一个返回值）.
	lua_pcall(luaEnv, 2, 1, 0);
	// 获取返回值.
	int ret = (int)lua_tonumber(luaEnv, -1);

	// 将返回值出栈.
	lua_pop(luaEnv, 1);
	std::cout << "addition=" << ret << std::endl;
	// 释放Lua运行时环境.
	lua_close(luaEnv);

	/* pause */
	printf( "Press enter to exit..." );
	return 0;
}





