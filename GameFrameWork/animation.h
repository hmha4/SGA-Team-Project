#pragma once
#include <vector>

//void* - ���̵� ������
//�ֺ���� ����Ų�� -> (�ڷ����� ���ֹ����ʰ� ����ų������)
//���̵������ʹ� ���Ը��ϸ� �����̵� ����ų �� �ְ�
//��ſ� ĳ����(����ȯ)�� ��! �����ϰ� ����ؾ��Ѵ�

typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);


class animation
{
public:
	typedef vector<POINT>	vFrameList;
	typedef vector<int>		vPlayList;

	//�ۺ����� ������ ������ ������ �����Ӱ� �ϱ�����

private:
	int				_frameNum;		//������ �� ��
	vFrameList		_frameList;		//������ ����Ʈ
	vPlayList		_playList;		//�÷���(�ִϸ��̼�) ����Ʈ

	int				_frameWidth;	//������ ����ũ��
	int				_frameHeight;	//������ ����ũ��
		
	BOOL			_loop;			//���� ����

	float			_frameUpdateSec;
	float			_elapsedSec;

	DWORD			_nowPlayIndex;
	BOOL			_play;

	void*						_obj;						//����
	CALLBACK_FUNCTION			_callbackFunction;			//�ݹ�
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;	//������
	

public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release();

	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setFPS(int framePerSec);

	void frameUpdate(float elpasedTime);

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay() { return _play; }
	inline POINT getFramePos() { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth() { return _frameWidth; }
	inline int getFrameHeight() { return _frameHeight; }
};

