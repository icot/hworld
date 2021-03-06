/**
    Copyright 2014, HexWorld Authors.

    This file is part of HexWorld.

    HexWorld is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    HexWorld is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with HexWorld.  If not, see <http://www.gnu.org/licenses/>.
**/
/** @file ray.hpp
    @brief Ray Declaration.
    @author Luis Cabellos
    @date 2013-09-24
*/
//------------------------------------------------------------------------------
#ifndef RAY_HPP_
#define RAY_HPP_

//------------------------------------------------------------------------------
#include "gfxinc.hpp"

//------------------------------------------------------------------------------
class Ray{
public:
    glm::vec3 origin = glm::vec3{ 0.0 };
    glm::vec3 direction = glm::vec3{ 1.0 };
};

//------------------------------------------------------------------------------
#endif//RAY_HPP_

//------------------------------------------------------------------------------
