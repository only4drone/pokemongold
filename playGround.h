#pragma once
#include "gameNode.h"
#include "tileMap.h"
#include "character.h"
#include "poketmonManager.h"


class playGround : public gameNode
{
private:
	tileMap* _tileMap;							// Ÿ�ϸ� Ŭ����
	character* _character;						// ĳ���� Ŭ����
	poketmonManager* _pM;						// ���ϸ� �Ŵ��� Ŭ����


public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
	
};

