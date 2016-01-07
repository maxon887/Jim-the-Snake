/*	Copyright © 2015 Lukyanau Maksim

	This file is part of Cross++ Game Engine.

    Cross++ Game Engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cross++ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cross++.  If not, see <http://www.gnu.org/licenses/>			*/
#pragma once

#ifdef C3D
	#include "Graphics3D.h"
	class Graphics;
#else
	#include "Graphics.h"
	class Graphics3D;
#endif
#include "Input.h"
#include "Config.h"
#include "Audio.h"

namespace cross {

class Debuger;

extern Game* game;
extern Launcher* launcher;
extern Graphics* graphics;
extern Graphics3D* gfx3D;
extern Input* input;
extern Config* config;
extern Debuger* debuger;

/* Class reflect particular game scene. Like menu, level 1 etc.
   Every game must implement at least one Screen class.
   Witch will be loaded through Game::GetStartScreen function */
class Screen{
public:
	/* Calls once before screen show up. */
	virtual void Start() { };
	/* Calls every frame update. Ideally 60 times per second(60fps)*/
	virtual void Update(float sec) { };
	/* Calls where game need to be stoped like lost focus or input phone call */
	virtual void Suspend() { };
//Internal data. You don't need call any of this methods or modify variable
public:
	virtual ~Screen() { };
};
    
}
