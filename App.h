#pragma once
#include < Windows.h >  // 添加头文件
#include < string >

int MsgWait();          // 定义全局的消息循环函数

class CApp
{
public:
	CApp();
	~CApp();

public:
	friend LRESULT CALLBACK MyProcFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam); // 声明友元函数
	int Regis(std::string className, WNDPROC func = MyProcFunc);
	int Create(std::string title); // func为回调函数

protected:
	virtual int AllMsgHandle(int msg, WPARAM, LPARAM) = 0;

protected:
	HWND m_hwnd;
};
