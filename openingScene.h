#pragma once
#include "gameNode.h"

class openingScene : public gameNode
{
private:

	int _index;					//������ �̹��� ��� �뵵 ����

	image* opening;

	int _waitTime;				// ������ ��� �ð�

public:
	openingScene();
	~openingScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

