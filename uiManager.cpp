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

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{

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
