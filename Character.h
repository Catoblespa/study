#pragma once
#include <iostream>
#include "Map.h"
#include <windows.h>
#include "item.h"
#include <random>

using namespace std;

static bool dropItem = false;

enum EquipSlot
{
	WeaponSlot,
	ArmorSlot,
};

class Character {
protected:                                    // �÷��̾� ����(�̸�, ����, �ִ�ä��, �ִ븶��, ���ݷ�, ��Ÿ�)
	int hpmax;
	int mpmax;
	int atkback;
	int range;
	bool skillState = 0;                     // �����ߵ� ���� Ȯ�κ���
	int speed = 1;

public:
	char* name;                                // ���� ����(����ä��, ���縶��, ������ݷ�, ����, ������ġ)
	char* job;
	int hp;
	int mp;
	int atk;
	int def;
	int locx;
	int locy;

	item* equipedItem[2];

	Character();                              // �÷��̾� ����(�̸�, ����)
	Character(const Character &player);         // �÷��̾� 2 ���� (�����̸�, �ٸ�����)
	void status();                         // �÷��̾� �������ͽ�
	virtual bool run(Character* player2, Character* Monster1, Character* Monster2, Map* map, item* Item1, item* Item2);
	virtual bool attack(Character* player2, Character* Monster1, Character* Monster2, Map* map, bool* turnState1, bool* turnState2);        // �����Լ�
	virtual bool playerAttack(Character* player2);              // �÷��̾� ��������
	bool monsterAttack(Character* Monster1);              // ���� ��������
	virtual bool atkBuffSkill();                     // ���ݹ�����ų�Լ�
	void atkBack();                          // ������ų�����Լ�
	void rest();                             // �޽��Լ�
	virtual bool playerhpCheck(const char* _name, int _hp);                     // �÷��̾�hpüũ�Լ�
	bool monsterhpCheck(Character* Monster);                     // ����hpüũ�Լ�
	virtual bool turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, Map* map, item* Item1, item* Item2);   // �� �÷��̾� ���� �ൿ�Լ�
	void interval();                          // ���м�
	void errorMessage();                       // �����޼��� ���
	void dropItemCheck(Map* map, Character* Monster);
	int GenerateRandom(int min, int max);
	void EquipItem(EquipSlot slot, item* Item);
	virtual ~Character();
};

