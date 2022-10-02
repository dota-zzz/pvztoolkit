#include "function.h"
#include "preparation.h"
#include "lib.h"

bool Function::is_zombie_weak = false;
bool Function::is_auto_pick = false;

Function::Function()
{
    get_pvz_handle();
    get_DPI();
    checkpoint_address = 0xffffffff & ReadMemory<uintptr_t>(base_address, fir_checkpoint_offset);
    zombie_obiect_sequence_address = 0xffffffff & ReadMemory<uintptr_t>(checkpoint_address + sec_zombie_object_sequence_offsec);
    sunshine_num_address = checkpoint_address + sec_sunshine_num_offset;
    plant_cd = std::vector<int>(55);
    for (int i = 0; i < 55; ++i)
    {
        plant_cd[i] = ReadMemory<int>(0x69F2C4 + 0x24 * i); //保存冷却时间
    }
};
int Function::get_sunshine_num()
{
    return ReadMemory<int>(0x006A9F38,0x768,0x5560);
}
void Function::change_sunshine_num(int num)
{
    WriteMemory<int>(num, 0x006A9F38,0x768,0x5560);
}
void Function::zombie_weak()
{
    int zombie_max_num = ReadMemory<int>(0x006A9F38,0x768,0x94); //读取最大时僵尸数
    while (is_zombie_weak == true)
    {
        while (get_game_status() == 3 && is_zombie_weak == true)
        {
            for (int i = 0; i < zombie_max_num; ++i)
            {
                WriteMemory<int>(1, 0x006A9F38,0x768,0x90,0xC8 + i * 0x15C); //本体血量置1
                WriteMemory<int>(1, 0x006A9F38,0x768,0x90,0xD0 + i * 0x15C); //饰品血量置1
            }
            Sleep(2000);
            zombie_max_num = ReadMemory<int>(0x006A9F38,0x768,0x94);
        }
        Sleep(5000);
    }
}
void Function::open_zombie_weak()
{
    if (is_zombie_weak == false)
    {
        is_zombie_weak = true;
        // std::thread *task = new std::thread(zombie_weak, this);
        std::thread zombie_weak_task(zombie_weak); //开启新进程执行
        // task->detach();
        zombie_weak_task.detach();
    }
}
void Function::close_zombie_weak()
{
    is_zombie_weak = false;
}
int Function::get_zombie_num()
{
    return ReadMemory<int>(0x006A9F38,0x768,0xA0);
}
int Function::get_game_status()
{
    return ReadMemory<int>(0x006A9F38, 0x7FC); //游戏窗口状态一级偏移0x7FC
}
// void Function::open_no_plant_cd()
// {
//     for (int i = 0; i < 55; ++i)
//     {
//         WriteMemory<int>(20, 0x69F2C4 + 0x24 * i); //植物冷却时间0x69F2C4,+24下一个
//     }
// }
// void Function::close_no_plant_cd()
// {
//     for (int i = 0; i < 55; ++i)
//     {
//         WriteMemory<int>(plant_cd[i], 0x69F2C4 + 0x24 * i); //植物冷却时间0x69F2C4,+24下一个
//     }
// }
void Function::auto_pick()
{
    int item_max_num = ReadMemory<int>(0x006A9F38,0x768,0xE8);
    while (is_auto_pick == true)
    {
        while (get_game_status() == 3 && is_auto_pick == true)
        {
            for (int i = 0; i < item_max_num; ++i)
            {
                while (ReadMemory<int>(0x006A9F38, 0x768, 0x138, 0x30) != 0 || ReadMemory<int>(0x006A9F38, 0x768, 0x164) == 1 || ReadMemory<int>(0x006A9F38, 0x320, 0xE4) < 80)
                { //手上有植物或铲子，暂停，鼠标纵坐标小于卡槽
                }
                if (ReadMemory<int>(0x006A9F38, 0x768, 0xE4, 0x58 + i * 0xD8) == 4)
                {
                    int x = ReadMemory<float>(0x006A9F38, 0x768, 0XE4, 0x24 + i * 0xD8);
                    int y = ReadMemory<float>(0x006A9F38, 0x768, 0XE4, 0x28 + i * 0xD8);
                    if (y >= 80)
                    {
                        left_click(x, y);
                    }
                    Sleep(200);
                }
            }
            item_max_num = ReadMemory<int>(0x006A9F38, 0x768, 0xE8);
        }
    }
}
void Function::open_auto_pick()
{
    if (is_auto_pick == false)
    {
        is_auto_pick = true;
        std::thread auto_pick_task(Function::auto_pick);
        auto_pick_task.detach();
    }
}
void Function::close_auto_pick()
{
    is_auto_pick = false;
}
void Function::open_no_plant_cost()
{
    WriteMemory<int>(1, 0x006A9F38, 0x814);
}
void Function::close_no_plant_cost()
{
    WriteMemory<int>(0, 0x006A9F38, 0x814);
}