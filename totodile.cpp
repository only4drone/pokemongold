#include "pch.h"
#include "totodile.h"

//������

totodile::totodile()
{
}

totodile::~totodile()
{
}

HRESULT totodile::init()
{
	switch (RND->getFromIntTo(0, 3))
	{
	case 0:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����	
		_poketmon.index = 158;								//����������ȣ 158
		_poketmon.level = RND->getFromIntTo(1, 18);			//ó�� ���� ���� 1~50
		_poketmon.type1 = static_cast<int>(TYPE::WATER);	//��Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�	
		_poketmon.attack = 65;								//����					
		_poketmon.defense = 64;								//���	
		_poketmon.specialAttack = 44;						//Ư������	
		_poketmon.specialDefense = 48;						//Ư�����	
		_poketmon.speed = 43;								//���ǵ�		

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.86f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.85f;						//������ ����
		_poketmon.levelSpecialAttack = 1.61f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.66f;				//������ Ư������
		_poketmon.levelSpeed = 1.6f;						//������ ���ǵ�
		_poketmon.levelHP = 2.54f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 50;			//ü��	
		_poketmon.currentExp;
		_poketmon.maxExp = 1059860;							//100���� ����ġ��	

		 //��ų

		_poketmon.skill[0] = 27;
		_poketmon.skill[1] = 17;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "��������";							//�̸� ��������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����	
		_poketmon.index = 159;								//����������ȣ 159
		_poketmon.level = RND->getFromIntTo(19, 50);		//ó�� ���� ���� 19~50
		_poketmon.type1 = static_cast<int>(TYPE::WATER);	//��Ÿ��	
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�	
		_poketmon.attack = 80;								//����					
		_poketmon.defense = 80;								//���	
		_poketmon.specialAttack = 59;						//Ư������	
		_poketmon.specialDefense = 63;						//Ư�����	
		_poketmon.speed = 58;								//���ǵ�			

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 2.04f;						//������ ���ݷ�
		_poketmon.levelDefense = 2.04f;						//������ ����
		_poketmon.levelSpecialAttack = 1.79f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.84f;				//������ Ư������
		_poketmon.levelSpeed = 1.78f;						//������ ���ǵ�
		_poketmon.levelHP = 2.69f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 65;			//ü��	
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��	

		//��ų

		_poketmon.skill[0] = 27;
		_poketmon.skill[1] = 17;
		_poketmon.skill[2] = 24;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 2:

		_poketmon.name = "��ũ�δ���";						//�̸� ��ũ�δ���
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����	
		_poketmon.index = 160;								//����������ȣ 160
		_poketmon.level = RND->getFromIntTo(30, 50);		//ó�� ���� ���� 30~50
		_poketmon.type1 = static_cast<int>(TYPE::WATER);	//��Ÿ��	
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
		_poketmon.evolutionLevel = 2;						//��ȭ�ܰ�	
		_poketmon.attack = 105;								//����					
		_poketmon.defense = 100;							//���	
		_poketmon.specialAttack = 79;						//Ư������	
		_poketmon.specialDefense = 83;						//Ư�����	
		_poketmon.speed = 78;								//���ǵ�		

		_poketmon.iconNumX = 14;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 2.34f;						//������ ���ݷ�
		_poketmon.levelDefense = 2.28f;						//������ ����
		_poketmon.levelSpecialAttack = 2.03f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 2.08f;				//������ Ư������
		_poketmon.levelSpeed = 2.02f;						//������ ���ǵ�
		_poketmon.levelHP = 2.89f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 85;			//ü��	
		_poketmon.currentExp;
		_poketmon.maxExp;									//����ġ��	

		//��ų

		_poketmon.skill[0] = 27;
		_poketmon.skill[1] = 17;
		_poketmon.skill[2] = 24;
		_poketmon.skill[3] = 25;


		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}

	return S_OK;

}

void totodile::release()
{
}

void totodile::update()
{
}

void totodile::render()
{
}
