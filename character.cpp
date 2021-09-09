#include "pch.h"
#include "character.h"
#include "poketmonManager.h"
#include "tileMap.h"
#include "npc.h"

character::character()
{
}

character::~character()
{
}

HRESULT character::init() // ����
{
    imageInit();
    poketmonSetting();

    _image = IMAGEMANAGER->findImage("���̵�_�¿�");
    _shadowImage = IMAGEMANAGER->findImage("ĳ����_�׸���");
    _grassImage = IMAGEMANAGER->findImage("Ǯ��1");
    _battleLoadingImage = IMAGEMANAGER->findImage("��Ʋ�ε�");
    _flashLoadingImage = IMAGEMANAGER->findImage("�÷��÷ε�");

    _direction = _isMoving = _isSloping = _isPoketmonMeet = _frontTileType = _alpha = 0;
    _jumpPower = JUMPPOWER;
    _gravity = GRAVITY;
    _frameCount = _currentFrame = _loadingCount = _scriptAction = 0;
    _x = WINSIZEX / 2 + TILESIZE / 2;
    _y = WINSIZEY / 2;
    _currentTile = 4853;
    _slopeDistance = 0;
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
    poketmonMeet();
    npcScript();
    
    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) tileAction();

}

void character::controll() // ĳ���� ��Ʈ�� ó��
{
    if (_isPoketmonMeet || UIMANAGER->isUiOpen() || _npc->getIsMove()) // ���ϸ� �����ų� UI���ְų� npc���� ����ǥ ���ִٸ�~
    {
        idle(_direction); // ���̵� ó��
        return; // �Լ� �������� 
    }

    if (!_isMoving && !_isSloping) // �̵� ���� �ƴϰ�, ��Ż�� �ƴ� ��
    {
        // ���̵�
        if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) idle(0);
        if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) idle(1);
        if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) idle(2);
        if (KEYMANAGER->isOnceKeyUp(VK_UP)) idle(3);

        // �ȱ�
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) // ������ �̵�
        {
            if (_grassCount >= 3) _grassCount = 0; // Ǯ Ÿ�� �̵� ���� �� �ʱ�ȭ ����
            run(0);
            if (!_isMoving) tileCheck(0);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)) // ���� �̵�
        {
            if (_grassCount >= 3) _grassCount = 0; // Ǯ Ÿ�� �̵� ���� �� �ʱ�ȭ ����
            run(1);
            if (!_isMoving) tileCheck(1);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_DOWN)) // �Ʒ� �̵�
        {
            if (_grassCount >= 3) _grassCount = 0; // Ǯ Ÿ�� �̵� ���� �� �ʱ�ȭ ����
            run(2);
            if (!_isMoving) tileCheck(2);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_UP)) // �� �̵�
        {
            if (_grassCount >= 3) _grassCount = 0; // Ǯ Ÿ�� �̵� ���� �� �ʱ�ȭ ����
            run(3);
            if (!_isMoving) tileCheck(3);
            tileAction();
        }
    }

    // �޴�â (enter Key)
    if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) UIMANAGER->setOpenMenu(true);

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

    // ������ ī��Ʈ ����
    _frameCount++;

    // ī��Ʈ�� ���� ��ġ���� ������X ����
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

    // ������ī��Ʈ �ʱ�ȭ
    if (_frameCount > 5) _frameCount = 0;
}

void character::poketmonMeet() // ���ϸ� ���� �� ó��
{
    // ���ϸ� ���� �ÿ��� ó���ǵ���.
    if (!_isPoketmonMeet) return;

    // ���ϸ� ���� �� Y������ ����
    _battleLoadingImage->setFrameY(0); 

    // �ε� ī��Ʈ ����
    _loadingCount++; 

    // �÷��� �ε� �̹��� ���İ� ����
    if (_loadingCount % 15 == 0) _alpha = 0;
    if (_loadingCount % 15 == 7) _alpha = 150;
    if (_loadingCount % 15 == 14) _alpha = 255;

    // ��Ʋ �ε� �̹��� ����
    if (_loadingCount % 2 == 0)
    {
        if (_loadingCount > 70) _battleLoadingImage->setFrameX(_battleLoadingImage->getFrameX() + 1);

        // �ƽ� ������ �����ϸ� ��Ʋ������ ��ȯ
        if (_battleLoadingImage->getFrameX() >= _battleLoadingImage->getMaxFrameX() && !UIMANAGER->getIsBattle())
        {
            UIMANAGER->setIsBattle(true);
            UIMANAGER->setIsAnimation(true);
            UIMANAGER->setIsBattleScript(true); 
            _battleLoadingImage->setFrameX(0);
            _battleLoadingImage->setFrameY(0);
            _loadingCount = 0;
            _isPoketmonMeet = false;
        }
    }   
}

void character::npcScript() // npc ��ȭ ��ũ��Ʈ ó��
{
    // ��ũ��Ʈ �������� ��������
    if (UIMANAGER->getIsScript()) return;

    for (int i = 0; i < 8; i++)
    {
        RECT temp;
        RECT npc = _npc->getnpcRC()[i].detectRC;

        if (IntersectRect(&temp, &_rc, &npc) && !UIMANAGER->isUiOpen() && !_isMoving) // npc Ž�� ��Ʈ�� �浹 ��, ui���� ��, ������ ��
        {
            // ���� ���� ���� ��ũ��Ʈ ��� ����
            if (_scriptAction == 1 && i == 7) 
            {
                UIMANAGER->setIsScript(true);           // ��ũ��Ʈ ����.
                UIMANAGER->setNPC(NPC::SHOP, true);     // ���� ��ũ��Ʈ ����
                _scriptAction = 0;                      // ��ũ��Ʈ �׼� �ʱ�ȭ
            }

            //if (_scriptAction == 1 && 1 == 4)
            //{
            //    _isPoketmonMeet = 1;
            //    _scriptAction = 0;
            //}

            //if (_scriptAction == 1 && 1 == 5)
            //{
            //    _isPoketmonMeet = 1;
            //}

            //if (_scriptAction == 1 && 1 == 6)
            //{
            //    _isPoketmonMeet = 1;
            //}

            if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _scriptAction == 0) // �����̽��� ������ ��
            {
                UIMANAGER->setIsScript(true); // ��ũ��Ʈ ����.

                switch (i) // �浹�� npc�� ��� ����
                {
                case 0: // ��Ӵ�
                    UIMANAGER->setNPC(NPC::MOM, true);
                    break;
                case 1: // ���ڻ�
                    UIMANAGER->setNPC(NPC::GONG, true);
                    break;
                case 2: // ���ڻ� ����
                    UIMANAGER->setNPC(NPC::SUPPORTER, true);
                    break;
                case 3: // ��ȣ�� ����������������
                    UIMANAGER->setNPC(NPC::POKECENTER, true);
                    break;
                case 4: // ���� 1
                    UIMANAGER->setNPC(NPC::TRAINER1, true);
                    _scriptAction = 1;                          // ��ũ��Ʈ �׼� = 1
                    break;
                case 5: // ���� 2
                    UIMANAGER->setNPC(NPC::TRAINER2, true);
                    _scriptAction = 1;                          // ��ũ��Ʈ �׼� = 1
                    break;
                case 6: // ��� ����
                    UIMANAGER->setNPC(NPC::CHAMPION, true);
                    _scriptAction = 1;                          // ��ũ��Ʈ �׼� = 1
                    break;
                case 7: // ���� ����
                    UIMANAGER->setIsScript(false);              // ��ũ��Ʈ ���ְ�
                    UIMANAGER->setOpenShop(true);               // ���� ����
                    _scriptAction = 1;                          // ��ũ��Ʈ �׼� = 1
                    break;
                }                
            }
        }
    }
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
    // �ٶ� ������ Ÿ���� �� �� �ִ� Ÿ������ üũ
    switch (direction)
    {
    case 0: // ������ ����
        if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_DOOR) _frontTileType = 3;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_RIGHTSLOPE) _frontTileType = 5;
        else _frontTileType = 0;

        break;
    case 1: // ���� ����
        if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_DOOR) _frontTileType = 3;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_LEFTSLOPE) _frontTileType = 4;
        else _frontTileType = 0;

        break;
    case 2: // �Ʒ��� ����
        if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_DOOR) _frontTileType = 3;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_BOTTOMSLOPE) _frontTileType = 6;
        else _frontTileType = 0;

        break;
    case 3: // ���� ����
        if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_DOOR) _frontTileType = 3;
        else _frontTileType = 0;

        break;
    }

    // �Ʒ��� ���� �� �� ��ü Ÿ�� �迭�� ������ �Ѿ�ٸ� Ÿ���� ���ٴ� ���̴� �̵� �Ұ� Ÿ�Ϸ� ó��
    if (_currentTile + 214 > TILE && direction == 2) _frontTileType = 0;
}

void character::tileAction() // ĳ������ Ÿ�� Ÿ�Կ� ���� �׼� ó��
{
    // �⺻, Ǯ, �� Ÿ���� ��
    if (_frontTileType == 1 || _frontTileType == 2 || _frontTileType == 3)
    {
        switch (_direction) // ���⿡ ���� ��ǥ�̵�
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

            switch (_direction)                             // ���� Ÿ�� �ε��� ����
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

    // ��Ż���� ��
    if (_frontTileType == 4 || _frontTileType == 5)
    {
        if (!_isSloping) _slopeDistance = _tileMap->getCameraX();   // ���� ��ġ �� �� ���
        slope(_frontTileType);
    }
    else if (_frontTileType == 6)
    {
        if (!_isSloping) _slopeDistance = _tileMap->getCameraY();   // ���� ��ġ �� �� ���
        slope(_frontTileType);
    }
}

void character::grass() // Ǯ Ÿ�� ó��
{
    // ���ϸ� ���� ���� �ƴ� �� 
    if (!_isPoketmonMeet)
    {
        int rndPoketmonMeet = RND->getFromIntTo(1, 100);

        if (rndPoketmonMeet <= POKETMONMEET) _isPoketmonMeet = 1;
        else _isPoketmonMeet = 0;
    }
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

void character::slope(int direction) // ��Ż�� Ÿ�� ó��
{
    _isSloping = 1;

    switch (direction)
    {
    case 4:     // ���� ��Ż��
        _y -= _jumpPower;
        _jumpPower -= _gravity;
        _tileMap->setCameraX(_tileMap->getCameraX() - 6);   // ī�޶� �̵�
       
        if (_y > WINSIZEY / 2)  // ĳ���Ͱ� �پ��ٰ� ���ڸ��� ���ƿ��� ��
        {
            _y = WINSIZEY / 2;                                      // y ��ǥ �ʱ�ȭ
            _tileMap->setCameraX(_slopeDistance - (TILESIZE * 2));  // x ��ǥ �ʱ�ȭ
            _currentTile -= 2;                                      // Ÿ�� �ε��� ����
            _isSloping = _frontTileType = _slopeDistance = 0;       // ������ �ʱ�ȭ
            _jumpPower = JUMPPOWER;
            _gravity = GRAVITY;       
        }
        break;
    case 5:     // ������ ��Ż��
        _y -= _jumpPower;
        _jumpPower -= _gravity;
        _tileMap->setCameraX(_tileMap->getCameraX() + 6);   // ī�޶� �̵�

        if (_y > WINSIZEY / 2)  // ĳ���Ͱ� �پ��ٰ� ���ڸ��� ���ƿ��� ��
        {
            _y = WINSIZEY / 2;                                      // y ��ǥ �ʱ�ȭ
            _tileMap->setCameraX(_slopeDistance + (TILESIZE * 2));  // x ��ǥ �ʱ�ȭ
            _currentTile += 2;                                      // Ÿ�� �ε��� ����
            _isSloping = _frontTileType = _slopeDistance = 0;       // ������ �ʱ�ȭ
            _jumpPower = JUMPPOWER;
            _gravity = GRAVITY;
        }
        break;
    case 6:     // �Ʒ��� ��Ż��
        _y -= _jumpPower;
        _jumpPower -= _gravity;
        _tileMap->setCameraY(_tileMap->getCameraY() + 6);   // ī�޶� �̵�

        if (_y > WINSIZEY / 2)  // ĳ���Ͱ� �پ��ٰ� ���ڸ��� ���ƿ��� ��
        {
            _y = WINSIZEY / 2;                                      // y ��ǥ �ʱ�ȭ
            _tileMap->setCameraY(_slopeDistance + (TILESIZE * 2));  // x ��ǥ �ʱ�ȭ
            _currentTile += 428;                                    // Ÿ�� �ε��� ����
            _isSloping = _frontTileType = _slopeDistance = 0;       // ������ �ʱ�ȭ
            _jumpPower = JUMPPOWER;
            _gravity = GRAVITY;
        }
        break;
    }
}

void character::ui() // uiâ ȣ��
{
    // UIâ ����
    if (UIMANAGER->getOpenMenu()) UIMANAGER->menu();
    if (UIMANAGER->getOpenShop()) UIMANAGER->shop();
    if (UIMANAGER->getOpenPokecenter()) UIMANAGER->pokeCenter();
    if (UIMANAGER->getIsBattle()) UIMANAGER->battle();
    if (UIMANAGER->getIsScript()) UIMANAGER->script();
}

void character::poketmonSetting() // �׽�Ʈ ������
{
    _poketmon[0].name = "ġ�ڸ�Ÿ";							// �̸�
    _poketmon[0].gender = "����";							// ����
    _poketmon[0].isGender = 0;							// ���� üũ
    _poketmon[0].index = 152;								// �ε��� ��ȣ
    _poketmon[0].level = 20;								// ���ϸ� ���� ����
    _poketmon[0].evolutionLevel = 0;						// ��ȭ �ܰ�

    _poketmon[0].type1 = static_cast<int>(TYPE_PLAYER::GRASS); 								// ���ϸ� Ÿ��1	
    _poketmon[0].type2 = static_cast<int>(TYPE_PLAYER::NONE);								// ���ϸ� Ÿ��2

    _poketmon[0].iconNumX = 30;							//���ϸ� �̴� ������ ��ǥx
    _poketmon[0].iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy
    
    _poketmon[0].attack = 49;								// 1���� �ʱ� ����
    _poketmon[0].defense = 65;							// 1���� �ʱ� ���	
    _poketmon[0].specialAttack = 49;						// 1���� �ʱ� Ư������
    _poketmon[0].specialDefense = 65;						// 1���� �ʱ� Ư�����
    _poketmon[0].speed = 45;								// 1���� �ʱ� ���ǵ�
    _poketmon[0].currentHP = 45;							// 1���� �ʱ� ���� ü��
    _poketmon[0].maxHP = 45;								// 1���� �ʱ� �ִ� ü��

    _poketmon[0].levelAttack = 1.67f;                     //������ ���ݷ�
    _poketmon[0].levelDefense = 1.86f;                    //������ ����
    _poketmon[0].levelSpecialAttack = 1.67f;              //������ Ư�����ݷ�
    _poketmon[0].levelSpecialDefense = 1.86f;             //������ Ư������
    _poketmon[0].levelSpeed = 1.62f;                      //������ ���ǵ�
    _poketmon[0].levelHP = 2.49f;                         //������ ü��

    _poketmon[0].sumAttack = 1;							// ���� ����
    _poketmon[0].sumDefense = 1;							// ���� ���
    _poketmon[0].sumSpecialAttack = 1;					// ���� Ư������
    _poketmon[0].sumSpecialDefense = 1;					// ���� Ư�����
    _poketmon[0].sumSpeed = 1;							// ���� ���ǵ�
    _poketmon[0].sumMaxHP = 1;							// ���� ü��

    _poketmon[0].currentExp = 800;						// ���� ����ġ(���� ���� �� ����ġ, level�� ��ŭ ���� ������ �� �����ֱ�)
    _poketmon[0].maxExp = 1971;							// �ִ� ����ġ(���� ������ �ִ� ����ġ �� ǥ��)

    _poketmon[0].totalEXP = 8800;							// ��Ż ����ġ

    _poketmon[0].skill1 = 1;								// ��ų1 �ε��� 
    _poketmon[0].skill2 = 2;								// ��ų2 �ε��� 
    _poketmon[0].skill3 = 3;								// ��ų3 �ε��� 
    _poketmon[0].skill4 = 4;								// ��ų4 �ε��� 
    _poketmon[0].skillPP1 = 10;							// ��ų1 ���� PP
    _poketmon[0].skillPP2 = 10;							// ��ų2 ���� PP
    _poketmon[0].skillPP3 = 10;							// ��ų3 ���� PP
    _poketmon[0].skillPP4 = 10;							// ��ų4 ���� PP

    _poketmon[0].item = 1;								// ���� ���� ������ �ε���

//--------------------------------------------------------------------------------------------------------------
    _poketmon[1].name = "����";							// �̸�
    _poketmon[1].gender = "����";							// ����
    _poketmon[1].isGender = 1;							// ���� üũ
    _poketmon[1].index = 17;								// �ε��� ��ȣ
    _poketmon[1].level = 20;								// ���ϸ� ���� ����
    _poketmon[1].evolutionLevel = 1;						// ��ȭ �ܰ�
              
    _poketmon[1].type1 = static_cast<int>(TYPE_PLAYER::FLYING); 								// ���ϸ� Ÿ��1	
    _poketmon[1].type2 = static_cast<int>(TYPE_PLAYER::NONE);								// ���ϸ� Ÿ��2
              
    _poketmon[1].iconNumX = 12;							//���ϸ� �̴� ������ ��ǥx
    _poketmon[1].iconNumY = 0;								//���ϸ� �̴� ������ ��ǥy

    _poketmon[1].attack = 49;								// 1���� �ʱ� ����
    _poketmon[1].defense = 65;							// 1���� �ʱ� ���	
    _poketmon[1].specialAttack = 49;						// 1���� �ʱ� Ư������
    _poketmon[1].specialDefense = 65;						// 1���� �ʱ� Ư�����
    _poketmon[1].speed = 45;								// 1���� �ʱ� ���ǵ�
    _poketmon[1].currentHP = 45;							// 1���� �ʱ� ���� ü��
    _poketmon[1].maxHP = 45;								// 1���� �ʱ� �ִ� ü��
              
    _poketmon[1].levelAttack = 1.67f;                     //������ ���ݷ�
    _poketmon[1].levelDefense = 1.86f;                    //������ ����
    _poketmon[1].levelSpecialAttack = 1.67f;              //������ Ư�����ݷ�
    _poketmon[1].levelSpecialDefense = 1.86f;             //������ Ư������
    _poketmon[1].levelSpeed = 1.62f;                      //������ ���ǵ�
    _poketmon[1].levelHP = 2.49f;                         //������ ü��
              
    _poketmon[1].sumAttack = 1;							// ���� ����
    _poketmon[1].sumDefense = 1;							// ���� ���
    _poketmon[1].sumSpecialAttack = 1;					// ���� Ư������
    _poketmon[1].sumSpecialDefense = 1;					// ���� Ư�����
    _poketmon[1].sumSpeed = 1;							// ���� ���ǵ�
    _poketmon[1].sumMaxHP = 1;							// ���� ü��
              
    _poketmon[1].currentExp = 800;						// ���� ����ġ(���� ���� �� ����ġ, level�� ��ŭ ���� ������ �� �����ֱ�)
    _poketmon[1].maxExp = 1971;							// �ִ� ����ġ(���� ������ �ִ� ����ġ �� ǥ��)
              
    _poketmon[1].totalEXP = 8800;							// ��Ż ����ġ
              
    _poketmon[1].skill1 = 1;								// ��ų1 �ε��� 
    _poketmon[1].skill2 = 2;								// ��ų2 �ε��� 
    _poketmon[1].skill3 = 3;								// ��ų3 �ε��� 
    _poketmon[1].skill4 = 4;								// ��ų4 �ε��� 
    _poketmon[1].skillPP1 = 10;							// ��ų1 ���� PP
    _poketmon[1].skillPP2 = 10;							// ��ų2 ���� PP
    _poketmon[1].skillPP3 = 10;							// ��ų3 ���� PP
    _poketmon[1].skillPP4 = 10;							// ��ų4 ���� PP
              
    _poketmon[1].item = 2;								// ���� ���� ������ �ε���
}

void character::render() // ����
{    
    // ĳ���� �̹��� ����
    _image->frameRender(getMemDC(), _rc.left, _rc.top);

    if (KEYMANAGER->isToggleKey(VK_TAB)) // �����Ͱ��� ǥ��
    {
        Rectangle(getMemDC(), _rc);

        char str[128];
        sprintf_s(str, "_isMoving : %d", _isMoving);
        TextOut(getMemDC(), 100, 160, str, strlen(str));

        sprintf_s(str, "_frontTileType : %d", _frontTileType);
        TextOut(getMemDC(), 100, 190, str, strlen(str));

        sprintf_s(str, "_���� Ÿ�� : %d", _currentTile);
        TextOut(getMemDC(), 100, 220, str, strlen(str));

        sprintf_s(str, "_���ϸ� ���� : %d", _isPoketmonMeet);
        TextOut(getMemDC(), 100, 250, str, strlen(str));

        sprintf_s(str, "_scriptAction : %d", _scriptAction);
        TextOut(getMemDC(), 100, 280, str, strlen(str));
    }
    
    // ��Ż�� �̵� ���� �� �׸��� ������
    if (_isSloping) 
    {
        _shadowImage->render(getMemDC(), _rc.left, WINSIZEY / 2 - TILESIZE / 2);
    }

    // Ǯ Ÿ�� �̵� ���� �� Ǯ���� �̹��� ������
    if (_tileMap->getTile()[_currentTile].type == TILETYPE_GRASS)
    {
        if (_grassCount == 0) _grassImage = IMAGEMANAGER->findImage("Ǯ��1");
        if (_grassCount == 3) _grassImage = IMAGEMANAGER->findImage("Ǯ��2");
        _grassImage->render(getMemDC(), _x - 22, _y - 2);
        _grassCount++;
        if (_grassCount >= 3) _grassCount = 3;
    }

    // ���ϸ� ���� �� �÷����̹���, ��Ʋ�ε��̹��� ���
    if (!UIMANAGER->getIsBattle())
    {
        if (_isPoketmonMeet && _loadingCount > 70) _battleLoadingImage->frameRender(getMemDC(), 0, 0);
        if (_isPoketmonMeet && _loadingCount <= 70) _flashLoadingImage->alphaRender(getMemDC(), _alpha);
    }

    // uiâ ȣ��
    ui();
}

void character::imageInit() // �̹��� ���ϵ� �ҷ���
{
    // ĳ����
    IMAGEMANAGER->addFrameImage("���̵�_�¿�", "image/character_idle_RL.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("���̵�_����", "image/character_idle_UD.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ȱ�_�¿�", "image/character_run_RL.bmp", 112, 128, 2, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ȱ�_����", "image/character_run_UD.bmp", 224, 128, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ĳ����_�׸���", "image/character_shadow.bmp", 56, 64, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("Ǯ��2", "image/poketmon_grass2.bmp", 45, 21, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("Ǯ��1", "image/poketmon_grass1.bmp", 48, 36, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��Ʋ�ε�", "image/battle_loading.bmp", 17920, 596, 28, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�÷��÷ε�", "image/flash_loading.bmp", 640, 576, 1, 1, true, RGB(255, 0, 255));

    //���ϸ� ��
    IMAGEMANAGER->addFrameImage("155B", "image/poketmon/no_155B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("156B", "image/poketmon/no_156B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("157B", "image/poketmon/no_157B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("152B", "image/poketmon/no_152B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("153B", "image/poketmon/no_153B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("154B", "image/poketmon/no_154B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("158B", "image/poketmon/no_158B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("159B", "image/poketmon/no_159B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("160B", "image/poketmon/no_160B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("25B", "image/poketmon/no_25B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("26B", "image/poketmon/no_26B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("19B", "image/poketmon/no_19B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("20B", "image/poketmon/no_20B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("16B", "image/poketmon/no_16B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("17B", "image/poketmon/no_17B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("18B", "image/poketmon/no_18B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("21B", "image/poketmon/no_21B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("22B", "image/poketmon/no_22B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("10B", "image/poketmon/no_10B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("11B", "image/poketmon/no_11B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("12B", "image/poketmon/no_12B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("13B", "image/poketmon/no_13Bbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("14B", "image/poketmon/no_14B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("15B", "image/poketmon/no_15B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
}


