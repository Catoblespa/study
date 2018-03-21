#pragma once
#include "Map.h"
#include "Warrior.h"
#include "Lancer.h"
#include "Monster.h"
#include "item.h"

class GameWindow {
private:
	bool turnstate1 = true; // player1�� �� ���º���
	bool turnstate2 = false; // player2�� �� ���º���
	void location(Character* player, Character* player2, Character* monster1, Character* monster2);
	void gameSet(Character* player, Character* player2);
	void interval();

public:
	Map * map;
	Monster* monster[2];
	Character* player[2];
	item* Item[2];

	void itemSet();
	void monsterSet();
	void gameRestart();
	void gameStart(Map* map);
	bool playstate = true; // ������ ���º��� false = Gmae End
	void errorMessage(); 

	GameWindow();
	~GameWindow();
};

