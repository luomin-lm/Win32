#include "App.h" // ������ͷ�ļ�

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

	// �������ڳɹ�
	if (app.Regis("Demo") && app.Create("Demo")){
		return MsgWait(); // ������Ϣѭ��
	}
	return 0;
}
