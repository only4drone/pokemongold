#pragma once
#include "gameNode.h"

#define POKETMONMEET 7						// ���ϸ� ���� Ȯ��
#define JUMPPOWER 10						// ���� �Ŀ�
#define GRAVITY	1							// �߷� �Ŀ�

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
//struct tagPOKETMON_PLAYER
//{
//	string name;							// �̸�
//	string gender;							// ����
//	bool isGender;							// ���� üũ
//	int index;								// �ε��� ��ȣ
//	int level;								// ���ϸ� ���� ����
//	int	evolutionLevel;						// ��ȭ �ܰ�
//
//	int type1; 								// ���ϸ� Ÿ��1	
//	int type2;								// ���ϸ� Ÿ��2
//
//	int iconNumX;							// ���ϸ� â���� ������ �ѹ� X��
//	int iconNumY;							// ���ϸ� â���� ������ �ѹ� Y��
//
//	int	attack;								// 1���� �ʱ� ����
//	int	defense;							// 1���� �ʱ� ���	
//	int specialAttack;						// 1���� �ʱ� Ư������
//	int	specialDefense;						// 1���� �ʱ� Ư�����
//	int	speed;								// 1���� �ʱ� ���ǵ�
//	int	currentHP;							// 1���� �ʱ� ���� ü��
//	int	maxHP;								// 1���� �ʱ� �ִ� ü��
//
//	float levelAttack;						// ������ �����ϴ� ����
//	float levelDefense;						// ������ �����ϴ� ���	
//	float levelSpecialAttack;				// ������ �����ϴ� Ư������
//	float levelSpecialDefense;				// ������ �����ϴ� Ư�����
//	float levelSpeed;						// ������ �����ϴ� ���ǵ�
//	float levelHP;							// ������ �����ϴ� ü��
//
//	int sumAttack;							// ���� ����
//	int sumDefense;							// ���� ���
//	int sumSpecialAttack;					// ���� Ư������
//	int sumSpecialDefense;					// ���� Ư�����
//	int sumSpeed;							// ���� ���ǵ�
//	int sumMaxHP;							// ���� ü��
//
//	float currentExp;						// ���� ����ġ(���� ���� �� ����ġ, level�� ��ŭ ���� ������ �� �����ֱ�)
//	float	maxExp;							// �ִ� ����ġ(���� ������ �ִ� ����ġ �� ǥ��)
//
//	float totalEXP;							// ��Ż ����ġ
//
//	int	skill[4];							// ��ų1 �ε��� 
//	int skillPP[4];							// ��ų1 ���� PP
//
//	int item;								// ���� ���� ������ �ε���
//};

// ���� ����
class poketmonManager;
class tileMap;
class npc;

class character : public gameNode
{
private:
	poketmonManager* _pM;									// ���ϸ� �Ŵ��� Ŭ���� 		
	tileMap* _tileMap;										// Ÿ�ϸ� Ŭ����
	npc* _npc;												// npc Ŭ����
	tagPOKETMON_PLAYER _poketmon[6];						// ������ ������ ���ϸ�

	image* _image;											// ĳ���� �̹���
	image* _shadowImage;									// ��Ż�� �̵� �� �׸��� �̹���
	image* _grassImage;										// Ǯ�� �̹���
	image* _flashLoadingImage;								// �÷��� �ε� �̹���
	image* _battleLoadingImage;								// ��Ʋ �ε� �̹���
	RECT _rc;												// ĳ���� ��Ʈ

	float _x, _y;											// ĳ���� ���� ��ǥ
	float _jumpPower;										// ���� �Ŀ�
	float _gravity;											// �߷� �Ŀ�

	int _state;												// ���� ����
	int _frameCount;										// ������ �̹��� ���͹� ī��Ʈ
	int _currentFrame;										// ���� ������
	int _direction;											// ĳ���� ���� 0: ��, 1: ��, 2: ��, 3: ��
	int _currentTile;										// ���� �÷��̾ ��ġ�� Ÿ�� �ε���
	int _frontTileType;										// �ٶ� ������ Ÿ�� Ÿ��
	int _slopeDistance;										// ��Ż�� �̵� �Ÿ�
	int _grassCount;										// Ǯ �̹��� ����� ī��Ʈ��
	int _alpha;												// �÷��� �ε� �̹����� ���İ�
	int _loadingCount;										// ���ϸ� ���� �� ��Ʋ �ε������� ���͹� ī��Ʈ
	int _scriptAction;										// ��ȭ ��ũ��Ʈ �� ��� �׼� �ʿ��� �� ����ϴ� ����

	bool _isMoving;											// ���� ĳ���Ͱ� �̵� ������?
	bool _isSloping;										// ���� ĳ���Ͱ� ��Ż�� �̵� ������?				
	bool _isPoketmonMeet;									// Ǯ Ÿ�Ͽ��� ���ϸ� ���� ������?


public:
	character();
	~character();

	virtual HRESULT init();															//�ʱ�ȭ �Լ�
	virtual void release();															//�޸� ���� �Խ�
	virtual void update();															//�����ϴ� �Լ�
	virtual void render();															//�׸��� �Լ�

	void imageInit();																// �̹��� ���ϵ� �ҷ���
	void imageSetting();															// ���¿� ���� ���� �̹��� ����
	void imageFrame();																// �̹��� ������ ó��
	void controll();																// ĳ���� ��Ʈ�� ó��
	void idle(int direction);														// ���̵� ó��
	void run(int direction);														// �ȱ� ó��
	void tileCheck(int direction);													// Ÿ�� üũ ó��
	void tileAction();																// ��ǥ �̵� ó��
	void grass();																	// Ǯ Ÿ�� ó��
	void door(int doorIndex);														// �� Ÿ�� ó��
	void slope(int direction);														// ��Ż�� Ÿ�� ó��
	void ui();																		// uiâ ó��
	void poketmonMeet();															// ���ϸ� ���� �� ó��
	void npcScript();																// npc ��ȭ ��ũ��Ʈ ó��
	void poketmonSetting();			// �׽�Ʈ�� ������

	float getCharacterX() { return _x; }											// ĳ���� X��ǥ ����
	float getCharacterY() { return _y; }											// ĳ���� Y��ǥ ����
	int getDirection() { return _direction; }										// ĳ���� ���� ����
	int getCurrentTile() { return _currentTile; }									// ĳ���Ͱ� ��ġ�� Ÿ�� �ε��� ����
	bool getIsMoving() { return _isMoving; }										// �̵� ������ �Ұ� ����
	bool getIsSloping() { return _isSloping; }										// ��Ż�� �̵� ������ �Ұ� ����
	bool getIsPoketmonMeet() { return _isPoketmonMeet; }							// ���ϸ� ���� ������ �Ұ� ����
	RECT getRect() { return _rc; }													// ��Ʈ ����
	tagPOKETMON_PLAYER getPoketmon(int arrNum) { return _poketmon[arrNum]; }		// ���� ���ϸ� ����
	void setPoketmon(tagPOKETMON_PLAYER poke,int arrNum) { _poketmon[arrNum] = poke; } //���� ���ϸ� ����

	void setCurrentHP(int arrNum, int damage) { _poketmon[arrNum].currentHP -= damage; }	// ü�� ���� ����
	void setSkillPP(int arrNum, int arrNum2) { _poketmon[arrNum].skillPP[arrNum2]--; }		// PP ���� ����
	void setTotalExp(int arrNum, int exp) { _poketmon[arrNum].totalEXP += exp; }			// ���� ����ġ ���� ����
	void setScriptAction(int scriptAction) {_scriptAction = scriptAction; }					// _scriptAction ����

	void setPoketmonManagerMemoryAddressLink(poketmonManager* pM) { _pM = pM; }				// �޸� �ּ� ��ũ
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }				// �޸� �ּ� ��ũ
	void setNPCMemoryAddressLink(npc* npc) { _npc = npc; }									// �޸� �ּ� ��ũ
};
