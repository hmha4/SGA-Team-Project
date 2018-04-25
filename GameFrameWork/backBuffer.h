#pragma once

class backBuffer
{
	typedef struct tagBackBufferInfo
	{
		HDC hMemDC;			//����� DC
		HBITMAP hBit;		//�� ��Ʈ�� �̹���
		HBITMAP hOBit;		//�õ� ��Ʈ��
		int width;
		int height;

		tagBackBufferInfo()
		{
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
		}
	}BackBuffer_Info, *LPBackBuffer_Info;
private:
	LPBackBuffer_Info _backBufferInfo;

public:
	backBuffer();
	~backBuffer();

	HRESULT init(int width, int height);
	void release(void);
	void render(HDC hdc);

	//�޸�DC������ ���� ������
	inline HDC getMemDC() { return _backBufferInfo->hMemDC; }
};

