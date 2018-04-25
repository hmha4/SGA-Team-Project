#pragma once
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _mountain;		//��� �̹���
	image* _ball;			//�� �̹���

	RECT _rc;
	float _x, _y;			//����

	int _probeY;			//Y�� Ž�� ����Ʈ

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release();
	void update();
	void render();
};

