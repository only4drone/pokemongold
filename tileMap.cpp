#include "pch.h"
#include "tileMap.h"
#include "character.h"

tileMap::tileMap()
{
}

tileMap::~tileMap()
{
}

HRESULT tileMap::init()
{
	//�� �̹���
	_map = IMAGEMANAGER->addImage("map", "image/pokemon_Map.bmp", 7936, 2304, true, RGB(255, 0, 255));
	_startHome1 = IMAGEMANAGER->addImage("��1��", "image/pokemon_start_home1.bmp", 640, 512, true, RGB(255, 0, 255));
	_startHome2 = IMAGEMANAGER->addImage("��2��", "image/pokemon_start_home2.bmp", 512, 384, true, RGB(255, 0, 255));
	_startCenter = IMAGEMANAGER->addImage("���۸ʼ���", "image/pokemon_start_center.bmp", 640, 768, true, RGB(255, 0, 255));
	_gymCenter = IMAGEMANAGER->addImage("ü�����ʼ���", "image/pokemon_gym_center.bmp", 640, 512, true, RGB(255, 0, 255));
	_gymGym = IMAGEMANAGER->addImage("ü������ü����", "image/pokemon_gym_gym.bmp", 640, 1024, true, RGB(255, 0, 255));
	_gymMart = IMAGEMANAGER->addImage("ü�����ʸ�Ʈ", "image/pokemon_gym_mart.bmp", 768, 512, true, RGB(255, 0, 255));

	//�� ī�޶� �ʱ�ȭ
	_cameraX = 0;
	_cameraY = 0;

	//Ÿ�� �Ӽ� �ʱ�ȭ (��������)
	for (int i = 0; i < TILE; i++)
	{
			_tile[i].type = TILETYPE_CLOSE;
	}

	load();

	return S_OK;
}

void tileMap::release()
{
}

void tileMap::update()
{
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) // ������ �̵�
	//{
	//	_cameraX += 64;
	//}
	//
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT)) // ���� �̵�
	//{
	//	_cameraX -= 64;
	//}
	//
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN)) // �Ʒ� �̵�
	//{
	//	_cameraY += 64;
	//}
	//
	//if (KEYMANAGER->isStayKeyDown(VK_UP)) // �� �̵�
	//{
	//	_cameraY -= 64;
	//}
	//����� �ҷ�����
	//if (KEYMANAGER->isOnceKeyDown('R'))
	//{
	//	save();
	//}
	//if (KEYMANAGER->isOnceKeyDown('Y'))
	//{
	//	load();
	//}
	
	setTile();
}

void tileMap::render()
{
	//���̹���
	_map->render(getMemDC(), -6400 -_cameraX, -1152 - _cameraY);
	_startHome1->render(getMemDC(), 1536 + TILESIZE * 5 - _cameraX, -_cameraY);
	_startHome2->render(getMemDC(), 640 + 1536 + TILESIZE * 10 - _cameraX, -_cameraY);
	_startCenter->render(getMemDC(), 512 + 640 + 1536 + TILESIZE * 15 - _cameraX, -_cameraY);
	_gymCenter->render(getMemDC(),  640 + 512 + 640 + 1536 + TILESIZE * 20 - _cameraX, -_cameraY);
	_gymGym->render(getMemDC(), 640 + 640 + 512 + 640 + 1536 + TILESIZE * 25 - _cameraX, -_cameraY);
	_gymMart->render(getMemDC(), 640 + 640 + 640 + 512 + 640 + 1536 + TILESIZE * 30 - _cameraX, -_cameraY);

	//Ÿ�� �Ӽ����� ���� �ٸ�(��������)
	for (int i = 0; i < TILE; i++)
	{
			if (_tile[i].type == TILETYPE_CLOSE) continue;	//���������� ���� render����
			if (_tile[i].rc.left > WINSIZEX || _tile[i].rc.right < 0 || _tile[i].rc.top > WINSIZEY || _tile[i].rc.bottom < 0) continue;	//â �ۿ� Ÿ���� render����
			
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				if (_tile[i].type == TILETYPE_OPEN)
				{
					HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
					HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
					Rectangle(getMemDC(), _tile[i].rc);
					SelectObject(getMemDC(), oldBrush);
					DeleteObject(brush);
				}

				if (_tile[i].type == TILETYPE_GRASS)
				{
					HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
					HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
					Rectangle(getMemDC(), _tile[i].rc);
					SelectObject(getMemDC(), oldBrush);
					DeleteObject(brush);
				}

				if (_tile[i].type == TILETYPE_DOOR)
				{
					HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
					HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
					Rectangle(getMemDC(), _tile[i].rc);
					SelectObject(getMemDC(), oldBrush);
					DeleteObject(brush);
				}

				if (_tile[i].type == TILETYPE_LEFTSLOPE)
				{
					HBRUSH brush = CreateSolidBrush(RGB(125, 0, 0));
					HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
					Rectangle(getMemDC(), _tile[i].rc);
					SelectObject(getMemDC(), oldBrush);
					DeleteObject(brush);
				}

				if (_tile[i].type == TILETYPE_RIGHTSLOPE)
				{
					HBRUSH brush = CreateSolidBrush(RGB(0, 125, 0));
					HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
					Rectangle(getMemDC(), _tile[i].rc);
					SelectObject(getMemDC(), oldBrush);
					DeleteObject(brush);
				}

				if (_tile[i].type == TILETYPE_BOTTOMSLOPE)
				{
					HBRUSH brush = CreateSolidBrush(RGB(0, 0, 125));
					HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
					Rectangle(getMemDC(), _tile[i].rc);
					SelectObject(getMemDC(), oldBrush);
					DeleteObject(brush);
				}
			}
	}

	char str[128];
	sprintf_s(str, "cameraX : %d", _cameraX);
	TextOut(getMemDC(), 100, 100, str, strlen(str));

	sprintf_s(str, "cameraY : %d", _cameraY);
	TextOut(getMemDC(), 100, 130, str, strlen(str));
}

void tileMap::setTile()
{
	//��ü�� Ÿ�� ��Ʈ ����
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 214; j++)
		{
			_tile[i * 214 + j].rc = RectMake(-6400 + j * TILESIZE - _cameraX, -1152 +  i * TILESIZE - _cameraY, TILESIZE, TILESIZE);
		}
	}

	//�Ӽ� �ο�(���� ����)
	for (int i = 0; i < TILE; i++)
	{
		if (PtInRect(&_tile[i].rc, _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown('C'))
				_tile[i].type = TILETYPE_CLOSE;
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
				_tile[i].type = TILETYPE_OPEN;
			if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
				_tile[i].type = TILETYPE_GRASS;
			if (KEYMANAGER->isStayKeyDown('W'))
				_tile[i].type = TILETYPE_DOOR;
			if (KEYMANAGER->isStayKeyDown('A'))
				_tile[i].type = TILETYPE_LEFTSLOPE;
			if (KEYMANAGER->isStayKeyDown('D'))
				_tile[i].type = TILETYPE_RIGHTSLOPE;
			if (KEYMANAGER->isStayKeyDown('S'))
				_tile[i].type = TILETYPE_BOTTOMSLOPE;

		}
	}
}

void tileMap::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("tileSave.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tile, sizeof(tagTile) * (TILE) , &write, NULL);

	CloseHandle(file);
}

void tileMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tile, sizeof(tagTile) * (TILE) , &read, NULL);

	CloseHandle(file);
}