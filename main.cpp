#include "Character.h"

int main() {

	Character player, player2;

	bool turnstate1 = true; // player1�� �� ���º���
	bool turnstate2 = false; // player2�� �� ���º���
	bool playstate = true; // ������ ���º��� false = Gmae End
	while (1) {
		player.charicterSet();
		player2.charicterSet();
		cout << player.name << " vs " << player2.name << "\nBattle Start !!" << endl;
		while (playstate == true) {                 // ��������
			while (turnstate1 == true)
				playstate = player.turn(&player2.hp, &player2.def, &turnstate1, &turnstate2);
			while (turnstate2 == true && playstate == true)
				playstate = player2.turn(&player.hp, &player.def, &turnstate2, &turnstate1);
		}
		cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
		cin >> playstate;         // ����� Ȯ��
		if (playstate == true) { // ����۽� �ʱ�ȭ
			turnstate1 = true;
			turnstate2 = false;
		}else
			return 0;
	}
}

//�ؾ��Ұ� : �����߰�, ��Ÿ�����, ��ġ�����Ǳ���(ó���� 1�����) >> ���߰�(2�����迭 [10][10]������ ���� ��, ��, ĳ������ġ ����) >> 2�� ��ƽ���������� �����