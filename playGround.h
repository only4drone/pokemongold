#pragma once
#include "gameNode.h"
//#include "tileMap.h"
//#include "character.h"
//#include "poketmonManager.h"
//#include "npc.h"
#include "endingScene.h"
#include "openingScene.h"
#include "inGameScene.h"




class playGround : public gameNode
{
private:
	//tileMap* _tileMap;							// Ÿ�ϸ� Ŭ����
	//character* _character;						// ĳ���� Ŭ����
	//poketmonManager* _pM;						// ���ϸ� �Ŵ��� Ŭ����
	//npc* _npc;									// npc Ŭ����



public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
	
};

