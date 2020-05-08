#include "App.h" // 添加类的头文件

class CMyApp : public CApp
{
protected:
	virtual int AllMsgHandle(int msg, WPARAM, LPARAM)
	{
		HDC hdc;
		PAINTSTRUCT ps;
		switch (msg)
		{
		case WM_PAINT:
			hdc = BeginPaint(m_hwnd, &ps);
			Rectangle(hdc, 20, 20, 200, 200);
			EndPaint(m_hwnd, &ps);
			return TRUE;
			break;
		}
		return FALSE;
	}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd)
{
	CMyApp app;

	// 创建窗口成功
	if (app.Regis("Demo") && app.Create("Demo")){
		return MsgWait(); // 进入消息循环
	}
	return 0;
}
