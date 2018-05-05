#pragma once
#include "gameNode.h"

class PlayerManager;

class HotDogScene :	public gameNode
{
private:
	PlayerManager*	_pm;
	
	float				_loopX;				//���� ��� ���������� ���� ����
	int					_scriptX;			//�ڸ� �̹��� X��ǥ
	int					_scriptState;		//�ڸ� �ܰ�
	int					_count;				//����Ŵ��� ���۵����� ���� �ӽ� ī��Ʈ ����

	//��ư ���� ����
	BOOL						_pressX;	//��ư ǥ�� ����
	int							_Xframe;	//��ư ������
	int							_Xcount;	//��ư ������ ���� ī��Ʈ

	//���̵� ȭ��
	int					_alpha;
	BOOL				_sceneStart;

public:
	HotDogScene();
	~HotDogScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void OutStage();
	
	//�� ��ŸƮ
	void SceneStart();

	//��ư �Լ�
	void button();
	
	//�ڸ� �Լ�
	void Script();
	void MoveScript();
	void CheckStatus();
};

