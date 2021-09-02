#pragma once
#include "gameNode.h"

class tile : public gameNode
{
private:
	int _idX;
	int _idY;

	POINT _center;	//Ÿ���� ����
	RECT _rc;

	//F = G + H
	//F == �� �Ÿ� ��� (totalCost)
	//G == ���������κ��� ���� �������� ��κ��(costFromStart)
	//H == ���� ������ ������������ ��κ��(costToGoal)

	float _totalCost;		//F
	float _costFromStart;	//G
	float _costToGoal;		//H

	bool _isOpen;			//�����ִ� ���̴�?

	tile* _parentNode;		//���� ��� (��� ���ŵǴ� Ÿ��)

	COLORREF _color;
	HBRUSH _brush;
	HPEN _pen;

	string _attribute;

public:
	tile();
	~tile();

	HRESULT init(int idX, int idY);
	void release();
	void update();
	void render();

	int getIdX() { return _idX; }
	int getIdY() { return _idY; }

	void setColor(COLORREF color)
	{
		DeleteObject(_brush);
		_color = color;
		_brush = CreateSolidBrush(_color);
	}

	RECT getRect() { return _rc; }

	//================= ���� ���� ������ & ������ =============

	void setCenter(POINT center) { _center = center; }
	POINT getCenter() { return _center; }

	void setAttribute(string str) { _attribute = str; }
	string getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }

	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(tile* t) { _parentNode = t; }
	tile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

};

