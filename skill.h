#pragma once
#include "gameNode.h"

enum class STATUS_AILMENT	// �����̻�
{
	POISON,					// ��
	BURN,					// ȭ��
	PARALYSIS,				// ����
	SLEEP,					// ����
	FREEZE,					// ����
	NONE					// ����
};

enum class CLASSIFCATION	// �з�
{
	PHYSICS,				// ����
	SPECIAL,				// Ư��
	CHANGE,					// ��ȭ

};

class skill : public gameNode
{
private:

	int _power;					// ����
	int _accuracy;				// ���߷�
	int _PP;					// PP
	int _number;				// �ѹ�
	int _skillLever;			// ��ų����

	int _index;					// Ȯ�� ���ǰɋ� �ʿ��� ��


public:

	skill();
	~skill();

	HRESULT init();
	void release();
	void update();
	void render();

	void tackle();			// �����ġ��
	void stringShot();		// �ǻձ�
	void harden();			// �ܴ�������
	void confusion();		// ������
	void poisonPowder();	// ������
	void stunSpore();		// ��������
	void sleepPowder();		// ���鰡��

	void poisonSting();		// ��ħ
	void focusEnergy();		// ������
	void twineedle();		// ����ϵ�

	void sandAttack();		// �𷡻Ѹ���
	void gust();			// �ٶ�����Ű��
	void quickAttack();		// ������ȭ
	void wingAttack();		// ����ġ��

	void tailWhip();		// ��������

	void peck();			// �ɱ�
	void growl();			// �����Ҹ�
	void leer();			// ��������

	void thunderShock();	// �����ũ
	void thunderbolt();		// 10����Ʈ

	void razorLeaf();		// �ٳ�������
	void reflect();			// ���÷���

	void smokescreen();		// ����
	void ember();			// �Ҳɼ���

	void rage();			// �г�
	void waterGun();		// ������






};


