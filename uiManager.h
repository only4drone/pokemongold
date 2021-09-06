#pragma once
#include "singletonBase.h"
#include <string>

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


class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//���� �޴� ������
	int buyCnt = 0;								//������ �޴� ������
	int menuCnt = 0;
	bool shopWindow = false;					//���� �޴�â ����� �ȶ����
	bool buyWindow = false;						//������ �޴�â ����� �ȶ����

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

	bool uiOpen = false;


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


	void script(NPC npc);		// ���Ŀ� �Ű������� npc��ȣ �޾ƿͼ� �� ��Ȳ�� �´� �ؽ�Ʈ ������ָ� �� ����.


	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }
	bool isUiOpen();


};

