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

    _poketmon.level = static_cast<int>(cbrt(_poketmon.currentExp));
    
    //�ƽ� ����ġ��  ������ 3������

    _poketmon.maxExp = pow(_poketmon.level, 3);

}

void poketmon::render()
{
}


