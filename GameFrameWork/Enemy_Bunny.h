#pragma once
#include "gameNode.h"

class Enemy_Bunny : public gameNode
{
private:
	//�䳢�� ���� �̳�
	enum STATE
	{
		LEFT_IDLE, RIGHT_IDLE,
		LEFT_JUMP, RIGHT_JUMP,
		DEFAULT
	};

private:
	image * _img;		//�䳢 �̹���
	float _x, _y;		//�䳢 ��ǥ
	RECT _rc;			//�䳢 ��Ʈ
	STATE _state;		//�䳢 ���� ����
	float _moveSpeed;	//�䳢 �������¿����� �̵��ӵ�
	RECT _hitRc;		//�䳢 Į ��Ʈ

	int _hp;			//�䳢 HP

	BOOL _isRight;		//�䳢�� ����
	int _countTime;		//������ �̹����� ���� ī��Ʈ
	int _frameSpeed;	//������ �ӵ�
	int _currentFrameX;	//���� ������ ��ȣ
	int _currentFrameY;

	BOOL _isJump;		//�����߳�
	float _jumpPower;	//������
	float _gravity;		//�߷�

	int _time;			//�뵵�� �پ���
	int _rndTime;		//�䳢�� �����ϱ��� ����ϴ� �ð� ����
	
	float _playerX;		//�÷��̾� x��ǥ
	float _playerY;		//�÷��̾� y��ǥ
	RECT _playerRc;		//�÷��̾� ��Ʈ
	RECT _playerHitRc;	//�÷��̾� ������ ��Ʈ
	BOOL _isDamage;
	BOOL _isPlayerDamage;

	int _probeX;
	int _probeY;

public:
	Enemy_Bunny();
	~Enemy_Bunny();

	HRESULT init(float x, float y);
	void release();
	void update();
	void render();

	void Move();
	void Draw();

	void Jump();

	void LoopAnimation(UINT value = 0);	//��� ������Ŵ
	void OneShotAnimation();			//�ѹ��� �ִϸ��̼�
	void StopAnimation(UINT value = 0);	//�� �����ӿ��� ����

	void SetPlayerInfo(float x, float y, RECT rc, RECT hitRc) { _playerX = x; _playerY = y; _playerRc = rc; _playerHitRc = hitRc; }

	void SetState(STATE state, UINT frameSpeed = 5);
	STATE GetState() { return _state; }

	RECT GetRect() { return _rc; }

	void SetHp(int hp) { _hp = hp; }
	int GetHp() { return _hp; }

	RECT GetHitRect() { return _hitRc; }

	void PixelCollision1();
	void PixelCollision2();

	float GetX() { return _x; }
	float GetY() { return _y; }

	BOOL GetIsDamage() { return _isDamage; }
	void SetIsDamage(BOOL isDamage) { _isDamage = isDamage; }
	BOOL GetIsPlayerDamage() { return _isPlayerDamage; }
	void SetIsPlayerDamage(BOOL isPlayerDamage) { _isPlayerDamage = isPlayerDamage; }
};

