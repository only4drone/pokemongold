#include "pch.h"
#include "skill.h"
#include "poketmon.h"

skill::skill()
{
}

skill::~skill()
{
}

HRESULT skill::init()
{
	imageInit();

	STATUS_AILMENT::NONE;	// �����̻� �ʱⰪ�� ����

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
}

void skill::render()
{
}

void skill::tackle()			// �����ġ��
{
	_power = 40;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::NOMAL;				//Ÿ��

}

void skill::stringShot()		//�ǻձ�
{
	_power = NULL;				//����
	_PP = 40;					//PP
	_accuracy = 95;				//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::BUG;					//Ÿ��

}

void skill::harden()			//�ܴ�������
{
	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = NULL;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::confusion()			//������
{
	_power = 50;				//����
	_PP = 25;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::SPECIAL;		//�з�
	TYPE::PSYCHC;				//Ÿ��	
}

void skill::poisonPowder()		//������
{
	_power = NULL;				//����
	_PP = 35;					//PP
	_accuracy = 75;				//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::POISON;				//Ÿ��
	STATUS_AILMENT::POISON;		//�����̻�
}

void skill::stunSpore()			//��������
{
	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = 75;				//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::GRASS;				//Ÿ��
	STATUS_AILMENT::PARALYSIS;	//�����̻�
}

void skill::sleepPowder()		//���鰡��
{
	_power = NULL;				//����
	_PP = 15;					//PP
	_accuracy = 75;				//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::GRASS;				//Ÿ��
	STATUS_AILMENT::SLEEP;		//�����̻�
}

void skill::poisonSting()		//��ħ
{
	_index = RND->getFromIntTo(0, 100);

	_power = 15;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::POISON;				//Ÿ��

	if (_index > 80) STATUS_AILMENT::POISON;	//�����̻� 20�� Ȯ����..

}

void skill::focusEnergy()		//������
{
	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = NULL;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::twineedle()			//����ϵ�
{
	_power = 25;				//����
	_PP = 20;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::BUG;					//Ÿ��
}

void skill::sandAttack()		//�𷡻Ѹ���
{
	_power = NULL;				//����
	_PP = 15;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::GROUND;				//Ÿ��

}

void skill::gust()				//�ٶ�����Ű��
{
	_power = 40;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::SPECIAL;		//�з�
	TYPE::FLYING;				//Ÿ��
}

void skill::quickAttack()		//������ȭ
{
	_power = 40;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::wingAttack()		//����ġ��
{
	_power = 60;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::FLYING;				//Ÿ��
}

void skill::tailWhip()			//��������
{
	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::peck()				//�ɱ�
{
	_power = 35;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::FLYING;				//Ÿ��
}

void skill::growl()				//�����Ҹ�
{
	_power = NULL;				//����
	_PP = 40;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::leer()				//°������
{
	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::thunderShock()		//�����ũ
{
	_index = RND->getFromIntTo(0, 100);

	_power = 40;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::SPECIAL;		//�з�
	TYPE::ELECTR;				//Ÿ��

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//�����̻� 10��Ȯ���� ����

}

void skill::thunderbolt()		//10����Ʈ
{
	_index = RND->getFromIntTo(0, 100);

	_power = 90;				//����
	_PP = 15;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::SPECIAL;		//�з�
	TYPE::ELECTR;				//Ÿ��

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//�����̻� 10�� Ȯ���� ����
}

void skill::razorLeaf()			//�ٳ�������
{
	_power = 55;				//����
	_PP = 25;					//PP
	_accuracy = 95;				//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::GRASS;				//Ÿ��
}

void skill::reflect()			//���÷��� ���������� �ݰ�.
{
	_power = NULL;				//����
	_PP = 20;					//PP
	_accuracy = NULL;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::PSYCHC;				//Ÿ��
}

void skill::smokescreen()		//����
{
	_power = NULL;				//����
	_PP = 20;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::CHANGE;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::ember()				//�Ҳɼ���
{
	_index = RND->getFromIntTo(0, 100);

	_power = 40;				//����
	_PP = 25;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::SPECIAL;		//�з�
	TYPE::FIRE;					//Ÿ��

	if (_index > 90) STATUS_AILMENT::BURN; //�����̻�
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//��밡 �������¸� ���� �� ���� --��������--
}

void skill::rage()				//�г�
{
	_power = 20;				//����
	_PP = 20;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::PHYSICS;		//�з�
	TYPE::NOMAL;				//Ÿ��
}

void skill::waterGun()			//������
{
	_power = 40;				//����
	_PP = 25;					//PP
	_accuracy = 100;			//���߷�
	CLASSIFCATION::SPECIAL;		//�з�
	TYPE::WATER;				//Ÿ��
}

void skill::imageInit()	//��ų �̹���
{
	IMAGEMANAGER->addImage("attack", "image/skill/attack.bmp", 32, 32, true, RGB(255, 0, 255));							
	IMAGEMANAGER->addFrameImage("bind", "image/skill/bind.bmp", 720, 45, 12, 1, true, RGB(255, 0, 255));				
	IMAGEMANAGER->addFrameImage("cut", "image/skill/cut.bmp", 600, 50, 12, 1, true, RGB(255, 0, 255));					
	IMAGEMANAGER->addFrameImage("fire", "image/skill/fire.bmp", 352, 20, 8, 1, true, RGB(255, 0, 255));					
	IMAGEMANAGER->addFrameImage("growth", "image/skill/growth.bmp", 1152, 72, 12, 1, true, RGB(255, 0, 255));			
	IMAGEMANAGER->addFrameImage("horn", "image/skill/horn.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("attack3", "image/skill/attack3.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut3", "image/skill/cut3.bmp", 144, 36, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lightScreen", "image/skill/lightScreen.bmp", 450, 63, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "image/skill/move.bmp", 220, 56, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poison", "image/skill/poison.bmp", 1620, 50, 27, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shine", "image/skill/shine.bmp", 418, 38, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shock", "image/skill/shock.bmp", 138, 42, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snap", "image/skill/snap.bmp", 960, 40, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("spark", "image/skill/spark.bmp", 352, 44, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("squall", "image/skill/squall.bmp", 1118, 57, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("slash", "image/skill/slash.bmp", 480, 60, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skyAttack", "image/skill/skyAttack.bmp", 600, 70, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("smokescreen", "image/skill/smokescreen.bmp", 560, 20, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("razonWind", "image/skill/razonWind.bmp", 1456, 112, 13, 1, true, RGB(255, 0, 255));
	

}
