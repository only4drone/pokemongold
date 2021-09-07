#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"
#include "character.h"

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

	IMAGEMANAGER->addImage("pokeShift0", "image/menuUI/pokeShift_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift1", "image/menuUI/pokeShift_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift2", "image/menuUI/pokeShift_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift3", "image/menuUI/pokeShift_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift4", "image/menuUI/pokeShift_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift5", "image/menuUI/pokeShift_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift6", "image/menuUI/pokeShift_6.bmp", 640, 576, true, RGB(255, 0, 255));

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
		uiOpen = false;
	}
}

void uiManager::menu()
{
	uiOpen = true;

	if (!bagWindow) {
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && menuCnt < 6) {
			menuCnt += 1;
			//�޴� ȭ��ǥ ���Ʒ� �����̴�
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && menuCnt > 0) {
			menuCnt -= 1;
		}
	}


	switch (menuCnt)
	{
	case 0: //����
		IMAGEMANAGER->findImage("menu0")->render(_backBuffer->getMemDC());
		break;
	case 1: //���ϸ�
		IMAGEMANAGER->findImage("menu1")->render(_backBuffer->getMemDC());
		break;
	case 2://����
		IMAGEMANAGER->findImage("menu2")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenBag = true;
			//bag();
		};
		break;
	case 3://���ϱ��
		IMAGEMANAGER->findImage("menu3")->render(_backBuffer->getMemDC());
		break;
	case 4://�̸�
		IMAGEMANAGER->findImage("menu4")->render(_backBuffer->getMemDC());
		break;
	case 5://����
		IMAGEMANAGER->findImage("menu5")->render(_backBuffer->getMemDC());
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
			break;
		}

		
		//�Ʒ��� ���������� �ʿ��Ҷ� ���ϸ� ������ �޾ƿ´� <- ���߿� �ڵ� ���� ��ġ�� ���������� �ٲ����
		for (int i = 0; i < myPokemon.size(); i++) {
			myPokemon[i].name = _character->getPoketmon(i).name;
			myPokemon[i].maxHP = _character->getPoketmon(i).maxHP;
			myPokemon[i].currentHP = _character->getPoketmon(i).currentHP;
			myPokemon[i].level = _character->getPoketmon(i).level;
		}

		char str[128];
		
		

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(38, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);


		char poke[128];


		for (int i = 0; i < myPokemon.size(); i++) {
			string strname = myPokemon[i].name;
			strcpy_s(poke, strname.c_str());

			sprintf_s(str, "%s", poke);
			TextOut(_backBuffer->getMemDC(), 100, 15+ (i * 65), str, strlen(str));

			sprintf_s(str, "%d", myPokemon[i].maxHP);
			TextOut(_backBuffer->getMemDC(), 530, 3 + (i * 65), str, strlen(str));

			sprintf_s(str, "%d", myPokemon[i].currentHP);
			TextOut(_backBuffer->getMemDC(), 440, 3 + (i * 65), str, strlen(str));

			sprintf_s(str, "%d", myPokemon[i].level);
			TextOut(_backBuffer->getMemDC(), 320, 25 + (i * 65), str, strlen(str));

		}
		
		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);


	
	}
	

}


void uiManager::bag()
{
	bagWindow = true;

	if (bagWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && bagCnt < 3) {
			bagCnt ++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && bagCnt > 0) {
			bagCnt --;
		}


		switch (bagCnt) {

		case 0: // ���濡�� ���ͺ��� Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag0")->render(_backBuffer->getMemDC());
			//Ŭ�������� ������ 1�� �̻��̸� ���� �ƴϸ� �� ����
			if (pokeballQ > 0) {
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					pokeballQ++;
				};
			}
			break;
		case 1:// ���濡�� ��ó�࿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag1")->render(_backBuffer->getMemDC());
			if (medicineQ > 0) {
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					medicineQ++;
				};
			}
			break;
		case 2:// ���濡�� ��޻�ó�࿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag2")->render(_backBuffer->getMemDC());
			if (goodMedicineQ > 0) {
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					goodMedicineQ++;
				};
			}
			break;
		case 3:// ���濡�� �����⿡ Ŀ���� �ִ�
			IMAGEMANAGER->findImage("bag3")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {

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



void uiManager::script()
{
	uiOpen = true;

	switch (_npc)
	{
	case NPC::TITLE:
		_vScript = TXTDATA->txtLoad("script/Ÿ��Ʋ.txt");
		break;
	case NPC::MOM_FIRST:
		_vScript = TXTDATA->txtLoad("script/����1.txt");
		break;
	case NPC::MOM_NORMAL:
		_vScript = TXTDATA->txtLoad("script/����2.txt");
		break;
	case NPC::DR_FIRST:
		_vScript = TXTDATA->txtLoad("script/���ڻ�_ó��.txt");
		break;
	case NPC::DR_BEFORE_POKEMON:
		_vScript = TXTDATA->txtLoad("script/���ڻ�_���ϸ���.txt");
		break;
	case NPC::DR_AFTER_POKEMON:
		_vScript = TXTDATA->txtLoad("script/���ڻ�_���ϸ���.txt");
		break;
	case NPC::DR_NORMAL:
		_vScript = TXTDATA->txtLoad("script/���ڻ�_�ϻ�.txt");
		break;
	case NPC::SUPPORTER:
		_vScript = TXTDATA->txtLoad("script/����.txt");
		break;
	case NPC::CHAMPION_BATTLE_START:
		_vScript = TXTDATA->txtLoad("script/�����Ʋ����.txt");
		break;
	case NPC::CHAMPION_BATTLE_AFTER:
		_vScript = TXTDATA->txtLoad("script/�����Ʋ��.txt");
		break;
	case NPC::CHAMPION_BATTLE_END:
		_vScript = TXTDATA->txtLoad("script/�����Ʋ��.txt");
		break;
	case NPC::TRAINER1_BATTLE_BEFORE:
		_vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ��.txt");
		break;
	case NPC::TRAINER1_BATTLE_START:
		_vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ����.txt");
		break;
	case NPC::TRAINER1_BATTLE_END:
		_vScript = TXTDATA->txtLoad("script/�̵���1_��Ʋ��.txt");
		break;
	case NPC::TRAINER1_BATTLE_WIN:
		_vScript = TXTDATA->txtLoad("script/�̵���1_�¸�����.txt");
		break;
	case NPC::TRAINER2_BATTLE_BEFORE:
		_vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ��.txt");
		break;
	case NPC::TRAINER2_BATTLE_START:
		_vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ����.txt");
		break;
	case NPC::TRAINER2_BATTLE_END:
		_vScript = TXTDATA->txtLoad("script/�̵���2_��Ʋ��.txt");
		break;
	case NPC::TRAINER2_BATTLE_WIN:
		_vScript = TXTDATA->txtLoad("script/�̵���2_�¸�����.txt");
		break;
	case NPC::POKECENTER:
		_vScript = TXTDATA->txtLoad("script/��ȣ��.txt");
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
		_vScript = TXTDATA->txtLoad("script/��Ʋ(�ӽ�).txt");
		break;
	default:
		break;
	}
	

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
			uiOpen = false;
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

bool uiManager::isUiOpen()
{
	return uiOpen;
}
