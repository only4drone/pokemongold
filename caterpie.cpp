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
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "ĳ����";							//�̸� ĳ����
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 10;								//����������ȣ 10
		_poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 30;								//����					
		_poketmon.defense = 35;								//���
		_poketmon.specialAttack = 20;						//Ư������
		_poketmon.specialDefense = 20;						//Ư�����
		_poketmon.speed = 45;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 45;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100���� ����ġ��
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 1:

		_poketmon.name = "�ܵ���";							//�̸� �ܵ���
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 11;								//����������ȣ 11
		_poketmon.level = RND->getFromIntTo(7, 50);			//ó�� ���� ���� 7~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 20;								//����					
		_poketmon.defense = 55;								//���
		_poketmon.specialAttack = 25;						//Ư������
		_poketmon.specialDefense = 25;						//Ư�����
		_poketmon.speed = 30;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 50;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 2:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 12;								//����������ȣ 12
		_poketmon.level = RND->getFromIntTo(10, 50);		//ó�� ���� ���� 10~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//����Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//����Ÿ��
		_poketmon.evolutionLevel = 2;						//��ȭ�ܰ�
		_poketmon.attack = 45;								//����					
		_poketmon.defense = 50;								//���
		_poketmon.specialAttack = 80;						//Ư������
		_poketmon.specialDefense = 80;						//Ư�����
		_poketmon.speed = 70;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 60;			//ü��
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

void caterpie::release()
{
}

void caterpie::update()
{
}

void caterpie::render()
{
}
