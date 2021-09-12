#include "pch.h"
#include "weedle.h"

weedle::weedle()
{
}

weedle::~weedle()
{
}

HRESULT weedle::init()
{
	switch (RND->getFromIntTo(0, 3))
	{
	case 0:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//����üũ ����
		_poketmon.index = 13;								//����������ȣ 13
		_poketmon.level = RND->getFromIntTo(1, 6);			//ó�� ���� ���� 1~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//��Ÿ��
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 35;								//����					
		_poketmon.defense = 30;								//���
		_poketmon.specialAttack = 20;						//Ư������
		_poketmon.specialDefense = 20;						//Ư�����
		_poketmon.speed = 50;								//���ǵ�		

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 1;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.5f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.44f;						//������ ����
		_poketmon.levelSpecialAttack = 1.32f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.32f;				//������ Ư������
		_poketmon.levelSpeed = 1.68f;						//������ ���ǵ�
		_poketmon.levelHP = 2.44f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 40;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100���� ����ġ��

		//��ų

		_poketmon.skill[0] = 7;
		_poketmon.skill[1] = 2;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//����üũ ����
		_poketmon.index = 14;								//����������ȣ 14
		_poketmon.level = RND->getFromIntTo(7, 10);			//ó�� ���� ���� 7~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//��Ÿ��
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 25;								//����					
		_poketmon.defense = 50;								//���
		_poketmon.specialAttack = 25;						//Ư������
		_poketmon.specialDefense = 25;						//Ư�����
		_poketmon.speed = 35;								//���ǵ�		

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 1;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.38f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.68f;						//������ ����
		_poketmon.levelSpecialAttack = 1.38f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.38f;				//������ Ư������
		_poketmon.levelSpeed = 1.5f;						//������ ���ǵ�
		_poketmon.levelHP = 2.49f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 45;			//ü��
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

		_poketmon.name = "��ħ��";							//�̸� ��ħ��
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//����üũ ����
		_poketmon.index = 15;								//����������ȣ 15
		_poketmon.level = RND->getFromIntTo(11, 15);		//ó�� ���� ���� 10~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//��Ÿ��
		_poketmon.evolutionLevel = 2;						//��ȭ�ܰ�
		_poketmon.attack = 90;								//����					
		_poketmon.defense = 40;								//���
		_poketmon.specialAttack = 45;						//Ư������
		_poketmon.specialDefense = 80;						//Ư�����
		_poketmon.speed = 75;								//���ǵ�		

		_poketmon.iconNumX = 20;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 2.16f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.56f;						//������ ����
		_poketmon.levelSpecialAttack = 1.62f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 2.04f;				//������ Ư������
		_poketmon.levelSpeed = 1.98f;						//������ ���ǵ�
		_poketmon.levelHP = 2.69f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 65;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��

		//��ų

		_poketmon.skill[0] = 28;
		_poketmon.skill[1] = 8;
		_poketmon.skill[2] = 9;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}

	return S_OK;

}

void weedle::release()
{
}

void weedle::update()
{
}

void weedle::render()
{
}
