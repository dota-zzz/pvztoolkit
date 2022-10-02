#pragma once
#include "global.h"
#include <initializer_list>
// 读取内存函数
template <typename T, typename... Args>
T ReadMemory(Args... args)
{
    extern HANDLE g_pvz_handle;
    std::initializer_list<uintptr_t> lst = {static_cast<uintptr_t>(args)...};
    uintptr_t buff = 0;
    T result = T();
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        buff &= 0xffffffff;
        if (it != lst.end() - 1)
        {
            ReadProcessMemory(g_pvz_handle, (const void *)(buff + *it), &buff, sizeof(buff), nullptr);
        }
        else
        {
            ReadProcessMemory(g_pvz_handle, (const void *)(buff + *it), &result, sizeof(result), nullptr);
        }
    }
    return result;
}
// 改写内存函数
template <typename T, typename... Args>
void WriteMemory(T value, Args... args)
{
    extern HANDLE g_pvz_handle;
    std::initializer_list<uintptr_t> lst = {static_cast<uintptr_t>(args)...};
    uintptr_t buff = 0;
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        buff &= 0xffffffff;
        if (it != lst.end() - 1)
            ReadProcessMemory(g_pvz_handle, (const void *)(buff + *it), &buff, sizeof(buff), nullptr);
        else
            WriteProcessMemory(g_pvz_handle, (void *)(buff + *it), &value, sizeof(value), nullptr);
    }
}
// #include "handle.h"
// #include <initializer_list>
// // 读取内存函数
// template <typename T, typename... Args>
// T ReadMemory(Args... args)
// {
//     extern HANDLE g_pvz_handle;
//     std::initializer_list<uintptr_t> lst = {static_cast<uintptr_t>(args)...};
//     uintptr_t buff = 0;
//     T result = T();
//     for (auto it = lst.begin(); it != lst.end(); ++it)
//     {
//         if (it != lst.end() - 1)
//             ReadProcessMemory(g_pvz_handle, (const void *)(buff + *it), &buff, sizeof(buff), nullptr);
//         else
//             ReadProcessMemory(g_pvz_handle, (const void *)(buff + *it), &result, sizeof(result), nullptr);
//     }
//     return result;
// }
// // 改写内存函数
// template <typename T, typename... Args>
// void WriteMemory(T value, Args... args)
// {
//     extern HANDLE g_pvz_handle;
//     std::initializer_list<uintptr_t> lst = {static_cast<uintptr_t>(args)...};
//     uintptr_t buff = 0;
//     for (auto it = lst.begin(); it != lst.end(); it++)
//         if (it != lst.end() - 1)
//             ReadProcessMemory(g_pvz_handle, (const void *)(buff + *it), &buff, sizeof(buff), nullptr);
//         else
//             WriteProcessMemory(g_pvz_handle, (void *)(buff + *it), &value, sizeof(value), nullptr);
// }
