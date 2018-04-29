#pragma once
#include "gameNode.h"
class Player :
    public gameNode
{
private:
    //ĳ���� ����
    enum STATE {
        RIGHT_IDLE, LEFT_IDLE,
        RIGHT_WALK, LEFT_WALK,
        RIGHT_RUN,  LEFT_RUN,
        RIGHT_JUMP, LEFT_JUMP,
        RIGHT_MID,  LEFT_MID,
        RIGHT_FALL, LEFT_FALL,
        RIGHT_LAND, LEFT_LAND,
        RIGHT_LADDER_ON, LEFT_LADDER_ON,
        LADDER_UP, LADDER_DOWN,
        RIGHT_LADDER_OFF, LEFT_LADDER_OFF,
        RIGHT_DUCK, LEFT_DUCK,
        RIGHT_DUCK_KICK, LEFT_DUCK_KICK,
        RIGHT_ATTACK_1, LEFT_ATTACK_1,
        RIGHT_ATTACK_2, LEFT_ATTACK_2,
        RIGHT_ATTACK_3, LEFT_ATTACK_3,
        RIGHT_JUMP_ATTACK, LEFT_JUMP_ATTACK
    };
    //ĳ���� ����
    enum DIRECTION {
        LEFT, RIGHT
    };

    image * _img;           //�̹���
    animation * _anim;      //�ִϸ��̼�

    RECT _rc;               //RECT
    float _x, _y;           //����
    float _speed;           //�ӵ�
    float _friction;        //����
    float _jumpPower;       //���� �Ŀ�
    float _gravity;         //�߷�
    bool _onLadder;         //��ٸ�
    bool _onGround;         //

    DIRECTION _direction;   //����
    STATE _state;           //����

    int _probeX;            //X Ž�� ��
    int _probeY;            //Y Ž�� ��
public:
    Player();
    ~Player();

    HRESULT init();
    void release();
    void update();
    void render();

    //�ִϸ��̼� ����
    void ChangeAnim(STATE state, string animKeyName);
    //���� ���� �Լ�
    void Friction(string direction, float maxSpeed);
    //�����浹
    void GroundCollision();
};

