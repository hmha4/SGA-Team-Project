#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("�հ�����", "hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("�ް�����", "hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));


	_width = _progressBarTop->getWidth();
	
	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update() 
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarTop->getHeight());
}

void progressBar::render() 
{
	IMAGEMANAGER->render("�ް�����", 
		getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 
		0, 0,
		_progressBarBottom->getWidth(), 
		_progressBarBottom->getHeight());

	IMAGEMANAGER->render("�հ�����", getMemDC(),
		_rcProgress.left + _progressBarTop->getWidth() / 2,
		_y + _progressBarTop->getHeight() / 2,
		0, 0,
		_width, 
		_progressBarTop->getHeight());

}


void progressBar::setGauge(float currentGauge, float maxGauge)
{
	//����� ������
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}
