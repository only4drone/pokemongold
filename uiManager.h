#pragma once
#include "singletonBase.h"
#include <string>
#include <vector>



enum class NPC
{
	// title
	TITLE,

	// mom
	MOM_FIRST,
	MOM_NORMAL,

	// Dr.Gong
	DR_FIRST,
	DR_BEFORE_POKEMON,
	DR_AFTER_POKEMON,
	DR_NORMAL,
	SUPPORTER,

	// champion
	CHAMPION_BATTLE_START,
	CHAMPION_BATTLE_AFTER,
	CHAMPION_BATTLE_END,

	// trainers
	TRAINER1_BATTLE_BEFORE,
	TRAINER1_BATTLE_START,
	TRAINER1_BATTLE_END,
	TRAINER1_BATTLE_WIN,

	TRAINER2_BATTLE_BEFORE,
	TRAINER2_BATTLE_START,
	TRAINER2_BATTLE_END,
	TRAINER2_BATTLE_WIN,

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


};


class character;

class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//���� �޴� ������
	int buyCnt = 0;								//������ �޴� ������
	int menuCnt = 0;
	int bagCnt = 0;
	int pokesCnt = 0;
	bool shopWindow = false;					//���� �޴�â ����� �ȶ����
	bool buyWindow = false;						//������ �޴�â ����� �ȶ����
	bool bagWindow = false;
	bool menuWindow = false;
	bool pokeWindow = false;
	int pokeballQ = 50;   // ���Ϻ� ���� ���� , �Ʒ��� ��ó��, ��޻�ó�� ���� (Q)
	int medicineQ = 22;
	int goodMedicineQ = 13;
	int delaycnt;
	int iconCnt;
	// isOpen
	bool _isOpenShop;							// ���� �����ִ���
	bool _isOpenBag;							// ���� �����ִ���
	bool _isOpenPokecenter;						// ���ɼ��� �����ִ���
	bool _isOpenMenu;							// �޴� �����ִ���


	// script
	bool _isScript;								// ��ȭ ���� (��ȭ ������)
	bool _isScriptSkip;							// ��ŵ ���� (��ȭ �Ѳ����� ���)
	image* _scriptImage;						// ��ũ��Ʈ ����̹���
	int _scriptIndex;							// ��ũ��Ʈ �� ī��Ʈ(����?)
	int _txtIndex;								// ��ũ��Ʈ ���� ī��Ʈ
	vector<string> _vScript;					// ��ũ��Ʈ�� ���� ����
	string _txt;								// ���� �ؽ�Ʈ ����

	// pokeCenter
	int cnt = 0;

	int _index = 0;

	bool uiOpen = false;						// ui ���� �ִ��� ����

	NPC _npc;
	character* _character;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void shop();
	void bag();

	void pokeCenter();
	void menu();

	void pokeShift();

	void script();		// ���Ŀ� �Ű������� npc��ȣ �޾ƿͼ� �� ��Ȳ�� �´� �ؽ�Ʈ ������ָ� �� ����.


	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }

	NPC getNPC() { return _npc; }
	void setNPC(NPC npc) { _npc = npc; }

	bool isUiOpen();

	bool getOpenShop() { return _isOpenShop; }
	void setOpenShop(bool openShop) { _isOpenShop = openShop; }

	bool getOpenBag() { return _isOpenBag; }
	void setOpenBag(bool openBag) { _isOpenBag = openBag; }

	bool getOpenPokecenter() { return _isOpenPokecenter; }
	void setOpenPokecenter(bool openPoke) { _isOpenPokecenter = openPoke; }

	bool getOpenMenu() { return _isOpenMenu; }
	void setOpenMenu(bool openMenu) { _isOpenMenu = openMenu; }

	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};

