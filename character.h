#pragma once
#include "gameNode.h"

// ĳ���� ����
enum class STATE
{
	IDLE_RL,								// ���̵� �¿�
	IDLE_UD,								// ���̵� ����
	RUN_RL,									// �ȱ� �¿�
	RUN_UD,									// �ȱ� ����
};

//���ϸ� Ÿ��
enum class TYPE_PLAYER
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

// ĳ���� ���ϸ�
struct tagPOKETMON_PLAYER
{
	string name;							// �̸�
	string gender;							// ����
	bool isGender;							// ���� üũ
	int index;								// �ε��� ��ȣ
	int level;								// ���ϸ� ���� ����
	int	evolutionLevel;						// ��ȭ �ܰ�

	int type1; 								// ���ϸ� Ÿ��1	
	int type2;								// ���ϸ� Ÿ��2

	int	attack;								// 1���� �ʱ� ����
	int	defense;							// 1���� �ʱ� ���	
	int specialAttack;						// 1���� �ʱ� Ư������
	int	specialDefense;						// 1���� �ʱ� Ư�����
	int	speed;								// 1���� �ʱ� ���ǵ�
	int	currentHP;							// 1���� �ʱ� ���� ü��
	int	maxHP;								// 1���� �ʱ� �ִ� ü��

	int	levelAttack;						// ������ �����ϴ� ����
	int	levelDefense;						// ������ �����ϴ� ���	
	int levelSpecialAttack;					// ������ �����ϴ� Ư������
	int	levelSpecialDefense;				// ������ �����ϴ� Ư�����
	int	levelSpeed;							// ������ �����ϴ� ���ǵ�
	int levelHP;							// ������ �����ϴ� ü��

	int sumAttack;							// ���� ����
	int sumDefense;							// ���� ���
	int sumSpecialAttack;					// ���� Ư������
	int sumSpecialDefense;					// ���� Ư�����
	int sumSpeed;							// ���� ���ǵ�
	int sumMaxHP;							// ���� ü��

	int currentExp;							// ���� ����ġ(���� ���� �� ����ġ, level�� ��ŭ ���� ������ �� �����ֱ�)
	int	maxExp;								// �ִ� ����ġ(���� ������ �ִ� ����ġ �� ǥ��)

	int	skill1;								// ��ų1 �ε��� 
	int	skill2;								// ��ų2 �ε��� 
	int	skill3;								// ��ų3 �ε��� 
	int	skill4;								// ��ų4 �ε��� 
};

// ���� ����
class poketmonManager;
class tileMap;

class character : public gameNode
{
private:
	poketmonManager* _pM;									// ���ϸ� �Ŵ��� Ŭ���� 		
	tileMap* _tileMap;										// Ÿ�ϸ� Ŭ����
	tagPOKETMON_PLAYER _poketmon[6];						// ������ ������ ���ϸ�

	image* _image;											// ĳ���� �̹���
	RECT _rc;												// ĳ���� ��Ʈ

	float _x, _y;											// ĳ���� ���� ��ǥ

	int _state;												// ���� ����
	int _frameCount;										// ������ �̹��� ���͹� ī��Ʈ
	int _currentFrame;										// ���� ������
	int _direction;											// ĳ���� ���� 0: ��, 1: ��, 2: ��, 3: ��

	bool _isMoving;											// ���� ĳ���Ͱ� �̵� ������?

public:
	character();
	~character();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void imageInit();										// �̹����� �ҷ���
	void imageSetting();									// ���� �̹��� ����
	void imageFrame();										// �̹��� ������ ó��
	void controll();										// ĳ���� ��Ʈ�� ó��
	void idle(int direction);								// ���̵� ó��
	void run(int direction);								// �ȱ� ó��
	void move();											// ��ǥ �̵� ó��

	float getCharacterX() {}

	void setPoketmonManagerMemoryAddressLink(poketmonManager* pM) { _pM = pM; }		// �޸� �ּ� ��ũ
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }		// �޸� �ּ� ��ũ
};
