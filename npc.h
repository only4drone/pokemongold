#pragma
#include "gameNode.h"

#define npcMAX 11				//npc max

//npc ����ü
struct tagNPC
{
	image* Img;					// npc �̹���
	image* markImg;				//����ǥ �̹���
	RECT rc;					//npc ��Ʈ
	RECT detectRC;				//������Ʈ(���� ��)
	RECT moveRC;				//������ ��Ʈ(�� ��Ʈ �ȿ� ���� npc�� �ٰ���

	int npcX, npcY;				//npc �����̰� �ϴ� ����
	int moveCount;				//�����̴� �ð�ī��Ʈ
	int markCount;				//����ǥ ����ī��Ʈ
};

//���� ����
class tileMap;
class character;

class npc : public gameNode
{
private:
	//Ŭ����
	tileMap* _tileMap;
	character* _character;

	tagNPC _npc[11];				//npc - 0: �÷��̾� ���� 1: ���ڻ� 2: ���ڻ� ���� 3: ��ȣ�� 4: ����1 5: ����2 6: ��� 7: ��Ʈ ���� 8~10 : ���Ϻ�

	RECT _moveRC;					//����1 �����ӷ�Ʈ 2�� �ʿ��ؼ� ����

	int count;					//������ ������ ī��Ʈ

	bool _isMove;				//������ ����  �Ӽ��ٲٴ� ���� ���ֱ� ���� ����

public:
	npc();
	~npc();

	virtual HRESULT init();
	virtual void relise();
	virtual void update();
	virtual void render();

	void setNPC();									//NPC �ʱ�ȭ �Լ�
	void updateNPC();								//NPC ������Ʈ �Լ�
	void move();									//������ �Լ�(�÷��̾� ����, ����1, ����2)

	//������
	tagNPC* getnpcRC() { return _npc; }				//npc�� ���� ������
	inline bool getIsMove() { return _isMove; }		//isMove�� ���� ������

	//������
	void setNPCX4(int npcX) { _npc[4].npcX = npcX; }
	void setNPCX5(int npcX) { _npc[5].npcX = npcX; }

	//�ּ� ��ũ
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }
	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};


