#include "pch.h"
#include "pidgey.h"

//����

pidgey::pidgey()
{
}

pidgey::~pidgey()
{
}

HRESULT pidgey::init()
{
    switch (RND->getFromIntTo(0, 3))
    {
    case 0:

        _poketmon.name = "����";							    //�̸� ����
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
        _poketmon.index = 16;								//����������ȣ 16
        _poketmon.level = RND->getFromIntTo(1, 50);			//ó�� ���� ���� 1~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//�븻Ÿ��
        _poketmon.type2 = static_cast<int>(TYPE::FLYING);	//����Ÿ��
        _poketmon.evolutionLevel = 0;						//��ȭ�ܰ�
        _poketmon.attack = 45;								//����					
        _poketmon.defense = 40;								//���
        _poketmon.specialAttack = 35;						//Ư������
        _poketmon.specialDefense = 35;						//Ư�����
        _poketmon.speed = 56;								//���ǵ�		

        _poketmon.iconNumX = 12;							//���ϸ� �̴� ������ ��ǥx
        _poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

        _poketmon.levelAttack = 1.62f;                      //������ ���ݷ�
        _poketmon.levelDefense = 1.56f;                     //������ ����
        _poketmon.levelSpecialAttack = 1.5f;                //������ Ư�����ݷ�       
        _poketmon.levelSpecialDefense = 1.5f;               //������ Ư������       
        _poketmon.levelSpeed = 1.76f;                       //������ ���ǵ�        
        _poketmon.levelHP = 2.44f;                          //������ ü��    

        _poketmon.maxHP = _poketmon.currentHP = 40;			//ü��
        _poketmon.currentExp;
        _poketmon.maxExp = 1059860;							//100���� ����ġ��

        //��ų

        _poketmon.skill[0] = 10;
        _poketmon.skill[1] = 11;
        _poketmon.skill[2] = 0;
        _poketmon.skill[3] = 0;

        //potketmonEXP();

        genderSettings();

        ability();

        break;

    case 1:

        _poketmon.name = "����";							    //�̸� ����
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
        _poketmon.index = 17;								//����������ȣ 17
        _poketmon.level = RND->getFromIntTo(19, 50);		//ó�� ���� ���� 19~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//���Ÿ��
        _poketmon.type2 = static_cast<int>(TYPE::FLYING);	//����Ÿ��
        _poketmon.evolutionLevel = 1;						//��ȭ�ܰ�
        _poketmon.attack = 60;								//����					
        _poketmon.defense = 55;								//���
        _poketmon.specialAttack = 50;						//Ư������
        _poketmon.specialDefense = 50;						//Ư�����
        _poketmon.speed = 71;								//���ǵ�		

        _poketmon.iconNumX = 12;							//���ϸ� �̴� ������ ��ǥx
        _poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

        _poketmon.levelAttack = 1.8f;                       //������ ���ݷ�
        _poketmon.levelDefense = 1.74f;                     //������ ����
        _poketmon.levelSpecialAttack = 1.68f;               //������ Ư�����ݷ�
        _poketmon.levelSpecialDefense = 1.68f;              //������ Ư������
        _poketmon.levelSpeed = 1.94f;                       //������ ���ǵ�
        _poketmon.levelHP = 2.67f;                          //������ ü��

        _poketmon.maxHP = _poketmon.currentHP = 63;			//ü��
        _poketmon.currentExp;
        _poketmon.maxExp;									//����ġ��

        //��ų

        _poketmon.skill[0] = 10;
        _poketmon.skill[1] = 11;
        _poketmon.skill[2] = 12;
        _poketmon.skill[3] = 0;

        //potketmonEXP();

        genderSettings();

        ability();

        break;

    case 2:

        _poketmon.name = "������";							//�̸� ������
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//����üũ ����
        _poketmon.index = 18;								//����������ȣ 18
        _poketmon.level = RND->getFromIntTo(36, 50);		//ó�� ���� ���� 36~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//���Ÿ��
        _poketmon.type2 = static_cast<int>(TYPE::FLYING);	//����Ÿ��
        _poketmon.evolutionLevel = 2;						//��ȭ�ܰ�
        _poketmon.attack = 80;								//����					
        _poketmon.defense = 75;								//���
        _poketmon.specialAttack = 70;						//Ư������
        _poketmon.specialDefense = 70;						//Ư�����
        _poketmon.speed = 101;								//���ǵ�		

        _poketmon.iconNumX = 12;							//���ϸ� �̴� ������ ��ǥx
        _poketmon.iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

        _poketmon.levelAttack = 2.04f;                      //������ ���ݷ�
        _poketmon.levelDefense = 1.98f;                     //������ ����
        _poketmon.levelSpecialAttack = 1.92f;               //������ Ư�����ݷ�
        _poketmon.levelSpecialDefense = 1.92f;              //������ Ư������
        _poketmon.levelSpeed = 2.3f;                        //������ ���ǵ�
        _poketmon.levelHP = 2.87f;                          //������ ü��

        _poketmon.maxHP = _poketmon.currentHP = 83;			//ü��
        _poketmon.currentExp;
        _poketmon.maxExp;									//����ġ��

        //��ų

        _poketmon.skill[0] = 10;
        _poketmon.skill[1] = 11;
        _poketmon.skill[2] = 12;
        _poketmon.skill[3] = 13;


        //potketmonEXP();

        genderSettings();

        ability();

        break;
    }

    return S_OK;

}

void pidgey::release()
{
}

void pidgey::update()
{
}

void pidgey::render()
{
}
