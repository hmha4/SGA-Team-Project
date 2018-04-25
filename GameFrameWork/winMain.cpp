#include "stdafx.h"
#include "playGround.h"

//====================== �� �� �� �� ============
HINSTANCE	_hInstance;		//�ν��Ͻ� ��ȣ
HWND		_hWnd;
LPTSTR _lpszClass = TEXT("Nona Windows API");

//���콺 ��ǥ
POINT _ptMouse;
playGround _pg;


//================ �Լ� ������ Ÿ�� ���� ============
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);
//==================================================

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	//������ â ������ ���� �ʱ�ȭ (����) -> �� ������ ����
	//������ â ���¸� ����� -> ȭ�鿡 ����
	MSG			message;		//������ �޽��� ����ü
	WNDCLASS	wndClass;		//������ ������ ��� ����ü

	//�ν��Ͻ� ��ȣ ����
	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//������ ���� ������ ���� ���
	RegisterClass(&wndClass);

	//������ â ����
	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,				//������ â ���� X��ǥ
		WINSTARTY,				//������ â ���� Y��ǥ
		WINSIZEX,				//������ â ����ũ��
		WINSIZEY,				//������ â ����ũ��
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//������ â�� ���� ���̰� ������ش�
	ShowWindow(_hWnd, cmdShow);

	//�÷��̱׶��尡 �ʱ�ȭ �����ϸ� ��ó��~
	if (FAILED(_pg.init()))
	{
		return 0;
	}

	//GetMessage : �޽����� ������ ������ ó��
	//PeekMessage : �޽����� ������ �ȵ����� ��� �������� ��������

	/*
	// �����쿡�� �߻��ϴ� �޽��� ���� ó�� ����
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//Ű���� �Է� �� ���콺 Ŭ�� �޽����� ó�� ���ش�
		DispatchMessage(&message);	//������ �߻��� �޽������� �������ִ� ���� 
	}
	*/

	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);	//Ű���� �Է� �� ���콺 Ŭ�� �޽����� ó�� ���ش�
			DispatchMessage(&message);	//������ �߻��� �޽������� �������ִ� ���� 
		}
		else
		{
			TIMEMANAGER->update(60.0f);
			_pg.update();
			_pg.render();
		}
	}


	_pg.release();

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _pg.MainProc(hWnd, iMessage, wParam, lParam);
}

//Ŭ���̾�Ʈ ���� �������� ���� �Լ�
void setWindowSize(int x, int y, int width, int height)
{
	//������ ��Ʈ
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	//������ �������� ���������ִ� �Լ�
	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);

}