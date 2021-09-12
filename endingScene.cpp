#include "pch.h"
#include "endingScene.h"

endingScene::endingScene()
{
}

endingScene::~endingScene()
{
}

HRESULT endingScene::init()
{
	SOUNDMANAGER->play("ending", 0.01f * UIMANAGER->soundVolume);
	_endingBackground[0] = IMAGEMANAGER->addImage("�������1", "image/end_image/endingBackground1.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1
	_endingBackground[1] = IMAGEMANAGER->addImage("�������2", "image/end_image/endingBackground2.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1
	_endingBackground[2] = IMAGEMANAGER->addImage("�������3", "image/end_image/endingBackground3.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1
	_endingBackground[3] = IMAGEMANAGER->addImage("�������4", "image/end_image/endingBackground4.bmp", 640, 576, true, RGB(255, 0, 255));				// ���� ��� 1

	_endingPokemon[0] = IMAGEMANAGER->addFrameImage("�������ϸ�1", "image/end_image/endingPokemon1.bmp", 192, 68, 3, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(������?)
	_endingPokemon[1] = IMAGEMANAGER->addFrameImage("�������ϸ�2", "image/end_image/endingPokemon2.bmp", 162, 56, 3, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(�����)
	_endingPokemon[2] = IMAGEMANAGER->addFrameImage("�������ϸ�3", "image/end_image/endingPokemon3.bmp", 216, 68, 3, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(����Ű��)
	_endingPokemon[3] = IMAGEMANAGER->addFrameImage("�������ϸ�4", "image/end_image/endingPokemon4.bmp", 208, 72, 4, 1, true, RGB(255, 0, 255));		// ���� ���ϸ� 1(������)

	_time = TIMEMANAGER->getWorldTime();		// ���� �ð����� ����

	return S_OK;
}

void endingScene::release()
{
}

void endingScene::update()
{
	static int count = 0;

	if (count % 7 == 0)
	{
		if (_index < 2 && _endCount != 3) _index++;				// ���� ���ϸ� ������ ������ ����
		else if (_index < 3 && _endCount == 3) _index++;		// �������� �������� 4���̶� �������ϋ��� ���� �� �ٸ��� ����
		else _index = 0;
	}

	count++;

	// �� ȭ���� 2�ʰ� ������ ���� ȭ������ �Ѿ���� ����
	if (TIMEMANAGER->getWorldTime() >= _time + 2 && _endCount < 3)
	{
		_endCount++;		// �迭��ȣ + 1
		_time = TIMEMANAGER->getWorldTime();		// �ð� �� �ٽ� �޾ƿ�
		_index = 0;			// ������ ��ȣ �ʱ�ȭ
	}
}

void endingScene::render()
{
	_endingBackground[_endCount]->render(getMemDC());		// n���� ��� ����
	for (int i = 0; i < 5; i++)
	{
		// n��° ���ϸ� ������ ����
		_endingPokemon[_endCount]->frameRender(getMemDC(), 50 + i * 120, 20, _index, 0);
		_endingPokemon[_endCount]->frameRender(getMemDC(), 50 + i * 120, WINSIZEY - 30 - 50, _index, 0);
	}

	//����
	////////////////////////////////////////////////////////////////////////////  			
	_scrCnt++;

	if (_scrCnt <= 200) {
	
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);
		const char* s1 = "���ϸ��� ������ ���� �� ������Ʈ";


		sprintf_s(str, s1);
		TextOut(_backBuffer->getMemDC(), 110, 250, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	}
	else if (_scrCnt > 200 && _scrCnt < 400) {
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		const char* s1_1 = "���� : ���� 29�� �� ���繫��";

		sprintf_s(str, s1_1);
		TextOut(_backBuffer->getMemDC(), 130, 250, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	
	
	}
	else if (_scrCnt > 400 && _scrCnt < 600) {
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);
		const char* s1 = "�÷��� ���ּż� �����մϴ�.";
		const char* s1_1 = "Thanks for Playing this Game";

		sprintf_s(str, s1);
		TextOut(_backBuffer->getMemDC(), 160, 250, str, strlen(str));
		sprintf_s(str, s1_1);
		TextOut(_backBuffer->getMemDC(), 20, 290, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	
	}
	else if (_scrCnt > 600) {
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(50, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);
		const char* s1 = "TO BE COUNTINUE";


		sprintf_s(str, s1);
		TextOut(_backBuffer->getMemDC(), 60, 250, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	
	}

	//////////////////////////////////////////////////////////////////////////
	//


}
