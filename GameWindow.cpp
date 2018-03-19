#include "GameWindow.h"

void GameWindow::interval() {     // ���м�
	cout << "==============================================================" << endl;
}
void GameWindow::location(Character* player, Character* player2) {
	player->locx = 1;      // �ʱ� �÷��̾� ��ġ����
	player->locy = 5;
	player2->locx = 8;
	player2->locy = 5;
	return;
}

void GameWindow::gameSet(Character* player, Character* player2) {         // ���Ӽ���
	cout << player->name << "("<< player->job << ")"<< " vs " << player2->name << "(" << player2->job << ")" << endl;
	cout << "\nBattle Start !!" << endl;
	return;
}

void GameWindow::gameRestart() {
	cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
	cin >> playstate;         // ����� Ȯ��
	interval();
	if (playstate == true) { // ����۽� �ʱ�ȭ
		turnstate1 = true;
		turnstate2 = false;
	}
	else
		return;
}

void GameWindow::gameStart(Map* map) { // ��������
	Character* player = new Character();
	Character* player2 = new Character();
	location(player, player2);
	gameSet(player, player2);
	while (playstate == true) {
		while (turnstate1 == true)
			playstate = player->turn(&player2->hp, &player2->def, &player2->locx, &player2->locy,
				&turnstate1, &turnstate2, map);
		while (turnstate2 == true && playstate == true)
			playstate = player2->turn(&player->hp, &player->def, &player->locx, &player->locy,
				&turnstate2, &turnstate1, map);
	}	
	if (playstate == false)
		return;
}

GameWindow::GameWindow()
{
	map = new Map;
	gameStart(map);
}

GameWindow::~GameWindow()
{
}
