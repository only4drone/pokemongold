#pragma once
#include "gameNode.h"
#include "tileMap.h"
#include "character.h"
#include "poketmonManager.h"
#include "npc.h"

class inGameScene : public gameNode
{
private:
	tileMap* _tileMap;							// Ÿ�ϸ� Ŭ����
	character* _character;						// ĳ���� Ŭ����
	poketmonManager* _pM;						// ���ϸ� �Ŵ��� Ŭ����
	npc* _npc;									// npc Ŭ����

public:
	inGameScene();
	~inGameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


