#include "pch.h"
#include "poketmon.h"

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

void poketmon::render()
{
}


