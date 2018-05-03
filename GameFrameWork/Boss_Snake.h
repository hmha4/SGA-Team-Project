#pragma once
#include "gameNode.h"

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
	int						_startX, _endX;		//������ ������ ����

public:
	Boss_Snake();
	~Boss_Snake();

	HRESULT init();
	void release();
	void update();
	void render();

	void Set(float x, float y);
	void CheckState();
	void Operation();
	void Move(string direction);
	void Die();
	RECT AttackRC();
	RECT DamageRC();
	
	void SetDamage(int damage) { _HP -= damage; }
	void PlayDamage();
};

