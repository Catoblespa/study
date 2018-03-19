#pragma once
#include "Character.h"
#include "Map.h"
class GameWindow {
private:
	bool turnstate1 = true; // player1�� �� ���º���
	bool turnstate2 = false; // player2�� �� ���º���
	void location(Character* player, Character* player2);
	void gameSet(Character* player, Character* player2);
	void interval();

public:
	Map * map;
	void gameRestart();
	void gameStart(Map* map);
	bool playstate = true; // ������ ���º��� false = Gmae End

	GameWindow();
	~GameWindow();
};

