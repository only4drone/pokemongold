#pragma once
#include "singletonBase.h"


class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//���� �޴� ������
	int buyCnt = 0;								//������ �޴� ������
	bool shopWindow = false;					//���� �޴�â ����� �ȶ����
	bool buyWindow = false;						//������ �޴�â ����� �ȶ����

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void shop();
	void bag();

};

