#pragma once
#include "gameNode.h"

enum class STATUS_AILMENT	// �����̻�
{
	NONE,					// ����
	POISON,					// ��
	BURN,					// ȭ��
	PARALYSIS,				// ����
	SLEEP,					// ����
	FREEZE,					// ����
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

	string _name;				// ��ų �̸� <�αⰡ �߰� �ش޶�� �Ѱ�>

	string _imgName;			// �̹��� ��ﶧ �̸� �ʿ��Ұ� ���Ƽ� �ϴ� �߰� ���߿� ��Ȳ���� �����������.



	image* _skillImg;			//��ų �̹���
	int _currentFrame;			//������ �ʱ�ȭ �Ұ�.
	int _frameCount;			//������ ī��Ʈ
	int _count;					//ī��Ʈ �� ������
	
	


	int _power;					// ����
	int _accuracy;				// ���߷�
	int _PP;					// PP
	int _number;				// �ѹ�
	int _skillLever;			// ��ų����

	POINT _imgPoint;			// �̹��� ���� �� �����ҷ��� ���� �Լ�
	

	int _index;					// Ȯ�� ���ǰɋ� �ʿ��� ��

	bool _isSkill;				// ��ų ���Ȯ��
	bool _isWhoSkill;			// �̹��� ��ġ ���°� �����ҷ��� ���� �Ұ� �÷��̾�(true) �ΰ� �߻�(false)�ΰ� 

	RECT rc;					//��ġ ���� �ӽÿ�

public:

	skill();
	~skill();

	HRESULT init();
	void release();
	void update();
	

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

	void render();

	void skillAni();		// ��ų �ִϸ��̼�
	void imageInit();		// �̹���



	bool getIsSkill() { return _isSkill; }					//�Ұ� getter��
	void setIsSkill(bool skill) { skill = _isSkill; }		//�Ұ� setter��






};


