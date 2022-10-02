#include "global.h"
#include "lib.h"
void left_click(int x, int y)
{
    x /= g_DPI;
    y /= g_DPI;
    int position = MAKELPARAM(x, y);
    PostMessage(g_pvz_hwnd, WM_LBUTTONDOWN, 0, position);
    PostMessage(g_pvz_hwnd, WM_LBUTTONUP, 0, position);
}