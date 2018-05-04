#pragma once
#include "gameNode.h"

class Player;

class Boss_Snake : public gameNode
{
private:
	image*					_img;				//���� �̹���
	animation*				_motion;			//���� �ִϸ��̼�
	animation*				_exMotion;			//���� �ִϸ��̼� ����
	float					_x, _y;				//���� ��ǥ
	BOSS_SNAKE				_state;				//���� ����
	BOSS_SNAKE				_exState;			//���� ���� ����
	BOSS_SNAKE_DIRECTION	_direction;			//���� ����
	int						_HP;
												
	RECT					_rc;				//������ ��Ʈ
	RECT					_attackRC;			//������ ��Ʈ
	int						_attack;			//���� (0:���� �ƴ�, 1:����, 2:����)
	int						_attackCount;		//���� ī��Ʈ
												
	int						_count;				//ī��Ʈ
	BOOL					_isPlay;			//�ִ� �÷��� ����
	BOOL					_isDamage;			//������ ���� ����
	int						_startX, _endX;		//������ ������ ����

	float					playerX, playerY;
	RECT					playerAttackBox;
	RECT					playerDamageBox;

public:
	Boss_Snake();
	~Boss_Snake();

	HRESULT init();
	void release();
	void update(Player * player);
	void render();

	void Set(float x, float y);
	void CheckState(Player * player);
	void Operation();
	void Move(string direction);
	void Die();
	RECT AttackRC(Player * player);
	RECT DamageRC();
	void GetDamage();


	void GetPlayerInfo(Player * player);
	
	BOSS_SNAKE GetState() { return _state; }
	float GetX() { return _x; }
	float GetY() { return _y; }

	void SetDamage(int damage) { _HP -= damage; }
	void PlayDamage();
};

