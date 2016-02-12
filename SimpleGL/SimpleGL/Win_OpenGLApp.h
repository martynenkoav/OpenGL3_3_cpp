#pragma once

#include "openGLControl.h"

// ����� ����������
class COpenGLWinApp
{
public:
	HWND hWnd; // ��������� ����
	COpenGLControl oglControl; // ����� OpenGL ���������

	void ResetTimer();
	void UpdateTimer();
	float sof(float fVal);

	bool InitializeApp(string a_sAppName);
	void RegisterAppClass(HINSTANCE hAppInstance);
	bool CreateAppWindow(string sTitle);
	
	void AppBody();
	void Shutdown();

	HINSTANCE GetInstance();

	LRESULT CALLBACK MsgHandlerMain(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

private:
	HINSTANCE hInstance; // ��������� ����������
	string sAppName;
	HANDLE hMutex;

	bool bAppActive; // ��� ��������, ������� �� ����������
	DWORD dwLastFrame;
	float fFrameInterval;
};

namespace Keys
{
	int Key(int iKey);
	int Onekey(int iKey);
	extern char kp[256];
}

extern COpenGLWinApp appMain;

void InitScene(LPVOID), RenderScene(LPVOID), ReleaseScene(LPVOID);