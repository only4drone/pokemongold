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
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 13;								//����������ȣ 13
		_poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//��Ÿ��
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 35;								//����					
		_poketmon.defense = 30;								//���
		_poketmon.specialAttack = 20;						//Ư������
		_poketmon.specialDefense = 20;						//Ư�����
		_poketmon.speed = 50;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 40;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100���� ����ġ��
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 1:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 14;								//����������ȣ 14
		_poketmon.level = RND->getFromIntTo(7, 50);			//ó�� ���� ���� 7~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//��Ÿ��
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 25;								//����					
		_poketmon.defense = 50;								//���
		_poketmon.specialAttack = 25;						//Ư������
		_poketmon.specialDefense = 25;						//Ư�����
		_poketmon.speed = 35;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 45;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 2:

		_poketmon.name = "��ħ��";							//�̸� ��ħ��
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 15;								//����������ȣ 15
		_poketmon.level = RND->getFromIntTo(10, 50);		//ó�� ���� ���� 10~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//��Ÿ��
		_poketmon.evolutionLevel = 2;						//��ȭ�ܰ�
		_poketmon.attack = 90;								//����					
		_poketmon.defense = 40;								//���
		_poketmon.specialAttack = 45;						//Ư������
		_poketmon.specialDefense = 80;						//Ư�����
		_poketmon.speed = 75;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 65;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

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
