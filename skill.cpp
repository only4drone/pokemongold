#include "pch.h"
#include "skill.h"
#include "poketmon.h"
#include "poketmonManager.h"

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
		

	_index = _currentFrame = _frameCount = 0;		//�ִϸ��̼� ���� �ʱ�ȭ

	//_isWhoSkill = true;
	_isSkill = false;								//�ʱ�ȭ

	_imgX = 0;
	_imgY = 0;

	if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	�߻��Ͻ�
	if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	�÷��̾� �Ͻ�

	SOUNDMANAGER->addSound("�����ġ��", "soundFX/BodySlam.wav", true, false);

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
	

	//�ؿ� Ű�Ŵ������� üũ�ҷ��� ���� �͵� ���߿� ������ ��
	//if (KEYMANAGER->isOnceKeyDown('K')) _isSkill = true;
	//if (KEYMANAGER->isOnceKeyDown('I')) _isWhoSkill = true;			//�� (�÷��̾�)
	//if (KEYMANAGER->isOnceKeyDown('U')) _isWhoSkill = false;		//�߻�

	if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	�߻��Ͻ�
	if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	�÷��̾� �Ͻ�
	
	skillAni();
	


}

void skill::skillNone()													//��ų����
{
	//_skillNumber = 0;													//��ų�ѹ�

	_name = " -";														//�̸�

	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = 0;
		_imgY = 0;
	}
	_power = NULL;														//����
	_PP = NULL;															//PP
	_accuracy = NULL;													//���߷�

	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::tackle()													// �����ġ��
{

	//_skillNumber = 1;													//��ų�ѹ�

	_name = "�����ġ��";												//�̸�


	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = 25;
		_imgY = 0;
	}
	_imgName = "attack";												//�̹����̸�

	

	_power = 40;														//����
	_PP = 35;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��

}

void skill::stringShot()												//�ǻձ�
{
	//_skillNumber = 2;													//��ų�ѹ�

	_name = "�ǻձ�";													//�̸�
	
	if (!_isWhoSkill)
	{

		_imgX = -200;
		_imgY = 0;

		_imgName = "mystringShot";											//�̹����̸�
	
	}


	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -100;

		_imgName = "wildstringShot";											//�̹����̸�
		
	}


	_power = NULL;														//����
	_PP = 40;															//PP
	_accuracy = 95;														//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);						//Ÿ��

}

void skill::confusion()													//������
{
	//_skillNumber = 3;													//��ų�ѹ�

	_name = "������";													//�̸�
	if (!_isWhoSkill)
	{
		_imgX = -200;
		_imgY = 50;

		_imgName = "myconfusion";											//�̹����̸�
	}
	
	
	if (_isWhoSkill)
	{
		_imgX = 125;
		_imgY = -100;

		_imgName = "wildconfusion";											//�̹����̸�
	}										


	_power = 50;														//����
	_PP = 25;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);					//Ÿ��	
}

void skill::poisonPowder()												//������
{
	//_skillNumber = 4;													//��ų�ѹ�

	_name = "������";													//�̸�
	_imgName = "poison";												//�̹����̸�
	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = -80;
		_imgY = -50;
	}
	_power = NULL;														//����
	_PP = 35;															//PP
	_accuracy = 75;														//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);					//Ÿ��
	_ifAilment = STATUS_AILMENT::POISON;								//�����̻�
}

void skill::stunSpore()													//��������
{
	//_skillNumber = 5;													//��ų�ѹ�

	_name = "��������";													//�̸�
	_imgName = "poison";												//�̹����̸�
	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = -80;
		_imgY = -50;
	}
	_power = NULL;														//����
	_PP = 30;															//PP
	_accuracy = 75;														//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);					//Ÿ��
	_ifAilment = STATUS_AILMENT::PARALYSIS;								//�����̻�
}

void skill::sleepPowder()												//���鰡��
{
	//_skillNumber = 6;													//��ų�ѹ�

	_name = "���鰡��";													//�̸�
	_imgName = "poison";												//�̹����̸�
	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = -80;
		_imgY = -50;
	}
	_power = NULL;								 						//����
	_PP = 15;															//PP
	_accuracy = 75;														//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);					//Ÿ��
	_ifAilment = STATUS_AILMENT::SLEEP;									//�����̻�
}

void skill::poisonSting()												//��ħ
{
	//_skillNumber = 7;													//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "��ħ";														//�̸�
	
	
	if (!_isWhoSkill)
	{
		_imgName = "mypoisonSting";											//�̹����̸�
		
		_imgX = -150;
		_imgY = 70;

	}
	
	if (_isWhoSkill)
	{
		_imgName = "wildpoisonSting";

		_imgX = 150;
		_imgY = -70;
	}


	_power = 15;														//����
	_PP = 35;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);					//Ÿ��

	if (_index > 80) STATUS_AILMENT::POISON;							//�����̻� 20�� Ȯ����..

}

void skill::focusEnergy()												//������
{
	//_skillNumber = 8;													//��ų�ѹ�

	_name = "������";													//�̸�


	_imgName = "growth";

	if (!_isWhoSkill)
	{	

		_imgX = -380;
		_imgY = 160;

	}

	if (_isWhoSkill)
	{	
		_imgX = 300;
		_imgY = -220;
	}


	_power = NULL;														//����
	_PP = 30;															//PP
	_accuracy = NULL;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::twineedle()													//����ϵ�
{
	//_skillNumber = 9;													//��ų�ѹ�

	_name = "����ϵ�";													//�̸�
	
	if (!_isWhoSkill)
	{
		_imgName = "myhorn";

		_imgX = -150;
		_imgY = 70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildhorn";

		_imgX = 150;
		_imgY = -70;
	}




	_power = 25;														//����
	_PP = 20;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);						//Ÿ��
}

void skill::sandAttack()												//�𷡻Ѹ���
{
	//_skillNumber = 10;												//��ų�ѹ�

	_name = "�𷡻Ѹ���";												//�̸�
	
	if (!_isWhoSkill)
	{
		_imgName = "mysandAttack";

		_imgX = -200;
		_imgY = 0;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildsandAttack";

		_imgX = 80;
		_imgY = -150;
	}

	_power = NULL;														//����
	_PP = 15;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GROUND);					//Ÿ��

}

void skill::gust()														//�ٶ�����Ű��
{
	//_skillNumber = 11;												//��ų�ѹ�

	_name = "�ٶ�����Ű��";												//�̸�
	_imgName = "squall";												//�̹����̸�

	if (!_isWhoSkill)
	{
		
		_imgX = 0;
		_imgY = 0;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = 25;
	}


	_power = 40;														//����
	_PP = 35;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);					//Ÿ��
}

void skill::quickAttack()												//������ȭ
{
	//_skillNumber = 12;												//��ų�ѹ�

	_name = "������ȭ";													//�̸�
	
	if (!_isWhoSkill)
	{
		_imgName = "myquickAttack";

		_imgX = -400;
		_imgY = -15;
	}
	if (_isWhoSkill)
	{
		_imgName = "wildquickAttack";

		_imgX =  -100;
		_imgY = -250;
	}

	_power = 40;														//����
	_PP = 30;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::wingAttack()												//����ġ��
{
	//_skillNumber = 13;												//��ų�ѹ�

	_name = "����ġ��";													//�̸�
	_imgName = "wingAttack";											//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -50;
		_imgY = 0;
	}
	if (_isWhoSkill)
	{

		_imgX = -20;
		_imgY = 20;
	}

	

	_power = 60;														//����
	_PP = 35;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);					//Ÿ��
}

void skill::tailWhip()													//��������
{
	//_skillNumber = 14;												//��ų�ѹ�

	_name = "��������";												//�̸�
	_imgName = "tailWhip";													//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -50;
		_imgY = -50;
	}
	if (_isWhoSkill)
	{

		_imgX = -20;
		_imgY = -50;
	}


	_power = NULL;														//����
	_PP = 30;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::peck()														//�ɱ�
{
	//_skillNumber = 15;												//��ų�ѹ�

	_name = "�ɱ�";														//�̸�
	
	if (!_isWhoSkill)
	{
		_imgName = "mypoisonSting";

		_imgX = -150;
		_imgY = 70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildpoisonSting";

		_imgX = 150;
		_imgY = -70;
	}

	_power = 35;														//����
	_PP = 35;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);					//Ÿ��
}

void skill::growl()														//�����Ҹ�
{
	//_skillNumber = 16;												//��ų�ѹ�

	_name = "�����Ҹ�";													//�̸�

	if (!_isWhoSkill)
	{
		_imgName = "mygrowl";

		_imgX = -200;
		_imgY = 50;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildgrowl";

		_imgX = 180;
		_imgY = -270;
	}

	_power = NULL;														//����
	_PP = 40;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::leer()														//°������
{
	//_skillNumber = 17;												//��ų�ѹ�

	_name = "°������";													//�̸�
	

	if (!_isWhoSkill)
	{
		_imgName = "myleer";

		_imgX = -250;
		_imgY = 0;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildleer";

		_imgX = 50;
		_imgY = -150;
	}
	

	_power = NULL;														//����
	_PP = 30;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::thunderShock()												//�����ũ
{
	//_skillNumber = 18;												//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "�����ũ";													//�̸�
								
	
	_imgName = "thunderShock";

	if (!_isWhoSkill)
	{
		_imgX = -60;
		_imgY = -100;

	}

	if (_isWhoSkill)
	{
		_imgX = -45;
		_imgY = -100;
	}
	
		
	
	

	_power = 40;														//����
	_PP = 30;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);					//Ÿ��

	if (_index > 90) STATUS_AILMENT::PARALYSIS;							//�����̻� 10��Ȯ���� ����

}

void skill::thunderbolt()												//10����Ʈ
{
	//_skillNumber = 19;												//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "10����Ʈ";													//�̸�
	
	_imgName = "spark";

	if (!_isWhoSkill)
	{
		_imgX = -10;
		_imgY = -50;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -50;
	}
	

	_power = 90;														//����
	_PP = 15;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);					//Ÿ��

	if (_index > 90) STATUS_AILMENT::PARALYSIS;							//�����̻� 10�� Ȯ���� ����
}

void skill::razorLeaf()													//�ٳ�������
{
	//_skillNumber = 20;												//��ų�ѹ�

	_name = "�ٳ�������";												//�̸�
	

	if (!_isWhoSkill)
	{
		_imgName = "myrazorLeaf";											//�̹����̸�

		_imgX = -410;
		_imgY = -70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildrazorLeaf";											//�̹����̸�

		_imgX = -50;
		_imgY = -250;
	}

	_power = 55;														//����
	_PP = 25;															//PP
	_accuracy = 95;														//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);					//Ÿ��
}

void skill::reflect()													//���÷��� ���������� �ݰ�.
{
	//_skillNumber = 21;												//��ų�ѹ�

	_name = "���÷���";													//�̸�
	_imgName = "lightScreen";											//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -300;
		_imgY = 100;

	}

	if (_isWhoSkill)
	{
		_imgX = 300;
		_imgY = -250;
	}

	_power = NULL;														//����
	_PP = 20;															//PP
	_accuracy = NULL;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);					//Ÿ��
}

void skill::smokescreen()												//����
{
	//_skillNumber = 22;												//��ų�ѹ�

	_name = "����";														//�̸�
	

	if (!_isWhoSkill)
	{
		_imgName = "mysmokescreen";											//�̹����̸�

		_imgX = -200;
		_imgY = -50;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildsmokescreen";

		_imgX = -80;
		_imgY = -250;
	}

	_power = NULL;														//����
	_PP = 20;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::ember()														//�Ҳɼ���
{
	//_skillNumber = 23;												//��ų�ѹ�

	_index = RND->getFromIntTo(0, 100);

	_name = "�Ҳɼ���";													//�̸�
														//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgName = "myember";

		_imgX = -250;
		_imgY = -75;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildember";
		
		_imgX = -40;
		_imgY = -155;
	}

	_power = 40;														//����
	_PP = 25;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::FIRE);					//Ÿ��

	if (_index > 90) STATUS_AILMENT::BURN;								//�����̻�
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//��밡 �������¸� ���� �� ���� --��������--
}

void skill::rage()														//�г�
{
	//_skillNumber = 24;												//��ų�ѹ�

	_name = "�г�";														//�̸�
	_imgName = "rage";													//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -30;
		_imgY = -55;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -25;
	}

	_power = 20;														//����
	_PP = 20;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::waterGun()													//������
{
	//_skillNumber = 25;												//��ų�ѹ�

	_name = "������";													//�̸�
													

	if (!_isWhoSkill)
	{
		_imgName = "mywaterGun";

		_imgX = -250;
		_imgY = -75;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildwaterGun";

		_imgX = -60;
		_imgY = -110;
	}

	_power = 40;														//����
	_PP = 25;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::SPECIAL;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::WATER);					//Ÿ��
}

void skill::harden()													//�ܴ�������
{
	//_skillNumber = 26;												//��ų�ѹ�

	_name = "�ܴ�������";												//�̸�
	_imgName = "harden";													//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -320;
		_imgY = 200;

	}

	if (_isWhoSkill)
	{
		_imgX = 350;
		_imgY = -200;
	}

	_power = NULL;														//����
	_PP = 30;															//PP
	_accuracy = NULL;													//���߷�
	_ifcation = CLASSIFCATION::CHANGE;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::scratch()													//������
{
	//_skillNumber = 27;												//��ų�ѹ�

	_name = "������";													//�̸�
	_imgName = "scratch";												//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -25;
		_imgY = -25;

	}

	if (_isWhoSkill)
	{
		_imgX = 25;
		_imgY = 0;
	}

	_power = 40;														//����
	_PP = 35;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::furyAttack()												//�������
{
	//_skillNumber = 28;												//��ų�ѹ�

	_name = "�������";												//�̸�
	
	if (!_isWhoSkill)
	{
		_imgName = "myhorn";

		_imgX = -150;
		_imgY = 70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildhorn";

		_imgX = 150;
		_imgY = -70;
	}

	_power = 15;														//����
	_PP = 20;															//PP
	_accuracy = 85;														//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}
		
void skill::bind()														//���̱�
{
	//_skillNumber = 29;												//��ų�ѹ�

	_name = "���̱�";													//�̸�
	_imgName = "bind";													//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -75;
		_imgY = -25;

	}

	if (_isWhoSkill)
	{
		_imgX = -50;
		_imgY = -25;
	}

	_power = 15;														//����
	_PP = 20;															//PP
	_accuracy = 85;														//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//Ÿ��
}

void skill::bite()
{
	//_skillNumber = 30;												//��ų�ѹ�

	_name = "����";														//�̸�
	_imgName = "snap";													//�̹����̸�

	if (!_isWhoSkill)
	{
		_imgX = -50;
		_imgY = -50;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -25;
	}
	
	
	_power = 60;														//����
	_PP = 25;															//PP
	_accuracy = 100;													//���߷�
	_ifcation = CLASSIFCATION::PHYSICS;									//�з�
	_skilltype = static_cast<int>(SKILL_TYPE::DARK);					//Ÿ��
}


void skill::render()
{
	if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	�߻��Ͻ�
	if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	�÷��̾� �Ͻ�
	

	char str[128];

	//if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	�߻��Ͻ�
	//else if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	�÷��̾� �Ͻ�

	
	if (_isSkill) IMAGEMANAGER->frameRender(_imgName, getMemDC(), _imgPoint.x, _imgPoint.y, _currentFrame, 0);



	//sprintf_s(str, "��ǥx : %d ", _imgX);
	//TextOut(getMemDC(), 50, 150, str, strlen(str));
	//sprintf_s(str, "��ǥy : % d ", _imgY);
	//TextOut(getMemDC(), 50, 170, str, strlen(str));
	//sprintf_s(str, "���� : %d ", _isWhoSkill);
	//TextOut(getMemDC(), 50, 190, str, strlen(str));


}

void skill::skillAni()
{

	// ��ų �ִϸ��̼��� ������ ������ �����̱� ������ isSkill�̶�� ���� �־ ���� �ִ� �ؾ��Ұ� ����
	// isSkill�� true ���϶� �̹����� �߰� �ִϸ��̼��� ������ isSkill�� false���� �Ǵ°� ���� ����
	// �ִϸ��̼��� ���ư����� �ϴ� �ʿ��ϴ�.

	if (_isSound)
	{
		switch (_skillIndex)
		{
		case 0:
			skillNone();
			break;
		case 1:
			tackle();
			SOUNDMANAGER->play("�����ġ��", 0.01f * UIMANAGER->getVolume());
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
		case 29:
			bind();
			break;
		case 30:
			bite();
		}
	}

	_isSound = false;

	if (_isSkill)	//��ų�� Ȱ��ȭ ������
	{	
		

		_frameCount++;		//������ ������
		_count++;			//�����ð��ڿ� ������ �ҷ���

		if (_frameCount % 4 == 0)	//�ӵ� ���� �����ȵǴ°� �����ϴ�.
		{
			_currentFrame++; //���������� �����

			//IMAGEMANAGER->findImage(_imgName)->setFrameX(IMAGEMANAGER->findImage(_imgName)->getFrameX() + 1);


			if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count < 30)		//�ϴ��� �����̹��� ���̾� �ҷ����� && �����ð��� 200count�� �帣��
			{
				_currentFrame = 0;					//�������� �ʱ�ȭ ���� ��� �̹����� �ݺ���Ű��
			}
			else if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count > 30)		//�ƽ��������̰� ī���Ͱ� 200�̻��̸� ������ �̹����� ������.
			{
				_isSkill = false;					//���ǿ� ������ ��ų�� ��Ȱ��ȭ ���Ѽ� �̹����� �����
				_count = 0;							//ī���͸� �ٽ� �ʱ�ȭ �����ش�
				_currentFrame = 0;					//���������ӵ� �ʱ�ȭ

				// ��Ʋ ����
				if (UIMANAGER->getAttackCount() < 2)
				{

					UIMANAGER->setIsNext(true);
					UIMANAGER->setIsScript(true);
					UIMANAGER->setIsCount(true);
					UIMANAGER->setIsTurn(false);
				}

				else if (UIMANAGER->getAttackCount() > 1)
				{
					UIMANAGER->setIsAttack(false);
					UIMANAGER->setAttackCount(0);
				}
			}
		}
	}
}

void skill::imageInit()	//��ų �̹���
{
	IMAGEMANAGER->addFrameImage("attack", "image/skill/attack.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bind", "image/skill/bind.bmp", 2880, 180, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut", "image/skill/cut.bmp", 1440, 150, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fire", "image/skill/fire.bmp", 176, 100, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("growth", "image/skill/growth.bmp", 2400, 150, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myhorn", "image/skill/myhorn.bmp", 900, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildhorn", "image/skill/wildhorn.bmp", 900, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("attack3", "image/skill/attack3.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut3", "image/skill/cut3.bmp", 144, 36, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lightScreen", "image/skill/lightScreen.bmp", 1500, 210, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "image/skill/move.bmp", 440, 112, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poison", "image/skill/poison.bmp", 7680, 200, 32, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shine", "image/skill/shine.bmp", 418, 38, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shock", "image/skill/shock.bmp", 138, 42, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snap", "image/skill/snap.bmp", 3840, 160, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("spark", "image/skill/spark.bmp", 1200, 150, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("squall", "image/skill/squall.bmp", 4300, 114, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("slash", "image/skill/slash.bmp", 480, 60, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skyAttack", "image/skill/skyAttack.bmp", 600, 70, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mysmokescreen", "image/skill/mysmokescreen.bmp", 5200, 280, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildsmokescreen", "image/skill/wildsmokescreen.bmp", 8060, 400, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("razonWind", "image/skill/razonWind.bmp", 1456, 112, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("confuseRay", "image/skill/confuseRay.bmp", 312, 78, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mystringShot", "image/skill/mystringShot.bmp", 5940, 150, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildstringShot", "image/skill/wildstringShot.bmp", 5940, 235, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myconfusion", "image/skill/myconfusion.bmp", 1680, 160, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildconfusion", "image/skill/wildconfusion.bmp", 1680, 160, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mypoisonSting", "image/skill/mypoisonSting.bmp", 450, 90, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildpoisonSting", "image/skill/wildpoisonSting.bmp", 450, 90, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mysandAttack", "image/skill/mysandAttack.bmp", 2750, 198, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildsandAttack", "image/skill/wildsandAttack.bmp", 2750, 198, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myquickAttack", "image/skill/myquickAttack.bmp", 6360, 340, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildquickAttack", "image/skill/wildquickAttack.bmp", 7440, 400, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wingAttack", "image/skill/wingAttack.bmp", 1600, 80, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tailWhip", "image/skill/tailWhip.bmp", 1260, 190, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mygrowl", "image/skill/mygrowl.bmp", 1360, 280, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildgrowl", "image/skill/wildgrowl.bmp", 1360, 280, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myleer", "image/skill/myleer.bmp", 2310, 200, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildleer", "image/skill/wildleer.bmp", 2310, 200, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("thunderShock", "image/skill/thunderShock.bmp", 2860, 260, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("scratch", "image/skill/scratch.bmp", 1040, 130, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harden", "image/skill/harden.bmp", 540, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rage", "image/skill/rage.bmp", 570, 170, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myrazorLeaf", "image/skill/myrazorLeaf.bmp", 9920, 400, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildrazorLeaf", "image/skill/wildrazorLeaf.bmp", 9920, 400, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mywaterGun", "image/skill/mywaterGun.bmp", 4200, 260, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildwaterGun", "image/skill/wildwaterGun.bmp", 4200, 260, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myember", "image/skill/myember.bmp", 4300, 300, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildember", "image/skill/wildember.bmp", 4300, 300, 10, 1, true, RGB(255, 0, 255));


}

void skill::skillNumLink(int index)		// ��ų�� ��ų�ѹ��� ���� �ؼ� �Ѱ���?
{	
	switch (index)
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
	case 29:
		bind();
		break;
	case 30:
		bite();
	}

}
