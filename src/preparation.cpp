#include "preparation.h"
#include "global.h"

void get_pvz_handle()
{
    g_pvz_hwnd = FindWindowW(NULL, L"Plants vs. Zombies"); //获得窗口句柄,字符串前加上L表示wchar,null表示在所有类型中选择,unicode字符集使用findwindoww
    // HWND g_pvz_hwnd = FindWindowW(NULL, L"Plants vs. Zombies 1.2.0.1073 RELEASE");
    // HWND g_pvz_hwnd = FindWindowW(NULL, L"植物大战僵尸中文版");
    DWORD dw_pvz_pid = 0;
    GetWindowThreadProcessId(g_pvz_hwnd, &dw_pvz_pid);                 //获得进程号
    g_pvz_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dw_pvz_pid); //打开进程,PROCESS_ALL_ACCESS给予进程所有可能权限,false表示所得进程句柄不可被继承
}

void get_DPI()
{
    RECT pvz_rect;
    GetClientRect(g_pvz_hwnd, &pvz_rect);
    g_DPI = (1.0 * 800) / (pvz_rect.right - pvz_rect.left);
}