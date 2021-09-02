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

	_tileMap->setCharacterMemoryAddressLink(_character);
	_character->setPoketmonManagerMemoryAddressLink(_pM);
	_character->setTileMapMemoryAddressLink(_tileMap);
	_pM->setCharacterMemoryAddressLink(_character);

	_tileMap->init();
	_character->init();
	_pM->init();



	

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

	_tileMap->update();
	_character->update();
	_pM->update();

	
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//==============������ ���� �ǵ帮�� ���� ============

	_tileMap->render();
	_character->render();
	_pM->render();


	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

