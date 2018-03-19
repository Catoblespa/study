#include "Character.h"

Character::Character() {
	int jobNumber = 0;
	locx = 0;
	locy = 0;

	name = new char[1];

	cout << "name = ";
	cin >> name;
	while (true) {
		cout << "select Job (1. Warrior // 2. Lancer) ";

		cin >> jobNumber;
		switch (jobNumber)
		{
		case 1:
			Warrior("Warrior");
			interval();
			status();
			return;
		case 2:
			Lancer("Lancer");
			interval();
			status();
			return;
		default:
			errorMessage();
			interval();
			break;
		}
	}
}
Character::Character(const Character &player) {

	name = new char[1];
	name = player.name;
	if(player.range == 1){
			Lancer("Lancer");
			interval();
			status();
			return;
	}
	else if (player.range == 2) {
		Warrior("Warrior");
		interval();
		status();
		return;
	}
}
void Character::interval() {     // ���м�
	cout << "==============================================================" << endl;
}
void Character::errorMessage() { //�����޼��� ���
	cout << "error! Please enter the correct Number!" << endl;
	return;
}
bool Character::hpCheck(int* _hp) { // hpüũ
	if (*_hp <= 0) {
		interval();
		cout << name << " Win" << endl;
		interval();
		return false;
	}
	cout << "enemy's Hp = " << *_hp << endl;
	return true;
}
bool Character::attack(int* _hp, int* _def) {	// ����
	cout << "attack! " << endl;
	int damage = (atk - *_def);
	if (damage > 0)
		*_hp -= (atk - *_def);
	else if (damage <= 0)            // �������� 0�����ϰ�� 0����ó��
		damage = 0;
	cout << damage << "Damage!" << endl;
	if (skillState == 1)   // ��ų�ߵ� Ȯ��
		atkBack();
	return hpCheck(_hp);
}
bool Character::atkBuffSkill() { // ���ù���
	if (skillState == 1) {
		cout << "Be activated Buff...." << endl;
		return true;
	}
	else if (mp < 10) {
		cout << "Not enough MP" << endl;
		return true;
	}
	atk += 10;
	mp -= 10;
	cout << "atkBuff! atk = " << atk << ", mp = " << mp << endl;
	skillState = 1;
	return false;
}
void Character::atkBack() { // ���������Լ�	
	atk = atkback;
	skillState = 0;
	return;
}
void Character::status() { // �������ͽ�
	interval();
	cout << "name = " << name << "\nJob = " << job << "\nhp = " << hp << " / " << hpmax
		<< "\nmp = " << mp << " / " << mpmax << "\natk = " << atk << "\ndef = " << def
		<< "\nlocx = " << locx << ", locy = " << locy << endl;
	interval();
	return;
}
void Character::Warrior(const char* jobname) {     // ����
	job = new char[strlen(jobname) + 1];
	strcpy(job, jobname);
	hpmax = 60;
	hp = hpmax;
	mpmax = 30;
	mp = mpmax;
	atkback = 15;
	atk = atkback;
	def = 10;
	range = 1;
	return;
}
void Character::Lancer(const char* jobname) {   // ����
	job = new char[strlen(jobname) + 1];
	strcpy(job, jobname);
	hpmax = 45;
	hp = hpmax;
	mpmax = 20;
	mp = mpmax;
	atkback = 17;
	atk = atkback;
	def = 7;
	range = 2;
	return;
}
void Character::rest() { // �޽�
	if (hp < hpmax) {
		hp += 5;
		if (hp > hpmax)
			hp = hpmax;
		cout << "Hp recovery " << hp << " / " << hpmax << endl;
	}
	if (mp < mpmax) {
		mp += 5;
		if (mp > mpmax)
			mp = mpmax;
		cout << "Mp recovery " << hp << " / " << hpmax << endl;
	}
	return;
}
bool Character::run(int* _locx, int* _locy, Map* map) {  // �̵�
	int goingNumber = 0;
	cout << "Where will you go? (1. Right // 2. Left // 3. Up  // 4. Down)" << endl;
	cin >> goingNumber;

	switch (goingNumber) {
	case 1:
		locx++;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locx--;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                 // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locx--;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	case 2:
		locx--;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locx++;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                     // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locx++;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	case 3:
		locy--;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locy++;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                      // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locy++;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	case 4:
		locy++;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locy--;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                       // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locy--;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Character::turn(int* _hp, int* _def, int* _locx, int* _locy, bool* turnState1, bool* turnState2, Map* map) {
	// �÷��̾� �� (����÷��̾� hp, def, location, �� �÷��̾��� �� ���º���, ��)
	int turnMenu = 0;
	bool locxationState = true;
	bool gameState = true; // ������ ���� Ȯ��
	interval();
	cout << name << "'s Turn!" << endl;
	cout << "1. attack // 2. skill // 3. rest // 4. run // 5. status // 6. View Map" << endl;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		if (abs(locx - *_locx) > range) {            // ��Ÿ�üũ
			cout << "Not enough Range" << endl;
			*turnState1 = true;
			*turnState2 = !(*turnState1);
			return gameState;
		}
		gameState = attack(_hp, _def);
		break;
	case 2:
		*turnState1 = atkBuffSkill();            // ��ų ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 3:
		rest();
		break;
	case 4:
		*turnState1 = run(_locx, _locy, map);                // �̵� ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
	case 5:
		status();
		*turnState1 = true;                         // �������ͽ� Ȯ�� (���� �ѱ��� ����)
		*turnState2 = !(*turnState1);
		return gameState;
	case 6:
		map->playerLocChecking(locx, locy, *_locx, *_locy);
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
	*turnState1 = false;
	*turnState2 = !(*turnState1);
	return gameState;
}
Character::~Character()
{
	delete (name);
	delete (job);
}
