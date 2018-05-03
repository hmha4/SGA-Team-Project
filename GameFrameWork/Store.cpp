#include "stdafx.h"
#include "Store.h"


Store::Store()
{
}


Store::~Store()
{
}

HRESULT Store::init()
{
	IMAGEMANAGER->addImage("storeBackgroundCol", "storeBackgroundCol.bmp", 1200, 500, false, RGB(0, 0, 0));

	CAMERA->SetPos(WINSIZEX / 2, WINSIZEY / 2);

	_pm = new PlayerManager;
	_pm->init();

	for (int i = 0; i < 4; i++)
	{
		_rc[i] = RectMake((WINSIZEX / 2 - 270) + 120 * i, WINSIZEY / 2 + 50, 10, 10);
	}

	_hotsauce = new HotSauce;
	_hotsauce->init(CAMERA->GetCenterX() - 280, CAMERA->GetCenterY() - 100);


	_potion = new PotionItem;
	_potion->init(CAMERA->GetCenterX() + 90, CAMERA->GetCenterY() - 100);

	_starPoint = new StarPoint;
	_starPoint->init(CAMERA->GetCenterX() - 30, CAMERA->GetCenterY() - 100);

	_sword = new Sword;
	_sword->init(CAMERA->GetCenterX() - 170, CAMERA->GetCenterY() - 100);

	_NPC = new StoreNPC;
	_NPC->init(CAMERA->GetCenterX() + 200, CAMERA->GetCenterY());

	_btn = new PurchaseBtn;
	_btn->init(CAMERA->GetCenterX() - 260, CAMERA->GetCenterY() + 100);

	_btn2 = new PurchaseBtn;
	_btn2->init(CAMERA->GetCenterX() + 80, CAMERA->GetCenterY() + 100);

	_btn3 = new PurchaseBtn;
	_btn3->init(CAMERA->GetCenterX() - 30, CAMERA->GetCenterY() + 100);

	_btn4 = new PurchaseBtn;
	_btn4->init(CAMERA->GetCenterX() - 150, CAMERA->GetCenterY() + 100);

	return S_OK;
}

void Store::update()
{
	_pm->GetPlayer()->GroundCollision("storeBackgroundCol");
	_pm->update();
	CAMERA->update(WINSIZEX / 2, WINSIZEY / 2, 3, false);



	_btn->update();
	_btn2->update();
	_btn3->update();
	_btn4->update();

	checkCollision();

	_NPC->update();


}

void Store::release()
{
	SAFE_DELETE(_hotsauce);
	SAFE_DELETE(_potion);
	SAFE_DELETE(_starPoint);
	SAFE_DELETE(_sword);
	SAFE_DELETE(_pm);
	SAFE_DELETE(_btn);
	SAFE_DELETE(_btn2);
	SAFE_DELETE(_btn3);
	SAFE_DELETE(_btn4);
	SAFE_DELETE(_NPC);
}

void Store::render()
{
	//img->render(getMemDC(), 0, 0);
	_pm->render();

	_hotsauce->render(_hotsauce->getX(), _hotsauce->getY());
	FontFunction(255, 0, 0, "hotsauce", CAMERA->GetCenterX() - 470, CAMERA->GetCenterY() - 160);

	_potion->render(_potion->getX(), _potion->getY());
	FontFunction(255, 0, 0, "potion", CAMERA->GetCenterX() - 105, CAMERA->GetCenterY() - 160);

	_starPoint->render(_starPoint->getX(), _starPoint->getY());
	FontFunction(255, 0, 0, "star", CAMERA->GetCenterX() - 235, CAMERA->GetCenterY() - 160);

	_sword->render(_sword->getX(), _sword->getY());
	FontFunction(255, 0, 0, "sword", CAMERA->GetCenterX() - 350, CAMERA->GetCenterY() - 160);

	_NPC->render(CAMERA->GetCenterX() + 200, CAMERA->GetCenterY());

	_btn->render(_btn->getX(), CAMERA->GetCenterY() + 100);
	_btn2->render(_btn2->getX(), CAMERA->GetCenterY() + 100);
	_btn3->render(_btn3->getX(), CAMERA->GetCenterY() + 100);
	_btn4->render(_btn4->getX(), CAMERA->GetCenterY() + 100);

}

void Store::FontFunction(int r, int g, int b, const char* txt, float rcX, float rcY)
{
	HFONT font, oldFont;
	RECT rcText = RectMake(rcX, rcY, 500, 300);

	font = CreateFont(20, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET,
		OUT_STRING_PRECIS, CLIP_CHARACTER_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_SWISS, TEXT("�ü�ü"));

	oldFont = (HFONT)SelectObject(getMemDC(), font);
	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextAlign(getMemDC(), TA_CENTER);
	DrawText(getMemDC(), TEXT(txt), strlen(txt), &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

	SetTextColor(getMemDC(), RGB(r, g, b));

	SetTextAlign(getMemDC(), TA_TOP);
	SetBkMode(getMemDC(), OPAQUE);

}

void Store::checkCollision()
{
	for (int i = 0; i < 4; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_rc[i], &_pm->GetPlayer()->GetColRC()))
		{
			switch (i)
			{
			case 0:
				_btn->setBool(true);
				_btn2->setBool(false);
				_btn3->setBool(false);
				_btn4->setBool(false);
				break;
			case 1:
				_btn4->setBool(true);
				_btn2->setBool(false);
				_btn->setBool(false);
				_btn3->setBool(false);
				break;
			case 2:
				_btn3->setBool(true);
				_btn->setBool(false);
				_btn2->setBool(false);
				_btn4->setBool(false);
				break;
			case 3:
				_btn2->setBool(true);
				_btn4->setBool(false);
				_btn->setBool(false);
				_btn3->setBool(false);
				break;
			}

		}
	}
}

PurchaseBtn * Store::getBtn(int i)
{
	PurchaseBtn* btn;
	switch (i)
	{
	case 1:
		btn = _btn;
		break;
	case 2:
		btn = _btn2;
		break;
	case 3:
		btn = _btn3;
		break;
	case 4:
		btn = _btn4;
		break;
	}
	return btn;
}
