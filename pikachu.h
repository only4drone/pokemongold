#pragma once
#include "poketmon.h"
class pikachu :  public poketmon //��ī��
{
public:
	pikachu();
	~pikachu();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

