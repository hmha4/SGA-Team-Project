#pragma once
#include "gameNode.h"
#include <vector>

class Player;

class PlayerUI :
	public gameNode
{
private:
	typedef struct tagInven
	{
		enum TYPE
		{
			STAR,
			POTION,
			DEFFAULT
		};

		int x, y;
		RECT rc;
		int type;
		bool isOnceClicked;

		tagInven() : x(0), y(0), rc({ 0, 0, 0, 0 }), type((int)DEFFAULT), isOnceClicked(false)
		{}
		tagInven(int x, int y)
			: rc(RectMake(x, y, 58, 66)), isOnceClicked(false)
		{
			this->x = x;
			this->y = y;
		}
		tagInven(int x, int y, int type)
			: rc(RectMake(x, y, 58, 66)), type(type), isOnceClicked(false)
		{
			this->x = x;
			this->y = y;
		}
	}Inven;
private:
	int _playerHP;
	bool _weapon;

	bool _isInven;

	Inven _inventory[8][5];
	vector<string> _loadInven;
	vector<int> _vInven;

	bool _isOnceClicked;
public:
	PlayerUI();
	~PlayerUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void SetPlayerInfo(Player * player);
	void SetInventoryVector(int type);

	void InitInvenPos();
	void DrawInventory();

	void UpdateInven();
};

