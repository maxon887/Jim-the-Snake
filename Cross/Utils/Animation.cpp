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
#include "Animation.h"

using namespace cross;

Animation::Animation(Animation& anim){
	this->graphics = anim.graphics;
	this->frames = anim.frames;
	this->rate = anim.rate;
	this->duration = anim.duration;
	this->frame_num = anim.frame_num;
	this->looped = anim.looped;
	this->original = false;
}

Animation::Animation(Graphics* gfx, float rate, Image* frames[], int frameCount){
	Init(gfx, rate, frames, frameCount, false);
}

Animation::Animation(Graphics* gfx, float rate, Image* frames[], int frameCount, bool looped){
	Init(gfx, rate, frames, frameCount, looped);
}

void Animation::Start(){
	duration = 0;
}

void Animation::Update(float sec){
	if(duration > frames.size() * rate && !looped){
		frame_num = 0;
		duration = 0xFF;
	}else{
		frame_num = (int)(duration / rate);
		frame_num = frame_num % frames.size();
		duration += sec;
	}
}

Image* Animation::GetImage(){
	return frames[frame_num];
}

bool Animation::IsRunning(){
	return duration != 0xFF;
}

Animation::~Animation(){
	if(original){
		for(unsigned int i = 0; i < frames.size(); i++){
			if(frames[i] != NULL){
				for(unsigned int j = i+1; j < frames.size(); j++){
					if(frames[i] == frames[j]){
						frames[j] = NULL;
					}
				}
				graphics->ReleaseImage(frames[i]);
				frames[i] = NULL;
			}
		}
	}
}

void Animation::Init(Graphics* gfx, float rate, Image* frames[], int frameCount, bool looped){
	original = true;
	this->graphics = gfx;
	this->duration = 0xFF;
	this->frame_num = 0;
	this->looped = looped;
	this->rate = rate;
	for(int i = 0; i < frameCount; i++){
		this->frames.push_back(frames[i]);
	}
}