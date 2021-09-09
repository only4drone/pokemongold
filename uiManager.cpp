#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"
#include "character.h"
#include "progressBar.h"

vector<tagPOKETMON_PLAYER> myPokemon(6);

//6��¥�� �� ���ϸ��� ��� �迭�� ������ �ش�.

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
	
	

	//�ҷ����°� ... ?
	//_character->getPoketmon(0).name;

	//�κ��丮�� 10ĭ���� �ʱ�ȭ���ش� . ��ĭ�� 10���� ���� ( 0~9)
	IMAGEMANAGER->addImage("���", "image/shopUI/shop_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ȴ�", "image/shopUI/shop_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�׸��δ�", "image/shopUI/shop_3.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("���ͺ�", "image/shopUI/buy_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ó��", "image/shopUI/buy_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��޻�ó��", "image/shopUI/buy_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ȼ��", "image/shopUI/buy_4.bmp", 640, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("menu0", "image/menuUI/menu_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu1", "image/menuUI/menu_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu2", "image/menuUI/menu_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu3", "image/menuUI/menu_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu4", "image/menuUI/menu_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu5", "image/menuUI/menu_6.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu6", "image/menuUI/menu_7.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bag0", "image/bag/bag_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bag1", "image/bag/bag_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bag2", "image/bag/bag_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bag3", "image/bag/bag_3.bmp", 640, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("pokeShift0", "image/menuUI/pokeShift_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift1", "image/menuUI/pokeShift_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift2", "image/menuUI/pokeShift_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift3", "image/menuUI/pokeShift_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift4", "image/menuUI/pokeShift_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift5", "image/menuUI/pokeShift_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift6", "image/menuUI/pokeShift_6.bmp", 640, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================
	IMAGEMANAGER->addImage("gear0", "image/menuUI/gear_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gear1", "image/menuUI/gear_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gear2", "image/menuUI/gear_2.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("status0", "image/menuUI/status_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("status1", "image/menuUI/status_1.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("setting0", "image/menuUI/setting_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("setting1", "image/menuUI/setting_1.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("dogam0", "image/menuUI/dogam_0.bmp", 640, 576, true, RGB(255, 0, 255));
	// =======================================================================================================================

	IMAGEMANAGER->addImage("��Ʋ���", "image/battle/battleBackground.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʋ�ൿ����", "image/battle/selectBehavior.bmp", 640, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ų����", "image/battle/backgroundSkill.bmp", 640, 289, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ŀ��", "image/battle/cursorBehavior.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�", "image/battle/playerImage.bmp", 188, 192, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("���Ϻ�����", "image/battle/poketballState.bmp", 28, 112, 1, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image/battle/gender.bmp", 7, 16, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ϸ����", "image/battle/appearPokemon.bmp", 600, 200, 3, 1,  true, RGB(255, 0, 255));

	// ========================================================================================================================

	IMAGEMANAGER->addFrameImage("pokeCenter", "image/shopUI/pokeCenter.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("Icon", "image/menuUI/pokeicon.bmp", 2048, 191, 32, 3, true, RGB(255, 0, 255));

	_scriptImage = IMAGEMANAGER->addImage("script", "image/dialogueUI.bmp", 650, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================

	_isAnimation = true;

	_hpBarPlayer = new progressBar;
	_hpBarPlayer->init(WINSIZEX - 161 - 192, 297, 192, 8, "image/battle/hpGauge.bmp", "image/battle/hpGaugeBack.bmp", "hpFront", "hpBack");
	//_hpBarPlayer->setGauge(100, 100);

	//_hpBarEnemy = new progressBar;
	//_hpBarEnemy->init(50, 90, 192, 8, "image/battle/hpGauge.bmp", "image/battle/hpGaugeBack.bmp");

	_expBar = new progressBar;
	_expBar->init(WINSIZEX - 193 - 256, 365, 256, 8, "image/battle/expGauge.bmp", "image/battle/expGaugeBack.bmp", "expFront", "expBack");
	//_expBar->setGauge(100, 100);

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
	uiOpen = true;
	shopWindow = true;

	if (shopWindow) {

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
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				shopWindow = false;
				uiOpen = false;
				shopCnt = 0;
				_isOpenShop = false;
				return;
			}
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
				// ���߿� ���⼭ �� �˻��ؼ� ������ Q (����) �� �÷��ְ� �ڵ� ���ٸ� �߰�
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					pokeballQ++;
				};
				break;
			case 1:
				IMAGEMANAGER->findImage("��ó��")->render(_backBuffer->getMemDC());
				// ���߿� ���⼭ �� �˻��ؼ� ������ Q (����) �� �÷��ְ� �ڵ� ���ٸ� �߰�
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					medicineQ++;
				};
				break;
			case 2:
				IMAGEMANAGER->findImage("��޻�ó��")->render(_backBuffer->getMemDC());
				// ���߿� ���⼭ �� �˻��ؼ� ������ Q (����) �� �÷��ְ� �ڵ� ���ٸ� �߰�
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					goodMedicineQ++;
				};
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
}

void uiManager::pokeCenter()
{
	uiOpen = true;
	IMAGEMANAGER->findImage("pokeCenter")->frameRender(_backBuffer->getMemDC(), 170, 105, _index, 0);

	cnt++;

	if (cnt == 15) {
		_index++;
		cnt = 0;
	}

	if (_index > 10) {
		_index = 0;
		//uiOpen = false;
		_isCount = true;
		_isScript = true;
		_isOpenPokecenter = false;
	}
}
/// <�޴�> ////////////////////////////////////////////
/// <�޴�> ////////////////////////////////////////////
/// <�޴�> ////////////////////////////////////////////

void uiManager::menu()
{
	uiOpen = true;

	if (!pokedogamWindow) {
		if (!statusWindow) {
			if (!settingWindow) {
				if (!pokeWindow) {
					if (!bagWindow) {
						if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && menuCnt < 6) {
							menuCnt += 1;
							//�޴� ȭ��ǥ ���Ʒ� �����̴�
						}
						if (KEYMANAGER->isOnceKeyDown(VK_UP) && menuCnt > 0) {
							menuCnt -= 1;
						}
					}
				}
			}
		}
	}

	switch (menuCnt)
	{
	case 0: //����
		IMAGEMANAGER->findImage("menu0")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenPokeDogam = true;
		
		};
		break;
	case 1: //���ϸ�
		IMAGEMANAGER->findImage("menu1")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenPokemon = true;
		
		};
		break;
	case 2://����
		IMAGEMANAGER->findImage("menu2")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenBag = true;
			
		};
		break;
	case 3://���ϱ��
		IMAGEMANAGER->findImage("menu3")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenPokeGear = true;
			
		};
		break;
	case 4://�̸�
		IMAGEMANAGER->findImage("menu4")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenPlayerStatus = true;
			
		};
		break;
	case 5://����
		IMAGEMANAGER->findImage("menu5")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenSetting = true;

		};
		break;
	case 6://�ݴ�
		IMAGEMANAGER->findImage("menu6")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			uiOpen = false;
			_isOpenMenu = false;
			menuCnt = 0;
		}
		return;
		break;
	}

	if (_isOpenBag)
	{
		bag();
	}
	if (_isOpenPlayerStatus)
	{
		playerStatus();
	}
	if (_isOpenPokeDogam)
	{
		pokeDogam();
	}
	if (_isOpenSetting)
	{
		setting();
	}
	if (_isOpenPokeGear)
	{
		pokeGear();
	}
	if (_isOpenPokemon) {
		pokeShift();
	}
}

void uiManager::pokeShift()
{
	pokeWindow = true;
	if (pokeWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && pokesCnt < 6) {
			pokesCnt += 1;

			//�޴� ȭ��ǥ ���Ʒ� �����̴�
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && pokesCnt > 0) {
			pokesCnt -= 1;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {
			pokesCnt = 0;
			pokeWindow = false;
			_isOpenPokemon = false;
		}
		switch (pokesCnt)
		{
		case 0:
			IMAGEMANAGER->findImage("pokeShift0")->render(_backBuffer->getMemDC());
			break;
		case 1: 
			IMAGEMANAGER->findImage("pokeShift1")->render(_backBuffer->getMemDC());
			break;
		case 2:
			
			IMAGEMANAGER->findImage("pokeShift2")->render(_backBuffer->getMemDC());
			break;
		case 3:
			
			IMAGEMANAGER->findImage("pokeShift3")->render(_backBuffer->getMemDC());
			break;
		case 4:
			
			IMAGEMANAGER->findImage("pokeShift4")->render(_backBuffer->getMemDC());
			break;
		case 5:
			
			IMAGEMANAGER->findImage("pokeShift5")->render(_backBuffer->getMemDC());
			break;
		case 6:
			IMAGEMANAGER->findImage("pokeShift6")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
			}

			break;
		}

		//�Ʒ��� ���������� �ʿ��Ҷ� ���ϸ� ������ �޾ƿ´� <- ���߿� �ڵ� ���� ��ġ�� ���������� �ٲ����
		for (int i = 0; i < myPokemon.size(); i++) {
			myPokemon[i].name = _character->getPoketmon(i).name;
			myPokemon[i].maxHP = _character->getPoketmon(i).maxHP;
			myPokemon[i].currentHP = _character->getPoketmon(i).currentHP;
			myPokemon[i].level = _character->getPoketmon(i).level;
			myPokemon[i].iconNumX = _character->getPoketmon(i).iconNumX;
			myPokemon[i].iconNumY = _character->getPoketmon(i).iconNumY;
		}


		char str[128];
		
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font5 = CreateFont(38, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

		delaycnt++;

		char poke[128];

		if (delaycnt == 8) {
			iconCnt++;
			delaycnt = 0;
		}
		
		for (int i = 0; i < myPokemon.size(); i++) {
			string strname = myPokemon[i].name;
			strcpy_s(poke, strname.c_str());

			if (myPokemon[i].maxHP == 0) return;

			IMAGEMANAGER->findImage("Icon")->frameRender(_backBuffer->getMemDC(),35,15 + 
				(i * 65), myPokemon[i].iconNumX+(iconCnt%2), myPokemon[i].iconNumY);

			sprintf_s(str, "%s",poke);
			TextOut(_backBuffer->getMemDC(), 100, 15+ (i * 65), str, strlen(str));

			sprintf_s(str, "/ %d", myPokemon[i].maxHP);
			TextOut(_backBuffer->getMemDC(), 530, 25 + (i * 63), str, strlen(str));

			sprintf_s(str, "HP : %d", myPokemon[i].currentHP);
			TextOut(_backBuffer->getMemDC(), 400, 25 + (i * 63), str, strlen(str));

			sprintf_s(str, ": L %d", myPokemon[i].level);
			TextOut(_backBuffer->getMemDC(), 260, 25 + (i * 63), str, strlen(str));

		}
		
		SelectObject(_backBuffer->getMemDC(), oldFont5);
		DeleteObject(font5);
	}
}


void uiManager::bag()
{
	bagWindow = true;

	// KEYMANAGER->init(); �ƴ� ���� �̴����൵ �׷��µ� ; �ƿ� ��¥

	if (bagWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && bagCnt < 3) {
			bagCnt ++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && bagCnt > 0) {
			bagCnt --;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			bagCnt = 0;
			bagWindow = false;
			uiOpen = false;
			_isOpenBag = false;

		};


		switch (bagCnt) {

		case 0: // ���濡�� ���ͺ��� Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag0")->render(_backBuffer->getMemDC());
			//Ŭ�������� ������ 1�� �̻��̸� ���� �ƴϸ� �� ����
			if (pokeballQ > 0) {
				
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					pokeballQ--;
					//�������� �ƴ� ��� �� ��
					//�����߿� ����� �� ���� bool �� üũ�ؼ� ����ϰ� ���� 
				};
			}
			break;
		case 1:// ���濡�� ��ó�࿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag1")->render(_backBuffer->getMemDC());
			if (medicineQ > 0) {
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					medicineQ--;
					//���ϸ� ����â���� �̵��� ��������ؼ� ü��ȸ��
				};
			}
			break;
		case 2:// ���濡�� ��޻�ó�࿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag2")->render(_backBuffer->getMemDC());
			if (goodMedicineQ > 0) {
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					goodMedicineQ--;
					//���ϸ� ����â���� �̵��� ��������ؼ� ü��ȸ��
				};
			}
			break;
		case 3:// ���濡�� �����⿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag3")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {

				bagCnt = 0;
				bagWindow = false;
				uiOpen = false;
				_isOpenBag = false;
				
			};

			break;
		}

		//������ �ؽ�Ʈ�� ǥ�����ִ� �κ�
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", pokeballQ);
		TextOut(_backBuffer->getMemDC(), 595, 78, str, strlen(str));


		sprintf_s(str, "%d", medicineQ);
		TextOut(_backBuffer->getMemDC(), 595, 143, str, strlen(str));

		sprintf_s(str, "%d", goodMedicineQ);
		TextOut(_backBuffer->getMemDC(), 595, 210, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	}
}
////////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////
// �߰��� �۾��Ұ� //////////////////
////////////////////////////////////
///////////////////////////////////
//////////////////////////////////
void uiManager::pokeDogam()
{
	pokedogamWindow = true;
	if (pokedogamWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && dogamCnt < 1) {
			dogamCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && dogamCnt > 0) {
			dogamCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			dogamCnt = 0;
			pokedogamWindow = false;
			uiOpen = false;
			_isOpenPokeDogam = false;

		};

		switch (dogamCnt) {
		case 0:
			IMAGEMANAGER->findImage("dogam0")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("dogam0")->render(_backBuffer->getMemDC());
			break;
		}
	}

}

void uiManager::pokeGear()
{

	gearWindow = true;
	if (gearWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && gearCnt < 2) {
			gearCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && gearCnt > 0) {
			gearCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			gearCnt = 0;
			gearWindow = false;
			uiOpen = false;
			_isOpenPokeGear = false;

		};
		switch (gearCnt) {
		case 0:
			IMAGEMANAGER->findImage("gear0")->render(_backBuffer->getMemDC());

			break;
		case 1:
			IMAGEMANAGER->findImage("gear1")->render(_backBuffer->getMemDC());
			break;
		case 2:
			IMAGEMANAGER->findImage("gear2")->render(_backBuffer->getMemDC());

			if (KEYMANAGER->isOnceKeyDown('Z')) {

				gearCnt = 0;
				gearWindow = false;
				uiOpen = false;
				_isOpenPokeGear = false;

			};

			break;
		
		}


		if (gearCnt == 0) {
			char str[128];

			SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

			HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

			HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);


			sprintf_s(str, "���ϱ��! �������� ���̴� !");
			TextOut(_backBuffer->getMemDC(), 135, 190, str, strlen(str));
			sprintf_s(str, "���⿡ ��¥�� ���� �߸� ��");
			TextOut(_backBuffer->getMemDC(), 135, 240, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont2);
			DeleteObject(font2);
		}




	}


}

void uiManager::playerStatus()
{
	statusWindow = true;
	if (statusWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && statusCnt < 1) {
			statusCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && statusCnt > 0) {
			statusCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			statusCnt = 0;
			statusWindow = false;
			uiOpen = false;
			_isOpenPlayerStatus = false;

		};
		switch (statusCnt) {
		case 0:
			IMAGEMANAGER->findImage("status0")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("status1")->render(_backBuffer->getMemDC());
			break;
		
		
		}



		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(52, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "����");
		TextOut(_backBuffer->getMemDC(), 180, 50, str, strlen(str));

		HFONT font21 = CreateFont(32, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont21 = (HFONT)SelectObject(_backBuffer->getMemDC(), font21);

		sprintf_s(str, "%d",gold);
		TextOut(_backBuffer->getMemDC(), 290, 190, str, strlen(str));


		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);

		SelectObject(_backBuffer->getMemDC(), oldFont21);
		DeleteObject(font21);

	}



}

void uiManager::setting()
{

	settingWindow = true;
	if (settingWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && settingCnt < 3) {
			settingCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && settingCnt > 0) {
			settingCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			settingCnt = 0;
			settingWindow = false;
			uiOpen = false;
			_isOpenSetting = false;

		};

		switch (settingCnt) {
		case 0:
			IMAGEMANAGER->findImage("setting0")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && soundVolume < 100) {
				soundVolume++;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT) && soundVolume > 0) {
				soundVolume--;
			}

			break;
		case 1:
			IMAGEMANAGER->findImage("setting1")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown('Z')) {
				settingCnt = 0;
				settingWindow = false;
				uiOpen = false;
				_isOpenSetting = false;
			}


			break;
		
		}


		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(56, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", soundVolume);
		TextOut(_backBuffer->getMemDC(), 500, 50, str, strlen(str));


		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);


	}


}

// ������� �޴� ���� ��ư ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uiManager::script()
{
	uiOpen = true;

	if (_isCount)
	{
		switch (_npc)
		{
		case NPC::TITLE:
			_vScript = TXTDATA->txtLoad("script/Ÿ��Ʋ.txt");
			break;
		case NPC::MOM:
			if (_momCount == 0)	_vScript = TXTDATA->txtLoad("script/����1.txt");
			else _vScript = TXTDATA->txtLoad("script/����2.txt");

			_momCount++;

			break;
		case NPC::GONG:
			if (_drCount == 0) _vScript = TXTDATA->txtLoad("script/���ڻ�_ó��.txt");
			else if (_drCount == 1) _vScript = TXTDATA->txtLoad("script/���ڻ�_���ϸ���.txt");
			else if (_drCount == 2) _vScript = TXTDATA->txtLoad("script/���ڻ�_���ϸ���.txt");
			else _vScript = TXTDATA->txtLoad("script/���ڻ�_�ϻ�.txt");

			_drCount++;

			break;
		case NPC::SUPPORTER:
			_vScript = TXTDATA->txtLoad("script/����.txt");
			break;
		case NPC::CHAMPION:
			if (_championCount == 0) _vScript = TXTDATA->txtLoad("script/����_��Ʋ����.txt");
			else if (_championCount == 1) _vScript = TXTDATA->txtLoad("script/����_��Ʋ��.txt");
			else if (_championCount == 2) _vScript = TXTDATA->txtLoad("script/����_��Ʋ��.txt");
			else _vScript = TXTDATA->txtLoad("script/����_�ϻ�.txt");

			_championCount++;

			break;
		case NPC::TRAINER1:
			if (_trainer1Count == 0)_vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ��.txt");
			else if (_trainer1Count == 1)_vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ����.txt");
			else if (_trainer1Count == 2)_vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ��.txt");
			else _vScript = TXTDATA->txtLoad("script/�̵���1_�¸�����.txt");

			_trainer1Count++;

			break;
		case NPC::TRAINER2:
			if (_trainer2Count == 0)_vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ��.txt");
			else if (_trainer2Count == 1)_vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ����.txt");
			else if (_trainer2Count == 2)_vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ��.txt");
			else _vScript = TXTDATA->txtLoad("script/�̵���2_�¸�����.txt");

			_trainer2Count++;

			break;
		case NPC::POKECENTER:
			if (_pokecenterCount == 0) _vScript = TXTDATA->txtLoad("script/��ȣ��_����.txt");
			else _vScript = TXTDATA->txtLoad("script/��ȣ��_��.txt");

			_pokecenterCount++;

			break;
		case NPC::SHOP:
			_vScript = TXTDATA->txtLoad("script/����.txt");
			break;
		case NPC::EVOLUTION:
			_vScript = TXTDATA->txtLoad("script/��ȭ.txt");
			break;
		case NPC::TOTODILE:
			_vScript = TXTDATA->txtLoad("script/������.txt");
			break;
		case NPC::CHIKORITA:
			_vScript = TXTDATA->txtLoad("script/ġ�ڸ�Ÿ.txt");
			break;
		case NPC::CYNDAQUIL:
			_vScript = TXTDATA->txtLoad("script/������.txt");
			break;
		case NPC::SELECTCANCEL:
			_vScript = TXTDATA->txtLoad("script/��Ÿ�ü������.txt");
			break;
		case NPC::BATTLE:
			_vScript = TXTDATA->txtLoad("script/��Ʋ.txt");
			break;
		default:
			break;
		}

		_isCount = false;
	}
	
	// ��ȭ ��ŵ
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isScriptSkip = true;
	}

	// ��ȭ ��
	if (_isScript)
	{
		// ������ �����Ⱚ ���ͼ� -1����
		if (_scriptIndex >= _vScript.size() - 1)
		{
			// ��Ʋ ��ũ��Ʈ�� ��Ʋ ��ũ��Ʈ ����
			if (_isBattleScript)
			{
				_isBattleScript = false;
			}
			// ������ ��ũ��Ʈ ���� �� �ʱ�ȭ(���� ��ũ��Ʈ ���ؼ�)
			_isScript = false;
			_txtIndex = 0;
			_scriptIndex = 0;
			uiOpen = false;
			if (_npc == NPC::POKECENTER && _pokecenterCount == 1)
			{
				_isOpenPokecenter = true;
				uiOpen = true;
			}

			if (_npc == NPC::POKECENTER && _pokecenterCount >= 2)
			{
				_pokecenterCount = 0;
			}
		}

		if (_isBattle)
		{
			// ����̹��� ����
			_scriptImage->render(_backBuffer->getMemDC());

			// �޾ƿ� �ؽ�Ʈ������ �Ѱ���
			_txt = _vScript[_scriptIndex];

			string currentPokemon = _character->getPoketmon(0).name;

			vector<string> _vStr;
			_vStr.push_back("�߻��� " + currentPokemon + "(��)��\n�ºθ� �ɾ�Դ�!;" + currentPokemon + "��(��)\n" + currentPokemon + "��(��);���ʷ� ���´�!;����! " + currentPokemon + "!;" + currentPokemon + "\n��(��)�� �ºο��� �̰��!;");

			TXTDATA->txtSave("script/��Ʋ.txt", _vStr);

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
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
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
		}
		else if (!_isBattle)
		{
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
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
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

void uiManager::battle()
{
	uiOpen = true;

	// ���� RGB(248, 248, 248)
	IMAGEMANAGER->findImage("��Ʋ���")->render(_backBuffer->getMemDC());
	_playerImage = IMAGEMANAGER->findImage("�÷��̾�");
	_enemyPokeImage = IMAGEMANAGER->findImage("155F");

	static int px = -_playerImage->getWidth();
	static int ex = WINSIZEX + _enemyPokeImage->getWidth() - 100;

	if (_isAnimation) //�÷��̾��ʿ��� Ʈ��� �ٲ������
	{
		_playerImage->render(_backBuffer->getMemDC(), px, 200);
		_enemyPokeImage->render(_backBuffer->getMemDC(), ex, 50);

		if (ex >= WINSIZEX - 200)
		{
			ex -= 5;
		}

		if (px <= 70)
		{
			px += 5; // �÷��̾� �̹����� ȭ��ۿ��� ���ڸ� ���� �̵��ϴ°��� �����ϱ� ����
			_npc = NPC::BATTLE;
		}
		else if (_isBattleScript)
		{
			_isCount = true;
			_isScript = true;
		}
		else
		{
			_time = TIMEMANAGER->getWorldTime();
			_isAnimation = false;
		}
	}
	else if (!_isAnimation && TIMEMANAGER->getWorldTime() >= _time + 0.3)
	{
		if (_appearIndex >= 0)
		{
			IMAGEMANAGER->findImage("���ϸ����")->frameRender(_backBuffer->getMemDC(), 70, 200, _appearIndex, 0);
			_behaviorCount = 0;
		}

		static int count = 0;
		count++;

		if (count % 7 == 0) // ���ϸ��� ������ ���ö�
		{
			_appearIndex--;
		}

		if (_appearIndex < 0) // ���ϸ��� ������ ��
		{
			//string index;
			//index = _character->getPoketmon(0).index;

			_currentHP = _character->getPoketmon(0).currentHP;
			_maxHP = _character->getPoketmon(0).maxHP;
			_currentEXP = _character->getPoketmon(0).currentExp;
			_maxEXP = _character->getPoketmon(0).maxExp;

			_hpBarPlayer->setGauge(_currentHP, _maxHP);
			_hpBarPlayer->render();

			_expBar->setGauge(_currentEXP, _maxEXP);
			_expBar->render();

		
			//IMAGEMANAGER->findImage(index + "");

			

			//	Ŀ���� ��ġ
			if (!_isOpenSkill && !_isOpenPokemon && !_isOpenBag)
			{
				if (_behaviorCount == 0)			// �ο��
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_isOpenSkill = true;
					}

					if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						_behaviorCount = 1;			// ����
					}
					else if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						_behaviorCount = 2;			// ���ϸ� ����â
					}
				}
				if (_behaviorCount == 1)			// ����
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_isOpenBag = true;
					}
					if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						_behaviorCount = 3;			// ��������
					}
					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						_behaviorCount = 0;			// �ο��
					}

				}
				if (_behaviorCount == 2)			// ���ϸ� ����â
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_isOpenPokemon = true;
						
					}
					if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						_behaviorCount = 0;			// �ο��
					}
					if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						_behaviorCount = 3;			// ��������
					}
				}
				if (_behaviorCount == 3)			// ��������
				{

					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						uiOpen = false;
						_isBattle = false;
						_behaviorCount = 0;
						px = -_playerImage->getWidth();
						ex = WINSIZEX + _enemyPokeImage->getWidth();
						_appearIndex = 2;
					}
					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						_behaviorCount = 2;			// ���ϸ� ����â
					}
					if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						_behaviorCount = 1;			// ����
					}
				}
			}
			// Ŀ���� ������ - �ο��
			IMAGEMANAGER->findImage("Ŀ��")->render(_backBuffer->getMemDC(), 285 + (_behaviorCount % 2)*160, 445 + (_behaviorCount / 2)*60);
		}
	}
	if (_isOpenBag)
	{
		bag();
	}
	if (_isOpenSkill)
	{
		skill();
	}
	if (_isOpenPokemon)
	{
		pokeShift();
	}
}

void uiManager::skill()
{
	static int skillCnt = 0;

	IMAGEMANAGER->findImage("��ų����")->render(_backBuffer->getMemDC(), 0, 287);

	SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

	HFONT font5 = CreateFont(38, 0, 0, 0, 700, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

	HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

	char skill[128];

	for (int i = 0; i < 4; i++) {
		//string strname = myPokemon[i].name;
		//strcpy_s(poke, strname.c_str());

		sprintf_s(skill, "�����ġ��");
		TextOut(_backBuffer->getMemDC(), 55, 330 + (i * 60), skill, strlen(skill));

		//sprintf_s(skill, "/ %d", myPokemon[i].maxHP);
		//TextOut(_backBuffer->getMemDC(), 530, 25 + (i * 63), skill, strlen(skill));
		//
		//sprintf_s(skill, "HP : %d", myPokemon[i].currentHP);
		//TextOut(_backBuffer->getMemDC(), 400, 25 + (i * 63), skill, strlen(skill));
		//
		//sprintf_s(skill, ": L %d", myPokemon[i].level);
		//TextOut(_backBuffer->getMemDC(), 260, 25 + (i * 63), skill, strlen(skill));

	}

	SelectObject(_backBuffer->getMemDC(), oldFont5);
	DeleteObject(font5);

	if (skillCnt > 0)
	{
		if(KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			skillCnt--;
		}
	}
	if (skillCnt < 3)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			skillCnt++;
		}
	}

	IMAGEMANAGER->findImage("Ŀ��")->render(_backBuffer->getMemDC(), 25, 335 + (skillCnt * 60));

	if (KEYMANAGER->isOnceKeyDown('V')) // ��ųâ���� �ٽ� �ൿ���� ���ϴ� UI ȣ��
	{
		skillCnt = 0;
		_isOpenSkill = false;
	}
}

bool uiManager::isUiOpen()
{
	return uiOpen;
}
