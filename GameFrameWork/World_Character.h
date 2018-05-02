#pragma once
#include <vector>

#define SIZEOFTRACE			22
#define BRIDGEX				2010
#define BRIDGETOPSTART		1484
#define BRIDGETOPEND		1630
#define BRIDGEBOTTOMSTART	1600
#define BRIDGEBOTTOMEND		1450

//Ŭ���� ���漱��
class World_Bridge;

struct tagTrace
{
	int						x, y;
	WORLD_CHARACTER_STATE	state;
	animation*				motion;
	int						idleFrame;
};

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


private:
	tagTrace					_traceFinn;							//�� �̵���θ� ���� ����ü
	vector<tagTrace>			_vTrace;							//�� �̵���θ� ���� ����
	image*						_jakeImg;							//����ũ �̹���
	float						_jakeX, _jakeY;						//����ũ ��ǥ
	animation*					_jakeMotion;						//����ũ ���
	BOOL						_followTrace;						//���� ���� ���� Ȯ��
	int							_traceIndex;						//���� �ε���

private:
	World_Bridge*				_bridge;							//�ٸ� Ŭ����
	BOOL						_canMakeBridge;						//�ٸ� ���� ������ ������ ��ġ �ϰ� �ִ��� Ȯ��
	BOOL						_meetDog;							//������ NPC �������� Ȯ��
	WORLD_MAKE_BRIDGE			_bridgeState;						//�ٸ� ���� ����

private:
	BOOL						_pressX;
	int							_Xframe;
	int							_Xcount;
	BUTTON_STATE				_buttonState;
	COLORREF					_colorStore;
	COLORREF					_colorBridge;
	COLORREF					_colorGraveyard;

public:
	World_Character();
	~World_Character();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	//FINN ���� �Լ�
	void CheckDirection();
	void CheckPixel();
	void ChangeState();
	void SetCamera();
	void Move();
	
	//JAKE ���� �Լ�
	void CheckTrace();
	void SaveTrace(int index);
	void DrawJake(HDC hdc);

	//�ٸ� ���� ���� �Լ�
	void MakeBridge();
	void BridgeOperation();
	WORLD_MAKE_BRIDGE GetBridgeState() { return _bridgeState; }
	void SetBridgeState(WORLD_MAKE_BRIDGE state) { _bridgeState = state; }

	//��ư �Լ�
	void button();

	float GetX() { return _x; }
	float GetY() { return _y; }
	
	void SetFinnState(WORLD_CHARACTER_STATE state) { _state = state; }

	void CheckStatus(HDC hdc);

	void GetAdressBridge(World_Bridge* bridge) { _bridge = bridge; }
};

