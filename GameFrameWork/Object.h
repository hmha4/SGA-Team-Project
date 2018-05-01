#pragma once
#include "gameNode.h"
class Object :
    public gameNode
{
protected:
    image * _img;           //�̹���

    string _imgName;        //�̹��� �̸�

    float _x, _y;           //��ǥ
    RECT _rc;               //RECT

    bool _inUse;            //���������
    bool _isCollided;       //�浹����

    int _frameX;
    float _frameCount;
public:
    Object();
    ~Object();

    virtual HRESULT init(float x, float y);
    virtual void release();
    virtual void update();
    virtual void render();

    bool Animate();
    void Collision(RECT rc);
    inline bool GetInUse() { return _inUse; }
};

