#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"



struct item {
	int itemNum = 0;
	// 0은 빈칸, 1은 몬스터볼 , 2는 상처약, 3은 고급상처약
	int itemQuan = 0;
	// 아이템 수량
};

uiManager::uiManager()
{
}

uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{

	//인벤토리를 10칸으로 초기화해준다 . 빈칸이 10개가 생김 ( 0~9)
	IMAGEMANAGER->addImage("사다", "image/shopUI/shop_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("팔다", "image/shopUI/shop_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("그만두다", "image/shopUI/shop_3.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("몬스터볼", "image/shopUI/buy_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상처약", "image/shopUI/buy_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("고급상처약", "image/shopUI/buy_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("안산다", "image/shopUI/buy_4.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("menu0", "image/menuUI/menu_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu1", "image/menuUI/menu_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu2", "image/menuUI/menu_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu3", "image/menuUI/menu_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu4", "image/menuUI/menu_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu5", "image/menuUI/menu_6.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu6", "image/menuUI/menu_7.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("pokeCenter", "image/shopUI/pokeCenter.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));

	_scriptImage = IMAGEMANAGER->addImage("script", "image/dialogueUI.bmp", 650, 576, true, RGB(255, 0, 255));

	_vScript = TXTDATA->txtLoad("Test.txt");

	return S_OK;
}

void uiManager::release()
{

}

void uiManager::update()
{
	//if (KEYMANAGER->isOnceKeyDown('P'))
	//{
	//	_isScript = true;
	//}
}

void uiManager::render()
{
}

void uiManager::shop()
{

	// 스위치 넣어서 상점이 열려있을때만
	if (!buyWindow) {
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && shopCnt < 2) {
			shopCnt += 1;
			//메뉴 화살표 위아래 움직이는
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && shopCnt > 0) {
			shopCnt -= 1;
		}
	}

	switch (shopCnt)
	{
	case 0:
		IMAGEMANAGER->findImage("사다")->render(_backBuffer->getMemDC());
		break;
	case 1:
		IMAGEMANAGER->findImage("팔다")->render(_backBuffer->getMemDC());
		break;
	case 2:
		IMAGEMANAGER->findImage("그만두다")->render(_backBuffer->getMemDC());
		return;
		break;
	}

	if (shopCnt == 0 && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
		buyWindow = true;
		//상점 구현 
	};

	if (buyWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && buyCnt < 4) {
			buyCnt += 1;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && buyCnt > 0) {
			buyCnt -= 1;
		}
		switch (buyCnt) {

		case 0:
			IMAGEMANAGER->findImage("몬스터볼")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("상처약")->render(_backBuffer->getMemDC());
			break;
		case 2:
			IMAGEMANAGER->findImage("고급상처약")->render(_backBuffer->getMemDC());
			break;
		case 3:
			IMAGEMANAGER->findImage("안산다")->render(_backBuffer->getMemDC());


			if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
				buyCnt = 0;
				//shopCnt = 0;
				buyWindow = false;
				//상점 구현 
			};

			break;
		}


	}





}

void uiManager::bag()
{

}

void uiManager::pokeCenter()
{
	IMAGEMANAGER->findImage("pokeCenter")->frameRender(_backBuffer->getMemDC(), 170, 105, _index, 0);
	cnt++;
	if (cnt == 15) {
		_index++;
		cnt = 0;
	}


	if (_index > 10) {
		_index = 0;
	}
}

void uiManager::menu()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && menuCnt < 6) {
		menuCnt += 1;
		//메뉴 화살표 위아래 움직이는
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && menuCnt > 0) {
		menuCnt -= 1;
	}

	switch (menuCnt)
	{
	case 0:
		IMAGEMANAGER->findImage("menu0")->render(_backBuffer->getMemDC());
		break;
	case 1:
		IMAGEMANAGER->findImage("menu1")->render(_backBuffer->getMemDC());
		break;
	case 2:
		IMAGEMANAGER->findImage("menu2")->render(_backBuffer->getMemDC());
		break;
	case 3:
		IMAGEMANAGER->findImage("menu3")->render(_backBuffer->getMemDC());
		break;
	case 4:
		IMAGEMANAGER->findImage("menu4")->render(_backBuffer->getMemDC());
		break;
	case 5:
		IMAGEMANAGER->findImage("menu5")->render(_backBuffer->getMemDC());
		break;
	case 6:
		IMAGEMANAGER->findImage("menu6")->render(_backBuffer->getMemDC());

		return;
		break;
	}




}

void uiManager::script()
{
	if (_isScript)
	{
		_scriptImage->render(_backBuffer->getMemDC());

		_txt = _vScript[_scriptIndex];

		if (!_isScriptSkip)
		{
			if (_txtIndex < _txt.length())
			{
				_txtIndex++;
			}
			else if (_txtIndex >= _txt.length())
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
				{
					_isScriptSkip = false;

					_txtIndex = 0;
					_scriptIndex++;
				}
			}
		}
		else if (_isScriptSkip)
		{
			if (_txtIndex >= _txt.length())
			{
				_isScriptSkip = false;
				_txtIndex = 0;
				_scriptIndex++;
			}
			else if (_txtIndex < _txt.length())
			{
				_isScriptSkip = false;
				_txtIndex = _txt.length();
			}
		}

		if (_scriptIndex >= _vScript.size())
		{
			_isScript = false;
		}

		SetBkMode(_backBuffer->getMemDC(), TRANSPARENT);
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));
		RECT rcText = RectMake(30, WINSIZEY - 120, 500, 70);

		HFONT font = CreateFont(35, 0, 0, 100, 1000, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼매직체"));

		HFONT oldFont = (HFONT)SelectObject(_backBuffer->getMemDC(), font);

		DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);

		SelectObject(_backBuffer->getMemDC(), oldFont);
		DeleteObject(font);
	}
}
