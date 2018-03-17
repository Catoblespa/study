#pragma once
#include <iostream>
#include "Map.h"

using namespace std;

class Character {
private:                                    // �÷��̾� ����(�̸�, ����, �ִ�ä��, �ִ븶��, ���ݷ�, ��Ÿ�)
	int hpmax;
	int mpmax;
	int atkback;
	int range;
	bool skillState = 0;                     // �����ߵ� ���� Ȯ�κ���

public: 
	char name[20];                                // ���� ����(����ä��, ���縶��, ������ݷ�, ����, ������ġ)
	char job[20];
	int hp;                                         
	int mp; 
	int atk;
	int def;
	int locx;
	
	Character();
	void charicterSet();                  // �÷��̾� ����(�̸�, ����)
	void status();                         // �÷��̾� �������ͽ�
	void Warrior();
	void Lancer();
	bool run(int* _locx);
	bool attack(int* _hp, int* _def);        // �����Լ�
	bool atkBuffSkill();                     // ���ݹ�����ų�Լ�
	void atkBack();                          // ������ų�����Լ�
	void rest();                             // �޽��Լ�
	bool hpCheck(int* _hp);                     // hpüũ�Լ�
	bool turn(int* _hp, int* _def, int* _locx, bool* turnState1, bool* turnState2, __int8 mapping[10][10]);   // �� �÷��̾� ���� �ൿ�Լ�
	void interval();                          // ���м�
	void errorMessage();                       // �����޼��� ���
	~Character();
};
