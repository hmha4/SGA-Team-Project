#pragma once
#include "gameNode.h"

class World;

class WorldScene : public gameNode
{
private:
	World* _world;

	//���̵� ȭ��
	int					_alpha;
	BOOL				_sceneStart;
public:
	WorldScene();
	~WorldScene();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� ��ŸƮ
	void SceneStart();
};

