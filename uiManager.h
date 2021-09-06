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


	void script();		// ���Ŀ� �Ű������� npc��ȣ �޾ƿͼ� �� ��Ȳ�� �´� �ؽ�Ʈ ������ָ� �� ����.


	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }
	bool isUiOpen();


};

