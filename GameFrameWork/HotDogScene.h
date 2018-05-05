#pragma once
#include "gameNode.h"

class PlayerManager;

class HotDogScene :	public gameNode
{
private:
	PlayerManager*	_pm;
	
	float				_loopX;
	int					_scriptX;
	int					_scriptState;

	//��ư ���� ����
	BOOL						_pressX;
	int							_Xframe;
	int							_Xcount;

public:
	HotDogScene();
	~HotDogScene();

	HRESULT init();
	void release();
	void update();
	void render();
	
	//��ư �Լ�
	void button();
	
	//�ڸ� �Լ�
	void Script();
	void MoveScript();
	void CheckStatus();
};

