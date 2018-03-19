#include "Map.h"

Map::Map() {
}
void Map::buildMapping() {  // �� �ʱ�ȭ
	cout << "�� = Wall, �� = " << "You" << ", �� = " << "Enemy" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (mapping[i][j]) {
			case 1:
				strcat(maps, wall);
				break;
			
			case 0:
				strcat(maps, road);
				break;

			case 3:
				strcat(maps, player1);
				break;

			case 4:
				strcat(maps, player2);
				break;

			default:
				break;
			}
		}
		cout << maps[i] << endl;
	}
	return;
}

void Map::ViewMap() {   // �ʺ���
	buildMapping();
	return;
}

void Map::playerLocChecking(int _locx1, int _locy1, int _locx2, int _locy2) {          // �÷��̾� ��ġüũ
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mapping[i][j] == 3 || mapping[i][j] == 4)
				mapping[i][j] = 0;
		}
	}
	mapping[_locy1][_locx1] = 3;
	mapping[_locy2][_locx2] = 4;
}

Map::~Map()
{
}
