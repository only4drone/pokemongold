#pragma once
#include "gameNode.h"

//Ÿ�� ������ 64 * 64
#define TILESIZE 64

//��ü Ÿ�� ����
#define TILE (214 * 36)

//���� Ÿ�� ����
#define TREE (84 * 2 + 84 * 2 + 18 * 5)

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
	RECT		rc;		//Ÿ�� ��Ʈ
	TILETYPE	type;	//Ÿ�� �Ӽ�
};

//���� Ÿ��
struct tagTree
{
	image*		image;	//Ÿ�� �̹���
	RECT		rc;		//Ÿ�� ��Ʈ
};

class character;

class tileMap : public gameNode
{
private:
	character* _character;

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
	tagTree _tree[TREE];					//���� Ÿ��

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
	void setCameraX(int x) { _cameraX = x; }		//�� ī�޶� x��ǥ�� ���� ������
	void setCameraY(int y) { _cameraY = y; }		//�� ī�޶� y��ǥ�� ���� ������


	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};
