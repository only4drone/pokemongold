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
    switch (RND->getFromIntTo(0,2))
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

         _poketmon.levelAttack;
         _poketmon.levelDefense;
         _poketmon.levelSpecialAttack;
         _poketmon.levelSpecialDefense;
         _poketmon.levelSpeed;
         _poketmon.levelHP;

         _poketmon.maxHP = _poketmon.currentHP = 45;		//ü��
         _poketmon.currentExp;
         _poketmon.maxExp = 1059860;						//100���� ����ġ��
         _poketmon.skill1;
         _poketmon.skill2;
         _poketmon.skill3;
         _poketmon.skill4;

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

         _poketmon.levelAttack;
         _poketmon.levelDefense;
         _poketmon.levelSpecialAttack;
         _poketmon.levelSpecialDefense;
         _poketmon.levelSpeed;
         _poketmon.levelHP;

         _poketmon.maxHP = _poketmon.currentHP = 60;		//ü��
         _poketmon.currentExp;
         _poketmon.maxExp;						            //����ġ��
         _poketmon.skill1;
         _poketmon.skill2;
         _poketmon.skill3;
         _poketmon.skill4;

         break;

     case 2:                                                
         
         _poketmon.name = "�ް��Ͽ�";						//�̸� �ް��Ͽ�
         _poketmon.isGender = RND->getFromIntTo(0, 1);	    //����üũ ����
         _poketmon.index = 154;							    //����������ȣ 154
         _poketmon.level = RND->getFromIntTo(33, 70);	    //ó�� ���� ���� 33~70
         _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //ǮŸ��
         _poketmon.type2 = static_cast<int>(TYPE::NONE);	//
         _poketmon.evolutionLevel = 0;					    //��ȭ�ܰ�
         _poketmon.attack = 82;							    //����					
         _poketmon.defense = 100;						    //���
         _poketmon.specialAttack = 83;                      //Ư������
         _poketmon.specialDefense = 100;                    //Ư�����
         _poketmon.speed = 80;							    //���ǵ�		

         _poketmon.levelAttack = 1;
         _poketmon.levelDefense;
         _poketmon.levelSpecialAttack;
         _poketmon.levelSpecialDefense;
         _poketmon.levelSpeed;
         _poketmon.levelHP = 2;

         _poketmon.maxHP = _poketmon.currentHP = 80;		//ü��
         _poketmon.currentExp;
         _poketmon.maxExp;						            //����ġ��
         _poketmon.skill1;
         _poketmon.skill2;
         _poketmon.skill3;
         _poketmon.skill4;
                  
         break;
     }
   


    return S_OK;
}

void chikorita::release()
{
}

void chikorita::update()
{
    _poketmon.sumMaxHP = _poketmon.maxHP + (_poketmon.levelHP * _poketmon.level);
    _poketmon.sumAttack = _poketmon.attack + (_poketmon.levelAttack * _poketmon.level);



}

void chikorita::render()
{
}
