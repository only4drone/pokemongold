#include "pch.h"
#include "chikorita.h"

//ġ�ڸ�Ÿ

chikorita::chikorita()
{
}

chikorita::~chikorita()
{
}

HRESULT chikorita::init()
{
    switch (RND->getFromIntTo(0, 3))
    {
    case 0:

        _poketmon.name = "ġ�ڸ�Ÿ";						//�̸� ġ�ڸ�Ÿ
        _poketmon.isGender = RND->getFromIntTo(0, 1);	    //����üũ ����
        _poketmon.index = 152;							    //����������ȣ 152
        _poketmon.level = RND->getFromIntTo(1, 50);		//ó�� ���� ���� 1~50
        _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //ǮŸ��
        _poketmon.type2 = static_cast<int>(TYPE::NONE);    //
        _poketmon.evolutionLevel = 0;					    //��ȭ�ܰ�
        _poketmon.attack = 49;							    //����					
        _poketmon.defense = 65;						    //���
        _poketmon.specialAttack = 49;                      //Ư������
        _poketmon.specialDefense = 65;                     //Ư�����
        _poketmon.speed = 45;							    //���ǵ�		

        _poketmon.iconNumX = 30;							//���ϸ� �̴� ������ ��ǥx
        _poketmon.iconNumY = 0;							//���ϸ� �̴� ������ ��ǥy

        _poketmon.levelAttack = 1.67f;                     //������ ���ݷ�
        _poketmon.levelDefense = 1.86f;                    //������ ����
        _poketmon.levelSpecialAttack = 1.67f;              //������ Ư�����ݷ�
        _poketmon.levelSpecialDefense = 1.86f;             //������ Ư������
        _poketmon.levelSpeed = 1.62f;                      //������ ���ǵ�
        _poketmon.levelHP = 2.49f;                         //������ ü��

        _poketmon.maxHP = _poketmon.currentHP = 45;		//ü��
        _poketmon.currentExp;
        _poketmon.maxExp;

        //��ų

        _poketmon.skill[0] = 1;
        _poketmon.skill[1] = 16;
        _poketmon.skill[2] = 0;
        _poketmon.skill[3] = 0;

        //potketmonEXP();

        genderSettings();

        ability();

        break;

    case 1:

        _poketmon.name = "���̸���";						//�̸� �����
        _poketmon.isGender = RND->getFromIntTo(0, 1);	    //����üũ ����
        _poketmon.index = 153;							    //����������ȣ 153
        _poketmon.level = RND->getFromIntTo(16, 50);	    //ó�� ���� ���� 16~50
        _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //ǮŸ��
        _poketmon.type2 = static_cast<int>(TYPE::NONE);	//
        _poketmon.evolutionLevel = 1;					    //��ȭ�ܰ�
        _poketmon.attack = 62;							    //����					
        _poketmon.defense = 80;							//���
        _poketmon.specialAttack = 63;                      //Ư������
        _poketmon.specialDefense = 80;                     //Ư�����
        _poketmon.speed = 60;							    //���ǵ�		

        _poketmon.iconNumX = 30;							//���ϸ� �̴� ������ ��ǥx
        _poketmon.iconNumY = 0;							//���ϸ� �̴� ������ ��ǥy

        _poketmon.levelAttack = 1.83f;                     //������ ���ݷ�
        _poketmon.levelDefense = 2.04f;                    //������ ����
        _poketmon.levelSpecialAttack = 1.83f;              //������ Ư�����ݷ�
        _poketmon.levelSpecialDefense = 2.04f;             //������ Ư������
        _poketmon.levelSpeed = 1.8f;                        //������ ���ǵ�
        _poketmon.levelHP = 2.64f;                         //������ ü��

        _poketmon.maxHP = _poketmon.currentHP = 60;		//ü��
        _poketmon.currentExp;
        _poketmon.maxExp;						            //����ġ��

        //��ų

        _poketmon.skill[0] = 1;
        _poketmon.skill[1] = 16;
        _poketmon.skill[2] = 20;
        _poketmon.skill[3] = 0;


        //potketmonEXP();

        genderSettings();

        ability();
        break;

    case 2:

        _poketmon.name = "�ް��Ͽ�";						//�̸� �ް��Ͽ�
        _poketmon.isGender = RND->getFromIntTo(0, 1);	    //����üũ ����
        _poketmon.index = 154;							    //����������ȣ 154
        _poketmon.level = RND->getFromIntTo(33, 70);	    //ó�� ���� ���� 33~70
        _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //ǮŸ��
        _poketmon.type2 = static_cast<int>(TYPE::NONE);	//
        _poketmon.evolutionLevel = 2;					    //��ȭ�ܰ�
        _poketmon.attack = 82;							    //����					
        _poketmon.defense = 100;						    //���
        _poketmon.specialAttack = 83;                      //Ư������
        _poketmon.specialDefense = 100;                    //Ư�����
        _poketmon.speed = 80;							    //���ǵ�	

        _poketmon.iconNumX = 30;							//���ϸ� �̴� ������ ��ǥx
        _poketmon.iconNumY = 0;							//���ϸ� �̴� ������ ��ǥy

        _poketmon.levelAttack = 2.07f;                     //������ ���ݷ�
        _poketmon.levelDefense = 2.28f;                    //������ ����
        _poketmon.levelSpecialAttack = 2.08f;              //������ Ư�����ݷ�
        _poketmon.levelSpecialDefense = 2.28f;             //������ Ư������
        _poketmon.levelSpeed = 2.04f;                      //������ ���ǵ�
        _poketmon.levelHP = 2.64f;                         //������ ü��

        _poketmon.maxHP = _poketmon.currentHP = 80;		//ü��
        _poketmon.currentExp;
        _poketmon.maxExp;						            //����ġ��

         //��ų

        _poketmon.skill[0] = 1;
        _poketmon.skill[1] = 16;
        _poketmon.skill[2] = 20;
        _poketmon.skill[3] = 21;


        //potketmonEXP();

        genderSettings();

        ability();

        break;
    }



    return S_OK;
}

void chikorita::release()
{
}

void chikorita::update()
{
}

void chikorita::render()
{
}
