#include "pch.h"
#include "rattata.h"

//����

rattata::rattata()
{
}

rattata::~rattata()
{
}

HRESULT rattata::init()
{
    switch (RND->getFromIntTo(0, 1))
    {
    case 0:

        _poketmon.name = "����";							    //�̸� ����
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
        _poketmon.index = 19;								//����������ȣ 19
        _poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//�븻 Ÿ��
        _poketmon.type2 = static_cast<int>(TYPE::NONE);		//
        _poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
        _poketmon.attack = 56;								//����					
        _poketmon.defense = 35;								//���
        _poketmon.specialAttack = 25;						//Ư������
        _poketmon.specialDefense = 35;						//Ư�����
        _poketmon.speed = 72;								//���ǵ�		

        _poketmon.levelAttack = 1;
        _poketmon.levelDefense;
        _poketmon.levelSpecialAttack;
        _poketmon.levelSpecialDefense;
        _poketmon.levelSpeed;
        _poketmon.levelHP = 2;

        _poketmon.maxHP = _poketmon.currentHP = 30;			//ü��
        _poketmon.currentExp;
        _poketmon.maxExp = 1000000;							//100���� ����ġ��
        _poketmon.skill1;
        _poketmon.skill2;
        _poketmon.skill3;
        _poketmon.skill4;

        break;

    case 1:

        _poketmon.name = "��Ʈ��";							//�̸� ��Ʈ��
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
        _poketmon.index = 20;								//����������ȣ 20
        _poketmon.level = RND->getFromIntTo(20, 50);		//ó�� ���� ���� 20~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//���Ÿ��
        _poketmon.type2 = static_cast<int>(TYPE::NONE);		//
        _poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
        _poketmon.attack = 81;								//����					
        _poketmon.defense = 60;								//���
        _poketmon.specialAttack = 50;						//Ư������
        _poketmon.specialDefense = 70;						//Ư�����
        _poketmon.speed = 97;								//���ǵ�		

        _poketmon.levelAttack = 1;
        _poketmon.levelDefense;
        _poketmon.levelSpecialAttack;
        _poketmon.levelSpecialDefense;
        _poketmon.levelSpeed;
        _poketmon.levelHP = 2;

        _poketmon.maxHP = _poketmon.currentHP = 55;			//ü��
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

void rattata::release()
{
}

void rattata::update()
{
}

void rattata::render()
{
}
