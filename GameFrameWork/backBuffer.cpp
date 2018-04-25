#include "stdafx.h"
#include "backBuffer.h"


backBuffer::backBuffer() : _backBufferInfo(NULL)
{
}


backBuffer::~backBuffer()
{

}

HRESULT backBuffer::init(int width, int height)
{
	HDC hdc = GetDC(_hWnd);

	_backBufferInfo = new BackBuffer_Info;
	_backBufferInfo->hMemDC = CreateCompatibleDC(hdc);	//�� DC���� ����
	_backBufferInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height); //�� ��Ʈ�� �̹���
	_backBufferInfo->hOBit = (HBITMAP)SelectObject(_backBufferInfo->hMemDC, _backBufferInfo->hBit);
	_backBufferInfo->width = width;
	_backBufferInfo->height = height;

	//�� ��Ʈ�� ������ �����Ͽ�����
	if (_backBufferInfo->hBit == NULL)
	{
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);


	return 0;
}

void backBuffer::release(void)	
{
	if (_backBufferInfo)
	{
		SelectObject(_backBufferInfo->hMemDC, _backBufferInfo->hOBit);
		DeleteObject(_backBufferInfo->hBit);
		DeleteDC(_backBufferInfo->hMemDC);

		delete _backBufferInfo;
		_backBufferInfo = 0;
	}
}

void backBuffer::render(HDC hdc)
{
	//��DC�� �׷����� �͵��� ��DC�� ��Ӻ��� ���ִ� �Ծ�
	BitBlt(hdc, 
		0, 0,					//����Ǽ� �׷����� ��
		_backBufferInfo->width, //�������� ����ũ��
		_backBufferInfo->height,//�������� ����ũ��
		_backBufferInfo->hMemDC,//�����ؿ� DC����
		0,						//�����ؿ� ��ǥ X, Y
		0, 
		SRCCOPY);
}
