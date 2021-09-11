#pragma once
#include "singletonBase.h"
#include <string>
#include <vector>


class progressBar;
class poketmonManager;


enum class NPC
{
	// title
	TITLE,

	// mom
	MOM,

	// Dr.Gong
	GONG,
	SUPPORTER,

	// champion
	CHAMPION,

	// trainers
	TRAINER1,
	TRAINER2,

	// where connect to player
	POKECENTER,
	SHOP,

	// about pokemon
	EVOLUTION,
	TOTODILE,		// ������
	CHIKORITA,		// ġ�ڸ�Ÿ
	CYNDAQUIL,		// ������

	// starting select cancel
	SELECTCANCEL,

	// battle(test)
	BATTLE,
	BATTLE_ATTACK,
	BATTLE_DOWN
};


class character;

class uiManager : public singletonBase<uiManager>
{
private:
	int gold = 5000;
	int soundVolume = 100;
	int shopCnt = 0;							//���� �޴� ������
	int buyCnt = 0;								//������ �޴� ������
	int menuCnt = 0;
	int bagCnt = 0;
	int pokesCnt = 0;
	int dogamCnt = 0;
	int settingCnt = 0;
	int statusCnt = 0;
	int gearCnt = 0;
	bool shopWindow = false;					//���� �޴�â ����� �ȶ����
	bool buyWindow = false;						//������ �޴�â ����� �ȶ����
	bool bagWindow = false;
	bool menuWindow = false;
	bool pokeshiftWindow = false;
	bool pokeWindow = false;
	bool settingWindow = false;
	bool pokedogamWindow = false;
	bool statusWindow = false;
	bool gearWindow = false;
	bool useMedicineWindow = false;
	bool useGoodMedicineWindow = false;
	bool howStrongWindow = false;
	int pokeballQ = 50;   // ���Ϻ� ���� ���� , �Ʒ��� ��ó��, ��޻�ó�� ���� (Q)
	int medicineQ = 22;
	int goodMedicineQ = 13;
	int delaycnt;
	int iconCnt;

	// isOpen
	bool _isOpenShop;	// ���� �����ִ���

	bool _isOpenPokeShift;
	bool _isOpenBag;
	bool _isOpenSetting;
	bool _isOpenPokeDogam;
	bool _isOpenPlayerStatus;
	bool _isOpenPokeGear;
	bool _isOpenHowStrong;
	// ������� �޴�â�� �ȿ� �ִ°� �����ִ���

	bool _isOpenPokecenter;						// ���ɼ��� �����ִ���
	bool _isOpenMenu;							// �޴� �����ִ���

	// isBattle
	bool _isOpenSkill;							// ���â �����ִ���
	bool _isOpenPokemon;						// ���ϸ� ����â �����ִ���
	bool _isBattle;								// ��Ʋ �������� �ƴ���
	bool _isAttack;								// ���� �������� �ƴ���

	// script
	bool _isScript;								// ��ȭ ���� (��ȭ ������)
	bool _isScriptSkip;							// ��ŵ ���� (��ȭ �Ѳ����� ���)
	image* _scriptImage;						// ��ũ��Ʈ ����̹���
	int _scriptIndex;							// ��ũ��Ʈ �� ī��Ʈ(����?)
	int _txtIndex;								// ��ũ��Ʈ ���� ī��Ʈ
	vector<string> _vScript;					// ��ũ��Ʈ�� ���� ����
	string _txt;								// ���� �ؽ�Ʈ ����

	int _momCount;								// ���� ��ȭ ���൵ ī��Ʈ
	int _drCount;								// ���ڻ� ��ȭ ���൵ ī��Ʈ
	int _championCount;							// ���� ��ȭ ���൵ ī��Ʈ
	int _trainer1Count;							// Ʈ���̳�1 ��ȭ ���൵ ī��Ʈ
	int _trainer2Count;							// Ʈ���̳�2 ��ȭ ���൵ ī��Ʈ
	int _pokecenterCount;						// ��ȣ�� ���� ��ȭ ���൵ ī��Ʈ

	bool _isCount;


	// pokeCenter
	int cnt = 0;

	int _index = 0;

	bool uiOpen = false;						// ui ���� �ִ��� ����

	//battle
	bool _isAnimation;							// �ִϸ��̼��� ���������� ���� üũ����

	image* _playerImage;						// �÷��̾� �̹���
	image* _playerPokeImage;					// �÷��̾� ���ϸ� �̹���
	image* _enemyImage;							// ��� Ʈ���̳� �̹���
	image* _enemyPokeImage;						// ��� ���ϸ� �̹���

	int _appearIndex = 2;						// ���ϸ� ��� �� �� ������ �̹��� ������

	progressBar* _hpBarPlayer;					// ü�� ������
	progressBar* _hpBarEnemy;
	progressBar* _expBar;						// ����ġ ������

	int _px, _ex;								// ��Ʋ �� �÷��̾� �� ���ʹ� �̹��� ���� ��ġ

	int _currentHP, _maxHP;						// ���� hp, �ִ� hp
	int _currentEXP, _maxEXP;					// ���� ����ġ, �ִ� ����ġ

	float _time;

	int _behaviorCount;							//Ŀ�� �������� ���� ����

	bool _isBattleScript;
	bool _isTurn;								// ���� �ִϸ��̼� ���� ������
	bool _isNext;								// ���� ���ϸ��� ���� ��������

	int _currentPoke = 0;						// �÷��̾��� ���� ���ϸ��� �ε��� ��ȣ(0~5)
	int _currentSkill;							// ���� ����� ��ų�� �ε��� ��ȣ(0~3)

	int _attackCount;							// ���� ���� ������
	int _whoTurn;								// ���� ������ ������(0 == ��� / 1 == �� �� / 2 == ��� ��)
	int _power;

	bool _isWin;								// ��Ʋ���� �¸�������

	// getStarting Pokemon
	bool _isStarting;


	// Ȯ��â(��/�ƴϿ�)
	bool _isAccept;

	// class
	NPC _npc;
	character* _character;
	poketmonManager* _poketmonManager;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void shop();

	void bag();
	void pokeDogam();
	void pokeGear();
	void playerStatus();
	void setting();

	void howStrong();

	void pokeCenter();
	void menu();

	void pokeShift();

	void script();		// ���Ŀ� �Ű������� npc��ȣ �޾ƿͼ� �� ��Ȳ�� �´� �ؽ�Ʈ ������ָ� �� ����.

	void battle();
	void skillSelect();
	void attack();
	
	void usePokeBall();
	void useMedicine();
	void useGoodMedicine();

	void getStartingPokemon();

	

	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }

	NPC getNPC() { return _npc; }
	void setNPC(NPC npc, bool isCount) { _npc = npc; _isCount = isCount; }

	bool getIsCount() { return _isCount; }
	void setIsCount(bool isCount) { _isCount = isCount; }

	bool isUiOpen();

	bool getOpenShop() { return _isOpenShop; }
	void setOpenShop(bool openShop) { _isOpenShop = openShop; }

	bool getOpenBag() { return _isOpenBag; }
	void setOpenBag(bool openBag) { _isOpenBag = openBag; }

	bool getOpenPokecenter() { return _isOpenPokecenter; }
	void setOpenPokecenter(bool openPoke) { _isOpenPokecenter = openPoke; }

	bool getOpenMenu() { return _isOpenMenu; }
	void setOpenMenu(bool openMenu) { _isOpenMenu = openMenu; }

	bool getIsBattle() { return _isBattle; }
	void setIsBattle(bool isBattle) { _isBattle = isBattle; }

	bool getIsAnimation() { return _isAnimation; }
	void setIsAnimation(bool isAnimation) { _isAnimation = isAnimation; }

	bool getIsBattleScript() { return _isBattleScript; }
	void setIsBattleScript(bool isBattleScript) { _isBattleScript = isBattleScript;	}

	bool getIsAttack() { return _isAttack; }
	void setIsAttack(bool isAttack) { _isAttack = isAttack; }

	bool getIsTurn() { return _isTurn; }
	void setIsTurn(bool isTurn) { _isTurn = isTurn; }

	bool getIsNext() { return _isNext; }
	void setIsNext(bool next) { _isNext = next; }

	int getAttackCount() { return _attackCount; }
	void setAttackCount(int attackCount) { _attackCount = attackCount; }

	int getGold() { return gold; };
	void setGold(int newgold) { gold = newgold; }

	int getCurrentPokemon() { return _currentPoke; }
	void setCurrentPokemon(int current) { _currentPoke = current; }

	bool getIsWin() { return _isWin; }
	void setIsWin(bool isWin) { _isWin = isWin; }

	bool getIsStarting() { return _isStarting; }
	void setIsStarting(bool starting) { _isStarting = starting; }

	bool getIsAccept() { return _isAccept; }
	void setIsAccept(bool accept) { _isAccept = accept; }

	int getDrCount() { return _drCount; }

	// Memory
	void setCharacterMemoryAddressLink(character* character) { _character = character; }
	void setSkillMemoryAddressLink(poketmonManager* pm) { _poketmonManager = pm; }
};

