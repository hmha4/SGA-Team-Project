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

	HRESULT	init(int x, int y);
	void	release();
	void	update(Player * player, string pixelName);
	void	render(HDC hdc);

	// getter
	bool getHp() { return hp; }
	bool getIsDead() { return isDead; }
	int	getX() { return x; }
	int	getY() { return y; }

	RECT	getHitBox() { return hitBox; }

	//setter
	void	setIsDead(bool isDead) { this->isDead = isDead; }

private:
	states state;
	imageStates imageState;

	int	x, y;		//��ǥ
	int	spd;		//���ǵ�
	int	gravity;	//�߷°�

	int	hp;		//ü��
	int	maxHp;	//�ִ�ü��

	int	jumpPower;				//������
	int	knockBackPower;			//�˹��Ŀ�
	int	knockBackDistance;		//�˹�Ÿ�
	int	maxKnockBackDistance;	//�ִ� �˹�Ÿ�

	bool isOnGroundLeft;	
	bool isOnGroundRight;	
	bool isOnGround;		
	bool groundIsInLeft;	
	bool groundIsInRight;	
	bool cliffIsInLeft;		
	bool cliffIsInRight;	

	bool isDead;	
	bool isHit;		

	int moveX;
	int moveY;

	image * img;
	animation * anim;

	RECT hitBox;	// == collision box
	int width;		// hitBox ����
	int height;		// hitBox ����
	Directions direction;	

	int hitTime;		//���� Ÿ�� ����
	int hitTimeLimit;

	int count;

	UINT period_idleToPatrol;
	UINT check_idleToPatrol;
	UINT jumpCount;
	UINT jumpCountLimit;
	int maxMoveDistance;
	int moveDistance;

	float distFromPlayer;

	float alertRange;

	RECT Temp; //Rect for IntersectRect
	COLORREF pixelColor; // COLERREF for PixelCollision

	

private: // �ٸ� ��ü���� �޾ƿ� �͵�
	Player * player;
	float playerX;
	float playerY;
	float playerAttackPower;
	RECT playerAttackBox;
	RECT playerHitBox;


private:

	void idle_behavior();
	void patrol_behavior();
	void alert_behavior();
	void alertJump_behavior();
	void getHit_behavior();

	void GetDamage();

	void GetPlayerInfo(Player * player);
	void CollisionUpdate(string pixelName);

	void PreventFastAttack(); // ���ӵǴ� ���� ����

private:

	void changeState(states state, imageStates imgState, string animKeyName); // ���¿� animation ����

	
};

