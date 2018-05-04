#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{

}

HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		//SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		TXTDATA->init();
		INIDATA->init();
        CAMERA->init("backBuffer");
        CAMERA->SetPos(0, 0);
        POPUP->init();
	}

	return S_OK;
}

void gameNode::release(void)	
{
	if (_managerInit)
	{
		//KillTimer(_hWnd, 1);
		KEYMANAGER->releaseSingleton();
        IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
        TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
        EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
        SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
        SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
        KEYANIMANAGER->release();
		KEYANIMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
		INIDATA->releaseSingleton();
        CAMERA->release();
        CAMERA->releaseSingleton();
        POPUP->release();
        POPUP->releaseSingleton();
		WORLDXY->releaseSingleton();
	}
	
	ReleaseDC(_hWnd, _hdc);
}

void gameNode::update(void)		
{
	//InvalidateRect(_hWnd, NULL, false);
    SOUNDMANAGER->update();
}

void gameNode::render(void)
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//HWND : �ڵ� �޽���
	//UINT : �޽��� ��ȣ
	//WPARAM : Ű���� �Է� �� Ŭ�� �޽��� ����
	//LPARAM : ���콺 ��ǥ ����
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
		//�����찡 �����ɶ� �� �� �� ȣ��ȴ�
		case WM_CREATE:

		break;
		//Ÿ�̸Ӱ� ���⼭ �۵�
	
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;
		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
					PostQuitMessage(0);
				break;
			}
		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}