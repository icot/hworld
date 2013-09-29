/** @file gamestate.cpp
    @brief Game State definitions.
    @author Luis Cabellos
    @date 2013-09-29
*/
//------------------------------------------------------------------------------
#include "gamestate.hpp"
#include "lua.hpp"
#include "util.hpp"

//------------------------------------------------------------------------------
GameState::GameState() noexcept : m_ls{nullptr} {
    //empty
    std::cout << "GameState empty constructor" << std::endl;
}

//------------------------------------------------------------------------------
GameState::GameState( lua_State * ls ) noexcept : m_ls{ls} {
    //empty
    std::cout << "GameState constructor" << std::endl;
}

GameState::GameState( GameState&& gs ) noexcept {
    std::cout << "GameState copy move" << std::endl;
    m_ls = std::move( gs.m_ls );
    gs.m_ls = nullptr;
}

GameState& GameState::operator=( GameState&& gs ) noexcept {
    std::cout << "GameState assign move" << std::endl;
    m_ls = std::move( gs.m_ls );
    gs.m_ls = nullptr;
    return *this;
}

//------------------------------------------------------------------------------
GameState::~GameState() noexcept{
    std::cout << "GameState destructor" << std::endl;
    if( m_ls ){
        lua_close( m_ls );
    }
}

//------------------------------------------------------------------------------
void GameState::start(){
    if( m_ls ){
        lua_getfield( m_ls, LUA_GLOBALSINDEX, "start" );     // 1
        if( lua_isfunction( m_ls, -1 ) ){
            auto ret = lua_pcall( m_ls, 0, 0, 0 );           // 0
            checkLuaReturn( m_ls, ret );
        }
    }
}

//------------------------------------------------------------------------------
void GameState::update( double dt ){
    if( m_ls ){
        lua_getfield( m_ls, LUA_GLOBALSINDEX, "update" );    // 1
        if( lua_isfunction( m_ls, -1 ) ){
            lua_pushnumber( m_ls, dt );                      // 2
            auto ret = lua_pcall( m_ls, 1, 0, 0 );           // 0
            checkLuaReturn( m_ls, ret );
        }
    }
}

//------------------------------------------------------------------------------
void GameState::stop(){
    if( m_ls ){
        lua_getfield( m_ls, LUA_GLOBALSINDEX, "stop" );      // 1
        if( lua_isfunction( m_ls, -1 ) ){
            auto ret = lua_pcall( m_ls, 0, 0, 0 );           // 0
            checkLuaReturn( m_ls, ret );
        }
    }
}

//------------------------------------------------------------------------------
