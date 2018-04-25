#pragma once
#include "singletonBase.h"
#include <time.h>

class randomFunction : public singletonBase < randomFunction >
{
public:

	//������
	randomFunction()
	{
		//TickCount == 0.001 
		srand(GetTickCount());
	}
	//�Ҹ���
	~randomFunction()
	{

	}

	//============== ������ ���� =================

	//������ ���� ���� ������ ������ �߻� 
	inline int getInt(int num) { return rand() % num; }

	//Ư�� ���� �������� ������ �̾ƿ��� ������
	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum) + fromNum;
	}

	//=============== �Ǽ��� ���� ====================
	inline float getFloat(float num)
	{
		return (float)rand() / (float)num;
	}

	// from ~ to
	//4. 65535

	inline float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toNum - fromNum) + fromNum);
	}


};
