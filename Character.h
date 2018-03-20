#pragma once
#include <iostream>
#include "Map.h"

using namespace std;

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
	Character();                              // �÷��̾� ����(�̸�, ����)
	Character(const Character &player);         // �÷��̾� 2 ���� (�����̸�, �ٸ�����)
	void status();                         // �÷��̾� �������ͽ�
	virtual bool run(Character* player2, Character* Monster1, Character* Monster2, Map* map);
	bool attack(Character* player2, Character* Monster1, Character* Monster2, Map* map, bool* turnState1, bool* turnState2);        // �����Լ�
	bool playerAttack(Character* player2);              // �÷��̾� ��������
	bool monsterAttack(Character* Monster1);              // ���� ��������
	bool atkBuffSkill();                     // ���ݹ�����ų�Լ�
	void atkBack();                          // ������ų�����Լ�
	void rest();                             // �޽��Լ�
	bool playerhpCheck(int _hp);                     // �÷��̾�hpüũ�Լ�
	bool monsterhpCheck(Character* Monster);                     // ����hpüũ�Լ�
	virtual bool turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, Map* map);   // �� �÷��̾� ���� �ൿ�Լ�
	void interval();                          // ���м�
	void errorMessage();                       // �����޼��� ���
	virtual ~Character();
};

