#include "Character.h"

Character::Character()
{
}
void Character::interval() {     // ���м�
	cout << "==============================================================" << endl;
} 
void Character::errorMessage() { //�����޼��� ���
	cout << "error! Please enter the correct Number!" << endl;
	return;
}
void Character::charicterSet() // ĳ���� ����
{
	int jobNumber = 0;
	cout << "(word length < 20)name = ";
	cin >> name;
	while (true) {
	cout << "select Job (1. Warrior // 2. Lancer) ";

	cin >> jobNumber;
		switch (jobNumber)
		{
		case 1:
			Warrior();
			interval();
			return;
		case 2:
			Lancer();
			interval();
			return;
		default:
			errorMessage();
			interval();
			break;
		}
	}
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
		<< "\nmp = " << mp << " / " << mpmax <<"\natk = " << atk << "\ndef = " << def << "\nloc = " << loc << endl;
	interval();
	return;
}
void Character::Warrior() {     // ����
	strcpy(job, "Warrior");
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
void Character::Lancer() {   // ����
	strcpy(job, "Lancer");
	hpmax = 50;
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
bool Character::run(int* _loc) {  // �̵�
	int goingNumber = 0;
	cout << "Where will you go? (1. Right // 2. Left)" << endl;
	cin >> goingNumber;
	
	switch (goingNumber) {
	case 1:	
		loc++; 
		if (loc == *_loc) {                  // ��ġ üŷ ������ġ�� �̵������ �޴���
			cout << "Same Location!" << endl;
			loc--;
			return true;
		}
		cout << "The distance between Your and the Enemy = " << abs(loc - *_loc) << endl;
		if (range >= abs(loc - *_loc))
			cout << "Attack Possible!" << endl;
		return false;
	case 2:	
		loc--;
		if (loc == *_loc) {                  // ��ġ üŷ ������ġ�� �̵������ �޴���
			cout << "Same Location!" << endl;
			loc++;
			return true;
		}
		cout << "The distance between Your and the Enemy = " << abs(loc - *_loc) << endl;
		if (range >= abs(loc - *_loc))
			cout << "Attack Possible!" << endl;
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Character::turn(int* _hp, int* _def, int* _loc, bool* turnState1, bool* turnState2) { // �÷��̾� �� (����÷��̾� hp, def, location, �� �÷��̾��� �� ���º���)
	int turnMenu = 0;
	bool locationState = true;
	bool gameState = true; // ������ ���� Ȯ��
	interval();
	cout << name << "'s Turn!\n1. attack // 2. skill // 3. rest // 4. run // 5. status" << endl;;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		if (abs(loc - *_loc) > range) {            // ��Ÿ�üũ
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
		*turnState1 = run(_loc);                // �̵� ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
	case 5:
		status();
		*turnState1 = true;                         // �������ͽ� Ȯ�� (���� �ѱ��� ����)
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
}
