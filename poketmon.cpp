#include "pch.h"
#include "poketmon.h"

#include <math.h>

poketmon::poketmon()
{
}

poketmon::~poketmon()
{
}

HRESULT poketmon::init()
{


    return S_OK;
}

void poketmon::release()
{
}

void poketmon::update()
{

}

void poketmon::attackAI()
{

}

void poketmon::genderSettings()
{
    if (_poketmon.isGender)         // ���ϸ� ����üũ�� Ʈ���Ͻ�
    {
        _poketmon.gender = "����";  // ���ϸ��� ������ ������ �ȴ�
    }
    else _poketmon.gender = "����"; // �� ���� ���ϸ��� ������ ������ �ȴ�.


}

void poketmon::potketmonEXP()
{

    //���ϸ� ������ ���� ����ġ���� 3������ �ϰ� �װ� int�� �����ؾ���
    //cbrt �������� 

    _poketmon.level = static_cast<int>(cbrt(_poketmon.totalEXP));

    //�ƽ� ����ġ��  ������ 3������

    _poketmon.maxExp = pow(_poketmon.level + 1, 3) - pow(_poketmon.level, 3);

    //���� ����ġ�� ��Ż ����ġ���� ���� ���� 3�����ѰŸ� ���� ����

    _poketmon.currentExp = _poketmon.totalEXP - pow(_poketmon.level, 3);

}

void poketmon::ability()
{
    //���� �ɷ�ġ��     =     1���� �ɷ�ġ  +        ������ �ɷ�ġ  * ���� �̴�.
    _poketmon.sumAttack = _poketmon.attack + (_poketmon.levelAttack * _poketmon.level);                               //���ݷ�       
    _poketmon.sumDefense = _poketmon.defense + (_poketmon.levelDefense * _poketmon.level);                            //����
    _poketmon.sumMaxHP = _poketmon.maxHP + (_poketmon.levelHP * _poketmon.level);                                     //hp
    _poketmon.sumSpecialAttack = _poketmon.specialAttack + (_poketmon.levelSpecialAttack * _poketmon.level);          //Ư�����ݷ�
    _poketmon.sumSpecialDefense = _poketmon.specialDefense + (_poketmon.levelSpecialDefense * _poketmon.level);       //Ư������
    _poketmon.sumSpeed = _poketmon.speed + (_poketmon.levelSpeed * _poketmon.level);                                  //���ǵ�

    _poketmon.currentHP = _poketmon.sumMaxHP;                                                                         //����ü�� ���ϸ󺼷� ������ ����

}

void poketmon::render()
{

}


