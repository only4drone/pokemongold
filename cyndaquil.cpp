#include "pch.h"
#include "cyndaquil.h"

//������

cyndaquil::cyndaquil()
{
}

cyndaquil::~cyndaquil()
{
}

HRESULT cyndaquil::init()
{
	switch (RND->getFromIntTo(0,2))
	{
		case 0:

			_poketmon.name = "������";							//�̸� ������
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
			_poketmon.index = 155;								//����������ȣ 155
			_poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
			_poketmon.type1 = static_cast<int>(TYPE::FIRE);		//��Ÿ��
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
			_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
			_poketmon.attack = 52;								//����					
			_poketmon.defense = 43;								//���
			_poketmon.specialAttack = 60;						//Ư������
			_poketmon.specialDefense = 50;						//Ư�����
			_poketmon.speed = 65;								//���ǵ�		

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 39;			//ü��
			_poketmon.currentExp;
			_poketmon.maxExp = 1059860;							//100���� ����ġ��
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

			break;
		
		case 1:

			_poketmon.name = "��������";							//�̸� ��������
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
			_poketmon.index = 156;								//����������ȣ 156
			_poketmon.level = RND->getFromIntTo(15, 50);		//ó�� ���� ���� 15~50
			_poketmon.type1 = static_cast<int>(TYPE::FIRE);		//��Ÿ��
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
			_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
			_poketmon.attack = 64;								//����					
			_poketmon.defense = 58;								//���
			_poketmon.specialAttack = 80;						//Ư������
			_poketmon.specialDefense = 65;						//Ư�����
			_poketmon.speed = 80;								//���ǵ�		

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 58;			//ü��
			_poketmon.currentExp;
			_poketmon.maxExp;									//����ġ��
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

			break;
		
		case 2:

			_poketmon.name = "���̹�";							//�̸� ���̹�
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
			_poketmon.index = 157;								//����������ȣ 157
			_poketmon.level = RND->getFromIntTo(36, 50);		//ó�� ���� ���� 36~50
			_poketmon.type1 = static_cast<int>(TYPE::FIRE);		//��Ÿ��
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
			_poketmon.evolutionLevel = 2;						//��ȭ�ܰ�
			_poketmon.attack = 84;								//����					
			_poketmon.defense = 78;								//���
			_poketmon.specialAttack = 109;						//Ư������
			_poketmon.specialDefense = 85;						//Ư�����
			_poketmon.speed = 100;								//���ǵ�		

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 78;			//ü��
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

void cyndaquil::release()
{
}

void cyndaquil::update()
{
}

void cyndaquil::render()
{
}
