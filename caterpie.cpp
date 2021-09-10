#include "pch.h"
#include "caterpie.h"

//ĳ����

caterpie::caterpie()
{
}

caterpie::~caterpie()
{
}

HRESULT caterpie::init()
{
	switch (RND->getFromIntTo(0, 3))
	{
	case 0:

		_poketmon.name = "ĳ����";							//�̸� ĳ����
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//����üũ ����
		_poketmon.index = 10;								//����������ȣ 10
		_poketmon.level = RND->getFromIntTo(1, 6);			//ó�� ���� ���� 1~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 30;								//����					
		_poketmon.defense = 35;								//���
		_poketmon.specialAttack = 20;						//Ư������
		_poketmon.specialDefense = 20;						//Ư�����
		_poketmon.speed = 45;								//���ǵ�		

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 1;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.44f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.5f;						//������ ����
		_poketmon.levelSpecialAttack = 1.32f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.32f;				//������ Ư������
		_poketmon.levelSpeed = 1.62f;						//������ ���ǵ�
		_poketmon.levelHP = 2.49f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 45;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;

		//��ų

		_poketmon.skill[0] = 1;
		_poketmon.skill[1] = 2;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "�ܵ���";							//�̸� �ܵ���
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//����üũ ����
		_poketmon.index = 11;								//����������ȣ 11
		_poketmon.level = RND->getFromIntTo(7, 50);			//ó�� ���� ���� 7~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 20;								//����					
		_poketmon.defense = 55;								//���
		_poketmon.specialAttack = 25;						//Ư������
		_poketmon.specialDefense = 25;						//Ư�����
		_poketmon.speed = 30;								//���ǵ�	

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 1;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.32f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.74f;					//������ ����
		_poketmon.levelSpecialAttack = 1.38f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.38f;				//������ Ư������
		_poketmon.levelSpeed = 1.44f;						//������ ���ǵ�
		_poketmon.levelHP = 2.54f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 50;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��

		//��ų

		_poketmon.skill[0] = 26;
		_poketmon.skill[1] = 0;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 2:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//����üũ ����
		_poketmon.index = 12;								//����������ȣ 12
		_poketmon.level = RND->getFromIntTo(10, 50);		//ó�� ���� ���� 10~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//����Ÿ��
		_poketmon.evolutionLevel = 2;						//��ȭ�ܰ�
		_poketmon.attack = 45;								//����					
		_poketmon.defense = 50;								//���
		_poketmon.specialAttack = 80;						//Ư������
		_poketmon.specialDefense = 80;						//Ư�����
		_poketmon.speed = 70;								//���ǵ�		

		_poketmon.iconNumX = 26;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 1;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.62f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.68f;						//������ ����
		_poketmon.levelSpecialAttack = 2.16f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 2.04f;				//������ Ư������
		_poketmon.levelSpeed = 1.92f;						//������ ���ǵ�
		_poketmon.levelHP = 2.64f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 60;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��

		//��ų

		_poketmon.skill[0] = 3;
		_poketmon.skill[1] = 4;
		_poketmon.skill[2] = 5;
		_poketmon.skill[3] = 6;

		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}



	return S_OK;

}

void caterpie::release()
{
}

void caterpie::update()
{

}

void caterpie::render()
{
}
