#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", 8000, 2111);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
	
public:
	//HRESULT == MS���� 
	//S_OK, E_FAIL, SUCCEDED ���� ���â�� ǥ�����ش�
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release(void);		//�޸� ���� �Լ�
	virtual void update(void);		//������Ʈ(����) �Լ�
	virtual void render(void);	//����(�׷��ִ�) �Լ�

	//����� ������
	image* getBackBuffer(void) { return _backBuffer; }

	//������� DC������ ������
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

