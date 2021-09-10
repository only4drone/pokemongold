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
    _skill = new skill;					//��ų 
    _skill->init();


    poketmonImage();

    poketmonSpawn();

    wildPoketmonSetting();

    

    return S_OK;
}

void poketmonManager::release()
{

}

void poketmonManager::update()
{
    if (KEYMANAGER->isOnceKeyDown('G'))
    {
        _wildPoketmon.currentHP -= 5;       //ü�±�°� Ȯ��
    }

    _skill->update();
}

void poketmonManager::poketmonSpawn()
{
   
    // ���ϸ��� ���ͷ� ����ְ� �ҷ��ö��� �������� �ѹ� �ҷ����°� ��� ��� ������ �� ����� ����
    // 1�� ���Ϳ� ��´�.  2�� ���͸� �������� ������. 3�� ���Ϳ� �ִ°� ���Ϳ� ��´�. 4�� ���͸� ���ͷ� �ѱ��.
    // 5�� �ѱ� ���ϸ��� ���͸� �����Ѵ�.
    // 1���� �ɷ�ġ ���������� �޾ƿ��°� Ȯ��  

    //ġ�ڸ�Ÿ                                              

    chikorita* monster0;
    monster0 = new chikorita;
    monster0->init();
    _vPoketmon.push_back(monster0);

    //������
    poketmon* monster1;
    monster1 = new cyndaquil;
    monster1->init();
    _vPoketmon.push_back(monster1);

    //������
    poketmon* monster2;
    monster2 = new totodile;
    monster2->init();
    _vPoketmon.push_back(monster2);

    //��ī��
    poketmon* monster3;
    monster3 = new pikachu;
    monster3->init();
    _vPoketmon.push_back(monster3);

    //����
    poketmon* monster4;
    monster4 = new pidgey;
    monster4->init();
    _vPoketmon.push_back(monster4);

    //������
    poketmon* monster5;
    monster5 = new weedle;
    monster5->init();
    _vPoketmon.push_back(monster5);

    //ĳ����
    poketmon* monster6;
    monster6 = new caterpie;
    monster6->init();
    _vPoketmon.push_back(monster6);

    //������
    poketmon* monster7;
    monster7 = new spearow;
    monster7->init();
    _vPoketmon.push_back(monster7);

    //��Ʈ��
    poketmon* monster8;
    monster8 = new rattata;
    monster8->init();
    _vPoketmon.push_back(monster8);
}

void poketmonManager::wildPoketmonSetting()     //�߻����ϸ� ����
{

    _randomPoketmon = RND->getFromIntTo(0, 8);                           //���� �߻����ϸ� ����

    _wildPoketmon.name = _vPoketmon[_randomPoketmon]->getTagPoketmon().name;                         //�߻����ϸ� �̸�
    _wildPoketmon.gender = _vPoketmon[_randomPoketmon]->getTagPoketmon().gender;                       //�߻����ϸ� ����
    _wildPoketmon.isGender = _vPoketmon[_randomPoketmon]->getTagPoketmon().isGender;                     //�߻����ϸ� ����Ȯ��
    _wildPoketmon.index = _vPoketmon[_randomPoketmon]->getTagPoketmon().index;                        //�߻����ϸ� ��ȣ
    _wildPoketmon.level = _vPoketmon[_randomPoketmon]->getTagPoketmon().level;                        //�߻����ϸ� ����
    _wildPoketmon.evolutionLevel = _vPoketmon[_randomPoketmon]->getTagPoketmon().evolutionLevel;               //�߻����ϸ� ��ȭ�ܰ�

    _wildPoketmon.iconNumX = _vPoketmon[_randomPoketmon]->getTagPoketmon().iconNumX;                     //�̴� ���ϸ� �̹��� ������ ��ǥ X
    _wildPoketmon.iconNumY = _vPoketmon[_randomPoketmon]->getTagPoketmon().iconNumY;                     //�̴� ���ϸ� �̹��� ������ ��ǥ Y

    _wildPoketmon.type1 = _vPoketmon[_randomPoketmon]->getTagPoketmon().type1;                        //Ÿ��1
    _wildPoketmon.type2 = _vPoketmon[_randomPoketmon]->getTagPoketmon().type2;                        //Ÿ��2

    _wildPoketmon.attack = _vPoketmon[_randomPoketmon]->getTagPoketmon().attack;                       //1���� ���ݷ�
    _wildPoketmon.defense = _vPoketmon[_randomPoketmon]->getTagPoketmon().defense;                      //1���� ����
    _wildPoketmon.specialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().specialAttack;                //1���� Ư�����ݷ�   
    _wildPoketmon.specialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().specialDefense;               //1���� Ư������
    _wildPoketmon.speed = _vPoketmon[_randomPoketmon]->getTagPoketmon().speed;                        //1���� ���ǵ�

    _wildPoketmon.currentHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().currentHP;                    //����ü��
    _wildPoketmon.maxHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().maxHP;                        //1���� �ִ�ü��;

    _wildPoketmon.levelAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelAttack;                  //������ ���ݷ�
    _wildPoketmon.levelDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelDefense;                 //������ ����
    _wildPoketmon.levelSpecialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpecialAttack;           //������ Ư�����ݷ�
    _wildPoketmon.levelSpecialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpecialDefense;          //������ Ư������
    _wildPoketmon.levelSpeed = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpeed;                   //������ ���ǵ�
    _wildPoketmon.levelHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelHP;                      //������ HP

    _wildPoketmon.sumAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumAttack;                    //���� �����
    _wildPoketmon.sumDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumDefense;                   //���� ����
    _wildPoketmon.sumSpecialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpecialAttack;             //���� Ư�����ݷ�
    _wildPoketmon.sumSpecialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpecialDefense;            //���� Ư������
    _wildPoketmon.sumSpeed = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpeed;                     //���� ���ǵ�
    _wildPoketmon.sumMaxHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumMaxHP;                     //���� �ִ�HP

    _wildPoketmon.currentExp = _vPoketmon[_randomPoketmon]->getTagPoketmon().currentExp;                   //���� ����ġ
    _wildPoketmon.maxExp = _vPoketmon[_randomPoketmon]->getTagPoketmon().maxExp;                       //��������
    _wildPoketmon.totalEXP = _vPoketmon[_randomPoketmon]->getTagPoketmon().totalEXP;                     //���� ������ �ִ� ����ġ

    _wildPoketmon.skill[0] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[0];                       //��ų1
    _wildPoketmon.skill[1] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[1];                       //��ų2
    _wildPoketmon.skill[2] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[2];                       //��ų3
    _wildPoketmon.skill[3] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[3];                       //��ų4

    _wildPoketmon.skillPP[0] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[0];                     //��ų1PP
    _wildPoketmon.skillPP[1] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[1];                     //��ų2PP
    _wildPoketmon.skillPP[2] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[2];                     //��ų3PP
    _wildPoketmon.skillPP[3] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[3];                     //��ų4PP

    _wildPoketmon.item = _vPoketmon[_randomPoketmon]->getTagPoketmon().item;                         //������..

   
}

void poketmonManager::render()
{
    char str[128];

    char poke[128];

    // string strname = myPokemon[i].name;
    // strcpy_s(poke, strname.c_str());


    string strnmae = _wildPoketmon.name;
    strcpy_s(poke, strnmae.c_str());

  sprintf_s(str, "���ϸ� �̸� : %s", poke);
  TextOut(getMemDC(), 280, 180, str, strlen(str));
  sprintf_s(str, "���ϸ� ����ü�� : %d ", _wildPoketmon.currentHP);
  TextOut(getMemDC(), 280, 200, str, strlen(str));
   // sprintf_s(str, "���ϸ� ���� : %d ", _wildPoketmon.level);
   // TextOut(getMemDC(), 100, 320, str, strlen(str));
   // sprintf_s(str, "���ϸ� ��ų��ȣ : %d ", _wildPoketmon.skill1);
   // TextOut(getMemDC(), 100, 340, str, strlen(str));

    _skill->render();
}

void poketmonManager::poketmonImage()
{
    //���ϸ� ��
    IMAGEMANAGER->addFrameImage("155F", "image/poketmon/no_155F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("156F", "image/poketmon/no_156F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("157F", "image/poketmon/no_157F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("152F", "image/poketmon/no_152Fbmp", 160, 160, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("153F", "image/poketmon/no_153F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("154F", "image/poketmon/no_154F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("158F", "image/poketmon/no_158F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("159F", "image/poketmon/no_159F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("160F", "image/poketmon/no_160F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("25F", "image/poketmon/no_25F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("26F", "image/poketmon/no_26F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("19F", "image/poketmon/no_19F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("20F", "image/poketmon/no_20F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("16F", "image/poketmon/no_16F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("17F", "image/poketmon/no_17F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("18F", "image/poketmon/no_18F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("21F", "image/poketmon/no_21F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("22F", "image/poketmon/no_22F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("10F", "image/poketmon/no_10F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("11F", "image/poketmon/no_11F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("12F", "image/poketmon/no_12F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("13F", "image/poketmon/no_13F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("14F", "image/poketmon/no_14F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("15F", "image/poketmon/no_15F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));

}


