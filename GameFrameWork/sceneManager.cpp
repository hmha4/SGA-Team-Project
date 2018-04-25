#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"



sceneManager::sceneManager()
{

}


sceneManager::~sceneManager()
{
}

DWORD CALLBACK loadingThread(LPVOID prc)
{
	//��ü�� ���� �̸� �ʱ�ȭ �صд�
	sceneManager::_readyScene->init();

	//�� ��ü�� ���ش�
	sceneManager::_currentScene = sceneManager::_readyScene;

	//�ε��� ���� �� ����
	sceneManager::_loadingScene->release();
	//�ε��� ���� ���� ����ص״� �� �ʱ�ȭ
	sceneManager::_loadingScene = NULL;
	sceneManager::_readyScene = NULL;

	//�߿��Ѱ� ������ ���ٴ°� �Ǹ������j...

	return 0;
}

gameNode* sceneManager::_currentScene = NULL;
gameNode* sceneManager::_loadingScene = NULL;
gameNode* sceneManager::_readyScene = NULL;

HRESULT sceneManager::init()
{
	_currentScene = NULL;
	_loadingScene = NULL;
	_readyScene = NULL;

	return S_OK;
}

void sceneManager::release()
{

}

void sceneManager::update()	
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render()	
{
	if (_currentScene) _currentScene->render();
}


//�� �߰� �Լ�        �θ� �� �̸�,    �ش� ��
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

gameNode* sceneManager::addLoadingScene(string loadingSceneName, gameNode* scene)
{
	if (!scene) return NULL;

    _mLoadingSceneList.insert(make_pair(loadingSceneName, scene));

	return scene;
}


//�� ����
HRESULT sceneManager::changeScene(string sceneName)
{
	//ã�����ϴ� ���� Ű �� ����
	mapSceneIter find = _mSceneList.find(sceneName);

	//��ã������
	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene) return S_OK;

    
	//�� ü������ �����ϸ� init�Լ��� �����Ѵ�
	if (SUCCEEDED(find->second->init()))
	{
		//���� ���� �ִٸ� ������ ���� ����
		if (_currentScene) _currentScene->release();

		//���� ���� �ٲٷ��� ���� �����Ѵ�
		_currentScene = find->second;
		//�� ������ ���߿� �������� �Ը��� ���� �ٲ㵵 �ȴ�
		
		return S_OK;
	}

	return E_FAIL;
}

HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName)
{
	//ã�����ϴ� ���� Ű �� ����
	mapSceneIter find = _mSceneList.find(sceneName);

	//��ã������
	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene) return S_OK;

	//�ε��� ����� �� ã�´�
	mapSceneIter findLoading = _mLoadingSceneList.find(loadingSceneName);

	if (findLoading == _mLoadingSceneList.end()) return changeScene(sceneName);

	//�� ü������ �����ϸ� init�Լ��� �����Ѵ�
	if (SUCCEEDED(findLoading->second->init()))
	{
		//���� ���� �ִٸ� ������ ���� ����
		if (_currentScene) _currentScene->release();

		_loadingScene = findLoading->second;

        //���� ���� �ε������� �ٲ��ְ�
        _currentScene = _loadingScene;
        //���� ���� ����
        _readyScene = find->second;

		//�� ������ ���߿� �������� �Ը��� ���� �ٲ㵵 �ȴ�

		//�ε��� ����� ������� �ݾ��ش�
		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &_loadingThreadID));

		return S_OK;
	}

	return E_FAIL;
}


