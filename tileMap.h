#pragma once
#include "gameNode.h"

#define TILESIZE 64				//Ÿ�� ������ 64 * 64

//��ü Ÿ�� ����
#define TILE 124 * 36

enum TILETYPE					//Ÿ�� �Ӽ�
{
	TILETYPE_OPEN,				//������ �� �ִ� Ÿ��
	TILETYPE_GRASS,				//Ǯ(���ϸ� �Ѹ� �� �ְ�)
	TILETYPE_CLOSE,				//������ �� ���� Ÿ��
	TILETYPE_DOOR,				//�̵��� �� �ִ� ��
	TILETYPE_LEFTSLOPE,			//���� ��Ż��
	TILETYPE_RIGHTSLOPE,		//������ ��Ż��
	TILETYPE_BOTTOMSLOPE		//�Ʒ��� ��Ż��
};


struct tagTile
{
	RECT		rc;		//Ÿ�� ��Ʈ
	TILETYPE	type;	//Ÿ�� �Ӽ�
};

class character;

class tileMap : public gameNode
{
private:
	character* _character;

	image* _map;							//��ü �� �̹���
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
	void setCameraX(int x) { _cameraX = x; }		//�� ī�޶� x��ǥ�� ���� ������
	void setCameraY(int y) { _cameraY = y; }		//�� ī�޶� y��ǥ�� ���� ������


	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};
