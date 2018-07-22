/*
 * Luatest.cpp
 *
 *  Created on: 2 juil. 2018
 *      Author: Administrator
 */
#include "Luatest.h"
#include <iostream>



//
// ��ʼ��Lua����.
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
// ����Lua�ļ���Lua����ʱ������.
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
// ��ȡȫ�ֺ���.
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

	// ���ؽű���Lua������.
	if (!loadLuaFile(luaEnv, "module.lua")){
		std::cout<<"Load Lua File FAILED!"<< std::endl;
		return -1;
	}

	// ��Ҫ���õĺ����ͺ������ò�����ջ.
	int a = 1;
	int b = 2;
	lua_getglobal(luaEnv, "func4");
	lua_pushnumber(luaEnv, a);
	lua_pushnumber(luaEnv, b);

	// ����Lua������2������,һ������ֵ��.
	lua_pcall(luaEnv, 2, 1, 0);
	// ��ȡ����ֵ.
	int ret = (int)lua_tonumber(luaEnv, -1);

	// ������ֵ��ջ.
	lua_pop(luaEnv, 1);
	std::cout << "addition=" << ret << std::endl;
	// �ͷ�Lua����ʱ����.
	lua_close(luaEnv);

	/* pause */
	printf( "Press enter to exit..." );
	return 0;
}





