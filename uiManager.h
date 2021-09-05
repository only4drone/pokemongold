#pragma once
#include "singletonBase.h"
#include <string>


class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//���� �޴� ������
	int buyCnt = 0;								//������ �޴� ������
	int menuCnt = 0;
	bool shopWindow = false;					//���� �޴�â ����� �ȶ����
	bool buyWindow = false;						//������ �޴�â ����� �ȶ����

	// script
	bool _isScript;
	bool _isScriptSkip;
	RECT _scriptRC;
	image* _scriptImage;
	int _scriptIndex;
	int _txtIndex;
	vector<string> _vScript;
	string _txt;

	// pokeCenter
	int cnt = 0;
	int _index = 0;

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

	void script();		// ���Ŀ� �Ű������� npc��ȣ �޾ƿͼ� �� ��Ȳ�� �´� �ؽ�Ʈ ������ָ� �� ����.


	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

};

