#include "childwindow.h"
#include "header.h"
#include<windows.h>
#include<stdio.h>

using namespace std;
ChildWindow::ChildWindow(OPENFILENAME _OFN)
{
    OFN=_OFN;
    set_window();
    //�Ľ��ؼ� �������� �����ϴ� �Լ� ȣ�� �ؾߵǴ� �κ�
}
LRESULT CALLBACK ChildWndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
    switch(iMessage)
    {
    //WM_CREATE: opengl ���÷��� �߰�
    case WM_PAINT:
        InvalidateRect(hWnd,NULL,true);
        return 0;
    }
    return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}
OPENFILENAME* ChildWindow::get_openfilename()
{
    return &OFN;
}
void ChildWindow::set_window()
{
    win.cbClsExtra=0;
    win.cbWndExtra=0;
    win.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
    win.hCursor=LoadCursor(NULL,IDC_ARROW);
    win.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    win.hInstance=g_hInst;
    win.lpfnWndProc=(WNDPROC)ChildWndProc;
    win.lpszMenuName=MAKEINTRESOURCE(NULL);
    win.lpszClassName="Child";
    win.style=CS_HREDRAW|CS_VREDRAW;
    RegisterClass(&win);
    CreateWindowEx(0,"Child","Child",WS_CHILD|WS_VISIBLE|WS_SYSMENU|WS_CAPTION|WS_THICKFRAME,10,30,700,500,window_main.get_handle(),(HMENU)NULL,g_hInst,NULL);
}
