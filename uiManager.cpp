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

	IMAGEMANAGER->addImage("menu0", "image/menuUI/menu_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu1", "image/menuUI/menu_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu2", "image/menuUI/menu_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu3", "image/menuUI/menu_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu4", "image/menuUI/menu_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu5", "image/menuUI/menu_6.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu6", "image/menuUI/menu_7.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("pokeCenter", "image/shopUI/pokeCenter.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));

	_scriptImage = IMAGEMANAGER->addImage("script", "image/dialogueUI.bmp", 650, 576, true, RGB(255, 0, 255));

	//_vScript = TXTDATA->txtLoad("Test.txt");		// ���("script/OO.txt");

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
		//�޴� ȭ��ǥ ���Ʒ� �����̴�
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
	// ��ȭ ��ŵ
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_isScriptSkip = true;
	}

	// ��ȭ ��
	if (_isScript)
	{
		// ������ �����Ⱚ ���ͼ� -1����
		if (_scriptIndex >= _vScript.size() - 1)
		{
			// ������ ��ũ��Ʈ ���� �� �ʱ�ȭ(���� ��ũ��Ʈ ���ؼ�)
			_isScript = false;
			_txtIndex = 0;
			_scriptIndex = 0;
		}

		// ����̹��� ����
		_scriptImage->render(_backBuffer->getMemDC());

		// �޾ƿ� �ؽ�Ʈ������ �Ѱ���
		_txt = _vScript[_scriptIndex];

		// ��ŵ�� �ƴ� ��쿡
		if (!_isScriptSkip)
		{
			// ���� ��ü ���̺��� ���簡 ������
			if (_txtIndex < _txt.length())
			{
				// �� ���ھ� ���
				_txtIndex++;
			}
			// ���� ���ڿ��� ���̰� ���� ��ü ���̺��� Ŀ�������ϸ�
			else if (_txtIndex >= _txt.length())
			{
				// ��ư�� ������
				if (KEYMANAGER->isOnceKeyDown('I'))
				{
					// ��ŵ ���� false(���� ���� ��ŵ���� �ʵ���)
					_isScriptSkip = false;

					// ���� �ε��� �ʱ�ȭ ���ְ� ���� �ٷ� �Ѱ���
					_txtIndex = 0;
					_scriptIndex++;
				}
			}
		}
		// ��ŵ�ϸ�
		else if (_isScriptSkip)
		{
			// ���� ���ڿ��� ��ü ���̺��� ��������� �ϸ�
			if (_txtIndex >= _txt.length())
			{
				// ��ŵ ���� false
				_isScriptSkip = false;
				
				// ���� �ε��� �ʱ�ȭ���ְ� ���� �ٷ� �Ѱ���
				_txtIndex = 0;
				_scriptIndex++;
			}
			// ���� ���ڿ��� ���̰� ��ü ���̺��� ������
			else if (_txtIndex < _txt.length())
			{
				// ��ŵ ���� false
				_isScriptSkip = false;
				
				// ���� ���� ���� ���
				_txtIndex = _txt.length();
			}
		}

		SetBkMode(_backBuffer->getMemDC(), TRANSPARENT);
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));
		RECT rcText = RectMake(30, WINSIZEY - 120, 500, 70);

		HFONT font = CreateFont(35, 0, 0, 0, 200, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ո���ü"));

		HFONT oldFont = (HFONT)SelectObject(_backBuffer->getMemDC(), font);

		DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);

		SelectObject(_backBuffer->getMemDC(), oldFont);
		DeleteObject(font);
	}
}
