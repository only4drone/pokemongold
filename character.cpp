#include "pch.h"
#include "character.h"
#include "poketmonManager.h"
#include "tileMap.h"

character::character()
{
}

character::~character()
{
}

HRESULT character::init() // ����
{
    imageInit();

    _image = IMAGEMANAGER->findImage("���̵�_�¿�");

    _direction = _isMoving = _frontTileType = 0;
    _frameCount = _currentFrame = 0;
    _x = WINSIZEX / 2 + TILESIZE / 2;
    _y = WINSIZEY / 2;
    _currentTile = 4813;

    _rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());


    return S_OK;
}

void character::release()
{
}

void character::update() // ������Ʈ
{
    controll();
    imageFrame();

    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) tileAction();

}

void character::controll() // ĳ���� ��Ʈ�� ó��
{
    if (!_isMoving)
    {
        // ���̵�
        if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) idle(0);
        if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) idle(1);
        if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) idle(2);
        if (KEYMANAGER->isOnceKeyUp(VK_UP)) idle(3);

        // �ȱ�
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) // ������ �̵�
        {
            run(0); 
            if (!_isMoving) tileCheck(0);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)) // ���� �̵�
        {
            run(1);
            if (!_isMoving) tileCheck(1);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_DOWN)) // �Ʒ� �̵�
        {
            run(2);
            if (!_isMoving) tileCheck(2);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_UP)) // �� �̵�
        {
            run(3);
            if (!_isMoving) tileCheck(3);
            tileAction();
        }
    }

    // enter Key
    if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
    {

    }

    // Z Key
    if (KEYMANAGER->isOnceKeyDown('Z'))
    {

    }

    // X Key
    if (KEYMANAGER->isOnceKeyDown('X'))
    {

    }
}

void character::imageSetting() // ���¿� ���� ���� �̹��� ����
{
    switch (_state)
    {
        case static_cast<int>(STATE::IDLE_RL) :
            _image = IMAGEMANAGER->findImage("���̵�_�¿�");
            break;
        case static_cast<int>(STATE::IDLE_UD) :
            _image = IMAGEMANAGER->findImage("���̵�_����");
            break;
        case static_cast<int>(STATE::RUN_RL) :
            _image = IMAGEMANAGER->findImage("�ȱ�_�¿�");
            break;
        case static_cast<int>(STATE::RUN_UD) :
            _image = IMAGEMANAGER->findImage("�ȱ�_����");
            break;
    }
}

void character::imageFrame() // �̹��� ������ ó��
{
    // ������Y �̹��� ����
    if (_direction == 0 || _direction == 2) _image->setFrameY(0);
    else _image->setFrameY(1);

    // ī��Ʈ�� ���� ��ġ���� ������X ����
    _frameCount++;
    if (_frameCount % 5 == 0)
    {
        // ������ �ʱ�ȭ
        if (_direction == 0 || _direction == 2)
        {
            _currentFrame++;
            if (_currentFrame > _image->getMaxFrameX()) _currentFrame = 0;
        }
        else
        {
            _currentFrame--;
            if (_currentFrame < 0) _currentFrame = _image->getMaxFrameX();
        }

        // X������ �̹��� ����
        _image->setFrameX(_currentFrame);
    }

    // ��Ʈ ����
    _rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

void character::idle(int direction) // ���̵� ó��
{
    // ���� ���� ó��
    if (direction == 0 || direction == 1) _state = static_cast<int>(STATE::IDLE_RL);
    else if (direction == 2 || direction == 3) _state = static_cast<int>(STATE::IDLE_UD);

    imageSetting();
}

void character::run(int direction) // �ȱ� ó��
{
    // ���� ���� ó��
    if (_tileMap->getCameraX() % TILESIZE == 0 && _tileMap->getCameraY() % TILESIZE == 0) _direction = direction;

    // ���� ���� ó��
    if (_direction == 0 || _direction == 1) _state = static_cast<int>(STATE::RUN_RL);
    else if (_direction == 2 || _direction == 3) _state = static_cast<int>(STATE::RUN_UD);

    // �̵� ������ ó��
    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) _isMoving = 1;

    imageSetting();
}

void character::tileCheck(int direction) // Ÿ�� üũ ó��
{
    //    TILETYPE_OPEN,				//������ �� �ִ� Ÿ��
    //    TILETYPE_GRASS,				//Ǯ(���ϸ� �Ѹ� �� �ְ�)
    //    TILETYPE_CLOSE,				//������ �� ���� Ÿ��
    //    TILETYPE_DOOR,				//�̵��� �� �ִ� ��
    //    TILETYPE_LEFTSLOPE,			//���� ��Ż��
    //    TILETYPE_RIGHTSLOPE,		//������ ��Ż��
    //    TILETYPE_BOTTOMSLOPE		//�Ʒ��� ��Ż��
    
    // �ٶ� ������ Ÿ���� �� �� �ִ� Ÿ������ üũ
    switch (direction)
    {
    case 0:
        if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_DOOR) _frontTileType = 3;
        else _frontTileType = 0;

        break;
    case 1:
        if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_DOOR) _frontTileType = 3;
        else _frontTileType = 0;

        break;
    case 2:
        if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_DOOR) _frontTileType = 3;
        else _frontTileType = 0;

        break;
    case 3:
        if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_DOOR) _frontTileType = 3;
        else _frontTileType = 0;

        break;
    }
}

void character::tileAction() // ��ǥ �̵� ó��
{
    // ���⿡ ���� ��ǥ�̵�
    if (_frontTileType == 1 || _frontTileType == 2 || _frontTileType == 3)
    {
        switch (_direction)
        {
        case 0:
            _tileMap->setCameraX(_tileMap->getCameraX() + 8);
            break;
        case 1:
            _tileMap->setCameraX(_tileMap->getCameraX() - 8);
            break;
        case 2:
            _tileMap->setCameraY(_tileMap->getCameraY() + 8);
            break;
        case 3:
            _tileMap->setCameraY(_tileMap->getCameraY() - 8);
            break;
        }

        // Ÿ�� ���߾ӿ� ���� Ÿ�� �ε��� ����, ��, Ǯ Ÿ�� ó��
        if (_tileMap->getCameraX() % TILESIZE == 0 && _tileMap->getCameraY() % TILESIZE == 0)
        {
            _isMoving = 0;

            switch (_direction)                            // ���� Ÿ�� �ε��� ����
            {
            case 0:
                _currentTile += 1;
                break;
            case 1:
                _currentTile -= 1;
                break;
            case 2:
                _currentTile += 214;
                break;
            case 3:
                _currentTile -= 214;
                break;
            }

            if (_frontTileType == 2) grass();               // Ǯ Ÿ���� �� ó��
            if (_frontTileType == 3) door(_currentTile);    // �� Ÿ���� �� ó��
        }
    }
}

void character::grass() // Ǯ Ÿ�� ó��
{
    int rndPoketmonMeet = RND->getFromIntTo(1, 100);

    if (rndPoketmonMeet <= POKETMONMEET)
    {
        _grassTest = 1;
    }
    else _grassTest = 0;
}

void character::door(int doorIndex) // �� Ÿ�� ó��
{
    switch (doorIndex)
    {
    case 5037:  // �ʵ忡�� �÷��̾� �� 1�� �̵�
        _currentTile = 5485;
        _tileMap->setCameraX(1920);
        _tileMap->setCameraY(192);
        break;
    case 3990:  // �÷��̾� �� 1������ 2�� �̵�
        _currentTile = 4003;
        _tileMap->setCameraX(2944);
        _tileMap->setCameraY(-256);
        break;
    case 4003:  // �÷��̾� �� 2������ 1�� �̵�
        _currentTile = 3990;
        _tileMap->setCameraX(2112);
        _tileMap->setCameraY(-256);
        break;
    case 5485:  // �÷��̾� �� 1������ �ʵ� �̵�
        _currentTile = 5037;
        _tileMap->setCameraX(640);
        _tileMap->setCameraY(64);
        break;
    case 5486:  // �÷��̾� �� 1������ �ʵ� �̵�
        _currentTile = 5037;
        _tileMap->setCameraX(640);
        _tileMap->setCameraY(64);
        break;
    case 4602:  // �ʵ忡�� ���ڻ� �� �̵�
        _currentTile = 6367;
        _tileMap->setCameraX(3584);
        _tileMap->setCameraY(448);
        break;
    case 6367:  // ���ڻ� ������ �ʵ� �̵�
        _currentTile = 4602;
        _tileMap->setCameraX(192);
        _tileMap->setCameraY(-64);
        break;
    case 6368:  // ���ڻ� ������ �ʵ� �̵�
        _currentTile = 4602;
        _tileMap->setCameraX(192);
        _tileMap->setCameraY(-64);
        break;
    case 5381:  // �ʵ忡�� ���ϸ� ���� �̵�
        _currentTile = 5525;
        _tileMap->setCameraX(4480);
        _tileMap->setCameraY(192);
        break;
    case 5525:  // ���ϸ� ���Ϳ��� �ʵ� �̵�
        _currentTile = 5381;
        _tileMap->setCameraX(-4736);
        _tileMap->setCameraY(192);
        break;
    case 5526:  // ���ϸ� ���Ϳ��� �ʵ� �̵�
        _currentTile = 5381;
        _tileMap->setCameraX(-4736);
        _tileMap->setCameraY(192);
        break;
    case 3656:  // �ʵ忡�� ü���� �̵�
        _currentTile = 7253;
        _tileMap->setCameraX(5504);
        _tileMap->setCameraY(704);
        break;
    case 7253:  // ü�������� �ʵ� �̵�
        _currentTile = 3656;
        _tileMap->setCameraX(-5568);
        _tileMap->setCameraY(-320);
        break;
    case 7254:  // ü�������� �ʵ� �̵�
        _currentTile = 3656;
        _tileMap->setCameraX(-5568);
        _tileMap->setCameraY(-320);
        break;
    case 3647:  // �ʵ忡�� ���� �̵�
        _currentTile = 5554;
        _tileMap->setCameraX(6336);
        _tileMap->setCameraY(192);
        break;
    case 5554:  // �������� �ʵ� �̵�
        _currentTile = 3647;
        _tileMap->setCameraX(-6144);
        _tileMap->setCameraY(-320);
        break;
    case 5555:  // �������� �ʵ� �̵�
        _currentTile = 3647;
        _tileMap->setCameraX(-6144);
        _tileMap->setCameraY(-320);
        break;
    }
}

void character::render() // ����
{
    _image->frameRender(getMemDC(), _rc.left, _rc.top);

    if (KEYMANAGER->isToggleKey(VK_TAB))
    {
        Rectangle(getMemDC(), _rc);
    }
    
    char str[128];
    sprintf_s(str, "_isMoving : %d", _isMoving);
    TextOut(getMemDC(), 100, 160, str, strlen(str));

    sprintf_s(str, "_frontTileType : %d", _frontTileType);
    TextOut(getMemDC(), 100, 190, str, strlen(str));

    sprintf_s(str, "_���� Ÿ�� : %d", _currentTile);
    TextOut(getMemDC(), 100, 220, str, strlen(str));

    sprintf_s(str, "_���ϸ� ���� : %d", _grassTest);
    TextOut(getMemDC(), 100, 250, str, strlen(str));
}

void character::imageInit() // �̹��� ���ϵ� �ҷ���
{
    // ĳ����
    IMAGEMANAGER->addFrameImage("���̵�_�¿�", "image/character_idle_RL.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("���̵�_����", "image/character_idle_UD.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ȱ�_�¿�", "image/character_run_RL.bmp", 112, 128, 2, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ȱ�_����", "image/character_run_UD.bmp", 224, 128, 4, 2, true, RGB(255, 0, 255));

    //���ϸ� ��
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_155B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��������_��", "image/poketmon/no_156B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("���̹�_��", "image/poketmon/no_157B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ġ�ڸ�Ÿ_��", "image/poketmon/no_152B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("���̸���_��", "image/poketmon/no_153B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ް��Ͽ�_��", "image/poketmon/no_154B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_158B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��������_��", "image/poketmon/no_159B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ũ�δ���_��", "image/poketmon/no_160B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ī��_��", "image/poketmon/no_25B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_26B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����_��", "image/poketmon/no_19B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��Ʈ��_��", "image/poketmon/no_20B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����_��", "image/poketmon/no_16B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����_��", "image/poketmon/no_17B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_18B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_21B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("����帱��_��", "image/poketmon/no_22B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ĳ����_��", "image/poketmon/no_10B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ܵ���_��", "image/poketmon/no_11B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_12B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_13Bbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������_��", "image/poketmon/no_14B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ħ��_��", "image/poketmon/no_15B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));

}


