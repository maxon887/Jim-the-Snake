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
	
#include "Collisioner.h"
#include "Misc.h"

#include "Snake.h"

void Collisioner::Update(float sec){
	auto it = partners.begin();
	while(it != partners.end()){
		Collisioner* obj = (*it);
		if(!CircleOnCollision(GetPosition(), GetRadius(), obj->GetPosition(), obj->GetRadius())){
			ObjectLeft(obj);
			it = partners.erase(it);
		}else{
			++it;
		}
	}
}

bool Collisioner::OnCollision(){
	if(partners.size() > 0)
		return true;
	else
		return false;
}

void Collisioner::CheckCollision(Collisioner* obj){
	for(Collisioner* partner : partners){
		if(obj == partner)
			return;
	}
	CollisionOccurred(obj);
	partners.push_back(obj);
}

void Collisioner::BreakUp(Collisioner* partner){
	auto it = partners.begin();
	while(it != partners.end()){
		if((*it) == partner){
			it = partners.erase(it);
			break;
		}else{
			++it;
		}
	}
}

Collisioner::~Collisioner(){
	for(Collisioner* partner : partners){
		partner->ObjectLeft(this);
		partner->BreakUp(this);
	}
}