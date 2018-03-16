#include "Character.h"

Character::Character()
{
}
void Character::interval() {     // ���м�
	cout << "==============================================================" << endl;
} 
void Character::charicterSet() // ĳ���� ����
{
	cout << "(word length < 20)name = ";
	cin >> name;
	cout << "hp = ";
	cin >> hpmax;
	hp = hpmax;
	cout << "mp = ";
	cin >> mpmax;
	mp = mpmax;
	cout << "atk = ";
	cin >> atkback;
	atk = atkback;
	cout << "def = ";
	cin >> def;
	interval();
}
bool Character::hpCheck(int* _hp) { // hpüũ
	if (*_hp <= 0) {
		cout << name << " Win" << endl;
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
	else if (mp < 3) {
		cout << "Not enough MP" << endl;
		return true;
	}
	atk += 10;
	mp -= 3;
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
	cout << "name = " << name << "\nhp = " << hp << " / " << hpmax 
		<< "\nmp = " << mp << " / " << mpmax <<"\natk = " << atk << "\ndef = " << def << endl;
	interval();
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
bool Character::turn(int* _hp, int* _def, bool* turnState1, bool* turnState2) { // �÷��̾� �� (����÷��̾� hp, def, �� �÷��̾��� �� ���º���)
	status();
	int turnMenu = 0;
	bool gameState = true; // ������ ���� Ȯ��
	cout << name << "'s Turn " << "1. attack // 2. skill // 3. rest" << endl;;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		gameState = attack(_hp, _def);
		break;
	case 2:
		*turnState1 = atkBuffSkill();
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 3:
		rest();
		break;
	default:
		cout << "error!" << endl;
		*turnState1 = true;
		return gameState;
	}
	*turnState1 = false;
	*turnState2 = true;

	return gameState;
}
Character::~Character()
{
}
