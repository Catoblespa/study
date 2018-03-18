#include "GameWindow.h"
void GameWindow::location() {
	player.locx = 1;      // �ʱ� �÷��̾� ��ġ����
	player.locy = 5;
	player2.locx = 8;
	player2.locy = 5;
	return;
}

void GameWindow::gameSet() {         // ���Ӽ��� (���÷��̾� ĳ���ͼ���, �ʼ���)
	player.charicterSet();
	player.status();
	player2.charicterSet();
	player2.status();
	cout << player.name << "("<< player.job << ")"<< " vs " << player2.name << "(" << player2.job << ")" << endl;
	cout << "\nBattle Start !!" << endl;
	return;
}

void GameWindow::gameRestart() {
	cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
	cin >> playstate;         // ����� Ȯ��
	player.interval();
	if (playstate == true) { // ����۽� �ʱ�ȭ
		turnstate1 = true;
		turnstate2 = false;
	}
	else
		return;
}

void GameWindow::gameStart() { // ��������
	while (1) {
		location();
		gameSet();
		while (playstate == true) {
			while (turnstate1 == true)
				playstate = player.turn(&player2.hp, &player2.def, &player2.locx, &player2.locy, &turnstate1, &turnstate2, &map);
			while (turnstate2 == true && playstate == true)
				playstate = player2.turn(&player.hp, &player.def, &player.locx, &player.locy, &turnstate2, &turnstate1, &map);
		}
		gameRestart();
		if (playstate == false)
			return;
	}
}

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
}
