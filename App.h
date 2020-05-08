#pragma once
#include < Windows.h >  // ���ͷ�ļ�
#include < string >

int MsgWait();          // ����ȫ�ֵ���Ϣѭ������

class CApp
{
public:
	CApp();
	~CApp();

public:
	friend LRESULT CALLBACK MyProcFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam); // ������Ԫ����
	int Regis(std::string className, WNDPROC func = MyProcFunc);
	int Create(std::string title); // funcΪ�ص�����

protected:
	virtual int AllMsgHandle(int msg, WPARAM, LPARAM) = 0;

protected:
	HWND m_hwnd;
};
