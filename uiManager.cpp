#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"



struct item {
	int itemNum = 0;
	// 0�� ��ĭ, 1�� ���ͺ� , 2�� ��ó��, 3�� ��޻�ó��
	int itemQuan = 0;
	// ������ ����
};

uiManager::uiManager()
{
}

uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	
	//�κ��丮�� 10ĭ���� �ʱ�ȭ���ش� . ��ĭ�� 10���� ���� ( 0~9)
	IMAGEMANAGER->addImage("���", "image/shopUI/shop_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ȴ�", "image/shopUI/shop_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�׸��δ�", "image/shopUI/shop_3.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("���ͺ�", "image/shopUI/buy_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ó��", "image/shopUI/buy_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��޻�ó��", "image/shopUI/buy_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ȼ��", "image/shopUI/buy_4.bmp", 640, 576, true, RGB(255, 0, 255));

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

	// ����ġ �־ ������ ������������
	if (!buyWindow) {
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && shopCnt < 2) {
			shopCnt += 1;
			//�޴� ȭ��ǥ ���Ʒ� �����̴�
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && shopCnt > 0) {
			shopCnt -= 1;
		}
	}

	switch (shopCnt)
	{
	case 0:
		IMAGEMANAGER->findImage("���")->render(_backBuffer->getMemDC());
		break;
	case 1:
		IMAGEMANAGER->findImage("�ȴ�")->render(_backBuffer->getMemDC());
		break;
	case 2:
		IMAGEMANAGER->findImage("�׸��δ�")->render(_backBuffer->getMemDC());
		return;
		break;
	}

	if (shopCnt == 0 && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
		buyWindow = true;
		//���� ���� 
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
			IMAGEMANAGER->findImage("���ͺ�")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("��ó��")->render(_backBuffer->getMemDC());
			break;
		case 2:
			IMAGEMANAGER->findImage("��޻�ó��")->render(_backBuffer->getMemDC());
			break;
		case 3:
			IMAGEMANAGER->findImage("�Ȼ��")->render(_backBuffer->getMemDC());


			if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
				buyCnt = 0;
				//shopCnt = 0;
				buyWindow = false;
				//���� ���� 
			};

			break;
		}
	
	
	}





}

void uiManager::bag()
{

}
