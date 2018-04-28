#pragma once

class World_Character
{
private:
	float						_x, _y;								//���� ��ǥ
	float						_angle;								//����
	image*						_img;								//�̹���
	animation*					_motion;							//������ �ִϸ��̼�
	WORLD_CHARACTER_STATE		_state;								//����
	int							_frameX, _frameY;					//������ ��ȣ(X,Y)
	int							_probeLeft, _probeRight;			//�ȼ� ���� ���� �¿� ��ǥ
	int							_probeUp, _probeDown;				//�ȼ� ���� ���� ���� ��ǥ 
	int							_collisionRight, _collisionLeft;	//�¿� �浹 üũ
	int							_collisionUp, _collisionDown;		//���� �浹 üũ
	RECT						_rc;								//��Ʈ
	BOOL						_right, _left, _up, _down;			//Ű�Է� ����


public:
	World_Character();
	~World_Character();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void setImage(string imageKey);
	virtual void checkDirection();
	virtual void checkPixel();
	virtual void changeState();
	virtual void setCamera();
	virtual void move();

	float getX() { return _x; }
	float getY() { return _y; }
};

