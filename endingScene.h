#pragma once
#include "gameNode.h"

class endingScene : public gameNode
{
private:

	image* _endingBackground[4];	// ���� ��� �̹���
	image* _endingPokemon[4];		// ���� ���ϸ� �̹���

	int _index;						// imageframe�� int����

	int _endCount;					// ���� ���� �̹��� �����ϴ� ����

	float _time;					// �ð������ ���� �ð�����


public:
	endingScene();
	~endingScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

