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
#include "JimTheSnake.h"
#include "Screen.h"
#include "Texter.h"
#include "Button.h"
#include "Commercial.h"

#include <list>

class Snake;
class Spider;
class Apple;
class Cactus;
class GameObject;

enum class GameState{
	ONREADY,
	RUNNING,
	PAUSED,
	GAMEOVER,
};

class GameScreen : public Screen{
public:
	GameScreen(JimTheSnake* game);
	~GameScreen();

	void Start();
	void Update(float sec);
	void Suspend();

	GameState GetState();
	void SetState(GameState newState);
	void AddScore(int gain);
	bool IsEmptyPosition(Point pos, float radius);
	Point GetEmptyPosition(float radius);
	list<Apple*>& GetApples();
	void StopMusic();
private:
	JimTheSnake* game;
	GameState state;
	Snake* snake;
	Commercial* commercial;
	Control control;
	list<Apple*> apples;
	list<Spider*> spiders;
	list<Cactus*> cactuses;

	Image* background;
	Image* score_img;
	Image* score_bright_img;
	Image* gameover_img;
	Image* pause_img;
	Image* ready_img;
	Image* best_img;

	Audio* music;
	Audio* apple_drop;
	Audio* game_over;
	Audio* btn_push;
	Audio* btn_pull;

	Button* back_btn;
	Button* menu_btn;
	Button* restart_btn;
	Button* pause_btn;
	Button* left_btn;
	Button* right_btn;

	Texter* score_texter;
	Texter* score_texter_light;

	int score;
	bool is_best_score;
	bool ad_downloaded;
	bool going_menu;
	bool on_left;
	bool on_right;
	float onready_time;
	float ad_timer;
	float centerW;
	float centerH;
	Point control_pos;
	Point input_pos;

	void Restart();
	void ProccessCollisions();
	void KeyPressedHandler(Key key);
	void ActionDownHandler(Point pos);
	void ActionMoveHandler(Point pos);
	void ActionUpHandler(Point pos);
	void CalcInput(float sec);
	void UpdateApples(float sec);
	void DrawApples();
	void UpdateSpiders(float sec);
	void DrawSpiders();
	void UpdateCactuses(float sec);
	void DrawCactuses();
	void DrawScore();
	void DrawLastScore();

	void OnResumeClick();
	void OnMenuClick();
	void OnRestartClick();
	void OnPauseClick();
};
