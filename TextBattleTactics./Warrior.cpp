#include "Warrior.h"



Warrior::Warrior(const char* jobname)
{
	name = new char[1];
	cout << "name = ";
	cin >> name;
	job = new char[strlen(jobname) + 1];
	strcpy(job, jobname);
	hpmax = 5;
	hp = hpmax;
	mpmax = 30;
	mp = mpmax;
	atkback = 15;
	atk = atkback;
	def = 10;
	range = 1;
}

bool Warrior::dash() {
	if (dashskillState == 1) {
		cout << "Be activated Buff...." << endl;
		return true;
	}
	else if (mp < 5) {
		cout << "Not enough MP" << endl;
		return true;
	}
	speed++;
	mp -= 5;
	cout << "speedup!! speed = " << speed << ", mp = " << mp << endl;
	dashskillState = 1;
	return false;
}

void Warrior::speedBack() {
	speed--;
	dashskillState = 0;
	return;
}
bool Warrior::run(Character* player2, Character* Monster1, Character* Monster2, Map* map, item* Item1, item* Item2) {  // �̵�
	int goingNumber = 0;
	cout << "Where will you go? (1. Right // 2. Left // 3. Up  // 4. Down)" << endl;
	cin >> goingNumber;

	switch (goingNumber) {
	case 1:
	if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		if (map->mapping[locy][locx + speed] == 6) {
			if (locy == Item1->locy && locx + speed == Item1->locx) {
				if (Item1->type == Sword)
					EquipItem(WeaponSlot, Item1);
				else if (Item1->type == Armmor)
					EquipItem(ArmorSlot, Item1);
			}
			else if (locy == Item2->locy && locx + speed == Item2->locx) {
				if (Item2->type == Sword)
					EquipItem(WeaponSlot, Item2);
				else if (Item2->type == Armmor)
					EquipItem(ArmorSlot, Item2);
			}
		}
		locx += speed;
		if (map->mapping[locy][locx] == 3 ||
			map->mapping[locy][locx] == 4 ||
			map->mapping[locy][locx] == 5) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same location!)" << endl;
			locx -= speed;
			return true;
		}
		else if (map->mapping[locy][locx] == 1) {                 // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locx -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy,
			Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			(range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) && Monster1->hp > 0) ||
			(range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)) && Monster2->hp > 0))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 2:
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		if (map->mapping[locy][locx - speed] == 6) {
			if (locy == Item1->locy && locx - speed == Item1->locx) {
				if (Item1->type == Sword)
					EquipItem(WeaponSlot, Item1);
				else if (Item1->type == Armmor)
					EquipItem(ArmorSlot, Item1);
			}
			else if (locy == Item2->locy && locx - speed == Item2->locx) {
				if (Item2->type == Sword)
					EquipItem(WeaponSlot, Item2);
				else if (Item2->type == Armmor)
					EquipItem(ArmorSlot, Item2);
			}
		}
		locx -= speed;
		if (map->mapping[locy][locx] == 3 ||
			map->mapping[locy][locx] == 4 ||
			map->mapping[locy][locx] == 5) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same location!)" << endl;
			locx += speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                     // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locx += speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy,
			Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			(range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) && Monster1->hp > 0) ||
			(range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)) && Monster2->hp > 0))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 3:
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		if (map->mapping[locy - speed][locx] == 6) {
			if (locy - speed == Item1->locy && locx == Item1->locx) {
				if (Item1->type == Sword)
					EquipItem(WeaponSlot, Item1);
				else if (Item1->type == Armmor)
					EquipItem(ArmorSlot, Item1);
			}
			else if (locy - speed == Item2->locy && locx == Item2->locx) {
				if (Item2->type == Sword)
					EquipItem(WeaponSlot, Item2);
				else if (Item2->type == Armmor)
					EquipItem(ArmorSlot, Item2);
			}
		}
		locy -= speed;
		if (map->mapping[locy][locx] == 3 ||
			map->mapping[locy][locx] == 4 ||
			map->mapping[locy][locx] == 5) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same location!)" << endl;
			locy += speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                      // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locy += speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy,
			Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			(range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) && Monster1->hp > 0) ||
			(range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)) && Monster2->hp > 0))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 4:
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		if (map->mapping[locy + speed][locx] == 6) {
			if (locy + speed == Item1->locy && locx == Item1->locx) {
				if (Item1->type == Sword)
					EquipItem(WeaponSlot, Item1);
				else if (Item1->type == Armmor)
					EquipItem(ArmorSlot, Item1);
			}
			else if (locy + speed == Item2->locy && locx == Item2->locx) {
				if (Item2->type == Sword)
					EquipItem(WeaponSlot, Item2);
				else if (Item2->type == Armmor)
					EquipItem(ArmorSlot, Item2);
			}
		}
		locy += speed;
		if (map->mapping[locy][locx] == 3 ||
			map->mapping[locy][locx] == 4 ||
			map->mapping[locy][locx] == 5) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same location!)" << endl;
			locy -= speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                       // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locy -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy,
			Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			(range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) && Monster1->hp > 0) ||
			(range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)) && Monster2->hp > 0))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Warrior::turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, Map* map, item* Item1, item* Item2) {
	// �÷��̾� �� (����÷��̾� hp, def, location, �� �÷��̾��� �� ���º���, ��)
	int turnMenu = 0;
	bool gameState = true; // ������ ���� Ȯ��
	interval();
	cout << name << "'s Turn!" << endl;
	cout << "1. attack // 2. attackskill // 3, dashSkill // 4. rest // 5. run // 6. status // 7. View Map" << endl;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		gameState = attack(player2, Monster1, Monster2, map, turnState1, turnState2);
		return gameState;
	case 2:
		*turnState1 = atkBuffSkill();            // ��ų ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 3:
		*turnState1 = dash();            // ��ų ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 4:
		rest();
		*turnState1 = false;
		*turnState2 = !(*turnState1);
		return gameState;
	case 5:
		*turnState1 = run(player2, Monster1, Monster2, map, Item1, Item2);                // �̵� ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
	case 6:
		status();
		*turnState1 = true;                         // �������ͽ� Ȯ�� (���� �ѱ��� ����)
		*turnState2 = !(*turnState1);
		return gameState;
	case 7:
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy, 
			Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		if (Monster1->hp <= 0)
			dropItemCheck(map, Monster1);
		else if (Monster2->hp <= 0)
			dropItemCheck(map, Monster2);
		map->ViewMap();
		*turnState1 = true;                         // �� Ȯ�� (���� �ѱ��� ����)
		*turnState2 = !(*turnState1);
		return gameState;
	default:
		errorMessage();
		*turnState1 = true;
		*turnState2 = !(*turnState1);
		return gameState;
	}
}
Warrior::~Warrior()
{
	if (name != NULL) {
		name = NULL;
		delete[] name;
	}
	if (job != NULL) {
		delete[] job;
		job = NULL;
	}
}
