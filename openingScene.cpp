#include "pch.h"
#include "openingScene.h"

openingScene::openingScene()
{
}

openingScene::~openingScene()
{
}

HRESULT openingScene::init()
{
	_opening = IMAGEMANAGER->addFrameImage("������", "image/op_image_frame.bmp", 65280, 576, 102, 1, true, RGB(255, 0, 255));
	_title = IMAGEMANAGER->addImage("��Ʈ��", "image/intro.bmp", 640, 576, true, RGB(255, 0, 255));
	_dr = IMAGEMANAGER->addImage("���ڻ�", "image/DrOh.bmp", 120, 168, true, RGB(255, 0, 255));

	SOUNDMANAGER->play("op_star", 0.01f * UIMANAGER->getVolume());

	//UIMANAGER->setIsScript(true);
	//UIMANAGER->setIsCount(true);

	return S_OK;
}

void openingScene::release()
{
}

void openingScene::update()
{
	//if (_count == 0 && !SOUNDMANAGER->isPlaySound("op_star"))
	//{
	//	SOUNDMANAGER->play("start", 0.01f * UIMANAGER->getVolume());
	//	_count++;
	//}
	//if (_count == 1 && !SOUNDMANAGER->isPlaySound("start"))
	//{
	//	SOUNDMANAGER->play("title", 0.01f * UIMANAGER->getVolume());
	//	_count++;
	//}

	static int count = 0;

	if (count % 2 == 0 && _freakIndex <= 100) _freakIndex++;

	if (_freakIndex == 100)
	{
		_freakIndex++;
		_waitTime = TIMEMANAGER->getWorldTime();
	}

	// Ÿ��Ʋ ȭ�� ���
	if (_isTitle)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			UIMANAGER->setNPC(NPC::TITLE, true);
			UIMANAGER->setIsScript(true);
			UIMANAGER->setIsCount(true);

			SOUNDMANAGER->stop("title");
			SOUNDMANAGER->play("start", 0.01f * UIMANAGER->getVolume());
		}
	}

	// ���� ������ ������ ������ 1 �� ����
	else if (_freakIndex >= 101 && TIMEMANAGER->getWorldTime() >= _waitTime + 1)
	{
		// Ÿ��Ʋ ȭ�� ���
		SOUNDMANAGER->play("title", 0.01f * UIMANAGER->getVolume());
		_isTitle = true;
	}

	//if (_titleIndex >= 101 && TIMEMANAGER->getWorldTime() >= _waitTime + 1)
	//{
	//	SCENEMANAGER->changeScene("�ΰ���");
	//}

	count++;
}

void openingScene::render()
{
	if (!_isTitle) _opening->frameRender(getMemDC(), 0, 0, _freakIndex, 0);
	if (_isTitle)
	{
		if (!UIMANAGER->getIsScript()) _title->render(getMemDC(), 0, 0);
		else
		{
			_dr->render(getMemDC(), WINSIZEX / 2 - _dr->getWidth() / 2, 200);
			UIMANAGER->script();
		}
	}

}
