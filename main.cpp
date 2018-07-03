#include <thread>
#include <fstream>
#include <string>
#include <iostream>
#include <ostream>
#include <windows.h>
#include <time.h>
#include <thread>

using namespace std;

void sleep(long d)
{
    clock_t start=clock();
    while(clock() - start < d); ///loop until time's up
}

void task1()
{
    HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	int w = 1920;
	int h = 1080;
    for(int i = 0; i < 200; i++)
    {
        StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);
    }
}


int main (int argc, char ** argv) {
    thread stuff = thread(task1);
    HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	int w = 1920;
	int h = 1080;
	for(int v = 0; v < 200; v++)
    {
        sleep(400);
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
    }
}

