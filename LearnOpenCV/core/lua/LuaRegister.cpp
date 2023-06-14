#include "LuaRegister.h"

using namespace Core;

LuaRegister* LuaRegister::instance = nullptr;

LuaRegister::LuaRegister()
{
    //����һ�� Lua state
    L = luaL_newstate();

    //Opens all standard Lua libraries into the given state.
    //����һ�������� Lua state �����е�Lua��׼��
    luaL_openlibs(L);

    //��Lua�ű��ļ�
    luaL_dofile(L, "asserts/script/main.lua");
}

LuaRegister::~LuaRegister()
{
    //�ر� Lua state
    lua_close(L);
}