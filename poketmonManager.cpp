#include "pch.h"
#include "poketmonManager.h"
#include "character.h"

poketmonManager::poketmonManager()
{
}

poketmonManager::~poketmonManager()
{
}

HRESULT poketmonManager::init()
{
    poketmonImage();



    return S_OK;
}

void poketmonManager::release()
{

}

void poketmonManager::update()
{

}

void poketmonManager::poketmonSpawn()
{
    // ������ �ְ�
    // RND->getFromIntTo(0, 10);

    // ����ġ������ ���� ���
    
    ////ġ�ڸ�Ÿ
    //poketmon* monster;
    //monster = new chikorita;
    //monster->init();
    //_vPoketmon.push_back(monster);

    ////������
    //poketmon* monster;
    //monster = new cyndaquil;
    //monster->init();
    //_vPoketmon.push_back(monster);

    ////������
    //poketmon* monster;
    //monster = new totodile;
    //monster->init();
    //_vPoketmon.push_back(monster);

    ////��ī��
    //poketmon* monster;
    //monster = new pikachu;
    //monster->init();
    //_vPoketmon.push_back(monster);

}

void poketmonManager::render()
{

}

void poketmonManager::poketmonImage()
{
    //���ϸ� ��
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_155F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��������_��", "image/poketmon/no_156F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("���̹�_��", "image/poketmon/no_157F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ġ�ڸ�Ÿ_��", "image/poketmon/no_152Fbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("���̸���_��", "image/poketmon/no_153F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ް��Ͽ�_��", "image/poketmon/no_154F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_158F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��������_��", "image/poketmon/no_159F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ũ�δ���_��", "image/poketmon/no_160F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ī��_��", "image/poketmon/no_25F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_26F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����_��", "image/poketmon/no_19F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��Ʈ��_��", "image/poketmon/no_20F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����_��", "image/poketmon/no_16F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����_��", "image/poketmon/no_17F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_18F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_21F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����帱��_��", "image/poketmon/no_22F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ĳ����_��", "image/poketmon/no_10F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ܵ���_��", "image/poketmon/no_11F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_12F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_13F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_14F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ħ��_��", "image/poketmon/no_15F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));

}


