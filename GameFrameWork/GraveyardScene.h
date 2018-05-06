#pragma once
#include "gameNode.h"
#include "Door.h"

class PlayerManager;
class EnemyManager;

class GraveyardScene :	public gameNode
{
private:
	vector<Object*>	_vDoor;
	PlayerManager*	_pm;
	EnemyManager*	_em;
	//Door *		_door;
	BOOL			_goHotdog;		//�������� ���� ��ġ

	//���̵� ȭ��
	int					_alpha;
	BOOL				_sceneStart;
    BOOL                _sceneChange;
	

public:
	GraveyardScene();
	~GraveyardScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void CheckStatus();
	void SceneStart();
	void DoorEnter();
	void GoSnakeStage();
};

