#pragma once
#include "singletonBase.h"

class CameraManager : public singletonBase<CameraManager>
{
private:
    enum STATE
    {
        MOVE,       //�̻��� ���󰡴� ��
        FOLLOW,     //ĳ���� ���󰡴� ��
        CONTROL
    };

    float offSetX2;     //������� x��ǥ
    float offSetY2;     //������� y��ǥ
    RECT _cameraRC;     //ī�޶� �����̰� �Ǵ� ����
    RECT _cameraTotalRC;
    float _x, _y;       //ī�޶��� ����
    bool _forOnce;
    float _cameraSpeed; //ī�޷� �ӵ�
    float _controlSpeed;

    STATE _state;

    int backgroundSizeX;    //���� ����� X ũ��
    int backgroundSizeY;    //���� ����� Y ũ��

    const char * imageName;


    float dist;
public:
    CameraManager();
    ~CameraManager();

    HRESULT init(const char * name);
    void release();
    //void Update(���� ���� x, ���� ���� y, ī�޶� �ӵ�, ĳ���� ���� �ƴ���);
    void update(float x, float y, float speed, bool isPlayer = false);
    void render(HDC hdc);

    //ī�޶��� x(left), y(top)��ǥ(�����ƴ�)
    //ī�޶� ������ �ִ°� �ƴ϶� ����ۿ� �׷��� �׸��� �̵���Ű�� 
    //���̱� ������ ������ ��Ÿ���� ���� ��밡��
    inline float GetX() { return -offSetX2; }
    inline float GetY() { return -offSetY2; }
    inline float GetCenterX() { return _x; }
    inline float GetCenterY() { return _y; }
    inline RECT GetRC() { return _cameraTotalRC; }
    inline STATE GetState() { return _state; }

    void SetState(const char * state);
    void SetPos(float x, float y);
    void SetSize(int sizeX, int sizeY);
};