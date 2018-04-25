#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//Ŭ���� ���漱��
//������� ���ѷ����� ���������� ���� �����̱⵵ ������
//���� ������ �ӵ��� ��û �������Ƿ� �ǹ����� �� ������
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	piccolo* _piccolo;

	enemyManager* _em;

	progressBar* _hpBar;

	float _currentHP, _maxHP;

	int _alphaValue;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision(void);

	void hitDamage(float damage);

	image* getShipImage() { return _ship; }
	
	//������ ���ݷ� �̻��Ͽ� ���� ������
	piccolo* getPiccoloMissile() { return _piccolo; }

	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	spaceShip();
	~spaceShip();
};

