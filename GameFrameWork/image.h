#pragma once
#include "animation.h"
//======================================
// ## 18.02.27 ## - image Class - ##
//======================================

class image
{
public:
	//�̹����� �ε�Ǵ� Ÿ��
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//���ҽ��κ��� 
		LOAD_FILE,			//���Ϸκ���
		LOAD_EMPTY,			//�� ��Ʈ���� ����
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD		resID;		//���ҽ� �ҷ��ö� �������� �ѹ�
		HDC			hMemDC;		//�޸� DC
		HBITMAP		hBit;		//��Ʈ��
		HBITMAP		hOBit;
		float		x;			//�̹����� x��ǥ(left)
		float		y;			//�̹����� y��ǥ(top)
		int			width;
		int			height;

		int			currentFrameX;	//���� ������ ��ȣ X
		int			currentFrameY;	//���� ������ ��ȣ Y
		int			maxFrameX;		//�ִ� ������ ��ȣ X
		int			maxFrameY;		//�ִ� ������ ��ȣ Y
		int			frameWidth;		//������ ����ũ��
		int			frameHeight;	//������ ����ũ��
		BYTE		loadType;
		RECT		boundingBox;	//�浹üũ �� �ڽ�

		tagImageInfo()
		{
			resID			= 0;
			hMemDC			= NULL;
			hBit			= NULL;
			hOBit			= NULL;
			x				= 0;
			y				= 0;
			width			= 0;
			height			= 0;
			currentFrameX	= 0;
			currentFrameY	= 0;
			maxFrameX		= 0;
			maxFrameY		= 0;
			frameWidth		= 0;
			frameHeight		= 0;
			loadType		= LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;		//�̹��� ���� ����ü
	CHAR*			_fileName;		//���Ϸκ��� �ε��ؿö� ���� �̸� ����
	BOOL			_trans;			//Ư���÷��� ���ܽ�ų����
	COLORREF		_transColor;	//Ư���÷� ���� �����

	BLENDFUNCTION	_blendFunc;		//���ĺ��� �Լ�
	LPIMAGE_INFO	_blendImage;	//���ĺ��� �̹���

public:
	image();
	~image();

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE, bool alpha = false);
	HRESULT init(const char* fileName, float x, float y,
		int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE, bool alpha = false);

	//�̹��� �ʱ�ȭ(�̹��� �̸�, �����ǥ, ����ũ��, ������ ��������)
	HRESULT init(const char* fileName, float x, float y,
		int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE, bool alpha = false);

	HRESULT init(const char* fileName, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE, bool alpha = false);

	//�޸� ���� �Լ�
	void release(void);

	//������ �÷��� ������ �Ǿ���Ѵٸ� ����� �Լ�
	void setTransColor(BOOL trans, COLORREF transColor);

	void render(HDC hdc);
	//������ �Լ� �Ѹ�DC, left, top ��ǥ
	void render(HDC hdc, int destX, int destY);

	//������ �Լ� �Ѹ�DC, �ѷ���X,Y, �����ؿ�X(left),Y(top),Width,Height
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	
    void alphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha);
    void alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

	void loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);
	
	void aniRender(HDC hdc, int destX, int destY, animation* ani);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	//�̹��� ������ �����ϱ� ���� Getter, Setter

	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX() { return _imageInfo->x; }

	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY() { return _imageInfo->y; }

	// �̹����� ������ǥ�� ��������
	inline void setCenter(float x, float y)
	{
		//�������̹����ϋ��� �׳� �����̹����϶� �����༭
		//�и��غ��ÿ�

		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float getCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ? _imageInfo->x + (_imageInfo->width / 2) : _imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float getCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ? _imageInfo->y + (_imageInfo->height / 2) : _imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	//�浹üũ�� �ٿ���ڽ�
	inline RECT boundingBox()
	{
		//������ �Ը��� �°� ¥������
		RECT rc = { _imageInfo->x,
					_imageInfo->y,
					_imageInfo->x + _imageInfo->frameWidth,
					_imageInfo->y + _imageInfo->frameHeight };

		return rc;
	}

	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX) _imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY) _imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline int getFrameY() { return _imageInfo->currentFrameY; }

	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight; }
};

