#pragma once
#include"poketmon.h"


class chikorita : public poketmon
{
private:


public:
	chikorita();
	~chikorita();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�



};

