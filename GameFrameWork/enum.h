#pragma once

#define WORLD_SPEED 2

enum WORLD_CHARACTER_STATE
{
	//����� �ɸ��� ����
	WORLD_EAST_IDLE,			//���� IDLE
	WORLD_EAST_MOVE,			//���� �̵�
	WORLD_WEST_IDLE,			//���� IDLE
	WORLD_WEST_MOVE,			//���� �̵�
	WORLD_NORTH_IDLE,			//���� IDLE
	WORLD_NORTH_MOVE,			//���� �̵�
	WORLD_SOUTH_IDLE,			//���� IDLE
	WORLD_SOUTH_MOVE,			//���� �̵�
	WORLD_NORTH_EAST_IDLE,		//�ϵ� IDLE
	WORLD_NORTH_EAST_MOVE,		//�ϵ� �̵�
	WORLD_NORTH_WEST_IDLE,		//�ϼ� IDLE
	WORLD_NORTH_WEST_MOVE,		//�ϼ� �̵�
	WORLD_SOUTH_EAST_IDLE,		//���� IDLE
	WORLD_SOUTH_EAST_MOVE,		//���� �̵�
	WORLD_SOUTH_WEST_IDLE,		//���� IDLE
	WORLD_SOUTH_WEST_MOVE,		//���� �̵�
	RIGHT
};