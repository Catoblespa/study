#include "Character.h"

int main() {

	Character player, player2;

	bool turnstate1 = true; // player1�� �� ���º���
	bool turnstate2 = false; // player2�� �� ���º���
	bool playstate = true; // ������ ���º��� false = Gmae End

	player.loc = 0;            // �ʱ� �÷��̾� ��ġ����
	player2.loc = 2;

	while (1) {
		player.charicterSet();
		player.status();
		player2.charicterSet();
		player2.status();
		cout << player.name << " vs " << player2.name << endl; 
		cout << "\nBattle Start !!" << endl;
		while (playstate == true) {                 // ��������
			while (turnstate1 == true)
				playstate = player.turn(&player2.hp, &player2.def, &player2.loc, &turnstate1, &turnstate2);
			while (turnstate2 == true && playstate == true)
				playstate = player2.turn(&player.hp, &player.def, &player.loc, &turnstate2, &turnstate1);
		}
		cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
		cin >> playstate;         // ����� Ȯ��
		player.interval();
		if (playstate == true) { // ����۽� �ʱ�ȭ
			turnstate1 = true;
			turnstate2 = false;
		}else
			return 0;
	}
}

//�ؾ��Ұ� : ���߰�(2�����迭 [10][10]������ ���� ��, ��, ĳ������ġ ����)