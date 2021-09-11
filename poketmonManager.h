#pragma once
#include "gameNode.h"
#include <vector>
#include "skill.h"

#include "poketmon.h"	//�߻����ϸ� ������ �������� ��� ����.


#pragma region poketmon

#include "chikorita.h"	//ġ�ڸ�Ÿ
#include "cyndaquil.h"	//������
#include "totodile.h"	//������
#include "pikachu.h"	//��ī��
#include "pidgey.h"		//����
#include "rattata.h"	//����
#include "caterpie.h"	//ĳ����
#include "spearow.h"	//������
#include "weedle.h"		//������

#pragma endregion


// ���� ����
class character;

class poketmonManager : public gameNode
{
private:
	typedef vector<poketmon*>				vPoketmon;
	typedef vector<poketmon*>::iterator		viPoketmon;

private:
	vPoketmon _vPoketmon;
	viPoketmon _viPoketmon;

	character* _character;
	skill* _skill;
	poketmon* _poketmon;

	tagPOKETMON_PLAYER _wildPoketmon;				//�߻����ϸ�

	tagPOKETMON_PLAYER _startPoketmon[3];			//ó������ ���ϸ�


	int _randomPoketmon;						//���ϸ� �������� ���������� ���� ����

public:

	poketmonManager();
	~poketmonManager();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void poketmonImage();										// ���ϸ� �̹��� �߰�
	void poketmonSpawn();										// ���ϸ� ����

	void wildPoketmonSetting();									//�߻� ���ϸ� ����

	void startPoketmonSetting();

	void setCharacterMemoryAddressLink(character* character) { _character = character; }		// �޸� �ּ� ��ũ


	tagPOKETMON_PLAYER getWildPoketmon() { return _wildPoketmon; }			//�߻� ���ϸ� ����
	tagPOKETMON_PLAYER* getStartPoketmon() { return _startPoketmon; }		//��ŸƮ ���ϸ� 

	skill* getSkill() { return _skill; }

	void setCurrentHP(int hp) { _wildPoketmon.currentHP -= hp; }

};
