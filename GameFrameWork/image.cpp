#include "stdafx.h"
#include "image.h"

#pragma comment(lib, "msimg32.lib")

image::image()
	:	_imageInfo(NULL), 
		_fileName(NULL), 
		_trans(false), 
		_transColor(RGB(0, 0, 0))
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{

	//�̹��� ������ �����ִٸ� �����Ѵ�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height); //�� ��Ʈ�� �̹���
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���ĺ��� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//��Ʈ���� ������ �����ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�ʱ�ȭ ���� ��������
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

//���Ϸκ��� �ʱ�ȭ    ���ϸ�, ���ϰ���ũ��, ���ϼ���ũ��, ����Į��
HRESULT image::init(const char* fileName, int width, int height,
	BOOL trans, COLORREF transColor, bool alpha)
{
	//�̹��� ������ �����ִٸ� �����Ѵ�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� ���̸� ���´�
	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

    if (alpha)
    {
        //���ĺ��� ����
        _blendFunc.BlendFlags = 0;
        _blendFunc.AlphaFormat = 0;
        _blendFunc.BlendOp = AC_SRC_OVER;

        _blendImage = new IMAGE_INFO;
        _blendImage->loadType = LOAD_EMPTY;
        _blendImage->hMemDC = CreateCompatibleDC(hdc);
        _blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
        _blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
        _blendImage->width = WINSIZEX;
        _blendImage->height = WINSIZEY;
    }
	//��Ʈ���� ������ �����ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�ʱ�ȭ ���� ��������
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, float x, float y,
	int width, int height, BOOL trans, COLORREF transColor, bool alpha)
{
	//�̹��� ������ �����ִٸ� �����Ѵ�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x		= x;
	_imageInfo->y		= y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� ���̸� ���´�
	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

    if (alpha)
    {
        //���ĺ��� ����
        _blendFunc.BlendFlags = 0;
        _blendFunc.AlphaFormat = 0;
        _blendFunc.BlendOp = AC_SRC_OVER;

        _blendImage = new IMAGE_INFO;
        _blendImage->loadType = LOAD_EMPTY;
        _blendImage->hMemDC = CreateCompatibleDC(hdc);
        _blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
        _blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
        _blendImage->width = WINSIZEX;
        _blendImage->height = WINSIZEY;
    }
	//��Ʈ���� ������ �����ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�ʱ�ȭ ���� ��������
		return E_FAIL;
	}


	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

//�̹��� �ʱ�ȭ(�̹��� �̸�, �����ǥ, ����ũ��, ������ ��������)
HRESULT image::init(const char* fileName, float x, float y,
	int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor, bool alpha)
{
	//�̹��� ������ �����ִٸ� �����Ѵ�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	//���� ���̸� ���´�
	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

    if (alpha)
    {
        //���ĺ��� ����
        _blendFunc.BlendFlags = 0;
        _blendFunc.AlphaFormat = 0;
        _blendFunc.BlendOp = AC_SRC_OVER;

        _blendImage = new IMAGE_INFO;
        _blendImage->loadType = LOAD_EMPTY;
        _blendImage->hMemDC = CreateCompatibleDC(hdc);
        _blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
        _blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
        _blendImage->width = WINSIZEX;
        _blendImage->height = WINSIZEY;
    }
	//��Ʈ���� ������ �����ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�ʱ�ȭ ���� ��������
		return E_FAIL;
	}


	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor, bool alpha)
{
	//�̹��� ������ �����ִٸ� �����Ѵ�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	//���� ���̸� ���´�
	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

    if (alpha)
    {
        //���ĺ��� ����
        _blendFunc.BlendFlags = 0;
        _blendFunc.AlphaFormat = 0;
        _blendFunc.BlendOp = AC_SRC_OVER;

        _blendImage = new IMAGE_INFO;
        _blendImage->loadType = LOAD_EMPTY;
        _blendImage->hMemDC = CreateCompatibleDC(hdc);
        _blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
        _blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
        _blendImage->width = WINSIZEX;
        _blendImage->height = WINSIZEY;
    }
	//��Ʈ���� ������ �����ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�ʱ�ȭ ���� ��������
		return E_FAIL;
	}


	ReleaseDC(_hWnd, hdc);

	return S_OK;
}


//�޸� ���� �Լ�
void image::release(void)
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);
		SAFE_DELETE(_blendImage);

		_trans = false;
		_transColor = NULL;
	}

}


//������ �÷��� ������ �Ǿ���Ѵٸ� ����� �Լ�
void image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}

void image::render(HDC hdc)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,
			_imageInfo->x,
			_imageInfo->y,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor
		);
	}
	else
	{
		BitBlt(hdc,
			_imageInfo->x,
			_imageInfo->y,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0, SRCCOPY);
	}
}


//������ �Լ� �Ѹ�DC, left, top ��ǥ
void image::render(HDC hdc, int destX, int destY)
{
    //if (!FrustumCull(destX, destY)) return;

	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//�ѷ��� DC
			destX,				//�ѷ��� ��ġ(left)
			destY,				//�ѷ��� ��ġ(top)
			_imageInfo->width,	//����ũ��
			_imageInfo->height,	//����ũ��
			_imageInfo->hMemDC,	//�����ؿ� DC
			0, 0,				//�����ؿ� left, top
			_imageInfo->width,	//�����ؿ� ����ũ��
			_imageInfo->height,	//�����ؿ� ����ũ��
			_transColor);		//���ܽ�ų ����
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}

}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,				//�ѷ��� DC
			destX,				//�ѷ��� ��ġ(left)
			destY,				//�ѷ��� ��ġ(top)
			sourWidth,			//����ũ��
			sourHeight,			//����ũ��
			_imageInfo->hMemDC,	//�����ؿ� DC
			sourX, sourY,		//�����ؿ� left, top
			sourWidth,			//�����ؿ� ����ũ��
			sourHeight,			//�����ؿ� ����ũ��
			_transColor);		//���ܽ�ų ����
	}
	else
	{
		BitBlt(hdc, destX, destY,
			sourWidth,
			sourHeight,
			_imageInfo->hMemDC,
			sourX, sourY, SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
    if (!FrustumCull(destX, destY)) return;

	if (_trans)
	{
		GdiTransparentBlt(
			hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor
		);
	}
	else
	{
		BitBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight, 
			SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
    if (!FrustumCull(destX, destY)) return;

	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		GdiTransparentBlt(
			hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			currentFrameX * _imageInfo->frameWidth,
			currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor
		);
	}
	else
	{
		BitBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			currentFrameX * _imageInfo->frameWidth,
			currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//���� �̹����� ���ĺ��带 ��������ִ� �Լ�
	_blendFunc.SourceConstantAlpha = alpha;

	//����Ÿ ����ó�� ���ܽ�ų ������ �ִٸ�
	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, _imageInfo->x, _imageInfo->y, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}


void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
    if (!FrustumCull(destX, destY)) return;

	//���� �̹����� ���ĺ��带 ��������ִ� �Լ�
	_blendFunc.SourceConstantAlpha = alpha;

	//����Ÿ ����ó�� ���ܽ�ų ������ �ִٸ�
	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}


void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
    _blendFunc.SourceConstantAlpha = alpha;

    if (_trans)
    {
        BitBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,
            hdc, destX, destY, SRCCOPY);

        GdiTransparentBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,
            _imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

        AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
            _blendImage->hMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
    }
    else
    {
        AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
            _imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _blendFunc);
    }
}

void image::alphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha)
{
    if (!FrustumCull(destX, destY)) return;

    //���� �̹����� ���ĺ��带 ��������ִ� �Լ�
    _blendFunc.SourceConstantAlpha = alpha;

    //����Ÿ ����ó�� ���ܽ�ų ������ �ִٸ�
    if (_trans)
    {
        BitBlt(_blendImage->hMemDC, 0, 0,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            hdc, destX, destY, SRCCOPY);

        GdiTransparentBlt(_blendImage->hMemDC, 0, 0,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            _imageInfo->currentFrameX * _imageInfo->frameWidth,
            _imageInfo->currentFrameY * _imageInfo->frameHeight,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            _transColor);

        AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
            _blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
    }
    else
    {
        AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            _imageInfo->currentFrameX * _imageInfo->frameWidth,
            _imageInfo->currentFrameY * _imageInfo->frameHeight,
            _imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
    }
}

void image::alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha)
{
    if (!FrustumCull(destX, destY)) return;

    //���� �̹����� ���ĺ��带 ��������ִ� �Լ�
    _blendFunc.SourceConstantAlpha = alpha;
    _imageInfo->currentFrameX = currentFrameX;
    _imageInfo->currentFrameY = currentFrameY;

    //����Ÿ ����ó�� ���ܽ�ų ������ �ִٸ�
    if (_trans)
    {
        BitBlt(_blendImage->hMemDC, 0, 0,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            hdc, destX, destY, SRCCOPY);

        GdiTransparentBlt(_blendImage->hMemDC, 0, 0,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            currentFrameX * _imageInfo->frameWidth,
            currentFrameY * _imageInfo->frameHeight,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            _transColor);

        AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
            _blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
    }
    else
    {
        AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            currentFrameX * _imageInfo->frameWidth,
            currentFrameY * _imageInfo->frameHeight,
            _imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
    }
}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	//���̳ʽ� ���� ���� ����
	if (offSetX < 0) offSetX = _imageInfo->width + (offSetX % _imageInfo->width);
	if (offSetY < 0) offSetY = _imageInfo->height + (offSetY % _imageInfo->height);

	int sourWidth;	//�����ؿ� ����ũ��
	int sourHeight;	//�����ؿ� ����ũ��

	RECT rcDest;
	RECT rcSour;

	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawAreaX;
	int drawAreaH = drawArea->bottom - drawAreaY;

	//y����� 
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{

		rcSour.top = (y + offSetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;

		//ȭ������� �������� ����������ŭ Ȯ�����ش�
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//���� ������ �׷��� ��ġ ���
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + offSetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			//���� ���� ����
			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;


			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}
	}
}

void image::aniRender(HDC hdc, int destX, int destY, animation * ani)
{
    if (!FrustumCull(destX, destY)) return;

	//������ ��ġ�� �°� �̹����� �ѷ��ش�
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}

void image::alphaAniRender(HDC hdc, int destX, int destY, animation * ani, BYTE alpha)
{
    if (!FrustumCull(destX, destY)) return;

    //������ ��ġ�� �°� �̹����� �ѷ��ش�
    alphaRender(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight(), alpha);
}

bool image::FrustumCull(int destX, int destY)
{
    if (_imageInfo->maxFrameX > 0 || _imageInfo->maxFrameY > 0)
    {
        if (destX <= CAMERA->GetRC().right &&
            destX + _imageInfo->frameWidth >= CAMERA->GetRC().left &&
            destY <= CAMERA->GetRC().bottom &&
            destY + _imageInfo->frameHeight >= CAMERA->GetRC().top)
        {
            return true;
        }
    }
    else if (_imageInfo->maxFrameX == 0 && _imageInfo->maxFrameY == 0)
    {
        if (destX <= CAMERA->GetRC().right &&
            destX + _imageInfo->width >= CAMERA->GetRC().left &&
            destY <= CAMERA->GetRC().bottom &&
            destY + _imageInfo->height >= CAMERA->GetRC().top)
        {
            return true;
        }
    }

    return false;
}
