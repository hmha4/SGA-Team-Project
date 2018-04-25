#include "stdafx.h"
#include "timer.h"
#include <mmsystem.h>	//timeGetTime() �� ����� �� �ִ�

#pragma comment(lib, "winmm.lib")

timer::timer()
{
}


timer::~timer()
{
}

HRESULT timer::init()
{
	//IRC
	if (QueryPerformanceFrequency((LARGE_INTEGER*)& _periodFrequency))
	{
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)& _lastTime);

		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{
		_isHardware = false;

		_lastTime = timeGetTime();	//������ �и��������� ����
		_timeScale = 0.001f;
	}

	_frameRate = 0;
	_FPSFrameRate = 0;
	_FPSTimeElapsed = 0;
	_worldTime = 0;

	return S_OK;
}

void timer::tick(float lockFPS)
{
	if (_isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		_curTime = timeGetTime();
	}

	//�ð� ������� �̴´�
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	//FPS�� ���س��ٸ�
	if (lockFPS > 0.0f)
	{
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	//����ð��� ����
	_lastTime = _curTime;

	//�������� ����
	_FPSFrameRate++;
	_FPSTimeElapsed += _timeElapsed;

	_worldTime += _timeElapsed;

	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameRate;
		_FPSFrameRate = 0;
		_FPSTimeElapsed = 0.0f;
	}
}

unsigned long timer::getFrameRate(char* str) const
{
	if (str != NULL)
	{
		wsprintf(str, "FPS : %d", _frameRate);
	}

	return _frameRate;
}
