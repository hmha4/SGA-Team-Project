#pragma once
#include "gameNode.h"

class Enemy_Bear : public gameNode
{
private:
	//���� ���� �̳�
	enum STATE
	{
		LEFT_IDLE, RIGHT_IDLE,
		LEFT_WALK, RIGHT_WALK,
		LEFT_BACK, RIGHT_BACK,
		LEFT_RUN, RIGHT_RUN,
		LEFT_JUMP, RIGHT_JUMP,
		LEFT_ROAR, RIGHT_ROAR,
		LEFT_ATTACK, RIGHT_ATTACK,
		LEFT_DIE, RIGHT_DIE,
		DEFAULT
	};

private:
	image * _img;		//�� �̹���
	float _x, _y;		//���� ��ǥ
	RECT _rc;			//�� ��Ʈ
	STATE _state;		//�� ����
	float _moveSpeed;	//�� �̵��ӵ�
	RECT _weaponRc;		//�� ���� ��Ʈ
	RECT _hitRc;		//�� ������ ��Ʈ
	int _hitTime;

	int _hp;			//�� HP

	BOOL _isAttack;		//�����߾��°�
	int _delay;			//���� ������
	float _saveX;
	float _saveY;

	float _probeX;
	float _probeY;

	BOOL _isRight;		//�� ����
	int _countTime;		//������ ī��Ʈ
	int _frameSpeed;	//������ �ӵ�
	int _currentFrameX;	//���� ������ ��ȣ

	BOOL _isJump;		//���� ����
	float _jumpPower;	//������
	float _gravity;		//�߷�

	int _time;			//�ٿ뵵
	int _rndTime;		//���� ��� �ð� ����
	int _rndPattern;	//�䳢�� �������� ����

	float _playerX;		//�÷��̾� x��ǥ
	float _playerY;		//�÷��̾� y��ǥ
	RECT _playerRc;		//�÷��̾� ��Ʈ
	RECT _playerHitRc;	//�÷��̾� ������ ��Ʈ
	BOOL _isDie;

	BOOL _isRoar;		//Ư������

public:
	Enemy_Bear();
	~Enemy_Bear();

	HRESULT init(float x, float y);
	void release();
	void update();
	void render();

	void Move();
	void Draw();

	void Pattern1();
	void Pattern2();
	void Pattern3();
	void Pattern4();

	void Jump();

	void Die();

	void LoopAnimation(UINT value1 = 0);	//��� ����
	void OneShotAnimation();				//�ѹ��� �ִ�

	void SetPlayerInfo(float x, float y, RECT rc, RECT hitRc) { _playerX = x; _playerY = y; _playerRc = rc; _playerHitRc = hitRc; }
	void SetState(STATE state, UINT frameSpeed = 5);
	STATE GetState() { return _state; }

	RECT GetRect() { return _rc; }

	void SetHp(int hp) { _hp = hp; }
	int GetHp() { return _hp; }

	RECT GetWeaponRect() { return _weaponRc; }
	RECT GetHitRect() { return _hitRc; }

	BOOL GetIsDie() { return _isDie; }
	void SetIsDie(BOOL isDie) { _isDie = isDie; }

	BOOL GetIsRoar() { return _isRoar; }

	float GetX() { return _x; }
	float GetY() { return _y; }
};

