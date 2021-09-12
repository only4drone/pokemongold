#pragma once
#include "gameNode.h"

class poketmonManager;
class character;

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

enum class SKILL_TYPE
{
	NOMAL,	//�븻
	FIRE,	//��
	WATER,	//��
	GRASS,	//Ǯ
	ELECTR,	//����
	ICE,	//����
	FIGHT,	//����
	POISON,	//��
	GROUND,	//��
	FLYING,	//����
	PSYCHC,	//�ʴɷ�
	BUG,	//����
	ROCK,	//����
	GHOST,	//����
	DRAGON,	//�巡��
	DARK,	//��
	STEEL,	//��ö
	FAIRY	//����
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

	int _imgX, _imgY;			//�̹��� ��ġ����

	//SKILL_TYPE _skilltype;		//��ųŸ��


	int _power;					// ����
	int _accuracy;				// ���߷�
	int _PP;					// PP

	int _skillNumber;			// ��ų �ѹ�
	int _skillLever;			// ��ų����

	int _skilltype;				// ��ų Ÿ��

	STATUS_AILMENT _ifAilment;	// �����̻�
	CLASSIFCATION _ifcation;	// �з�


	POINT _imgPoint;			// �̹��� ���� �� �����ҷ��� ���� �Լ�


	int _index;					// Ȯ�� ���ǰɋ� �ʿ��� ��

	bool _isSkill;				// ��ų ���Ȯ��
	bool _isWhoSkill;			// �̹��� ��ġ ���°� �����ҷ��� ���� �Ұ� �÷��̾�(true) �ΰ� �߻�(false)�ΰ� 

	// ���� ������� ����
	int _skillIndex;
	bool _isSound;

	RECT rc;					//��ġ ���� �ӽÿ�

	poketmonManager* _pM;
	character* _ch;

public:

	skill();
	~skill();

	HRESULT init();
	void release();
	void update();

	void skillNone();		// ��ų����
	void tackle();			// �����ġ��
	void stringShot();		// �ǻձ�
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
	void harden();			// �ܴ�������

	void scratch();			// ������
	void furyAttack();		// �������
	
							
			  //�߰��۾�
	void bind();			// ���̱�
	void bite();			// ����

	void render();

	void skillAni();		// ��ų �ִϸ��̼�
	void imageInit();		// �̹���

	void skillNumLink(int index);

	bool getIsSkill() { return _isSkill; }						//�Ұ� getter��
	void setIsSkill(bool skill) { _isSkill = skill; }			//�Ұ� setter��

	bool getWhoSkill() {return _isWhoSkill;	}					// whoskill getter��
	void setWhoSkill(bool whoSkill) { _isWhoSkill = whoSkill; }	// whoskill setter��

	string getSkillName() { return _name; }						//���� getter
	string getSkillImgName() { return _imgName; }				//�̹������� getter

	int getSkillPower() { return _power; }						//���� getter
	int getSkillPP() { return _PP; }							//PP getter
	int getSkillAccuracy() { return _accuracy; }				//���߷� getter

	int getSkillType() { return _skilltype; }

	int getSkillIndex() { return _skillIndex; }
	void setSkillIndex(int index) { _skillIndex = index; }

	bool getIsSound() { return _isSound; }
	void setIsSound(bool sound) { _isSound = sound; }

	//CLASSIFCATION getIfcation() { return _ifcation; }			//�з�
					//Ÿ��
	//STATUS_AILMENT getifAilemnt() { return _ifAilment; }		//�����̻�

	void setPoketmonmanagerMemoryAddressLink(poketmonManager* pM) { _pM = pM; }
	void setCharacterMemoryAddressLink(character* ch) { _ch = ch; }

};


