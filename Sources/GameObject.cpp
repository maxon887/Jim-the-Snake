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
	
#include "GameObject.h"

JimTheSnake*		GameObject::game = NULL;
GameScreen*			GameObject::screen = NULL;

void GameObject::Init(JimTheSnake* game){
	GameObject::game = game;
	GameObject::screen = dynamic_cast<GameScreen*>(game->GetCurrentScreen());
	if(!screen){
		throw string("Game object must be initialized under GameScreen");
	}
}

GameObject::GameObject(){
	SetPosition(Point(0, 0));
}

GameObject::GameObject(Point pos){
	SetPosition(pos);
}

void GameObject::SetPosition(Point pos){
	this->position = pos;
}

Point GameObject::GetPosition(){
	return position;
}
