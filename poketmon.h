#pragma once
#include "gameNode.h"

//���ϸ� Ÿ��
enum class TYPE
{
	NONE,	//����
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

// ���ϸ� ������
struct tagPOKETMON
{
	string name;							// �̸�
	string gender;							// ����
	bool isGender;							// ���� üũ
	int index;								// �ε��� ��ȣ
	int level;								// ���ϸ� ���� ����
	int	evolutionLevel;						// ��ȭ �ܰ�

	int iconNumX;							// �̴� ���ϸ� �̹��� ������ ��ǥ X
	int iconNumY;							// �̴� ���ϸ� �̹��� ������ ��ǥ Y
	
	int type1; 								// ���ϸ� Ÿ��1	
	int type2;								// ���ϸ� Ÿ��2

	int	attack;								// 1���� �ʱ� ����
	int	defense;							// 1���� �ʱ� ���	
	int specialAttack;						// 1���� �ʱ� Ư������
	int	specialDefense;						// 1���� �ʱ� Ư�����
	int	speed;								// 1���� �ʱ� ���ǵ�
	int	currentHP;							// 1���� �ʱ� ���� ü��
	int	maxHP;								// 1���� �ʱ� �ִ� ü��

	float levelAttack;						// ������ �����ϴ� ����
	float levelDefense;						// ������ �����ϴ� ���	
	float levelSpecialAttack;				// ������ �����ϴ� Ư������
	float levelSpecialDefense;				// ������ �����ϴ� Ư�����
	float levelSpeed;						// ������ �����ϴ� ���ǵ�
	float levelHP;							// ������ �����ϴ� ü��

	int sumAttack;							// ���� ����
	int sumDefense;							// ���� ���
	int sumSpecialAttack;					// ���� Ư������
	int sumSpecialDefense;					// ���� Ư�����
	int sumSpeed;							// ���� ���ǵ�
	int sumMaxHP;							// ���� ü��

	float currentExp;						// ���� ����ġ(���� ���� �� ����ġ, level�� ��ŭ ���� ������ �� �����ֱ�)
	float	maxExp;							// �ִ� ����ġ(���� ������ �ִ� ����ġ �� ǥ��)

	float totalEXP;							// ��Ż ����ġ

	int	skill1;								// ��ų1 �ε��� 
	int	skill2;								// ��ų2 �ε��� 
	int	skill3;								// ��ų3 �ε��� 
	int	skill4;								// ��ų4 �ε��� 

	int skill1PP;							// ��ų1 ���� PP
	int skill2PP;							// ��ų2 ���� PP	
	int skill3PP;							// ��ų3 ���� PP
	int skill4PP;							// ��ų4 ���� PP

	int item;								// ���� ���� ������ �ε���
};

class poketmon : public gameNode
{
protected:
	tagPOKETMON _poketmon;
	


public:
	poketmon();
	~poketmon();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void attackAI();

	void genderSettings();					//���� �Լ�
	void potketmonEXP();					//����ġ

	tagPOKETMON getTagPoketmon() { return _poketmon; }	//���ϸ���ü ����?
	
};