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
	CYNDAQUIL,		// ������
	TOTODILE,		// ������
	CHIKORITA,		// ġ�ڸ�Ÿ

	// starting select cancel
	SELECTCANCEL,

	// battle(test)
	BATTLE,
	BATTLE_ATTACK,
	BATTLE_DOWN,

	CHAMPION_BATTLE_DOWN,
	CHAMPION_BATTLE_WIN,
	TRAINER1_BATTLE_DOWN,
	TRAINER1_BATTLE_WIN,
	TRAINER2_BATTLE_DOWN,
	TRAINER2_BATTLE_WIN,

	// pokemon change
	POKEMONCHANGE,
};

class tileMap;
class character;

class uiManager : public singletonBase<uiManager>
{
private:

	tileMap* _tileMap;


	int gold = 5000;
	
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
	tagPOKETMON_PLAYER _currentEnemyPokemon;	// ���� �����ִ� ��� ���ϸ�
	tagPOKETMON_PLAYER _currentPokemon;			// ���� �����ִ� �� ���ϸ�
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

	bool _isBattleScript;						// ��Ʋ ���� ��ũ��Ʈ ���� ����
	bool _isTurn;								// ���� �ִϸ��̼� ���� ������
	bool _isNext;								// ���� ���ϸ��� ���� ��������
	bool _isBattleStart;						// ��Ʋ ���� �� �� �� üũ

	int _currentPoke;							// �÷��̾��� ���� ���ϸ��� �ε��� ��ȣ(0~5)
	int _currentEnemyIndex;						// ������ ���� ���ϸ��� �ε��� ��ȣ
	int _currentEnemy;							// ���� ���� ���� (0 == �߻� / 1 == Ʈ���̳�1 / 2 == Ʈ���̳�2 / 3 == ����)
	int _currentSkill;							// ���� ����� ��ų�� �ε��� ��ȣ(0~3)

	int _attackCount;							// ���� ���� ������
	int _whoTurn;								// ���� ������ ������(0 == ��� / 1 == �� �� / 2 == ��� ��)
	int _power;

	bool _isWin;								// ��Ʋ���� �¸�������
	bool _isWild;								// �߻� ���ϸ����� �ƴ���(Ʈ���̳�(false) or �߻�(true))

	// getStarting Pokemon
	bool _isStarting;							// ��Ÿ�� ���ϸ� �޾Ҵ���
	bool _isGetCyndaquil;						// ������ ȹ��
	bool _isGetTotodile;						// ������ ȹ��
	bool _isGetChikorita;						// ġ�ڸ�Ÿ ȹ��

	// Ȯ��â(��/�ƴϿ�)
	image* _confirmImage;						// Ȯ��â �̹���
	bool _isConfirm;							// Ȯ��â ����
	bool _isAccept;								// true == ��, false == �ƴϿ�
	int _acceptCount;							// 0 == ��, 1 == �ƴϿ�

	// ���� ȹ�濩��
	bool _isGetBadge;

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

	void shop();				// ����â

	void bag();					// ����â
	void pokeDogam();			// ����â
	void pokeGear();			// ���ϱ��â
	void playerStatus();		// �÷��̾� ����â
	void setting();				// ����â

	void howStrong();			// ���� ������ ���� â

	void pokeCenter();			// ���ϸ� ����(ȸ��)
	void menu();				// �޴�â

	void pokeShift();			// ���ϸ�â

	void script();				// ��ũ��Ʈ ���â

	void battle();				// ��Ʋâ
	void skillSelect();			// ��ų����â
	void attack();				// ���ݽ���
	
	void usePokeBall();			// ���Ϻ� ���
	void useMedicine();			// ��ó�� ���
	void useGoodMedicine();		// ���� ��ó�� ���

	void getStartingPokemon();	// ��Ÿ�� ���ϸ� ȹ��
	void confirm();				// Ȯ��â(��/�ƴϿ�)

	void levelUp();

	int soundVolume = 50;

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

	bool getIsConfirm() { return _isConfirm; }
	void setIsConfirm(bool confirm) { _isConfirm = confirm; }

	bool getIsCyndaquil() { return _isGetCyndaquil; }
	void setIsCyndaquil(bool Cyndaquil) { _isGetCyndaquil = Cyndaquil; }

	bool getIsTotodile() { return _isGetTotodile; }
	void setIsTotodile(bool Totodile) { _isGetTotodile = Totodile; }

	bool getIsChikorita() { return _isGetChikorita; }
	void setIsChikorita(bool Chikorita) { _isGetChikorita = Chikorita; }

	bool getIsBattleStart() { return _isBattleStart; }
	void setIsBattleStart(bool battleStart) { _isBattleStart = battleStart; }

	bool getIsWild() { return _isWild; }
	void setIsWild(bool isWild) { _isWild = isWild; }

	int getDrCount() { return _drCount; }
	int getChampionCount() { return _championCount; }
	int getTrainer1Count() { return _trainer1Count; }
	int getTrainer2Count() { return _trainer2Count; }

	bool getIsBadge() { return _isGetBadge; }

	// Memory
	void setCharacterMemoryAddressLink(character* character) { _character = character; }
	void setSkillMemoryAddressLink(poketmonManager* pm) { _poketmonManager = pm; }
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }
};

