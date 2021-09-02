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

    _direction = _isMoving = 0;
    _frameCount = _currentFrame = 0;
    _x = WINSIZEX / 2 + 32;
    _y = WINSIZEY / 2;

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


}

void character::controll() // ĳ���� ��Ʈ�� ó��
{
    // ���̵�
    if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) idle(0);
    if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) idle(1);
    if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) idle(2);
    if (KEYMANAGER->isOnceKeyUp(VK_UP)) idle(3);

    // �ȱ�
    if (!_isMoving)
    {
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) // ������ �̵�
        {
            run(0);
            move();
        }

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)) // ���� �̵�
        {
            run(1);
            move();
        }

        if (KEYMANAGER->isStayKeyDown(VK_DOWN)) // �Ʒ� �̵�
        {
            run(2);
            move();
        }

        if (KEYMANAGER->isStayKeyDown(VK_UP)) // �� �̵�
        {
            run(3);
            move();
        }
    }

    // ī�޶� Ÿ�� �̵�
    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) move();
    
    // Z Key
    if (KEYMANAGER->isOnceKeyDown('Z'))
    {

    }

    // X Key
    if (KEYMANAGER->isOnceKeyDown('X'))
    {

    }
}

void character::imageSetting() // ���� �̹��� ����
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

    _isMoving = 0;

    imageSetting();
}

void character::run(int direction) // �ȱ� ó��
{
    // ���� ���� ó��
    if (_tileMap->getCameraY() % TILESIZE == 0 && _tileMap->getCameraX() % TILESIZE == 0) _direction = direction;

    // ���� ���� ó��
    if (_direction == 0 || _direction == 1) _state = static_cast<int>(STATE::RUN_RL);
    else if (_direction == 2 || _direction == 3) _state = static_cast<int>(STATE::RUN_UD);

    // �̵� ������ ó��
    if (_tileMap->getCameraX() % TILESIZE != 0 && _tileMap->getCameraY() % TILESIZE != 0) _isMoving = 1;
    else _isMoving = 0;

    imageSetting();
}

void character::move() // ��ǥ �̵� ó��
{
    switch (_direction)
    {
    case 0:
        _tileMap->setCameraX(_tileMap->getCameraX() + 4);
        break;
    case 1:
        _tileMap->setCameraX(_tileMap->getCameraX() - 4);
        break;
    case 2:
        _tileMap->setCameraY(_tileMap->getCameraY() + 4);
        break;
    case 3:
        _tileMap->setCameraY(_tileMap->getCameraY() - 4);
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
    
}

void character::imageInit() // ���� �̹����� �ҷ���
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


