#include "Character.h"

Character::Character()
{
}
void Character::charicterSet()
{
	cout << "name = ";
	cin >> name;
	cout << "hp = ";
	cin >> hp;
	cout << "mp = ";
	cin >> mp;
	cout << "atk = ";
	cin >> atk;
	cout << "def = ";
	cin >> def;
} // ĳ���� ����
void Character::run() {
	speed = 15;
	if (sp <= 0) {
		sp = 0;
		cout << "Not enough sp" << endl;
		walk();
		return;
	}
	sp -= 3;
	return ;
}  // �޸���
void Character::walk() { // �ȱ�
	speed = 10;
	if (sp < spmax) {
		sp += 3;
	}
	return;
}
void Character::hpCheck() { // hpüũ
	if (hp <= 0) {
		cout << name << " Die" << endl;
	}
	return;
}
void Character::attack(int _hp, int _def) {	// ����
	_hp = _hp - (_def - atk);
	if (skillCount == 1) {
		atkBack();
	}
	return;
}
void Character::atkBuffSkill() { // ���ù���
	if (skillCount == 1) {
		cout << "���� ������...." << endl;
		return;
	}
	else if (mp < 3) {
		cout << "Not enough mp" << endl;
		return;
	}
	atk += 10;
	mp -= 3;
	skillCount = 1;
	return;
}
void Character::atkBack() { // ���������Լ�	
	atk = atkback;
	skillCount = 0;
	return;
}
void Character::viewCharacter() { // �������ͽ�
	cout << "name = " << name << "\nhp = " << hp << "\nmp = " << mp << "\nsp = " << sp << "\natk = " << atk << "\ndef = " << def << endl;
}
void Character::rest() { // �޽�
	if (hp < hpmax) {
		hp += 5;
	}
	if (mp < mpmax) {
		mp += 5;
	}
	return;
}
Character::~Character()
{
}
