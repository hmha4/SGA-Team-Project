#pragma once
#include "singletonBase.h"
#include <map>

//gameNode ���漱��
class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>				mapSceneList;
	typedef map<string, gameNode*>::iterator	mapSceneIter;

private:
	static gameNode* _currentScene;	//���� ��
	static gameNode* _loadingScene;	//�ε� ��(Ȥ�� ����)
	static gameNode* _readyScene;	//�ε��������� ü���� ���� ��� ��(ȣ���� ����2)

	mapSceneList _mSceneList;			//�� ����Ʈ
	mapSceneList _mLoadingSceneList;	//�ε� �� ����Ʈ (���߿� �ϳװ� �� �����ٹ�)

	DWORD _loadingThreadID;				//ȣ������ ������ ���� �־���� �ε� ������� ID

public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �߰� �Լ�        �θ� �� �̸�,    �ش� ��
	gameNode* addScene(string sceneName, gameNode* scene);
	gameNode* addLoadingScene(string loadingSceneName, gameNode* scene);

	//�� ����
	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName, string loadingSceneName);


	//������ �����ϸ� ���� �ȵǴ� ���� ����(?) ��
	//��ü�� private���� �ٷ� ������ ����� ���ش�
	//�Լ� friend�� �ְ� Ŭ���� friend�� �ִ�
	//������ �� ���� �� ����ؾ� �Ѵٸ� �ϳ� ������ ������
	friend DWORD CALLBACK loadingThread(LPVOID prc);
};

