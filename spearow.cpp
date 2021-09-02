#include "pch.h"
#include "spearow.h"

//������

spearow::spearow()
{
}

spearow::~spearow()
{
}

HRESULT spearow::init()
{
	switch (RND->getFromIntTo(0, 1))
	{
	case 0:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 21;								//����������ȣ 21
		_poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//�븻 Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//���� Ÿ��
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 60;								//����					
		_poketmon.defense = 30;								//���
		_poketmon.specialAttack = 31;						//Ư������
		_poketmon.specialDefense = 31;						//Ư�����
		_poketmon.speed = 70;								//���ǵ�		

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

		_poketmon.name = "����帱��";						//�̸� ����帱��
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 22;								//����������ȣ 22
		_poketmon.level = RND->getFromIntTo(20, 50);		//ó�� ���� ���� 20~50
		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//��� Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//���� Ÿ��
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 90;								//����					
		_poketmon.defense = 65;								//���
		_poketmon.specialAttack = 61;						//Ư������
		_poketmon.specialDefense = 61;						//Ư�����
		_poketmon.speed = 100;								//���ǵ�		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 65;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;
	}


	return S_OK;

  
}

void spearow::release()
{
}

void spearow::update()
{
}

void spearow::render()
{
}
