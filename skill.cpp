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

	_imgName = "lightScreen";							//ó���� ���� ��


	_index = _currentFrame = _frameCount = 0;		//�ִϸ��̼� ���� �ʱ�ȭ

	_isWhoSkill = false;							//�ʱ�ȭ
	_isSkill = false;							//�ʱ�ȭ

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{

	//�ؿ� Ű�Ŵ������� üũ�ҷ��� ���� �͵� ���߿� ������ ��
	if (KEYMANAGER->isOnceKeyDown('P')) _isSkill = true;
	if (KEYMANAGER->isOnceKeyDown('I')) _isWhoSkill = true;	//�� (�÷��̾�)
	if (KEYMANAGER->isOnceKeyDown('U')) _isWhoSkill = false;	//�߻�

	if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	rc = RectMake(480, _imgPoint.y, 112, 112);	// ���ϸ��� ��� ��� �� ���� ����


	skillAni();

}

void skill::skillNone()			//��ų����
{
	_skillNumber = 0;			//��ų�ѹ�

	_name = "";					//�̸�

	_power = NULL;				//����
	_PP = NULL;					//PP
	_accuracy = NULL;			//���߷�

	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::tackle()			// �����ġ��
{

	_skillNumber = 1;			//��ų�ѹ�

	_name = "�����ġ��";		//�̸�
	_imgName = "attack3";		//�̹����̸�

	_power = 40;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��

}

void skill::stringShot()		//�ǻձ�
{
	_skillNumber = 2;			//��ų�ѹ�

	_name = "�ǻձ�";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 40;					//PP
	_accuracy = 95;				//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);					//Ÿ��

}

void skill::confusion()			//������
{
	_skillNumber = 3;			//��ų�ѹ�

	_name = "������";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 50;				//����
	_PP = 25;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);				//Ÿ��	
}

void skill::poisonPowder()		//������
{
	_skillNumber = 4;			//��ų�ѹ�

	_name = "������";			//�̸�
	_imgName = "poison";		//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 35;					//PP
	_accuracy = 75;				//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);				//Ÿ��
	_ifAilment = STATUS_AILMENT::POISON;		//�����̻�
}

void skill::stunSpore()			//��������
{
	_skillNumber = 5;			//��ų�ѹ�

	_name = "��������";			//�̸�
	_imgName = "poison";		//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = 75;				//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);				//Ÿ��
	_ifAilment = STATUS_AILMENT::PARALYSIS;	//�����̻�
}

void skill::sleepPowder()		//���鰡��
{
	_skillNumber = 6;			//��ų�ѹ�

	_name = "���鰡��";			//�̸�
	_imgName = "poison";		//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 15;					//PP
	_accuracy = 75;				//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);				//Ÿ��
	_ifAilment = STATUS_AILMENT::SLEEP;		//�����̻�
}

void skill::poisonSting()		//��ħ
{
	_skillNumber = 7;			//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "��ħ";				//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 15;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);				//Ÿ��

	if (_index > 80) STATUS_AILMENT::POISON;	//�����̻� 20�� Ȯ����..

}

void skill::focusEnergy()		//������
{
	_skillNumber = 8;			//��ų�ѹ�

	_name = "������";			//�̸�
	_imgName = "growth";		//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = NULL;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::twineedle()			//����ϵ�
{
	_skillNumber = 9;			//��ų�ѹ�

	_name = "����ϵ�";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 25;				//����
	_PP = 20;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);					//Ÿ��
}

void skill::sandAttack()		//�𷡻Ѹ���
{
	_skillNumber = 10;			//��ų�ѹ�

	_name = "�𷡻Ѹ���";		//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 15;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GROUND);				//Ÿ��

}

void skill::gust()				//�ٶ�����Ű��
{
	_skillNumber = 11;			//��ų�ѹ�

	_name = "�ٶ�����Ű��";		//�̸�
	_imgName = "squall";		//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 40;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);				//Ÿ��
}

void skill::quickAttack()		//������ȭ
{
	_skillNumber = 12;			//��ų�ѹ�

	_name = "������ȭ";			//�̸�
	_imgName = "move";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 40;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::wingAttack()		//����ġ��
{
	_skillNumber = 13;			//��ų�ѹ�

	_name = "����ġ��";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 60;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);				//Ÿ��
}

void skill::tailWhip()			//��������
{
	_skillNumber = 14;			//��ų�ѹ�

	_name = "��������";		//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::peck()				//�ɱ�
{
	_skillNumber = 15;			//��ų�ѹ�

	_name = "�ɱ�";				//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 35;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);				//Ÿ��
}

void skill::growl()				//�����Ҹ�
{
	_skillNumber = 16;			//��ų�ѹ�

	_name = "�����Ҹ�";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 40;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::leer()				//°������
{
	_skillNumber = 17;			//��ų�ѹ�

	_name = "°������";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::thunderShock()		//�����ũ
{
	_skillNumber = 18;			//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "�����ũ";			//�̸�
	_imgName = "spark";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 40;				//����
	_PP = 30;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);				//Ÿ��

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//�����̻� 10��Ȯ���� ����

}

void skill::thunderbolt()		//10����Ʈ
{
	_skillNumber = 19;			//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "10����Ʈ";			//�̸�
	_imgName = "spark";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 90;				//����
	_PP = 15;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);				//Ÿ��

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//�����̻� 10�� Ȯ���� ����
}

void skill::razorLeaf()			//�ٳ�������
{
	_skillNumber = 20;			//��ų�ѹ�

	_name = "�ٳ�������";		//�̸�
	_imgName = "bind";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 55;				//����
	_PP = 25;					//PP
	_accuracy = 95;				//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);				//Ÿ��
}

void skill::reflect()			//���÷��� ���������� �ݰ�.
{
	_skillNumber = 21;			//��ų�ѹ�

	_name = "���÷���";			//�̸�
	_imgName = "lightScreen";	//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 20;					//PP
	_accuracy = NULL;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);				//Ÿ��
}

void skill::smokescreen()		//����
{
	_skillNumber = 22;			//��ų�ѹ�

	_name = "����";				//�̸�
	_imgName = "smokescreen";	//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 20;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::ember()				//�Ҳɼ���
{
	_skillNumber = 23;			//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "�Ҳɼ���";			//�̸�
	_imgName = "fire";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 40;				//����
	_PP = 25;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FIRE);					//Ÿ��

	if (_index > 90) STATUS_AILMENT::BURN; //�����̻�
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//��밡 �������¸� ���� �� ���� --��������--
}

void skill::rage()				//�г�
{
	_skillNumber = 24;			//��ų�ѹ�

	_name = "�г�";				//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 20;				//����
	_PP = 20;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::waterGun()			//������
{
	_skillNumber = 25;			//��ų�ѹ�

	_name = "������";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 40;				//����
	_PP = 25;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::WATER);				//Ÿ��
}

void skill::harden()			//�ܴ�������
{
	_skillNumber = 26;			//��ų�ѹ�

	_name = "�ܴ�������";		//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = NULL;				//����
	_PP = 30;					//PP
	_accuracy = NULL;			//���߷�
	_ifcation = CLASSIFCATION::CHANGE;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::scratch()			//������
{
	_skillNumber = 27;			//��ų�ѹ�

	_name = "������";			//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 40;				//����
	_PP = 35;					//PP
	_accuracy = 100;			//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::furyAttack()		//�������
{
	_skillNumber = 28;			//��ų�ѹ�

	_name = "�������";		//�̸�
	_imgName = "cut";			//�̹����̸�

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	�÷��̾� �Ͻ�
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	�߻��Ͻ�

	_power = 15;				//����
	_PP = 20;					//PP
	_accuracy = 85;				//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;		//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//Ÿ��
}

void skill::render()
{


	char str[128];

	if (_isSkill) Rectangle(getMemDC(), rc);

	if (_isSkill) IMAGEMANAGER->frameRender(_imgName, getMemDC(), _imgPoint.x, _imgPoint.y, _currentFrame, 0);



	//sprintf_s(str, "��ǥx : %d ", _imgPoint.x);
	//TextOut(getMemDC(), 50, 50, str, strlen(str));
	//sprintf_s(str, "��ǥy : % d ", _imgPoint.y);
	//TextOut(getMemDC(), 50, 70, str, strlen(str));
	//sprintf_s(str, "���� : %d ", _isWhoSkill);
	//TextOut(getMemDC(), 50, 90, str, strlen(str));


}

void skill::skillAni()
{

	// ��ų �ִϸ��̼��� ������ ������ �����̱� ������ isSkill�̶�� ���� �־ ���� �ִ� �ؾ��Ұ� ����
	// isSkill�� true ���϶� �̹����� �߰� �ִϸ��̼��� ������ isSkill�� false���� �Ǵ°� ���� ����
	// �ִϸ��̼��� ���ư����� �ϴ� �ʿ��ϴ�.


	if (_isSkill)	//��ų�� Ȱ��ȭ ������
	{
		_frameCount++;		//������ ������
		_count++;			//�����ð��ڿ� ������ �ҷ���

		if (_frameCount % 4 == 0)	//�ӵ� ���� �����ȵǴ°� �����ϴ�.
		{
			_currentFrame++; //���������� �����

			//IMAGEMANAGER->findImage(_imgName)->setFrameX(IMAGEMANAGER->findImage(_imgName)->getFrameX() + 1);


			if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count < 100)		//�ϴ��� �����̹��� ���̾� �ҷ����� && �����ð��� 200count�� �帣��
			{
				_currentFrame = 0;					//�������� �ʱ�ȭ ���� ��� �̹����� �ݺ���Ű��
			}
			else if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count > 100)		//�ƽ��������̰� ī���Ͱ� 200�̻��̸� ������ �̹����� ������.
			{
				_isSkill = false;					//���ǿ� ������ ��ų�� ��Ȱ��ȭ ���Ѽ� �̹����� �����
				_count = 0;							//ī���͸� �ٽ� �ʱ�ȭ �����ش�
			}

		}

	}



}

void skill::imageInit()	//��ų �̹���
{
	IMAGEMANAGER->addFrameImage("attack", "image/skill/attack.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bind", "image/skill/bind.bmp", 1440, 90, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut", "image/skill/cut.bmp", 1440, 150, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fire", "image/skill/fire.bmp", 176, 100, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("growth", "image/skill/growth.bmp", 2160, 144, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("horn", "image/skill/horn.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("attack3", "image/skill/attack3.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut3", "image/skill/cut3.bmp", 144, 36, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lightScreen", "image/skill/lightScreen.bmp", 900, 126, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "image/skill/move.bmp", 440, 112, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poison", "image/skill/poison.bmp", 3240, 100, 27, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shine", "image/skill/shine.bmp", 418, 38, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shock", "image/skill/shock.bmp", 138, 42, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snap", "image/skill/snap.bmp", 960, 40, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("spark", "image/skill/spark.bmp", 352, 44, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("squall", "image/skill/squall.bmp", 1118, 57, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("slash", "image/skill/slash.bmp", 480, 60, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skyAttack", "image/skill/skyAttack.bmp", 600, 70, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("smokescreen", "image/skill/smokescreen.bmp", 560, 20, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("razonWind", "image/skill/razonWind.bmp", 1456, 112, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("confuseRay", "image/skill/confuseRay.bmp", 312, 78, 4, 1, true, RGB(255, 0, 255));


}

void skill::skillNumLink(int index)		// ��ų�� ��ų�ѹ��� ���� �ؼ� �Ѱ���?
{
	_skillNumber = index;
	switch (_skillNumber)
	{
	case 0:
		skillNone();
		break;
	case 1:
		tackle();
		break;
	case 2:
		stringShot();
		break;
	case 3:
		confusion();
		break;
	case 4:
		poisonPowder();
		break;
	case 5:
		stunSpore();
		break;
	case 6:
		sleepPowder();
		break;
	case 7:
		poisonSting();
		break;
	case 8:
		focusEnergy();
		break;
	case 9:
		twineedle();
		break;
	case 10:
		sandAttack();
		break;
	case 11:
		gust();
		break;
	case 12:
		quickAttack();
		break;
	case 13:
		wingAttack();
		break;
	case 14:
		tailWhip();
		break;
	case 15:
		peck();
		break;
	case 16:
		growl();
		break;
	case 17:
		leer();
		break;
	case 18:
		thunderShock();
		break;
	case 19:
		thunderbolt();
		break;
	case 20:
		razorLeaf();
		break;
	case 21:
		reflect();
		break;
	case 22:
		smokescreen();
		break;
	case 23:
		ember();
		break;
	case 24:
		rage();
		break;
	case 25:
		waterGun();
		break;
	case 26:
		harden();
		break;
	case 27:
		scratch();
		break;
	case 28:
		furyAttack();
		break;
	}

}
