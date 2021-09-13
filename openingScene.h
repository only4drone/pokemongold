#pragma once
#include "gameNode.h"

class openingScene : public gameNode
{
private:

	int _freakIndex;					// ���������� ������ �̹��� ��� �뵵 ����
	int _titleIndex;

	image* _opening;
	image* _title;
	image* _dr;

	int _waitTime;				// ������ ��� �ð�

	int _count;

	bool _isTitle;

public:
	openingScene();
	~openingScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

