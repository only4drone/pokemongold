#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"
#include "character.h"
#include "progressBar.h"
#include "poketmonManager.h"
#include "tileMap.h"

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
	// ======================================================================================================================
	// ���� // ============================================================================================================

	SOUNDMANAGER->addSound("town1BGM", "soundFX/mainBGM.mp3", true, true);
	SOUNDMANAGER->addSound("town2BGM", "soundFX/road.mp3", true, true);
	SOUNDMANAGER->addSound("open", "soundFX/op.mp3", true, true);
	SOUNDMANAGER->addSound("title", "soundFX/title.mp3", true, true);
	SOUNDMANAGER->addSound("start", "soundFX/start.mp3", true, true);
	SOUNDMANAGER->addSound("ending", "soundFX/ending.mp3", true, true);
	SOUNDMANAGER->addSound("gym", "soundFX/gym.mp3", true, true);
	SOUNDMANAGER->addSound("battle", "soundFX/battle.mp3", true, true);
	SOUNDMANAGER->addSound("doctor", "soundFX/doctor.mp3", true, true);
	SOUNDMANAGER->addSound("pokecenter", "soundFX/pokecenter.mp3", true, true);
	SOUNDMANAGER->addSound("op_star", "soundFX/op_star.wav", true, false);

	// SOUNDMANAGER->play("switch", 0.01f * soundVolume);

	SOUNDMANAGER->addSound("pokeheal", "soundFX/pokeheal.mp3", true, false);
	SOUNDMANAGER->addSound("win", "soundFX/win.mp3", true, false);

	SOUNDMANAGER->addSound("x", "soundFX/xbutton.wav", true, false);
	SOUNDMANAGER->addSound("yes", "soundFX/yes.wav", true, false);
	SOUNDMANAGER->addSound("no", "soundFX/no.wav", true, false);
	SOUNDMANAGER->addSound("switch", "soundFX/switch.wav", true, false);
	SOUNDMANAGER->addSound("menu", "soundFX/menu.wav", true, false);
	SOUNDMANAGER->addSound("mom", "soundFX/mom.wav", true, false);
	SOUNDMANAGER->addSound("med", "soundFX/medicine.wav", true, false);
	SOUNDMANAGER->addSound("item", "soundFX/getitem.wav", true, false);
	SOUNDMANAGER->addSound("click", "soundFX/click.wav", true, false);
	SOUNDMANAGER->addSound("attack", "soundFX/attack.wav", true, false);
	// ======================================================================================================================
	

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

	IMAGEMANAGER->addImage("power", "image/menuUI/power_0.bmp", 640, 576, true, RGB(255, 0, 255));

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

	IMAGEMANAGER->addImage("pointer", "image/menuUI/map_p.bmp", 50, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("status0", "image/menuUI/status_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("status1", "image/menuUI/status_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("status2", "image/menuUI/status_2.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("setting0", "image/menuUI/setting_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("setting1", "image/menuUI/setting_1.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("dogam0", "image/menuUI/dogam_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("dogam1", "image/menuUI/dogam_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("dogam_c", "image/menuUI/dogam_cursor.bmp", 640, 576, true, RGB(255, 0, 255));
	// =======================================================================================================================

	IMAGEMANAGER->addImage("��Ʋ���", "image/battle/battleBackground.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʋ�ൿ����", "image/battle/selectBehavior.bmp", 640, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ų����", "image/battle/backgroundSkill.bmp", 640, 289, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ŀ��", "image/battle/cursorBehavior.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�", "image/battle/playerImage.bmp", 188, 192, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("���Ϻ�����", "image/battle/poketballState.bmp", 28, 112, 1, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image/battle/gender.bmp", 7, 16, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ϸ����", "image/battle/appearPokemon.bmp", 600, 200, 3, 1,  true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ȹ", "image/skill/monsterball.bmp", 15480, 300, 36, 1, true, RGB(255, 0, 255));

	// ========================================================================================================================

	IMAGEMANAGER->addFrameImage("pokeCenter", "image/shopUI/pokeCenter.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("Icon", "image/menuUI/pokeicon.bmp", 2048, 191, 32, 3, true, RGB(255, 0, 255));

	_scriptImage = IMAGEMANAGER->addImage("script", "image/dialogueUI.bmp", 650, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("��", "image/Yes.bmp", 192, 183, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ƴϿ�", "image/No.bmp", 192, 183, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("����", "image/battle/champion.bmp", 220, 220, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ʈ���̳�", "image/battle/trainer.bmp", 220, 220, true, RGB(255, 0, 255));

	// =======================================================================================================================

	_isAnimation = true;

	_hpBarPlayer = new progressBar;
	_hpBarPlayer->init(WINSIZEX - 161 - 192, 297, 192, 8, "image/battle/hpGauge.bmp", "image/battle/hpGaugeBack.bmp", "hpFront", "hpBack");
	//_hpBarPlayer->setGauge(100, 100);

	_hpBarEnemy = new progressBar;
	_hpBarEnemy->init(33, 72, 191, 8, "image/battle/hpGauge.bmp", "image/battle/hpGaugeBack.bmp", "eHpFront", "eHpBack");

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
	_isConfirm = true;
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
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				shopCnt += 1;
				//�޴� ȭ��ǥ ���Ʒ� �����̴�
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && shopCnt > 0) {
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				shopCnt -= 1;
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
					SOUNDMANAGER->play("x", 0.01f * soundVolume);
					shopWindow = false;
					uiOpen = false;
					shopCnt = 0;
					_isOpenShop = false;
					return;
				}
				break;
			}
		}



		if (shopCnt == 0 && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			buyWindow = true;
			//���� ���� 
		};

		if (buyWindow) {

			if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && buyCnt < 4) {
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				buyCnt += 1;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && buyCnt > 0) {
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				buyCnt -= 1;
			}

			switch (buyCnt) {
			case 0:
				IMAGEMANAGER->findImage("���ͺ�")->render(_backBuffer->getMemDC());
				// ���߿� ���⼭ �� �˻��ؼ� ������ Q (����) �� �÷��ְ� �ڵ� ���ٸ� �߰�
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					if (gold < 500) return;
					SOUNDMANAGER->play("yes", 0.01f * soundVolume);
					pokeballQ++;
					gold -= 500;
				};
				break;
			case 1:
				IMAGEMANAGER->findImage("��ó��")->render(_backBuffer->getMemDC());
				// ���߿� ���⼭ �� �˻��ؼ� ������ Q (����) �� �÷��ְ� �ڵ� ���ٸ� �߰�
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					if (gold < 200) return;
					SOUNDMANAGER->play("yes", 0.01f * soundVolume);
					medicineQ++;
					gold -= 200;
				};
				break;
			case 2:
				IMAGEMANAGER->findImage("��޻�ó��")->render(_backBuffer->getMemDC());
				// ���߿� ���⼭ �� �˻��ؼ� ������ Q (����) �� �÷��ְ� �ڵ� ���ٸ� �߰�
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					if (gold < 600) return;
					SOUNDMANAGER->play("yes", 0.01f * soundVolume);
					goodMedicineQ++;
					gold -= 600;
				};
				break;
			case 3:
				IMAGEMANAGER->findImage("�Ȼ��")->render(_backBuffer->getMemDC());
				if (KEYMANAGER->isOnceKeyDown('Z')) {
					SOUNDMANAGER->play("x", 0.01f * soundVolume);
					buyCnt = 0;
					//shopCnt = 0;
					buyWindow = false;
					//���� ���� 
				};

				break;
			}

			char str[128];

			SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

			HFONT font2 = CreateFont(32, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);


			sprintf_s(str, "%d", gold);
			TextOut(_backBuffer->getMemDC(), 440, 30, str, strlen(str));


			SelectObject(_backBuffer->getMemDC(), oldFont2);
			DeleteObject(font2);



		}
	}
}

void uiManager::pokeCenter()
{
	uiOpen = true;
	
	IMAGEMANAGER->findImage("pokeCenter")->frameRender(_backBuffer->getMemDC(), 170, 105, _index, 0);
	cnt++;
	
	if (_index == 4) SOUNDMANAGER->play("pokeheal", 0.01f * soundVolume);

	if (cnt == 20) {
		_index++;
		cnt = 0;
	}
	
	if (_index > 10) {
		_index = 0;
		//uiOpen = false;
		_isCount = true;
		_isScript = true;
		_isOpenPokecenter = false;
		_currentPoke = 0;
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
							SOUNDMANAGER->play("click", 0.01f * soundVolume);
							menuCnt += 1;
							
							//�޴� ȭ��ǥ ���Ʒ� �����̴�
						}
						if (KEYMANAGER->isOnceKeyDown(VK_UP) && menuCnt > 0) {
							SOUNDMANAGER->play("click", 0.01f * soundVolume);
							menuCnt -= 1;
						}
					}
				}
			}
		}
	}
	if (!_isOpenBag && !_isOpenPokemon && !_isOpenPokeDogam && !_isOpenPokeGear && !_isOpenPlayerStatus && !_isOpenSetting)
	{
		if (KEYMANAGER->isOnceKeyDown('X')) {
			SOUNDMANAGER->play("x", 0.01f * soundVolume);
				uiOpen = false;
				_isOpenMenu = false;
				menuCnt = 0;
		
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
				SOUNDMANAGER->play("x", 0.01f * soundVolume);
				uiOpen = false;
				_isOpenMenu = false;
				menuCnt = 0;
			}
			return;
			break;
		}
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

	if (_isOpenHowStrong) {
		howStrong();
	}
}

void uiManager::pokeShift()
{
	pokeWindow = true;

	if(!howStrongWindow) {
		if (pokeWindow) {

			if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && pokesCnt < 6) {
				pokesCnt += 1;
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				//�޴� ȭ��ǥ ���Ʒ� �����̴�
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && pokesCnt > 0) {
				pokesCnt -= 1;
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
			}
			if (KEYMANAGER->isOnceKeyDown('X')) {
				pokesCnt = 0;
				pokeWindow = false;
				_isOpenPokemon = false;
			}
		}
		if (!useMedicineWindow) {
			if (!useGoodMedicineWindow) {
				if (_isBattle && _character->getPoketmon(pokesCnt).maxHP != 0 && pokesCnt < 6)
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_currentPoke = pokesCnt;

						pokesCnt = 0;
						pokeWindow = false;
						_isOpenPokemon = false;
					}
				}
			}
		}
		switch (pokesCnt)
		{
		case 0:
			IMAGEMANAGER->findImage("pokeShift0")->render(_backBuffer->getMemDC());
			if (!_isBattle &&!useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//���������� ����
				_isOpenHowStrong = true;
				//���������� ���� ��

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(0, -50);
				if (_character->getPoketmon(0).currentHP >= _character->getPoketmon(0).sumMaxHP) {
					_character->setCurrentHP(0, _character->getPoketmon(0).currentHP - _character->getPoketmon(0).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(0, -100);
				if (_character->getPoketmon(0).currentHP >= _character->getPoketmon(0).sumMaxHP) {
					_character->setCurrentHP(0, _character->getPoketmon(0).currentHP - _character->getPoketmon(0).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 1: 
			IMAGEMANAGER->findImage("pokeShift1")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//���������� ����
				_isOpenHowStrong = true;
				//���������� ���� ��

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(1, -50);
				if (_character->getPoketmon(1).currentHP >= _character->getPoketmon(1).sumMaxHP) {
					_character->setCurrentHP(1, _character->getPoketmon(1).currentHP - _character->getPoketmon(1).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(1, -100);
				if (_character->getPoketmon(1).currentHP >= _character->getPoketmon(1).sumMaxHP) {
					_character->setCurrentHP(1, _character->getPoketmon(1).currentHP - _character->getPoketmon(1).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 2:
			IMAGEMANAGER->findImage("pokeShift2")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//���������� ����
				_isOpenHowStrong = true;
				//���������� ���� ��

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(2, -50);
				if (_character->getPoketmon(2).currentHP >= _character->getPoketmon(2).sumMaxHP) {
					_character->setCurrentHP(2, _character->getPoketmon(2).currentHP - _character->getPoketmon(2).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(2, -100);
				if (_character->getPoketmon(2).currentHP >= _character->getPoketmon(2).sumMaxHP) {
					_character->setCurrentHP(2, _character->getPoketmon(0).currentHP - _character->getPoketmon(2).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 3:
			IMAGEMANAGER->findImage("pokeShift3")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//���������� ����
				_isOpenHowStrong = true;
				//���������� ���� ��

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(3, -50);
				if (_character->getPoketmon(3).currentHP >= _character->getPoketmon(3).sumMaxHP) {
					_character->setCurrentHP(3, _character->getPoketmon(3).currentHP - _character->getPoketmon(3).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(3, -100);
				if (_character->getPoketmon(3).currentHP >= _character->getPoketmon(3).sumMaxHP) {
					_character->setCurrentHP(3, _character->getPoketmon(3).currentHP - _character->getPoketmon(3).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 4:
			IMAGEMANAGER->findImage("pokeShift4")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//���������� ����
				_isOpenHowStrong = true;
				//���������� ���� ��

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(4, -50);
				if (_character->getPoketmon(4).currentHP >= _character->getPoketmon(4).sumMaxHP) {
					_character->setCurrentHP(4, _character->getPoketmon(4).currentHP - _character->getPoketmon(4).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(4, -100);
				if (_character->getPoketmon(4).currentHP >= _character->getPoketmon(4).sumMaxHP) {
					_character->setCurrentHP(4, _character->getPoketmon(4).currentHP - _character->getPoketmon(4).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 5:
			IMAGEMANAGER->findImage("pokeShift5")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//���������� ����
				_isOpenHowStrong = true;
				//���������� ���� ��

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(5, -50);
				if (_character->getPoketmon(5).currentHP >= _character->getPoketmon(5).sumMaxHP) {
					_character->setCurrentHP(5, _character->getPoketmon(5).currentHP - _character->getPoketmon(5).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(5, -100);
				if (_character->getPoketmon(5).currentHP >= _character->getPoketmon(5).sumMaxHP) {
					_character->setCurrentHP(5, _character->getPoketmon(5).currentHP - _character->getPoketmon(5).sumMaxHP);
				}
				SOUNDMANAGER->play("med", 0.01f * soundVolume);
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
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
			myPokemon[i].sumMaxHP = _character->getPoketmon(i).sumMaxHP;
			myPokemon[i].currentHP = _character->getPoketmon(i).currentHP;
			myPokemon[i].level = _character->getPoketmon(i).level;
			myPokemon[i].iconNumX = _character->getPoketmon(i).iconNumX;
			myPokemon[i].iconNumY = _character->getPoketmon(i).iconNumY;
		}


		char str[128];
		
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font5 = CreateFont(30, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

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

			if (myPokemon[i].sumMaxHP == 0) return;

			IMAGEMANAGER->findImage("Icon")->frameRender(_backBuffer->getMemDC(),35,15 + 
				(i * 65), myPokemon[i].iconNumX+(iconCnt%2), myPokemon[i].iconNumY);

			sprintf_s(str, "%s",poke);
			TextOut(_backBuffer->getMemDC(), 100, 15+ (i * 65), str, strlen(str));

			sprintf_s(str, "/%d", myPokemon[i].sumMaxHP);
			TextOut(_backBuffer->getMemDC(), 530, 25 + (i * 63), str, strlen(str));

			sprintf_s(str, "HP : %d", myPokemon[i].currentHP);
			TextOut(_backBuffer->getMemDC(), 386, 25 + (i * 63), str, strlen(str));

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
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			bagCnt ++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && bagCnt > 0) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			bagCnt --;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {
			SOUNDMANAGER->play("x", 0.01f * soundVolume);

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
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
					// ��Ʋ ���� ������ ��� ����
					if (!_isBattle) return;

					// ���� ���ϸ��� ���� ��쿡 ��� �Ұ�
					if (_character->getPoketmon(5).maxHP != 0 || !_isWild) return;
					pokeballQ--;
					_isCatch = true;
					usePokeBall();
					bagCnt = 0;
					bagWindow = false;
					uiOpen = false;
					_isOpenBag = false;
					//�������� �ƴ� ��� �� ��
					//�����߿� ����� �� ���� bool �� üũ�ؼ� ����ϰ� ���� 
				};
			}
			break;
		case 1:// ���濡�� ��ó�࿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag1")->render(_backBuffer->getMemDC());
			if (medicineQ > 0) {
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
					medicineQ--;
					bagCnt = 0;
					bagWindow = false;
					uiOpen = false;
					_isOpenBag = false;
					//���ϸ� ����â���� �̵��� ��������ؼ� ü��ȸ��
					useMedicineWindow = true;
					_isOpenPokemon = true;
				};
			}
			break;
		case 2:// ���濡�� ��޻�ó�࿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag2")->render(_backBuffer->getMemDC());
			if (goodMedicineQ > 0) {
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
					goodMedicineQ--;
					//���ϸ� ����â���� �̵��� ��������ؼ� ü��ȸ��
					bagCnt = 0;
					bagWindow = false;
					uiOpen = false;
					_isOpenBag = false;
					//���ϸ� ����â���� �̵��� ��������ؼ� ü��ȸ��
					useGoodMedicineWindow = true;
					_isOpenPokemon = true;
				};
			}
			break;
		case 3:// ���濡�� �����⿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag3")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				SOUNDMANAGER->play("x", 0.01f * soundVolume);

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

		HFONT font2 = CreateFont(28, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", pokeballQ);
		TextOut(_backBuffer->getMemDC(), 590, 78, str, strlen(str));


		sprintf_s(str, "%d", medicineQ);
		TextOut(_backBuffer->getMemDC(), 590, 143, str, strlen(str));

		sprintf_s(str, "%d", goodMedicineQ);
		TextOut(_backBuffer->getMemDC(), 590, 210, str, strlen(str));

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

		IMAGEMANAGER->findImage("dogam1")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && dogamCnt < 23) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			dogamCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && dogamCnt > 0) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			dogamCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {
			SOUNDMANAGER->play("x", 0.01f * soundVolume);

			dogamCnt = 0;
			pokedogamWindow = false;
			uiOpen = false;
			_isOpenPokeDogam = false;

		};
		IMAGEMANAGER->findImage("dogam_c")->render(_backBuffer->getMemDC(),0,dogamCnt*23);
		switch (dogamCnt) {
		case 0:
			IMAGEMANAGER->findImage("10F")->render(_backBuffer->getMemDC(), 50, 30);
			break;
		case 1:
			IMAGEMANAGER->findImage("11F")->render(_backBuffer->getMemDC(), 50, 30);
			break;
		case 2:
			IMAGEMANAGER->findImage("12F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 3:
			IMAGEMANAGER->findImage("13F")->render(_backBuffer->getMemDC(), 50, 30);
			break;
		case 4:
			IMAGEMANAGER->findImage("14F")->render(_backBuffer->getMemDC(), 50, 30);
			break;
		case 5:
			IMAGEMANAGER->findImage("15F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 6:
			IMAGEMANAGER->findImage("16F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 7:
			IMAGEMANAGER->findImage("17F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 8:
			IMAGEMANAGER->findImage("18F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 9:
			IMAGEMANAGER->findImage("19F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 10:
			IMAGEMANAGER->findImage("20F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 11:
			IMAGEMANAGER->findImage("25F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 12:
			IMAGEMANAGER->findImage("26F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 13:
			IMAGEMANAGER->findImage("21F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 14:
			IMAGEMANAGER->findImage("22F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 15:
			IMAGEMANAGER->findImage("152F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 16:
			IMAGEMANAGER->findImage("153F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 17:
			IMAGEMANAGER->findImage("154F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 18:
			IMAGEMANAGER->findImage("155F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 19:
			IMAGEMANAGER->findImage("156F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 20:
			IMAGEMANAGER->findImage("157F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 21:
			IMAGEMANAGER->findImage("158F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 22:
			IMAGEMANAGER->findImage("159F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		case 23:
			IMAGEMANAGER->findImage("160F")->render(_backBuffer->getMemDC(), 50, 40);
			break;
		}
	}

}

void uiManager::pokeGear()
{

	gearWindow = true;
	if (gearWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && gearCnt < 2) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			gearCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && gearCnt > 0) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			gearCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {SOUNDMANAGER->play("x", 0.01f * soundVolume);

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
			IMAGEMANAGER->findImage("pointer")->render(_backBuffer->getMemDC(),
				535+_tileMap->getCameraX() / 13, 
				240+ _tileMap->getCameraY() /16);
			break;
		case 2:
			IMAGEMANAGER->findImage("gear2")->render(_backBuffer->getMemDC());

			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				SOUNDMANAGER->play("x", 0.01f * soundVolume);

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
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);


			sprintf_s(str, "���ϱ� ����� �� �ֽ��ϴ�.");
			TextOut(_backBuffer->getMemDC(), 135, 190, str, strlen(str));
			sprintf_s(str, "����� 10 �� 00 ��");
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
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			statusCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && statusCnt > 0) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			statusCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {
			SOUNDMANAGER->play("x", 0.01f * soundVolume);

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
			if (_isGetBadge) {
				IMAGEMANAGER->findImage("status2")->render(_backBuffer->getMemDC());
			}
			break;
		
		
		}



		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(52, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "����");
		TextOut(_backBuffer->getMemDC(), 180, 50, str, strlen(str));

		HFONT font21 = CreateFont(32, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

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
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			settingCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && settingCnt > 0) {
			SOUNDMANAGER->play("click", 0.01f * soundVolume);
			settingCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {
			SOUNDMANAGER->play("x", 0.01f * soundVolume);

			settingCnt = 0;
			settingWindow = false;
			uiOpen = false;
			_isOpenSetting = false;

		};

		switch (settingCnt) {
		case 0:
			IMAGEMANAGER->findImage("setting0")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && soundVolume < 100) {
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				soundVolume++;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT) && soundVolume > 0) {
				SOUNDMANAGER->play("click", 0.01f * soundVolume);
				soundVolume--;
			}

			break;
		case 1:
			IMAGEMANAGER->findImage("setting1")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				SOUNDMANAGER->play("x", 0.01f * soundVolume);
				settingCnt = 0;
				settingWindow = false;
				uiOpen = false;
				_isOpenSetting = false;
			}


			break;
		
		}


		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(42, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", soundVolume);
		TextOut(_backBuffer->getMemDC(), 500, 50, str, strlen(str));


		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);


	}


}

void uiManager::howStrong()
{
	howStrongWindow = true;
	IMAGEMANAGER->findImage("power")->render(_backBuffer->getMemDC());

	char str[128];

	SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

	HFONT font2 = CreateFont(38, 0, 0, 0, 700, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

	HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).index);
	TextOut(_backBuffer->getMemDC(), 85, 1, str, strlen(str));

	sprintf_s(str, (_character->getPoketmon(pokesCnt).name + _character->getPoketmon(pokesCnt).gender).c_str());
	TextOut(_backBuffer->getMemDC(), 50, 430, str, strlen(str));

	IMAGEMANAGER->findImage(to_string(_character->getPoketmon(pokesCnt).index) + "F")->render(_backBuffer->getMemDC(),20,150);

	sprintf_s(str, ":L %d", _character->getPoketmon(pokesCnt).level);
	TextOut(_backBuffer->getMemDC(), 50, 370, str, strlen(str));


	sprintf_s(str, "/ %d", _character->getPoketmon(pokesCnt).sumMaxHP);
	TextOut(_backBuffer->getMemDC(), 460, 150, str, strlen(str));

	sprintf_s(str, "HP : %d", _character->getPoketmon(pokesCnt).currentHP);
	TextOut(_backBuffer->getMemDC(), 280, 150, str, strlen(str));


	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumAttack);
	TextOut(_backBuffer->getMemDC(), 510, 240, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumDefense);
	TextOut(_backBuffer->getMemDC(), 510, 310, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumSpecialAttack);
	TextOut(_backBuffer->getMemDC(), 510, 380, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumSpecialDefense);
	TextOut(_backBuffer->getMemDC(), 510, 440, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumSpeed);
	TextOut(_backBuffer->getMemDC(), 510, 500, str, strlen(str));


	for (int i = 0; i < 4; i++) {
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[i]);
		sprintf_s(str, _poketmonManager->getSkill()->getSkillName().c_str());

		TextOut(_backBuffer->getMemDC(), 285, 5 + (i * 37), str, strlen(str));
	}





	SelectObject(_backBuffer->getMemDC(), oldFont2);
	DeleteObject(font2);


	if (KEYMANAGER->isOnceKeyDown('X')) {
		SOUNDMANAGER->play("x", 0.01f * soundVolume);

		howStrongWindow = false;
		_isOpenHowStrong = false;

	};


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

			if (_drCount == 1 && !_isStarting) break;
			_drCount++;

			break;
		case NPC::SUPPORTER:
			_vScript = TXTDATA->txtLoad("script/����.txt");
			break;
		case NPC::CHAMPION:
			if (_championCount == 0) _vScript = TXTDATA->txtLoad("script/����_��Ʋ��.txt");
			else if (_championCount == 1) _vScript = TXTDATA->txtLoad("script/����_��Ʋ����.txt");
			else if (_championCount == 2) _vScript = TXTDATA->txtLoad("script/����_��Ʋ�¸�.txt");
			else if (_championCount == 3) _vScript = TXTDATA->txtLoad("script/����_��Ʋ��.txt");
			else if (_championCount == 4) _vScript = TXTDATA->txtLoad("script/����_��Ʋ��.txt");
			else _vScript = TXTDATA->txtLoad("script/����_�ϻ�.txt");

			_championCount++;

			break;
		case NPC::TRAINER1:
			if (_trainer1Count == 0) _vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ��.txt");
			else if (_trainer1Count == 1) _vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ����.txt");
			else if (_trainer1Count == 2) _vScript = TXTDATA->txtLoad("script/�̵���1_�¸�����.txt");
			else _vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ��.txt");

			_trainer1Count++;
			//if (_trainer1Count >= 4) _trainer1Count = 6;

			break;
		case NPC::TRAINER2:
			if (_trainer2Count == 0) _vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ��.txt");
			else if (_trainer2Count == 1) _vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ����.txt");
			else if (_trainer2Count == 2) _vScript = TXTDATA->txtLoad("script/�̵���2_�¸�����.txt");
			else _vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ��.txt");

			_trainer2Count++;
			//if (_trainer2Count >= 4) _trainer2Count = 6;

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
		case NPC::BATTLE_ATTACK:
			_vScript = TXTDATA->txtLoad("script/����.txt");
			break;
		case NPC::BATTLE_DOWN:
			switch (_whoTurn)
			{
			case 1:
				_vScript = TXTDATA->txtLoad("script/�߻���Ʋ�¸�.txt");
				break;
			case 2:
				_vScript = TXTDATA->txtLoad("script/�й�.txt");
				break;
			}
			break;
		case NPC::CHAMPION_BATTLE_DOWN:
			_vScript = TXTDATA->txtLoad("script/�������ϸ����.txt");
			break;
		case NPC::CHAMPION_BATTLE_WIN:
			_vScript = TXTDATA->txtLoad("script/����_��Ʋ�¸�.txt");
			break;
		case NPC::TRAINER1_BATTLE_DOWN:
			_vScript = TXTDATA->txtLoad("script/Ʈ���̳�1_���ϸ����.txt");
			break;
		case NPC::TRAINER1_BATTLE_WIN:
			_vScript = TXTDATA->txtLoad("script/Ʈ���̳�1_��Ʋ�¸�.txt");
			break;
		case NPC::TRAINER2_BATTLE_DOWN:
			_vScript = TXTDATA->txtLoad("script/Ʈ���̳�2_���ϸ����.txt");
			break;
		case NPC::TRAINER2_BATTLE_WIN:
			_vScript = TXTDATA->txtLoad("script/Ʈ���̳�2_��Ʋ�¸�.txt");
			break;
		case NPC::LEVEL_UP:
			_vScript = TXTDATA->txtLoad("script/������.txt");
			break;
		case NPC::POKEMONCHANGE:
			_vScript = TXTDATA->txtLoad("script/���ϸ�ü.txt");
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

			// ���ϸ� ���� ó�� ���� ��� ���ϸ� ȸ�� �ִϸ��̼� ���
			if (_npc == NPC::POKECENTER && _pokecenterCount == 1)
			{
				_isOpenPokecenter = true;
				uiOpen = true;

				for (int i = 0; _character->getPoketmon(i).maxHP != 0; i++)
				{
					_character->setCurrentHP(i, _character->getPoketmon(i).currentHP - _character->getPoketmon(i).sumMaxHP);
				}
			}

			// ���ϸ� ���� ȸ�� ��
			if (_npc == NPC::POKECENTER && _pokecenterCount >= 2)
			{
				_pokecenterCount = 0;
			}


			// ��簡 ������ ���� ���� ����Ʈ �ִϸ��̼� ���
			if (_isAttack && _attackCount < 1)
			{
				_isTurn = true;
				_isNext = false;
			}

			if (_attackCount > 0)
			{
				_isTurn = true;
				_attackCount++;
			}

			//if (_isWin)
			//{
			//	_time = TIMEMANAGER->getWorldTime();
			//	_character->setTotalExp(_currentPoke, 50);
			//}

			// ������ ���ϸ��� �����߷��� ���(�߻� ����)
			if (_npc == NPC::CHAMPION_BATTLE_DOWN || _npc == NPC::TRAINER1_BATTLE_DOWN || _npc == NPC::TRAINER2_BATTLE_DOWN)
			{
				//_npc = NPC::CHAMPION;
				_currentEnemyIndex++;

				_appearIndexEnemy = 2;

				if (_npc == NPC::CHAMPION_BATTLE_DOWN)
				{
					_currentEnemyPokemon = _poketmonManager->getChampionPoketmon()[_currentEnemyIndex];
				}
				else if (_npc == NPC::TRAINER1_BATTLE_DOWN)
				{
					_currentEnemyPokemon = _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex];
				}
				else if (_npc == NPC::TRAINER2_BATTLE_DOWN)
				{
					_currentEnemyPokemon = _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex];
				}

				// ���ʹ� ü�¹�
				_hpBarEnemy->setGauge(_currentEnemyPokemon.currentHP, _currentEnemyPokemon.sumMaxHP, true);

				_isAttack = false;
				_isTurn = false;
				_isNext = false;
			}

			// è�Ǿ�� ��ȭ���� ��� ���� ��ũ��Ʈ���� �˾Ƽ� �̾������� ����
			if (_npc == NPC::CHAMPION && _championCount >= 3)
			{
				_npc = NPC::CHAMPION;
				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;
				_isScript = true;
				_isCount = true;
				_isGetBadge = true;		// ���� ȹ��

				if (_championCount == 5)
				{
					_isBattle = false;
					_isAttack = false;
					_attackCount = 0;
					_isTurn = false;
					_isNext = false;
					_whoTurn = 0;
					_currentEnemyIndex = 0;
					_skillCnt = 0;

					SOUNDMANAGER->stop("battle");
					SOUNDMANAGER->play("gym", 0.01f * UIMANAGER->getVolume());
				}
			}

			// Ʈ���̳ʵ�� ��ȭ���� ��� ���� ��ũ��Ʈ���� �˾Ƽ� �̾������� ����
			//if ((_npc == NPC::TRAINER1 && _trainer1Count >= 3) || (_npc == NPC::TRAINER2 && _trainer2Count >= 3))
			//{
			//	_isBattle = false;
			//	_isAttack = false;
			//	_attackCount = 0;
			//	_isTurn = false;
			//	_isNext = false;
			//	_whoTurn = 0;
			//	_currentEnemyIndex = 0;
			//
			//	//_npc = NPC::TRAINER1;
			//	_txtIndex = 0;
			//	_scriptIndex = 0;
			//	uiOpen = false;
			//	_isScript = true;
			//	_isCount = true;
			//}

			// �÷��̾ �̰��� ���
			if (_npc == NPC::CHAMPION_BATTLE_WIN || _npc == NPC::TRAINER1_BATTLE_WIN || _npc == NPC::TRAINER2_BATTLE_WIN)
			{
				if (_npc == NPC::CHAMPION_BATTLE_WIN) _npc = NPC::CHAMPION;
				else if (_npc == NPC::TRAINER1_BATTLE_WIN) _npc = NPC::TRAINER1;
				else if (_npc == NPC::TRAINER2_BATTLE_WIN) _npc = NPC::TRAINER2;

				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;
				_isScript = true;
				_isCount = true;
				_isBattle = false;
				_isAttack = false;
				_attackCount = 0;
				_isTurn = false;
				_isNext = false;
				_whoTurn = 0;
				_currentEnemyIndex = 0;
				_isScript = false;
				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;
				SOUNDMANAGER->stop("battle");
				SOUNDMANAGER->play("gym", 0.01f * soundVolume);

			}
			if ((_npc == NPC::CHAMPION || _npc == NPC::TRAINER1 || _npc == NPC::TRAINER2) && (_championCount == 3 || _trainer1Count == 3 || _trainer2Count == 3))
			{
				SOUNDMANAGER->stop("battle");
				SOUNDMANAGER->play("gym", 0.01f * soundVolume);

				if (_npc == NPC::CHAMPION) _championCount = 10;
				else if (_npc == NPC::TRAINER1) _trainer1Count = 10;
				else if (_npc == NPC::TRAINER2) _trainer2Count = 10;
			}

			//// ��Ʋ �� �÷��̾ ���� ���
			//if (_npc != NPC::CHAMPION_BATTLE_WIN && _npc != NPC::TRAINER1_BATTLE_WIN && _npc != NPC::TRAINER2_BATTLE_WIN && _championCount != 3 && _trainer1Count != 2 && _trainer2Count != 2)
			//{
			//}
			
			// ��Ʋ �� �÷��̾ ���� ���
			// ���� ���ϸ��� ���� ���
			if (_isBattle && _character->getPoketmon(_currentPoke).currentHP <= 0 && _character->getPoketmon(_currentPoke + 1).maxHP != 0)
			{
				//_character->setCurrentHP(_currentPoke, _character->getPoketmon(_currentPoke).currentHP - _character->getPoketmon(_currentPoke).sumMaxHP);

				_appearIndexPlayer = 2;

				_isAttack = false;
				_attackCount = 0;
				_isTurn = false;
				_isNext = false;
				_whoTurn = 0;
				_isChange = true;

				// ü�� 0���� ����
				_character->setCurrentHP(_currentPoke, _character->getPoketmon(_currentPoke).currentHP);

				_currentPoke++;

				//else
				//{
				//	for (int i = 0; _character->getPoketmon(i).maxHP != 0; i++)
				//	{
				//		_character->setCurrentHP(i, _character->getPoketmon(i).currentHP - _character->getPoketmon(i).sumMaxHP);
				//	}
				//}
			}
			// ���� ���ϸ��� ���� ���
			else if (_isBattle && (_character->getPoketmon(_currentPoke + 1).maxHP == 0 && _character->getPoketmon(_currentPoke).currentHP <= 0))
			{
				_isAttack = false;
				_isBattle = false;
				_attackCount = 0;
				_isTurn = false;
				_isNext = false;
				_whoTurn = 0;
				_currentEnemyIndex = 0;
				_currentPoke = 0;
				_skillCnt = 0;
				_isScript = false;
				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;

				// ü�� 0���� ����
				_character->setCurrentHP(_currentPoke, _character->getPoketmon(_currentPoke).currentHP);

				SOUNDMANAGER->stop("battle");
				SOUNDMANAGER->play("town2BGM", 0.01f * UIMANAGER->getVolume());

				//for (int i = 0; _character->getPoketmon(i).maxHP != 0; i++)
				//{
				//	_character->setCurrentHP(i, _character->getPoketmon(i).currentHP - _character->getPoketmon(i).sumMaxHP);
				//}
			}
			else if (_isBattle && _currentEnemyPokemon.currentHP <= 0)
			{
				_isAttack = false;
				_isBattle = false;
				_attackCount = 0;
				_isTurn = false;
				_isNext = false;
				_whoTurn = 0;
				_currentEnemyIndex = 0;
				_currentPoke = 0;
				_skillCnt = 0;
				_isScript = false;
				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;

				if (_npc != NPC::CHAMPION && _npc != NPC::TRAINER1 && _npc != NPC::TRAINER2)
				{
					SOUNDMANAGER->stop("battle");
					SOUNDMANAGER->play("town2BGM", 0.01f * UIMANAGER->getVolume());
				}
			
				//for (int i = 0; _character->getPoketmon(i).maxHP != 0; i++)
				//{
				//	_character->setCurrentHP(i, _character->getPoketmon(i).currentHP - _character->getPoketmon(i).sumMaxHP);
				//}
			}

			// ��ü�� ������
			if (_npc == NPC::POKEMONCHANGE)
			{
				_isChange = false;
			}

			// ���ϸ� ��ü
			if (_isChange)
			{
				vector<string> _vStr;
				_vStr.push_back("���� " + _character->getPoketmon(_currentPoke).name + "!;" + "aaa;");

				TXTDATA->txtSave("script/���ϸ�ü.txt", _vStr);

				_npc = NPC::POKEMONCHANGE;

				_isScript = true;
				_isCount = true;
				_txtIndex = 0;
				_scriptIndex = 0;
			}

			if (_npc == NPC::BATTLE_DOWN && _whoTurn == 1)
			{
				// �÷��̾� ü�¹�
				_hpBarPlayer->setGauge(_character->getPoketmon(_currentPoke).currentHP, _character->getPoketmon(_currentPoke).maxHP, true);

			}

			// ��Ÿ�� ���ϸ� ȹ�� ��
			if (_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA)
			{
				_isStarting == true;
				getStartingPokemon();
			}

			// ��Ʋ �¸� ��Ȳ�� �ƴϸ�
			if (_npc != NPC::CHAMPION_BATTLE_WIN && _npc != NPC::TRAINER1_BATTLE_WIN && _npc != NPC::TRAINER2_BATTLE_WIN && _championCount != 3 && _championCount != 4 && !_isChange)
			{
				// ������ ��ũ��Ʈ ���� �� �ʱ�ȭ(���� ��ũ��Ʈ ���ؼ�)
				_isScript = false;
				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;
			}

			if (_npc == NPC::TITLE)
			{
				_isScript = false;
				_txtIndex = 0;
				_scriptIndex = 0;
				uiOpen = false;
				SOUNDMANAGER->stop("start");
				SCENEMANAGER->changeScene("�ΰ���");
			}

			// Ʈ���̳ʵ��� ���� �ɾ��� ���
			//if ((_npc == NPC::TRAINER1 && _trainer1Count == 1) || (_npc == NPC::TRAINER2 && _trainer2Count == 1))
			//{
			//	_isBattle = true;
			//	_isCount = true;
			//}
		}

		if (_isBattle)
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
					if (_isWin && _scriptIndex == 1)
					{
						_isWin = false;
						_character->setTotalExp(_currentPoke, 100);

						//if (_character->getPoketmon(_currentPoke).currentExp >= _character->getPoketmon(_currentPoke).maxExp)
						//{
						//	_isLevelUp = true;
						//	_character->levelUp(_currentPoke);
						//}
						if (_character->getPoketmon(_currentPoke).level > _currentLevel)
						{
							_isLevelUp = true;
							//_character->levelUp(_currentPoke);
						}
					}
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						// ��ŵ ���� false(���� ���� ��ŵ���� �ʵ���)
						_isScriptSkip = false;

						// ���� �ε��� �ʱ�ȭ ���ְ� ���� �ٷ� �Ѱ���
						_txtIndex = 0;
						_scriptIndex++;

						if (!_isLevelUp && (_npc == NPC::CHAMPION_BATTLE_DOWN || _npc == NPC::TRAINER1_BATTLE_DOWN || _npc == NPC::TRAINER2_BATTLE_DOWN || _whoTurn == 1) && _scriptIndex == 2)
						{
							_scriptIndex++;
						}

						_isLevelUp = false;
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

					if (!_isLevelUp && (_npc == NPC::CHAMPION_BATTLE_DOWN || _npc == NPC::TRAINER1_BATTLE_DOWN || _npc == NPC::TRAINER2_BATTLE_DOWN || _whoTurn == 1) && _scriptIndex == 2)
					{
						_scriptIndex++;
					}
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
		// ��Ʋ �ƴ� ��
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
					// ��ŵ ���� false(���� ���� ��ŵ���� �ʵ���)
					_isScriptSkip = false;

					// ��Ÿ�� ���ϸ� �������� ���
					if ((_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA) && _scriptIndex == 0 && _txtIndex == _txt.length())
					{
						_isAccept = false;
						_isConfirm = true;
						_txtIndex++;
					}
					// ��ư�� ������
					if (!_isConfirm)
					{
						if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
						{
							// ���� �ε��� �ʱ�ȭ ���ְ� ���� �ٷ� �Ѱ���
							_txtIndex = 0;
							_scriptIndex++;
						}
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
		RECT rcText = RectMake(30, WINSIZEY - 150, 600, 120);

		HFONT font = CreateFont(60, 0, 0, 0, 500, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont = (HFONT)SelectObject(_backBuffer->getMemDC(), font);

		DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);

		SelectObject(_backBuffer->getMemDC(), oldFont);
		DeleteObject(font);


		/*char str[128];

		sprintf_s(str, "battle : %d", _isBattle);
		TextOut(_backBuffer->getMemDC(), 300, 10, str, strlen(str));

		sprintf_s(str, "confirm : %d", _isConfirm);
		TextOut(_backBuffer->getMemDC(), 300, 30, str, strlen(str));

		sprintf_s(str, "script : %d", _isScript);
		TextOut(_backBuffer->getMemDC(), 300, 50, str, strlen(str));

		sprintf_s(str, "champion : %d", _championCount);
		TextOut(_backBuffer->getMemDC(), 300, 70, str, strlen(str));*/
	}
}

void uiManager::battle()
{
	uiOpen = true;

	//// ��Ʋ ���� �� Ʈ���̳� ��Ʋ�� ��� ��� ���
	//if (_championCount == 1 || _trainer1Count == 1 || _trainer2Count == 1)
	//{
	//	_isScript = true;
	//	_isCount = true;
	//}

	// ���� RGB(248, 248, 248)
	IMAGEMANAGER->findImage("��Ʋ���")->render(_backBuffer->getMemDC());

	_playerImage = IMAGEMANAGER->findImage("�÷��̾�");

	if (_isBattleStart)
	{
		_behaviorCount = 0;
	}
	
	if (_isWild)
	{
		_currentEnemy = 0;
		_currentEnemyPokemon = _poketmonManager->getWildPoketmon();
	}
	else if (!_isWild)
	{
		switch (_npc)
		{
		case NPC::CHAMPION:
			if (_isBattleStart)
			{
				//_isBattleStart = false;

				_currentEnemyIndex = 0;
			}
			_currentEnemy = 3;
			_enemyImage = IMAGEMANAGER->findImage("����");
			_currentEnemyPokemon = _poketmonManager->getChampionPoketmon()[_currentEnemyIndex];
			break;
		case NPC::TRAINER1:
			if (_isBattleStart)
			{
				//_isBattleStart = false;

				_currentEnemyIndex = 0;
			}
			_currentEnemy = 1;
			_enemyImage = IMAGEMANAGER->findImage("Ʈ���̳�");
			_currentEnemyPokemon = _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex];
			break;
		case NPC::TRAINER2:
			if (_isBattleStart)
			{
				//_isBattleStart = false;

				_currentEnemyIndex = 0;
			}
			_currentEnemy = 2;
			_enemyImage = IMAGEMANAGER->findImage("Ʈ���̳�");
			_currentEnemyPokemon = _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex];
			break;
		//default:
		//	if (_isBattleStart)
		//	{
		//		_isBattleStart = false;
		//
		//		_npc = NPC::TRAINER1;
		//		_currentEnemyIndex = 0;
		//	}
		//	_currentEnemy = 1;
		//	_enemyImage = IMAGEMANAGER->findImage("Ʈ���̳�");
		//	_currentEnemyPokemon = _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex];
		//	break;
		}

		if (_currentEnemy == 1) _currentEnemyPokemon = _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex];
		if (_currentEnemy == 2) _currentEnemyPokemon = _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex];
		if (_currentEnemy == 3) _currentEnemyPokemon = _poketmonManager->getChampionPoketmon()[_currentEnemyIndex];
	}

	_currentPokemon = _character->getPoketmon(0);

	// �÷��̾� ü�¹�
	_hpBarPlayer->setGauge(_character->getPoketmon(_currentPoke).currentHP, _character->getPoketmon(_currentPoke).sumMaxHP, _isBattleStart);
	// ���ʹ� ü�¹�
	_hpBarEnemy->setGauge(_currentEnemyPokemon.currentHP, _currentEnemyPokemon.sumMaxHP, _isBattleStart);
	// ����ġ ��
	_expBar->setGauge(_character->getPoketmon(_currentPoke).currentExp, _character->getPoketmon(_currentPoke).maxExp, _isBattleStart);

	_isBattleStart = false;


	vector<string> _vStr;
	_vStr.push_back("�߻��� " + _currentEnemyPokemon.name + "(��)��\n�ºθ� �ɾ�Դ�!;" + "����" + "��(��)\n" + _currentPokemon.name + "��(��);���ʷ� ���´�!;����! " + _currentPokemon.name + "!;" + _currentPokemon.name + "\n��(��)�� �ºο��� �̰��!;");

	TXTDATA->txtSave("script/��Ʋ.txt", _vStr);

	_playerPokeImage = IMAGEMANAGER->findImage(to_string(_character->getPoketmon(_currentPoke).index) + "B");

	// �߻����ϸ���� ��Ʋ�� ���
	_enemyPokeImage = IMAGEMANAGER->findImage(to_string(_currentEnemyPokemon.index) + "F");

	static int px = -_playerImage->getWidth();
	static int ex = WINSIZEX;

	// �߻� ���ϸ���� ������ ��
	if (_isWild && _currentEnemyPokemon.currentHP > 0)
	{
		//_npc = NPC::BATTLE;
		// �߻��� ������ ó�� �̹��� �״�� ����	(���Ŀ� �߻� / Ʈ���̳� �� ���� �����ؼ� ���)
		if (_catchIndex < 15) _enemyPokeImage->render(_backBuffer->getMemDC(), ex, 0);
	}

	// ����ġ �ö󰡴°� �ð� �����Ϸ��� �ߴ� ��
	//if (_isWin && TIMEMANAGER->getWorldTime() >= _time + 1)
	//{
	//	_isAttack = false;
	//	_isBattle = false;
	//	_attackCount = 0;
	//	_isTurn = false;
	//	_isNext = false;
	//	_whoTurn = 0;
	//	_isWin = false;
	//}

	if (_isAnimation) //�÷��̾��ʿ��� Ʈ��� �ٲ������
	{
		_playerImage->render(_backBuffer->getMemDC(), px, 200);

		// Ʈ���̳ʿ��� ������ ��
		if (!_isWild)
		{
			_enemyImage->render(_backBuffer->getMemDC(), ex, 0);
		}

		if (ex >= WINSIZEX - 230)
		{
			ex -= 5;
		}

		if (px <= 70)
		{
			px += 5; // �÷��̾� �̹����� ȭ��ۿ��� ���ڸ� ���� �̵��ϴ°��� �����ϱ� ����
			//_npc = NPC::BATTLE;
		}
		else if (_isBattleScript && !_isScript)
		{
			_isCount = true;
			_isScript = true;
		}
		else if (!_isScript)
		{
			_time = TIMEMANAGER->getWorldTime();
			_isAnimation = false;
		}
	}
	else if (!_isAnimation && TIMEMANAGER->getWorldTime() >= _time + 0.3)
	{
		if (_appearIndexPlayer >= 0)
		{
			IMAGEMANAGER->findImage("���ϸ����")->frameRender(_backBuffer->getMemDC(), 70, 200, _appearIndexPlayer, 0);
		}
		if (_appearIndexEnemy >= 0)
		{
			// Ʈ���̳ʿ��� ��Ʋ�� ���
			if (!_isWild) IMAGEMANAGER->findImage("���ϸ����")->frameRender(_backBuffer->getMemDC(), WINSIZEX - 230, 0, _appearIndexEnemy, 0);
		}

		static int count = 0;
		count++;

		if (count % 7 == 0) // ���ϸ��� ������ ���ö�
		{
			_appearIndexPlayer--;
			_appearIndexEnemy--;
		}

		if (_appearIndexPlayer < 0) // ���ϸ��� ������ ��
		{
			//string index;
			//index = _character->getPoketmon(0).index;

			// �̹��� ���
			if (_character->getPoketmon(_currentPoke).currentHP > 0) _playerPokeImage->frameRender(_backBuffer->getMemDC(), 70, 200);

			// �÷��̾� ü�¹�
			_hpBarPlayer->setGauge(_character->getPoketmon(_currentPoke).currentHP, _character->getPoketmon(_currentPoke).sumMaxHP, _isBattleStart);
			_hpBarPlayer->render();

			// ����ġ ��
			_expBar->setGauge(_character->getPoketmon(_currentPoke).currentExp, _character->getPoketmon(_currentPoke).maxExp, _isBattleStart);
			_expBar->render();

			//_isBattleStart = false;

			// �̸� ����
			char str[128];

			SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

			HFONT font5 = CreateFont(45, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

			// �� ���ϸ�
			sprintf_s(str, (_character->getPoketmon(_currentPoke).name + _character->getPoketmon(_currentPoke).gender).c_str());
			//DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);		// ���Ŀ� ������ ���� ������
			TextOut(_backBuffer->getMemDC(), 320, 245, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont5);
			DeleteObject(font5);

			// ���� ����
			font5 = CreateFont(40, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

			// �� ���ϸ�
			sprintf_s(str, to_string(_character->getPoketmon(_currentPoke).level).c_str());
			//DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);		// ���Ŀ� ������ ���� ������
			TextOut(_backBuffer->getMemDC(), 545, 247, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont5);
			DeleteObject(font5);
			//IMAGEMANAGER->findImage(index + "");

		}
		if (_appearIndexEnemy < 0)
		{
			// Ʈ���̳ʿ��� ��Ʋ�� ���
			if (!_isWild && _currentEnemyPokemon.currentHP > 0) _enemyPokeImage->frameRender(_backBuffer->getMemDC(), WINSIZEX - 230, 0);

			// ���ʹ� ü�¹�
			_hpBarEnemy->setGauge(_currentEnemyPokemon.currentHP, _currentEnemyPokemon.sumMaxHP, _isBattleStart);
			_hpBarEnemy->render();

			// �̸� ����
			char str[128];

			SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

			HFONT font5 = CreateFont(45, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

			// ��� ���ϸ�
			sprintf_s(str, (_currentEnemyPokemon.name + _currentEnemyPokemon.gender).c_str());
			TextOut(_backBuffer->getMemDC(), 70, 20, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont5);
			DeleteObject(font5);

			// ���� ����
			font5 = CreateFont(40, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

			// ��� ���ϸ�
			sprintf_s(str, to_string(_currentEnemyPokemon.level).c_str());
			TextOut(_backBuffer->getMemDC(), 285, 25, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont5);
			DeleteObject(font5);
		}

		if (_appearIndexPlayer < 0 && _appearIndexEnemy < 0)
		{
			//	Ŀ���� ��ġ
			if (!_isOpenSkill && !_isOpenPokemon && !_isOpenBag && !_isAttack && !_isScript && !_isCatch)
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
					if (_isWild)
					{
						if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
						{
							uiOpen = false;
							_isBattle = false;
							_behaviorCount = 0;
							px = -_playerImage->getWidth();
							ex = WINSIZEX + _enemyPokeImage->getWidth();
							_appearIndexPlayer = 2;
							_appearIndexEnemy = 2;

							_isAttack = false;
							_attackCount = 0;
							_isTurn = false;
							_isNext = false;
							_whoTurn = 0;
							_currentPoke = 0;
							_skillCnt = 0;

							SOUNDMANAGER->stop("battle");
							SOUNDMANAGER->play("town2BGM", 0.01f * UIMANAGER->getVolume());
						}
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
		skillSelect();
	}
	if (_isOpenPokemon)
	{
		pokeShift();
	}
	if (_isAttack)
	{
		attack();
	}

	if (_isCatch)
	{
		usePokeBall();

		IMAGEMANAGER->frameRender("��ȹ", _backBuffer->getMemDC(), 200, 0, _catchIndex, 0);

		static int catchCount = 0;
		catchCount++;
		static float time;

		if (_catchIndex < 30)
		{
			if (catchCount % 4 == 0)
			{
				_catchIndex++;
			}
		}
		else if (_catchIndex == IMAGEMANAGER->findImage("��ȹ")->getMaxFrameX() - 1)
		{
			time = TIMEMANAGER->getWorldTime();
			_catchIndex++;
		}
		else if (_catchIndex == IMAGEMANAGER->findImage("��ȹ")->getMaxFrameX())
		{			
			if (TIMEMANAGER->getWorldTime() >= time + 1)
			{
				_catchIndex++;
			}
		}
		else
		{
			if (catchCount % 20 == 0)
			{
				_catchIndex++;
			}
		}

		if (_catchIndex >= IMAGEMANAGER->findImage("��ȹ")->getMaxFrameX())
		{
			catchCount = 0;
		}
	}

	//char str[128];

	//sprintf_s(str, "%d", _currentEnemyPokemon.level);
	//TextOut(_backBuffer->getMemDC(), 10, 10, str, strlen(str));

	//sprintf_s(str, "currentEnemy : %d", _currentEnemyIndex);
	//TextOut(_backBuffer->getMemDC(), 300, 90, str, strlen(str));

	//sprintf_s(str, "currentEnemyHP : %d", _currentEnemyPokemon.currentHP);
	//TextOut(_backBuffer->getMemDC(), 300, 110, str, strlen(str));

	//sprintf_s(str, "catch(bool) : %d", _isCatch);
	//TextOut(_backBuffer->getMemDC(), 200, 200, str, strlen(str));

	//sprintf_s(str, "catch : %d", _catchIndex);
	//TextOut(_backBuffer->getMemDC(), 200, 220, str, strlen(str));
	////_character->getPoketmon(_currentPoke).totalEXP >= _character->getPoketmon(_currentPoke).maxExp
}

void uiManager::skillSelect()
{
	IMAGEMANAGER->findImage("��ų����")->render(_backBuffer->getMemDC(), 0, 287);

	SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

	HFONT font5 = CreateFont(38, 0, 0, 0, 700, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

	HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

	char skill[128];
	char type[128];
	char pp[128];

	for (int i = 0; i < 4; i++) {
		//string strname = myPokemon[i].name;
		//strcpy_s(poke, strname.c_str());
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[i]);
		sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());

		TextOut(_backBuffer->getMemDC(), 55, 330 + (i * 60), skill, strlen(skill));
	}

	if (_skillCnt > 0)
	{
		if(KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_skillCnt--;
		}
	}
	if (_skillCnt < 3)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_skillCnt++;
		}
	}

	IMAGEMANAGER->findImage("Ŀ��")->render(_backBuffer->getMemDC(), 25, 335 + (_skillCnt * 60));

	switch (_skillCnt)
	{
	case 0:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[0]);
		_currentSkill = 0;
		break;
	case 1:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[1]);
		_currentSkill = 1;
		break;
	case 2:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[2]);
		_currentSkill = 2;
		break;
	case 3:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[3]);
		_currentSkill = 3;
		break;
	}

	switch ((SKILL_TYPE)_poketmonManager->getSkill()->getSkillType())
	{
	case SKILL_TYPE::NOMAL:
		sprintf_s(type, "�븻");
		break;
	case SKILL_TYPE::FIRE:
		sprintf_s(type, "�Ҳ�");
		break;
	case SKILL_TYPE::WATER:
		sprintf_s(type, "��");
		break;
	case SKILL_TYPE::GRASS:
		sprintf_s(type, "Ǯ");
		break;
	case SKILL_TYPE::ELECTR:
		sprintf_s(type, "����");
		break;
	case SKILL_TYPE::ICE:
		sprintf_s(type, "����");
		break;
	case SKILL_TYPE::FIGHT:
		sprintf_s(type, "����");
		break;
	case SKILL_TYPE::POISON:
		sprintf_s(type, "��");
		break;
	case SKILL_TYPE::GROUND:
		sprintf_s(type, "��");
		break;
	case SKILL_TYPE::FLYING:
		sprintf_s(type, "����");
		break;
	case SKILL_TYPE::PSYCHC:
		sprintf_s(type, "������");
		break;
	case SKILL_TYPE::BUG:
		sprintf_s(type, "����");
		break;
	case SKILL_TYPE::ROCK:
		sprintf_s(type, "����");
		break;
	case SKILL_TYPE::GHOST:
		sprintf_s(type, "��Ʈ");
		break;
	case SKILL_TYPE::DRAGON:
		sprintf_s(type, "�巡��");
		break;
	case SKILL_TYPE::DARK:
		sprintf_s(type, "��");
		break;
	case SKILL_TYPE::STEEL:
		sprintf_s(type, "��ö");
		break;
	case SKILL_TYPE::FAIRY:
		sprintf_s(type, "��");
		break;
	default:
		break;
	}
	sprintf_s(pp, "%00d/%00d", _character->getPoketmon(_currentPoke).skillPP[_currentSkill], _poketmonManager->getSkill()->getSkillPP());
	TextOut(_backBuffer->getMemDC(), 445, 425, pp, strlen(pp));
	TextOut(_backBuffer->getMemDC(), 485, 510, type, strlen(type));

	SelectObject(_backBuffer->getMemDC(), oldFont5);
	DeleteObject(font5);

	// �����ϸ� ���� ����
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		//_poketmonManager->getSkill()->setIsSkill(true);
		//skillCnt = 0;
		_power = _poketmonManager->getSkill()->getSkillPower();
		_isAttack = true;
		_isOpenSkill = false;
		_npc = NPC::BATTLE_ATTACK;
	}

	if (KEYMANAGER->isOnceKeyDown('X')) // ��ųâ ����
	{
		//skillCnt = 0;
		_isOpenSkill = false;
	}
}

void uiManager::attack() //����
{
	// ���ϸ� �������°� üũ
	if (_character->getPoketmon(_currentPoke).currentHP <= 0)
	{

	}

	// �ӵ� ��
	// �÷��̾ �� ���� ��
	if (_character->getPoketmon(_currentPoke).speed >= _currentEnemyPokemon.speed)
	{
		// �� ��
		if (_attackCount == 0)
		{
			if (!_isNext && !_isTurn)
			{
				vector<string> _vStr;

				char skill[128];

				_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[_currentSkill]);
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_character->getPoketmon(_currentPoke).name + "��\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/����.txt", _vStr);

				_isScript = true;
				_isCount = true;
			}
			if (_isTurn)
			{
				_whoTurn = 1;
				_poketmonManager->getSkill()->setWhoSkill(false);
				_poketmonManager->getSkill()->setSkillIndex(_character->getPoketmon(_currentPoke).skill[_currentSkill]);
				_poketmonManager->getSkill()->setIsSound(true);
				_poketmonManager->getSkill()->setIsSkill(true);

				_attackCount++;

				// ��뺰�� ������ ����
				switch (_currentEnemy)
				{
				case 0:		// �߻�
					_poketmonManager->setCurrentWildHP(_character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentWildHP(10);

					if (_poketmonManager->getWildPoketmon().currentHP <= 0)
					{
						vector<string> _vStr;

						_vStr.push_back("�߻��� " + _currentEnemyPokemon.name + "��(��) ��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� ȹ���ߴ�!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "�����(��) 500���� ȹ���ߴ�!;" + "aaa;");

						TXTDATA->txtSave("script/�߻���Ʋ�¸�.txt", _vStr);

						_npc = NPC::BATTLE_DOWN;
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				case 1:		// Ʈ���̳�1
					_poketmonManager->setCurrentTrainer1HP(_currentEnemyIndex, _character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentTrainer1HP(_currentEnemyIndex, 10);

					_isTurn = false;
					_isNext = false;

					if (_poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex].currentHP <= 0)
					{
						vector<string> _vStr;

						if (_currentEnemyIndex + 1 >= 2)
						{
							_npc = NPC::TRAINER1;
							_isWin = true;
						}
						else if (_poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex + 1].maxHP != 0)
						{
							_vStr.push_back("���� " + _currentEnemyPokemon.name + "��(��)\n��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� �����!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "�� ���û� �ҷ��(��)\n;" + _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "������ �ϰ��ִ�;" + "�� ���û� �ҷ��(��)\n" + _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "���ʷ� ���´�;" + "aaa;");

							TXTDATA->txtSave("script/Ʈ���̳�1_���ϸ����.txt", _vStr);

							_npc = NPC::TRAINER1_BATTLE_DOWN;
						}
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				case 2:		// Ʈ���̳�2
					_poketmonManager->setCurrentTrainer2HP(_currentEnemyIndex, _character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentTrainer2HP(_currentEnemyIndex, 10);

					_isTurn = false;
					_isNext = false;

					if (_poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex].currentHP <= 0)
					{
						vector<string> _vStr;

						if (_currentEnemyIndex + 1 >= 2)
						{
							_npc = NPC::TRAINER2;
							_isWin = true;
						}
						else if (_poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex + 1].maxHP != 0)
						{
							_vStr.push_back("���� " + _currentEnemyPokemon.name + "��(��)\n��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� �����!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "�� ���û� ������(��)\n;" + _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "������ �ϰ��ִ�;" + "�� ���û� ������(��)\n" + _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "���ʷ� ���´�;" + "aaa;");

							TXTDATA->txtSave("script/Ʈ���̳�2_���ϸ����.txt", _vStr);

							_npc = NPC::TRAINER2_BATTLE_DOWN;
						}
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				case 3:		// ����
					_poketmonManager->setCurrentChampionHP(_currentEnemyIndex, _character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentChampionHP(_currentEnemyIndex, 10);

					if (_poketmonManager->getChampionPoketmon()[_currentEnemyIndex].currentHP <= 0)
					{
						vector<string> _vStr;

						if (_currentEnemyIndex + 1 >= 3)
						{
							_npc = NPC::CHAMPION;
							_isWin = true;
						}
						else if (_poketmonManager->getChampionPoketmon()[_currentEnemyIndex + 1].maxHP != 0)
						{
							_vStr.push_back("���� " + _currentEnemyPokemon.name + "��(��)\n��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� �����!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "ü���� ���� ����(��)\n;" + _poketmonManager->getChampionPoketmon()[_currentEnemyIndex + 1].name + "��(��);" + "������ �ϰ��ִ�;" + "ü���� ���� ����(��)\n" + _poketmonManager->getChampionPoketmon()[_currentEnemyIndex + 1].name + "��(��);" + "���ʷ� ���´�;" + "aaa;");

							TXTDATA->txtSave("script/�������ϸ����.txt", _vStr);

							_npc = NPC::CHAMPION_BATTLE_DOWN;
						}
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				}
				_currentLevel = _character->getPoketmon(_currentPoke).level;


				//if (_currentEnemyPokemon.currentHP <= 0)
				//{
				//
				//	vector<string> _vStr;
				//
				//	_vStr.push_back("�߻��� " + _currentEnemyPokemon.name + "��(��) ��������!;" + _character->getPoketmon(_currentPoke).name + "��(��) 50�� ����ġ�� ȹ���ߴ�!;" + "�����(��) 500���� ȹ���ߴ�!;" + "aaa;");
				//
				//	TXTDATA->txtSave("script/�߻���Ʋ�¸�.txt", _vStr);
				//
				//	_npc = NPC::BATTLE_DOWN;
				//	_isScript = true;
				//	_isCount = true;
				//	_isWin = true;
				//}
			}
		}
		
		// ��� ��
		else if (_attackCount > 0)
		{
			if (_isTurn && _isNext)
			{
				_whoTurn = 2;
				_poketmonManager->getSkill()->setWhoSkill(true);
				_poketmonManager->getSkill()->setSkillIndex(_currentEnemyPokemon.skill[_currentSkillEnemy]);
				_poketmonManager->getSkill()->setIsSound(true);
				_poketmonManager->getSkill()->setIsSkill(true);

				_character->setCurrentHP(_currentPoke, _currentEnemyPokemon.sumAttack * _poketmonManager->getSkill()->getSkillPower() / 100);
				//_character->setCurrentHP(_currentPoke, 10);

				if (_character->getPoketmon(_currentPoke).currentHP <= 0)
				{
					vector<string> _vStr;

					_vStr.push_back(_character->getPoketmon(_currentPoke).name + "��(��) ��������!;" + "aaa;");

					TXTDATA->txtSave("script/�й�.txt", _vStr);

					_npc = NPC::BATTLE_DOWN;
					//_isChange = true;
				}

				_isTurn = false;
				_isNext = false;
			}
			else if (_isNext)
			{
				vector<string> _vStr;

				char skill[128];

				_currentSkillEnemy = RND->getInt(4);
				if (_currentEnemyPokemon.skill[_currentSkillEnemy] == 0)
				{
					while (true)
					{
						if (_currentEnemyPokemon.skill[_currentSkillEnemy] != 0) break;
						_currentSkillEnemy = RND->getInt(4);
					}
				}
				_poketmonManager->getSkill()->skillNumLink(_currentEnemyPokemon.skill[_currentSkillEnemy]);

				//_poketmonManager->getSkill()->skillNumLink(_currentEnemyPokemon.skill[RND->getInt(4)]);
				//if (_poketmonManager->getSkill()->getSkillName() == " -")
				//{
				//	while (true)
				//	{
				//		if (_poketmonManager->getSkill()->getSkillName() != " -") break;
				//		_poketmonManager->getSkill()->skillNumLink(_currentEnemyPokemon.skill[RND->getInt(4)]);
				//	}
				//}
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_currentEnemyPokemon.name + "��\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/����.txt", _vStr);
				//_currentEnemyPokemon;//getSkill()->setIsSkill(true);						// �߻� ���ϸ� ���� �ִϸ��̼� ���
			}

		}
	}

	// ��밡 ���� ��
	else
	{
		// ��� ��
		if (_attackCount == 0)
		{
			if (!_isNext && !_isTurn)
			{
				_isNext = true;

				vector<string> _vStr;

				char skill[128];

				_currentSkillEnemy = RND->getInt(4);
				if (_currentEnemyPokemon.skill[_currentSkillEnemy] == 0)
				{
					while (true)
					{
						if (_currentEnemyPokemon.skill[_currentSkillEnemy] != 0) break;
						_currentSkillEnemy = RND->getInt(4);
					}
				}
				_poketmonManager->getSkill()->skillNumLink(_currentEnemyPokemon.skill[_currentSkillEnemy]);

				//_poketmonManager->getSkill()->skillNumLink(_currentEnemyPokemon.skill[RND->getInt(4)]);
				//if (_poketmonManager->getSkill()->getSkillName() == " -")
				//{
				//	while (true)
				//	{
				//		if (_poketmonManager->getSkill()->getSkillName() != " -") break;
				//		_poketmonManager->getSkill()->skillNumLink(_currentEnemyPokemon.skill[RND->getInt(4)]);
				//	}
				//}
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_currentEnemyPokemon.name + "��\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/����.txt", _vStr);

				_isScript = true;
				_isCount = true;
			}
			if (_isTurn)
			{
				_whoTurn = 2;
				_poketmonManager->getSkill()->setWhoSkill(true);
				_poketmonManager->getSkill()->setSkillIndex(_currentEnemyPokemon.skill[_currentSkillEnemy]);
				_poketmonManager->getSkill()->setIsSound(true);
				_poketmonManager->getSkill()->setIsSkill(true);

				_attackCount++;

				_character->setCurrentHP(_currentPoke, _currentEnemyPokemon.sumAttack * _poketmonManager->getSkill()->getSkillPower() / 100);
				//_character->setCurrentHP(_currentPoke, 10);

				if (_character->getPoketmon(_currentPoke).currentHP <= 0)
				{
					vector<string> _vStr;

					_vStr.push_back(_character->getPoketmon(_currentPoke).name + "��(��) ��������!;" + "aaa;");

					TXTDATA->txtSave("script/�й�.txt", _vStr);

					_npc = NPC::BATTLE_DOWN;
					//_isChange = true;
				}
			}
		}

		// �� ��
		else if (_attackCount > 0)
		{
			if (_isTurn && _isNext)
			{
				_whoTurn = 1;
				_poketmonManager->getSkill()->setWhoSkill(false);
				_poketmonManager->getSkill()->setSkillIndex(_character->getPoketmon(_currentPoke).skill[_currentSkill]);
				_poketmonManager->getSkill()->setIsSound(true);
				_poketmonManager->getSkill()->setIsSkill(true);

				// ��뺰�� ������ ����
				switch (_currentEnemy)
				{
				case 0:		// �߻�
					_poketmonManager->setCurrentWildHP(_character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentWildHP(10);

					_isTurn = false;
					_isNext = false;

					if (_poketmonManager->getWildPoketmon().currentHP <= 0)
					{
						vector<string> _vStr;

						_vStr.push_back("�߻��� " + _currentEnemyPokemon.name + "��(��)��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� ȹ���ߴ�!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "�����(��) 500���� ȹ���ߴ�!;" + "aaa;");

						TXTDATA->txtSave("script/�߻���Ʋ�¸�.txt", _vStr);

						_npc = NPC::BATTLE_DOWN;
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				case 1:		// Ʈ���̳�1
					_poketmonManager->setCurrentTrainer1HP(_currentEnemyIndex, _character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentTrainer1HP(_currentEnemyIndex, 10);

					_isTurn = false;
					_isNext = false;

					if (_poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex].currentHP <= 0)
					{
						vector<string> _vStr;

						if (_currentEnemyIndex + 1 >= 2)
						{
							_npc = NPC::TRAINER1;
							_isWin = true;
						}
						else if (_poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex + 1].maxHP != 0)
						{
							_vStr.push_back("���� " + _currentEnemyPokemon.name + "��(��)\n��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� �����!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "�� ���û� �ҷ��(��)\n;" + _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "������ �ϰ��ִ�;" + "�� ���û� �ҷ��(��)\n" + _poketmonManager->getTrainer1Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "���ʷ� ���´�;" + "aaa;");

							TXTDATA->txtSave("script/Ʈ���̳�1_���ϸ����.txt", _vStr);

							_npc = NPC::TRAINER1_BATTLE_DOWN;
						}
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				case 2:		// Ʈ���̳�2
					_poketmonManager->setCurrentTrainer2HP(_currentEnemyIndex, _character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentTrainer2HP(_currentEnemyIndex, 10);

					_isTurn = false;
					_isNext = false;

					if (_poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex].currentHP <= 0)
					{
						vector<string> _vStr;

						if (_currentEnemyIndex + 1 >= 2)
						{
							_npc = NPC::TRAINER2;
							_isWin = true;
						}
						else if (_poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex + 1].maxHP != 0)
						{
							_vStr.push_back("���� " + _currentEnemyPokemon.name + "��(��)\n��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� �����!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "�� ���û� ������(��)\n;" + _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "������ �ϰ��ִ�;" + "�� ���û� ������(��)\n" + _poketmonManager->getTrainer2Poketmon()[_currentEnemyIndex + 1].name + "��(��);" + "���ʷ� ���´�;" + "aaa;");

							TXTDATA->txtSave("script/Ʈ���̳�2_���ϸ����.txt", _vStr);

							_npc = NPC::TRAINER2_BATTLE_DOWN;
						}
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				case 3:		// ����
					_poketmonManager->setCurrentChampionHP(_currentEnemyIndex, _character->getPoketmon(_currentPoke).sumAttack * _power / 100);
					//_poketmonManager->setCurrentChampionHP(_currentEnemyIndex, 10);

					_isTurn = false;
					_isNext = false;

					if (_poketmonManager->getChampionPoketmon()[_currentEnemyIndex].currentHP <= 0)
					{
						vector<string> _vStr;

						if (_currentEnemyIndex + 1 >= 3)
						{
							_npc = NPC::CHAMPION;
							_isWin = true;
						}
						else if (_poketmonManager->getChampionPoketmon()[_currentEnemyIndex + 1].maxHP != 0)
						{
							_vStr.push_back("���� " + _currentEnemyPokemon.name + "��(��)\n��������!;" + _character->getPoketmon(_currentPoke).name + "��(��)\n50�� ����ġ�� �����!;" + _character->getPoketmon(_currentPoke).name + "�� ������\n" + to_string(_character->getPoketmon(_currentPoke).level + 1) + "�� �ö����ϴ�!;" + "ü���� ���� ����(��)\n;" + _poketmonManager->getChampionPoketmon()[_currentEnemyIndex + 1].name + "��(��);" + "������ �ϰ��ִ�;" + "ü���� ���� ����(��)\n" + _poketmonManager->getChampionPoketmon()[_currentEnemyIndex + 1].name + "��(��);" + "���ʷ� ���´�;" + "aaa;");

							TXTDATA->txtSave("script/�������ϸ����.txt", _vStr);

							_npc = NPC::CHAMPION_BATTLE_DOWN;
						}
						_isScript = true;
						_isCount = true;
						_isWin = true;
						gold += 500;
					}
					break;
				}
				_currentLevel = _character->getPoketmon(_currentPoke).level;


				//_isTurn = false;
				//_isNext = false;

				//if (_currentEnemyPokemon.currentHP <= 0)
				//{
				//
				//	vector<string> _vStr;
				//
				//	_vStr.push_back("�߻��� " + _currentEnemyPokemon.name + "��(��) ��������!;" + _character->getPoketmon(_currentPoke).name + "��(��) 50�� ����ġ�� ȹ���ߴ�!;" + "�����(��) 500���� ȹ���ߴ�!;" + "aaa;");
				//
				//	TXTDATA->txtSave("script/�߻���Ʋ�¸�.txt", _vStr);
				//
				//	_npc = NPC::BATTLE_DOWN;
				//	_isScript = true;
				//	_isCount = true;
				//	_isWin = true;
				//}
			}
			else if (_isNext)
			{
				vector<string> _vStr;

				char skill[128];

				_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[_currentSkill]);
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_character->getPoketmon(_currentPoke).name + "��\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/����.txt", _vStr);
				
				//_currentEnemyPokemon;//getSkill()->setIsSkill(true);						// �߻� ���ϸ� ���� �ִϸ��̼� ���
			}

		}
	}
}

void uiManager::usePokeBall()
{
	//���Ϻ� ���� �� �ʿ��� ���Ϻ� ���ư���
	//���Ϻ��� ��� ���ϸ� ������ ���ϸ� �̹��� ������� ���Ϻ� ���Ÿ��� �̹��� ���
	//Ȯ�������� ��ȹ������ ���� �� ������� ��� - �� ���� ���ϸ� ����ü �������� - ��Ʋ �� - �ΰ��Ӿ�
	//��ȹ ���н� �ٽ� ���ϸ� �̹��� ������ְ� ��Ʋ �簳

	//���Ϻ� ���������� ���ư��� �̹��� ���

	//�¾����� �¿�� ���Ÿ��� �������̹��� ���

	if (_catchIndex > IMAGEMANAGER->findImage("��ȹ")->getMaxFrameX())
	{
		//��Ҵ� - ���� ����ü 3���� ����(����, ����, �������)
		for (int i = 0; i < 6; i++)
		{
			if (_character->getPoketmon(i).maxHP == 0)		// �� �ڸ��� ���
			{
				_character->setPoketmon(_poketmonManager->getWildPoketmon(), i);		// ���� ���ϸ� �߰�

				// �Ѹ��� ������ ����
				break;
			}
		}

		uiOpen = false;
		_isBattle = false;
		_isOpenBag = false;
		bagWindow = false;
		_px = -_playerImage->getWidth();
		_ex = WINSIZEX + _enemyPokeImage->getWidth();
		_behaviorCount = 0;
		_appearIndexPlayer = 2;
		_appearIndexEnemy = 2;
		_isCatch = false;
		_catchIndex = 0;
		_behaviorCount = 0;

		SOUNDMANAGER->stop("battle");
		SOUNDMANAGER->play("town2BGM", 0.01f * UIMANAGER->getVolume());
	}
}

void uiManager::useMedicine()
{
	//��� ����� ü���� 50 ȸ���Ѵ�
	//�Լ��� ���ϰ� ���� ����ȿ� �־ ��������ϴ�.
}

void uiManager::useGoodMedicine()
{
	//��� ����� ü���� 100 ȸ���Ѵ�
	//�Լ��� ���ϰ� ���� ����ȿ� �־ ��������ϴ�.
}

void uiManager::getStartingPokemon()
{
	//// ���ڻ�� ��ȭ �� �� ����� �Ŀ�
	//if (_drCount == 1)
	//{
	//
	//}
	// ���Ϻ��� ���ɸ� ��ũ��Ʈ ���

	// (��/�ƴϿ� ����)
	
	// ���ϸ� ȹ�� (��Ÿ�� ���ϸ� �ʱⰪ ���� �ʿ� - �̸�, ����, ���ݷ� ���)
	switch (_npc)
	{
	case NPC::CYNDAQUIL:
		_character->setPoketmon(_poketmonManager->getStartPoketmon()[0], 0);		// 0�� ���Կ� ���ϸ� �߰�
		_isGetCyndaquil = true;
		break;
	case NPC::TOTODILE:
		_character->setPoketmon(_poketmonManager->getStartPoketmon()[1], 0);		// 0�� ���Կ� ���ϸ� �߰�
		_isGetTotodile = true;
		break;
	case NPC::CHIKORITA:
		_character->setPoketmon(_poketmonManager->getStartPoketmon()[2], 0);		// 0�� ���Կ� ���ϸ� �߰�
		_isGetChikorita = true;
		break;
	}
	_drCount++;
	//_isStarting = true;
}

void uiManager::confirm()
{
	uiOpen = true;
	_isAccept = false;

	if (_acceptCount == 0)
	{
		// �� ���� �̹���
		IMAGEMANAGER->findImage("��")->render(_backBuffer->getMemDC(), WINSIZEX - 192, 210);			// y���� 212������ �� �����Ű���
		
		// ����Ű�� �Ʒ� �̵�
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_acceptCount++;
		}
		// �����̽��ٷ� ����
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			// ���� ��Ÿ�� ���ϸ��� ���� ���̶��
			if (_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA)
			{
				// �����ϴ� ���� ���� ��ũ��Ʈ ����
				_txtIndex = 0;
				_scriptIndex++;
			}
			
			_isAccept = true;		// �� ����
			_isConfirm = false;		// Ȯ��â ����
			uiOpen = false;			// UI����
			_acceptCount = 0;		// �������� �ٽ� ���� Ŀ���� �� �ְԲ� �ʱ�ȭ
		}
	}
	else if (_acceptCount == 1)
	{
		// �ƴϿ� ���� �̹���
		IMAGEMANAGER->findImage("�ƴϿ�")->render(_backBuffer->getMemDC(), WINSIZEX - 192, 210);
		
		// ����Ű�� �� �̵�
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_acceptCount--;
		}
		// �����̽��ٷ� ����
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
 			if (_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA)
			{
				_npc = NPC::SELECTCANCEL;	// ������ҷ� ��ũ��Ʈ �� ����
				_isCount = true;			// ��ũ��Ʈ ������ �� �ְԲ� ����

				// �ؽ�Ʈ �ʱ�ȭ
				_txtIndex = 0;
				_scriptIndex = 0;
			}
			_isAccept = false;		// �ƴϿ� ����
			_isConfirm = false;		// Ȯ��â ����
			uiOpen = false;			// UI����
			_acceptCount = 0;		// �������� �ٽ� ���� Ŀ���� �� �ְԲ� �ʱ�ȭ
		}
	}
}

bool uiManager::isUiOpen()
{
	return uiOpen;
}
