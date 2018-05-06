#pragma once
#include "gameNode.h"
#include "PlayerManager.h"
#include "Bubble.h"
#include "Door.h"
#include <vector>

class TutorialScene : public gameNode
{
private:
    PlayerManager * _pm;

    int _alpha;

	//�ڸ� ���� ����
	BOOL	_viewScript;
	int		_scriptX;
	int		_scriptState;

	//��ư ���� ����
	BOOL						_pressX;	//��ư ǥ�� ����
	int							_Xframe;	//��ư ������
	int							_Xcount;	//��ư ������ ���� ī��Ʈ

    vector<Object*> _vObject;
public:
    TutorialScene();
    ~TutorialScene();

    HRESULT init();
    void release();
    void update();
    void render();

	void TestText();
	void Script();
	void MoveScript();
	void button();
};

