#include "pch.h"
#include "pikachu.h"

//��ī��

pikachu::pikachu()
{
}

pikachu::~pikachu()
{
}

HRESULT pikachu::init()
{
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "��ī��";							//�̸� ��ī��
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 25;								//����������ȣ 25
		_poketmon.level = RND->getFromIntTo(1, 19);			//ó�� ���� ���� 1~50
		_poketmon.type1 = static_cast<int>(TYPE::ELECTR);	//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 55;								//����					
		_poketmon.defense = 40;								//���
		_poketmon.specialAttack = 50;						//Ư������
		_poketmon.specialDefense = 50;						//Ư�����
		_poketmon.speed = 90;								//���ǵ�		

		_poketmon.iconNumX = 28;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.74f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.56f;						//������ ����
		_poketmon.levelSpecialAttack = 1.68f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.68f;				//������ Ư������
		_poketmon.levelSpeed = 2.16f;						//������ ���ǵ�
		_poketmon.levelHP = 2.39f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 35;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100���� ����ġ��

		//��ų

		_poketmon.skill[0] = 18;
		_poketmon.skill[1] = 16;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 26;								//����������ȣ 26
		_poketmon.level = RND->getFromIntTo(20, 50);		//ó�� ���� ���� 1~15
		_poketmon.type1 = static_cast<int>(TYPE::ELECTR);	//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 90;								//����					
		_poketmon.defense = 55;								//���
		_poketmon.specialAttack = 90;						//Ư������
		_poketmon.specialDefense = 80;						//Ư�����
		_poketmon.speed = 110;								//���ǵ�		

		_poketmon.iconNumX = 28;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 2.16f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.74f;						//������ ����
		_poketmon.levelSpecialAttack = 2.16f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 2.04f;				//������ Ư������
		_poketmon.levelSpeed = 2.4f;						//������ ���ǵ�
		_poketmon.levelHP = 2.64f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 60;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//100���� ����ġ��

		//��ų

		_poketmon.skill[0] = 18;
		_poketmon.skill[1] = 14;
		_poketmon.skill[2] = 12;
		_poketmon.skill[3] = 19;

		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}


	return S_OK;


}

void pikachu::release()
{
}

void pikachu::update()
{
}

void pikachu::render()
{
}
