#pragma once
#include "gameNode.h"

#define TILESIZE 64				//Ÿ�� ������ 64 * 64

//Ÿ�� �� �� �����ϱ� ���� ��ó����
#define	STARTTILE 24 * 18		//���۸� Ÿ�ϰ���
#define BATTLETILE 60 * 18		//��Ʋ�� Ÿ�ϰ���
#define GYMTILE 40 * 36			//ü������ Ÿ�ϰ���

//��ü Ÿ�� ����
#define TILE 24 * 18 + 60 * 18 + 40 * 36

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
//�׽�Ʈ�� ����
enum DIRECTION
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
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

	DIRECTION _direction;
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
	void moveX();		//������ �Լ�
	void moveY();

	//������
	tagTile* getTile() { return _tile; }			//�� Ÿ�Ͽ� ���� ������

	int getCameraX() { return _cameraX; }			//�� ī�޶� X��ǥ�� ���� ������
	int getCameraY() { return _cameraY; }			//�� ī�޶� y��ǥ�� ���� ������

	//������
	void setCameraX(int x) { _cameraX = x; }
	void setCameraY(int y) { _cameraY = y; }


	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};
