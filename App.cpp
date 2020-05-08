#include "App.h"
#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600
#define WINDOW_TITLE	L"TDemo"
#define CLASS_NAME		L"CDemo"
int MsgWait()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

#define IDC_EDIT_APP_PTR	(0x0400 - 2)

LRESULT CALLBACK MyProcFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	CApp* pApp = (CApp*)GetDlgItemInt(hwnd, IDC_EDIT_APP_PTR, NULL, FALSE);

	if (pApp != NULL){
		// FALSE 代表子类没有处理该消息
		if (FALSE == pApp->AllMsgHandle(message, wParam, lParam)){
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		return 0;
	}
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_INITDIALOG:
		break;

	case WM_CREATE:
		pApp = (CApp*)((CREATESTRUCT*)lParam)->lpCreateParams;
		CreateWindow(TEXT("EDIT"), TEXT("0"), WS_CHILD | ES_PASSWORD, 0, 0, 10, 10, 
			hwnd, (HMENU)IDC_EDIT_APP_PTR, GetModuleHandle(0), NULL);
		SetDlgItemInt(hwnd, IDC_EDIT_APP_PTR, (UINT)pApp, FALSE);
		pApp->AllMsgHandle(message, wParam, lParam);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

CApp::CApp()
{
}
CApp::~CApp()
{
}
int CApp::Regis(std::string className, WNDPROC func)
{
	WNDCLASS windclass = { 0 };
	windclass.style = CS_HREDRAW | CS_VREDRAW;
	windclass.lpfnWndProc = func;
	windclass.cbClsExtra = 0;
	windclass.cbWndExtra = 0;
	windclass.hIcon = NULL;
	windclass.hCursor = LoadCursor(NULL, IDC_HAND);
	windclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windclass.lpszMenuName = NULL;
	windclass.lpszClassName = CLASS_NAME;
	windclass.hInstance = GetModuleHandle(0);

	if (!RegisterClass(&windclass))
		return 0; // 注册失败

	return 1;
}
int CApp::Create(std::string title)
{
	m_hwnd = CreateWindow(CLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, GetModuleHandle(0), this);
	if (NULL == m_hwnd){
		return 0;
	}

	// 四、显示 更新
	MoveWindow(m_hwnd, 400, 200, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	ShowWindow(m_hwnd, SW_NORMAL);
	UpdateWindow(m_hwnd);

	return 1;
}


