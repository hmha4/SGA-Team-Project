#pragma once

class World_Character;

class World_Bridge
{
private:
	World_Character*	_finn;

private:
	int		_x, _y;					//�ٸ� ���� ��ǥ
	int		_state;					//�ٸ� ���� 0:�ٸ� ����, 1:���� ����, 2:������, 3:���� �Ϸ�, 4:ö����
	image*	_img;					//�ٸ� �̹���
	int		_frameX, _frameY;		//������XY
	int		_count;					//ī��Ʈ
	BOOL	_startAni;				//�ִϸ��̼� ��ŸƮ
	int		_bridgeDirection;		// 0 : �Ͽ��� ������, 1 : ������ ������


public:
	World_Bridge();
	~World_Bridge();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void MakeBridge();
	void RemoveBridge();

	int GetBridgeDirection() { return _bridgeDirection; }
	void SetFrameX(int x) { _frameX = x; }
	void SetFrameY(int y) { _frameY = y; }
	void SetBridgeDirection(int direction) { _bridgeDirection = direction; }

	void SetStartAni(BOOL start) { _startAni = start; }

	void GetAdressFinn(World_Character* finn) { _finn = finn; }
};

