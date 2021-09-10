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
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "������";							//�̸� ������
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 21;								//����������ȣ 21
		_poketmon.level = RND->getFromIntTo(1, 19);			//ó�� ���� ���� 1~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//�븻 Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//���� Ÿ��
		_poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
		_poketmon.attack = 60;								//����					
		_poketmon.defense = 30;								//���
		_poketmon.specialAttack = 31;						//Ư������
		_poketmon.specialDefense = 31;						//Ư�����
		_poketmon.speed = 70;								//���ǵ�		

		_poketmon.iconNumX = 12;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 1.8f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.44f;						//������ ����
		_poketmon.levelSpecialAttack = 1.46f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.46f;				//������ Ư������
		_poketmon.levelSpeed = 1.92f;						//������ ���ǵ�
		_poketmon.levelHP = 2.44f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 40;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//100���� ����ġ��

		//��ų

		_poketmon.skill[0] = 15;
		_poketmon.skill[1] = 16;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "����帱��";						//�̸� ����帱��
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
		_poketmon.index = 22;								//����������ȣ 22
		_poketmon.level = RND->getFromIntTo(20, 50);		//ó�� ���� ���� 20~50

		potketmonEXP();										//����ġ

		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//��� Ÿ��
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//���� Ÿ��
		_poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
		_poketmon.attack = 90;								//����					
		_poketmon.defense = 65;								//���
		_poketmon.specialAttack = 61;						//Ư������
		_poketmon.specialDefense = 61;						//Ư�����
		_poketmon.speed = 100;								//���ǵ�		

		_poketmon.iconNumX = 12;							//���ϸ� �̴� ������ ��ǥx
		_poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

		_poketmon.levelAttack = 2.16f;						//������ ���ݷ�
		_poketmon.levelDefense = 1.86f;						//������ ����
		_poketmon.levelSpecialAttack = 1.82f;				//������ Ư�����ݷ�
		_poketmon.levelSpecialDefense = 1.82f;				//������ Ư������
		_poketmon.levelSpeed = 2.28f;						//������ ���ǵ�
		_poketmon.levelHP = 2.69f;							//������ ü��

		_poketmon.maxHP = _poketmon.currentHP = 65;			//ü��
		_poketmon.currentExp;
		_poketmon.maxExp;									//

		//��ų

		_poketmon.skill[0] = 15;
		_poketmon.skill[1] = 16;
		_poketmon.skill[2] = 17;
		_poketmon.skill[3] = 0;


		//potketmonEXP();

		genderSettings();

		ability();

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
