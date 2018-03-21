#include "Monster.h"

Monster::Monster(const char* _name, int _hp, int _mp, int _atk, int _def, int _range)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	hp = hpmax = _hp;
	mp = mpmax = _mp;
	atk = atkback = _atk;
	def = _def;
	range = _range;
}

bool Monster::attack(Character* player1, Character* player2, Map* map) {	// ���� �Ÿ� üũ
	cout << "attack! " << endl;
	for (int i = 1; i <= range; i++) {
		switch (map->mapping[locy + i][locx]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy + i][locx - i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy][locx - i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx - i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx + i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy][locx + i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy + i][locx + i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
	}
	Sleep(500);
	cout << "No enemies in range" << endl;
	atkBuffSkill();
	return true;
}
bool Monster::playerAttack(Character* player1, const char* _name) {
	int damage = (atk - player1->def);
	if (damage > 0)
		player1->hp -= (atk - player1->def);
	else if (damage <= 0)            // �������� 0�����ϰ�� 0����ó��
		damage = 0;
	Sleep(500);
	cout << player1->name << " " << damage << "Damage!" << endl;
	if (skillState == 1)   // ��ų�ߵ� Ȯ��
		atkBack();
	return playerhpCheck(player1->name, player1->hp, _name);
}
bool Monster::playerhpCheck(const char* _name, int _hp, const char* _name2) { // �÷��̾� hpüũ
	if (_hp <= 0) {
		interval();
		cout << _name2 << " Win" << endl;
		interval();
		return false;
	}
	cout << _name << "'s Hp = " << _hp << endl;
	return true;
}
bool Monster::monsterturn(Character* player1, Character* player2, Map* map) {
	// ���� �� (����÷��̾� hp, def, location, �� �÷��̾��� �� ���º���, ��)
	int turnMenu = GenerateRandom(1, 3);
	bool gameState = true; // ������ ���� Ȯ��
	interval();
	cout << name << "'s Turn!" << endl;

	switch (turnMenu) {
	case 1:
		Sleep(500);
		gameState = attack(player1, player2, map);
		return gameState;
	case 2:
		Sleep(500);
		atkBuffSkill();            // ��ų ������ ���� �ѱ�
		return gameState;
	case 3:
		rest();
		return gameState;
	default:
		break;
	}
}
bool Monster::atkBuffSkill() { // ���ù���
	if (skillState == 1) {
		cout << "Be activated Buff...." << endl;
		rest();
		return true;
	}
	else if (mp < 10) {
		cout << "Not enough MP" << endl;
		rest();
		return true;
	}
	atk += 10;
	mp -= 10;
	cout << "atkBuff! atk = " << atk << ", mp = " << mp << endl;
	skillState = 1;
	return false;
}

Monster::~Monster()
{
	if (name != NULL) {
		delete[] name;
		name = NULL;
	}
}
