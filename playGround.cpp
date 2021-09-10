#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	_tileMap = new tileMap;
	_character = new character;
	_pM = new poketmonManager;
	_npc = new npc;
	
	_tileMap->setCharacterMemoryAddressLink(_character);
	_tileMap->setNPCMemoryAddressLink(_npc);
	_character->setPoketmonManagerMemoryAddressLink(_pM);
	_character->setTileMapMemoryAddressLink(_tileMap);
	_character->setNPCMemoryAddressLink(_npc);
	_pM->setCharacterMemoryAddressLink(_character);
	UIMANAGER->setCharacterMemoryAddressLink(_character);
	UIMANAGER->setSkillMemoryAddressLink(_pM);
	_npc->setTileMapMemoryAddressLink(_tileMap);
	_npc->setCharacterMemoryAddressLink(_character);

	_tileMap->init();
	_npc->init();
	_character->init();
	_pM->init();

	UIMANAGER->init();

	//SCENEMANAGER->addScene("����", new endingScene);
	//SCENEMANAGER->changeScene("����");
	
	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	_character->update();
	_pM->update();
	_tileMap->update();
	_npc->update();
	
	//if (KEYMANAGER->isOnceKeyDown('P'))
	//{
	//	UIMANAGER->setVScript(TXTDATA->txtLoad("script/�̵���2_�¸�����.txt"));
	//	UIMANAGER->setIsScript(true);
	//}

	//SCENEMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//==============������ ���� �ǵ帮�� ���� ============

	_tileMap->render();
	_npc->render();
	_character->render();
	_pM->render();

	//UIMANAGER->pokeShift();
	//UIMANAGER->script();
	//SCENEMANAGER->render();
	//UIMANAGER->battle();

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

