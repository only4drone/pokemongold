#pragma once
#include "gameNode.h"

//Ÿ�� ������ 64 * 64
#define TILESIZE 64

//��ü Ÿ�� ����
#define TILE (214 * 36)

//Ÿ�� �Ӽ�
enum TILETYPE
{
	TILETYPE_OPEN,				//������ �� �ִ� Ÿ��
	TILETYPE_GRASS,				//Ǯ(���ϸ� �Ѹ� �� �ְ�)
	TILETYPE_CLOSE,				//������ �� ���� Ÿ��
	TILETYPE_DOOR,				//�̵��� �� �ִ� ��
	TILETYPE_LEFTSLOPE,			//���� ��Ż��
	TILETYPE_RIGHTSLOPE,		//������ ��Ż��
	TILETYPE_BOTTOMSLOPE		//�Ʒ��� ��Ż��
};

//�� Ÿ��
struct tagTile
{
	image* Img;			//�̹���
	RECT		rc;		//Ÿ�� ��Ʈ
	TILETYPE	type;	//Ÿ�� �Ӽ�
	int x, y;			//Ÿ�� �̹��� x�ε���, y�ε���
};

class character;
class npc;

class tileMap : public gameNode
{
private:
	character* _character;
	npc* _npc;

	image* _map;							//��ü �� �̹���
	
	//���۸� �ǹ� �� �̹���
	image* _startHome1;						//�� 1�� �̹���
	image* _startHome2;						//�� 2�� �̹���
	image* _startCenter;					//���۸� ����

	//ü������ �ǹ� �� �̹���
	image* _gymCenter;						//ü������ ����
	image* _gymGym;							//ü������ ü����
	image* _gymMart;						//ü������ ��Ʈ

	tagTile _tile[TILE];					//���۸� Ÿ��

	int _cameraX;							//�� ī�޶� X��ǥ
	int _cameraY;							//�� ī�޶� y��ǥ

public:
	tileMap();
	~tileMap();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	//�Լ�
	void setTile();		//�ʿ� Ÿ�� ����ִ� �Լ�
	void save();		//���� �Լ�
	void load();		//�ҷ����� �Լ�

	//������
	tagTile* getTile() { return _tile; }			//�� Ÿ�Ͽ� ���� ������

	int getCameraX() { return _cameraX; }			//�� ī�޶� X��ǥ�� ���� ������
	int getCameraY() { return _cameraY; }			//�� ī�޶� y��ǥ�� ���� ������

	//������
	void setTile6183Type(TILETYPE _type) { _tile[6183].type = _type; }	//6183�� Ÿ�� �Ӽ� ������
	void setTile5328Type(TILETYPE _type) { _tile[5328].type = _type; }	//5328�� Ÿ�� �Ӽ� ������
	void setCameraX(int x) { _cameraX = x; }		//�� ī�޶� x��ǥ�� ���� ������
	void setCameraY(int y) { _cameraY = y; }		//�� ī�޶� y��ǥ�� ���� ������

	void setCharacterMemoryAddressLink(character* character) { _character = character; }
	void setNPCMemoryAddressLink(npc* npc) { _npc = npc; }
};
