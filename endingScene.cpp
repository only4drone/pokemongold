#include "pch.h"
#include "endingScene.h"

endingScene::endingScene()
{
}

endingScene::~endingScene()
{
}

HRESULT endingScene::init()
{
	_endingBackground[0] = IMAGEMANAGER->addImage("�������1", "image/end_image/endingBackground1.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1
	_endingBackground[1] = IMAGEMANAGER->addImage("�������2", "image/end_image/endingBackground2.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1
	_endingBackground[2] = IMAGEMANAGER->addImage("�������3", "image/end_image/endingBackground3.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1
	_endingBackground[3] = IMAGEMANAGER->addImage("�������4", "image/end_image/endingBackground4.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1

	_endingPokemon[0] = IMAGEMANAGER->addFrameImage("�������ϸ�1", "image/end_image/endingPokemon1.bmp", 192, 68, 3, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(������?)
	_endingPokemon[1] = IMAGEMANAGER->addFrameImage("�������ϸ�2", "image/end_image/endingPokemon2.bmp", 162, 56, 3, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(�����)
	_endingPokemon[2] = IMAGEMANAGER->addFrameImage("�������ϸ�3", "image/end_image/endingPokemon3.bmp", 216, 68, 3, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(����Ű��)
	_endingPokemon[3] = IMAGEMANAGER->addFrameImage("�������ϸ�4", "image/end_image/endingPokemon4.bmp", 208, 72, 4, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(������)

	_time = TIMEMANAGER->getWorldTime();

	return S_OK;
}

void endingScene::release()
{
}

void endingScene::update()
{
	static int count = 0;

	if (count % 7 == 0)
	{
		if (_index < 2 && _endCount != 3) _index++;
		else if (_index < 3 && _endCount == 3) _index++;
		else _index = 0;
	}

	count++;

	if (TIMEMANAGER->getWorldTime() >= _time + 2 && _endCount < 3)
	{
		_endCount++;
		_time = TIMEMANAGER->getWorldTime();
		_index = 0;
	}
}

void endingScene::render()
{
	_endingBackground[_endCount]->render(getMemDC());
	for (int i = 0; i < 5; i++)
	{
		_endingPokemon[_endCount]->frameRender(getMemDC(), 50 + i * 120, 20, _index, 0);
		_endingPokemon[_endCount]->frameRender(getMemDC(), 50 + i * 120, WINSIZEY - 30 - 50, _index, 0);
	}
}
