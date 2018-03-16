#pragma once
#include <iostream>
using namespace std;

class Character
{
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
	int pos;
	Character();
	void charicterSet();                  // �÷��̾� ����(�̸�, ����)
	void status();                         // �÷��̾� �������ͽ�
	bool attack(int* _hp, int* _def);        // �����Լ�
	bool atkBuffSkill();                     // ���ݹ�����ų�Լ�
	void atkBack();                          // ������ų�����Լ�
	void rest();                             // �޽��Լ�
	bool hpCheck(int* _hp);                     // hpüũ�Լ�
	bool turn(int* _hp, int* _def, bool* turnState1, bool* turnState2);   // �� �÷��̾� ���� �ൿ�Լ�
	void interval();                                                         // ���м�
	~Character();
};

