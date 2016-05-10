#include "childwindow.h"

#ifndef _mainwindow_h_
#define _mainwindow_h_

class MainWindow
{

public:
    MainWindow(); // �⺻ ������.
    MainWindow(HINSTANCE hInstance,LPSTR lpszClassName,const int menu); // ���μ����� �ڵ�, ����� �������� Ŭ�����̸�, �޴��� �ڵ� �����ϴ� ������.
    void show_window(const int x,const int y,const int w,const int h); // �����츦 ���� �Լ�. x,y��ǥ�� w,h�� ���ڷ� �޴´�.
    void set_child_window(OPENFILENAME OFN);  // OPENFILENAME�� ���� childWindow�ν��Ͻ��� ����� �����Ͱ� �� �ν��Ͻ��� ����Ű���� ���ش�.
    void set_button_stat(int);
    int get_button_stat();
    int is_pressed[300];
    HWND get_handle(); // �������� �ڵ��� ��ȯ
    ChildWindow* get_child_window(); // child�����͸� ��ȯ


private:
    HINSTANCE hinst; // ���μ����� �ڵ�
    WNDCLASS win; // window ����ü
    HWND hwnd;    // window�� �����Ǹ�, �ڵ��� ���⿡ �����Ѵ�.
    ChildWindow *child; // childwindow�� ����Ű�� ������.
    int button_stat;
};

#endif