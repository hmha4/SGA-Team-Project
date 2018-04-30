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
        RIGHT_RUN, LEFT_RUN,
        RIGHT_JUMP, LEFT_JUMP,
        RIGHT_MID, LEFT_MID,
        RIGHT_FALL, LEFT_FALL,
        RIGHT_LAND, LEFT_LAND,
        RIGHT_LADDER_ON, LEFT_LADDER_ON,
        LADDER_UP, LADDER_DOWN,
        RIGHT_LADDER_OFF, LEFT_LADDER_OFF,
        RIGHT_DUCK, LEFT_DUCK,
        RIGHT_DUCK_KICK, LEFT_DUCK_KICK,
        RIGHT_DUCK_SLIDE, LEFT_DUCK_SLIDE,
        RIGHT_PUNCH_1, LEFT_PUNCH_1,
        RIGHT_PUNCH_2, LEFT_PUNCH_2,
        RIGHT_PUNCH_3, LEFT_PUNCH_3,
        RIGHT_JUMP_PUNCH, LEFT_JUMP_PUNCH,
        RIGHT_JAKE_PUNCH, LEFT_JAKE_PUNCH,
        RIGHT_SWORD_1, LEFT_SWORD_1,
        RIGHT_SWORD_2, LEFT_SWORD_2,
        RIGHT_JUMP_SWORD, LEFT_JUMP_SWORD,
        RIGHT_DUCK_SWORD, LEFT_DUCK_SWORD
    };
    //ĳ���� ����
    enum DIRECTION {
        LEFT, RIGHT
    };

    enum ITEM {
        DEFFAULT,
        SWORD,
        FLAMESWORD
    };

    image * _img;           //�̹���
    animation * _anim;      //�ִϸ��̼�

    RECT _rc;               //RECT
    RECT _colRC;
    float _x, _y;           //����
    float _colX, _colY;
    float _speed;           //�ӵ�
    float _friction;        //����
    float _jumpPower;       //���� �Ŀ�
    float _gravity;         //�߷�
    bool _onLadder;         //��ٸ�
    bool _onGround;         //

    DIRECTION _direction;   //ĳ���� ����
    STATE _state;           //ĳ���� ����
    ITEM _item;             //������ ����

    int _probeX;            //X Ž�� ��
    int _probeY;            //Y Ž�� ��

    bool _isCombo;
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

