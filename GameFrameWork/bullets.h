#pragma once
#include "gameNode.h"
#include <vector>		//�̰� ��ﳪ�� �����ο��

struct tagBullet
{
	image* bulletImage;		//�Ѿ� �̹���
	RECT rc;				//�Ѿ� �浹�ڽ�
	float x, y;				//�Ѿ� ��ǥ
	float angle;			//�Ѿ� ����
	float speed;
	float radius;			
	float fireX, fireY;		//�Ѿ� �߻���ġ
	bool isFire;			//�߻翩��
	int count;
};

//����(�ʵ�����) ����� �Ѿ�
class bullet : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	bullet();
	~bullet();

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);

	void move();

	void removeBullet(int arrNum);

	//������
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	
};


//�������� �߻��ϴ� �̽���
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
public:
	missile();
	~missile();

	virtual HRESULT init(int bulletMax, float range);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fire(float x, float y);

	void move(void);


};

//�߻��Ҷ� �����ؼ� ��� �̽���
class piccolo : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	piccolo();
	~piccolo();

	HRESULT init(int missileMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();

	void removeMissile(int arrNum);

	//������
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

};