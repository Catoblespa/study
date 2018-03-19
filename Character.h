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
	char* name;                                // ���� ����(����ä��, ���縶��, ������ݷ�, ����, ������ġ)
	char* job;
	int hp;                                         
	int mp; 
	int atk;
	int def;
	int locx;
	int locy;
	
	Character();                              // �÷��̾� ����(�̸�, ����)
	void status();                         // �÷��̾� �������ͽ�
	void Warrior(const char* jobname);
	void Lancer(const char* jobname);
	bool run(int* _locx, int* _locy, Map* map);
	bool attack(int* _hp, int* _def);        // �����Լ�
	bool atkBuffSkill();                     // ���ݹ�����ų�Լ�
	void atkBack();                          // ������ų�����Լ�
	void rest();                             // �޽��Լ�
	bool hpCheck(int* _hp);                     // hpüũ�Լ�
	bool turn(int* _hp, int* _def, int* _locx, int* _locy, bool* turnState1, bool* turnState2, Map* map);   // �� �÷��̾� ���� �ൿ�Լ�
	void interval();                          // ���м�
	void errorMessage();                       // �����޼��� ���
	~Character();
};

