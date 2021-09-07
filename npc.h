#pragma
#include "gameNode.h"

//npc ����ü
struct tagNPC
{
	image* Img;					// npc �̹���
	image* markImg;				//����ǥ �̹���
	RECT rc;					//npc ��Ʈ
	RECT detectRC;				//������Ʈ(���� ��)
	RECT moveRC;				//������ ��Ʈ(�� ��Ʈ �ȿ� ���� npc�� �ٰ���)

	int markCount;				//����ǥ ����ī��Ʈ
};

//���� ����
class tileMap;

class npc : public gameNode
{
private:
	//Ŭ����
	tileMap* _tileMap;

	tagNPC _npc[8];				//npc - 0: �÷��̾� ���� 1: ���ڻ� 2: ���ڻ� ���� 3: ��ȣ�� 4: ����1 5: ����2 6: ��� 7: ��Ʈ ����

	int count;					//������ ������ ī��Ʈ

public:
	npc();
	~npc();

	virtual HRESULT init();
	virtual void relise();
	virtual void update();
	virtual void render();

	void setNPC();							//NPC �ʱ�ȭ �Լ�
	void updateNPC();						//NPC ������Ʈ �Լ�
	void move();							//������ �Լ�(�÷��̾� ����, ����1, ����2)

	//������
	tagNPC* getnpcRC() { return _npc; }		//npc�� ���� ������

	//�ּ� ��ũ
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }
};


