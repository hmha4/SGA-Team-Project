#include "stdafx.h"
#include "Enemy_SmallZombie.h"
#include "PlayerManager.h"

Enemy_SmallZombie::Enemy_SmallZombie()
	:state(states::idle),
	imageState(imageStates::right_idle),
	spd(3), gravity(3),
	x(0), y(0), moveX(0), moveY(0),
	hitBox({ 0,0,0,0 }),
	playerHitBox({ 0,0,0,0 }),
	direction(RIGHT),
	alertRange(15),
	moveRange(0),	
	period_idleToPatrol(10)
{
}


Enemy_SmallZombie::~Enemy_SmallZombie()
{
}

HRESULT Enemy_SmallZombie::init()
{
	IMAGEMANAGER->addFrameImage("SmallZombie_idle", "SmallZombie_idle.bmp", 369, 70, 9, 2, true, RGB(255, 0, 255));

	int leftIdle[] = { 0 };
	//KEYANIMANAGER->addArrayFrameAnimation("SZ_leftIdle","SmallZombie_idle",)


	img = IMAGEMANAGER->findImage("SmallZombie_idle");
	anim = KEYANIMANAGER->findAnimation("SZ_rightIdle");
	anim->start();
	
	return S_OK;
}

void Enemy_SmallZombie::release()
{
}

void Enemy_SmallZombie::PlayerInfoUpdate(PlayerManager * PM)
{
	playerX = PM->GetPlayerX();
	playerY = PM->GetPlayerY();
	playerHitBox = PM->GetPlayerHitRC();

}

void Enemy_SmallZombie::update(PlayerManager * PM)
{
	PlayerInfoUpdate(PM);

	stateTrigger();

	if (state == states::idle) idle_behavior();
	else if (state == states::patrol) patrol_behavior();
	else if (state == states::alert) alert_behavior();

	hitBox = RectMakeCenter(x, y, 50, 50); // update hitBox
}

void Enemy_SmallZombie::render()
{
}


void Enemy_SmallZombie::idle_behavior()
{
	moveX = 0;
	moveY = gravity;




}

void Enemy_SmallZombie::patrol_behavior()
{
	moveX = direction ? -spd : spd;
	moveY = gravity;
}

void Enemy_SmallZombie::alert_behavior()
{
	moveX = (x > playerX) ? -spd : spd;
	moveY = gravity;

	direction = (x > playerX) ? LEFT : RIGHT;


}

void Enemy_SmallZombie::stateTrigger()
{
	float distFromPlayer = getDistance(x, y, playerX, playerY);

	if (state == states::idle) 
	{
		if (distFromPlayer < alertRange) state = states::alert;

		UINT i = 0;
		for (i; i <= period_idleToPatrol; ++i)
			if (i == period_idleToPatrol) { 
				bool change = RND->getFromIntTo(false, true); 
				bool dir = RND->getFromIntTo(LEFT, RIGHT);
				if (change == true) {
					if (dir == LEFT) changeState(patrol, left_walk, "SZ_leftWalk");
					if (dir == RIGHT) changeState(patrol, right_walk, "SZ_rightWalk");
				}
			} // ���� �ֱ⸶�� ���� ��ȭ idle <-> patrol 

	}
	else if (state == states::patrol) 
	{
		if (distFromPlayer < alertRange) state = states::alert;



	}
	else if (state == states::alert) 
	{
		
	}
}

void Enemy_SmallZombie::changeState(states state, imageStates imgState, string animKeyName)
{
	this->state = state;
	imageState = imgState;

	switch (imageState) {
	case Enemy_SmallZombie::left_idle:
	case Enemy_SmallZombie::right_idle: img = IMAGEMANAGER->findImage("SmallZombie_idle");
		break;
	case Enemy_SmallZombie::left_walk:
	case Enemy_SmallZombie::right_walk: img = IMAGEMANAGER->findImage("SmallZombie_walk");
		break;
	case Enemy_SmallZombie::left_jump:
	case Enemy_SmallZombie::right_jump: img = IMAGEMANAGER->findImage("SmallZombie_jump");
		break;
	case Enemy_SmallZombie::left_getHit:
	case Enemy_SmallZombie::right_getHit: img = IMAGEMANAGER->findImage("SmallZombie_getHit");
		break;
	}

	anim = KEYANIMANAGER->findAnimation(animKeyName);
	anim->start();

}