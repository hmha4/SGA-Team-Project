#include "stdafx.h"
#include "saveLoadTest.h"


saveLoadTest::saveLoadTest()
{
}


saveLoadTest::~saveLoadTest()
{
}

void saveLoadTest::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) save();
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) load();
}

void saveLoadTest::save()
{
	//���� �����
	// C - FILE*
	// C++ - ifstream, ofstream
	// WIN32 - CreateFile()

	HANDLE file;
	DWORD write;

	char str[128] = "�ϾƾƾǼҿ��� �����������ʰڴ�";

	file = CreateFile("�볪�ǹݶ�����.txt", GENERIC_WRITE, FALSE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}

void saveLoadTest::load()
{
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("�볪�ǹݶ�����.txt", GENERIC_READ, FALSE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);

	MessageBox(_hWnd, str, "���ð��Ӻ�����!¥��!", MB_OK);
}
