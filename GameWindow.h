#pragma once
#include "Character.h"
#include "Map.h"
class GameWindow {
private:
	bool turnstate1 = true; // player1�� �� ���º���
	bool turnstate2 = false; // player2�� �� ���º���
	bool playstate = true; // ������ ���º��� false = Gmae End

	void location();
	void gameSet();
	void gameRestart();

public:
	Character player, player2;
	Map map;
	void gameStart();
	GameWindow();
	~GameWindow();
};

