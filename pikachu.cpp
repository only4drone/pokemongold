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
	switch (RND->getFromIntTo(0,1))
	{
		case 0:

			_poketmon.name = "��ī��";							//�̸� ��ī��
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
			_poketmon.index = 25;								//����������ȣ 25
			_poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
			_poketmon.type1 = static_cast<int>(TYPE::ELECTR);	//����Ÿ��
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
			_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
			_poketmon.attack = 55;								//����					
			_poketmon.defense = 40;								//���
			_poketmon.specialAttack = 50;						//Ư������
			_poketmon.specialDefense = 50;						//Ư�����
			_poketmon.speed = 90;								//���ǵ�		

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 35;			//ü��
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

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 60;			//ü��
			_poketmon.currentExp;
			_poketmon.maxExp;									//100���� ����ġ��
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

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
