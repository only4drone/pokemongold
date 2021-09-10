#include "pch.h"
#include "tileMap.h"
#include "character.h"
#include "npc.h"

tileMap::tileMap()
{
}

tileMap::~tileMap()
{
}

HRESULT tileMap::init()
{
	//Ÿ�Ͽ� ����ִ� �̹���
	IMAGEMANAGER->addFrameImage("Ÿ��", "image/pokemon_tile.bmp", 960, 960, 15, 15, true, RGB(255, 0, 255));
	//���� �̹���
	IMAGEMANAGER->addImage("����", "image/pokemon_tree.bmp", 8256, 2560, true, RGB(255, 0, 255));

	//�� ī�޶� �ʱ�ȭ
	_cameraX = 2560;
	_cameraY = 0;
	
	load();

	return S_OK;
}

void tileMap::release()
{
}

void tileMap::update()
{
	//npc ��Ʈ�� ���� Ÿ���� �Ӽ��� ��������
	for (int i = 0; i < TILE; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_tile[i].rc, &_npc->getnpcRC()[j].rc))
			{
				if (_npc->getIsMove() == true) break;			//npc�� ������ ���� �Ӽ���ȭ ����
				_tile[i].type = TILETYPE_CLOSE;
			}
		}
	}

	setTile();
}

void tileMap::render()
{
	//���� �̹���
	IMAGEMANAGER->render("����", getMemDC(), -TILESIZE * 5 - 6400 - _cameraX, -1152 - _cameraY);
	
	//Ÿ�� �̹���
	for (int i = 0; i < TILE; i++)
	{
		if (_tile[i].rc.left > WINSIZEX || _tile[i].rc.right < 0 || _tile[i].rc.top > WINSIZEY || _tile[i].rc.bottom < 0) continue;

		IMAGEMANAGER->frameRender("Ÿ��", getMemDC(),
			_tile[i].rc.left, _tile[i].rc.top,
			_tile[i].x, _tile[i].y);
	}

	//Ÿ�� �Ӽ����� ���� �ٸ�(��������)
	for (int i = 0; i < TILE; i++)
	{
			if (_tile[i].type == TILETYPE_CLOSE) continue;
			if (_tile[i].rc.left > WINSIZEX || _tile[i].rc.right < 0 || _tile[i].rc.top > WINSIZEY || _tile[i].rc.bottom < 0) continue;
	
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

	file = CreateFile("tileSave1.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tile, sizeof(tagTile) * (TILE) , &read, NULL);

	CloseHandle(file);
}

TILETYPE tileMap::setTiletype(int frameX, int frameY)
{
	if (frameX <= 7 && frameY == 0) return TILETYPE_OPEN;
	if (frameX == 13 && frameY == 3) return TILETYPE_OPEN;
	else if (frameX == 8 && frameY == 0) return TILETYPE_GRASS;
	else if (frameX == 9 && frameY == 0) return TILETYPE_DOOR;
	else if (frameX >= 6 && frameX <= 10 && frameY == 1) return TILETYPE_DOOR;
	else if (frameX == 7 && frameY == 7) return TILETYPE_DOOR;
	else if (frameX == 0 && frameY == 1) return TILETYPE_LEFTSLOPE;
	else if (frameX == 3 && frameY == 1) return TILETYPE_RIGHTSLOPE;
	else if ((frameX == 1 || frameX == 2) && frameY == 1) return TILETYPE_BOTTOMSLOPE;
	return TILETYPE_CLOSE;
}
