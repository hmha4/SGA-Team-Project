#pragma once

class Player;

//TO DO : �÷��̾�� ����

class Enemy_SmallZombie
{
	enum imageStates
	{
		left_idle, right_idle,
		left_walk, right_walk,
		left_jump, right_jump,
		left_getHit, right_getHit
	};

	enum states
	{
		idle,
		patrol,
		alert,
		alertJump,
		getHit
	};

	enum Directions
	{
		LEFT,
		RIGHT
	};

public:
	Enemy_SmallZombie();
	~Enemy_SmallZombie();

	HRESULT init(int x, int y);
	void release();
	//void update(Player * player, string pixelName);
	void update();
	void render(HDC hdc);

	// getter
	bool getIsDie() { return isDie; }
	int getX() { return x; }
	int getY() { return y; }

private:
	int x, y;
	int spd;
	int gravity;

	int hp;
	int maxHp;

	int jumpPower;
	int knockBackPower;
	int knockBackDistance;
	int maxKnockBackDistance;

	bool isOnGround;
	bool groundIsInLeft;	
	bool groundIsInRight;
	bool cliffIsInLeft;
	bool cliffIsInRight;

	bool isDie;

	int moveX;
	int moveY;

	image * img;
	animation * anim;

	RECT hitBox;
	int width;
	int height;
	Directions direction;

	float alertRange;

	RECT Temp; //Rect for IntersectRect

private: // �ٸ� ��ü���� �޾ƿ� �͵�
	float playerX;
	float playerY;
	float playerAttackPower;
	RECT playerHitBox;


private:

	states state;
	imageStates imageState;

	void idle_behavior();
	void patrol_behavior();
	void alert_behavior();
	void alertJump_behavior();
	void getHit_behavior();

	void stateTrigger();

	UINT period_idleToPatrol;
	UINT check_idleToPatrol;
	UINT jumpCount;
	UINT jumpCountLimit;
	int maxMoveDistance;
	int moveDistance;

	float distFromPlayer;

	void GetPlayerInfo(Player * player);
	void CollisionUpdate(string pixelName);

private:

	void changeState(states state, imageStates imgState, string animKeyName); // ���¿� animation ����

	void CheckIsDie(int hp); // HP <= 0 �̸� isDie = true
};

