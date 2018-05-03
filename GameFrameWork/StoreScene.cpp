#include "stdafx.h"
#include "StoreScene.h"
#include "Store.h"


StoreScene::StoreScene()
{
}


StoreScene::~StoreScene()
{
}

HRESULT StoreScene::init()
{
	IMAGEMANAGER->addImage("storeBackground", "storeBackground.bmp", 600, 500, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("speechBalloon", "speechBalloon.bmp", 480, 60, true, RGB(255, 0, 255));
	_speechBalloon = IMAGEMANAGER->findImage("speechBalloon");

	_store = new Store;
	_store->init();

	_isSpeech = true;
	_state = WELCOME;

	_speechCnt = 0;

	return S_OK;
}

void StoreScene::update()
{
	if (_isSpeech)
	{
		_speechCnt++;
		if (_speechCnt % 400 == 0) { _isSpeech = false;  _speechCnt = 0; }
	}

	if (_store->getBtn(1)->getIsClicked() ||
		_store->getBtn(2)->getIsClicked() ||
		_store->getBtn(3)->getIsClicked() ||
		_store->getBtn(4)->getIsClicked())
	{
		_state = THANKS;
		_isSpeech = true;

	}

	_store->update();
}

void StoreScene::release()
{
	_store->release();
}

void StoreScene::render()
{
	IMAGEMANAGER->findImage("storeBackground")->render(getMemDC(), CAMERA->GetX(), CAMERA->GetY());
	_store->render();
	if (_isSpeech)
	{
		_speechBalloon->render(getMemDC(), WINSIZEX / 2 - 250, WINSIZEY / 2 + 150);

		switch (_state)
		{
		case WELCOME:
			_store->FontFunction(255, 0, 0, "어서오세요", WINSIZEX / 2 - 200, WINSIZEY / 2 + 30);
			break;
		case THANKS:
			_store->FontFunction(255, 0, 0, "감사합니다.", WINSIZEX / 2 - 200, WINSIZEY / 2 + 20);
			break;
		case DISCARCE:
			_store->FontFunction(255, 0, 0, "코인이 부족합니다", WINSIZEX / 2 - 200, WINSIZEY / 2 + 20);
			break;
		}
	}

}
