#pragma once

#include <windows.h>
#include <iostream>
#include "mymemory.h"
#include <thread>
#include <vector>
#include <wx/wx.h>

class Function
{
private:
    // uintptr_t sunshine_base_address = 0x00779618;
    // uintptr_t sunshine_firstoffset = 0x868;
    // uintptr_t sunshine_secondoffset = 0x5578;
    const uintptr_t base_address = 0x006A9F38;                //基址
    const uintptr_t fir_checkpoint_offset = 0x768;            //一级关卡偏移
    const uintptr_t sec_sunshine_num_offset = 0x5560;         //二级阳光偏移
    const uintptr_t sec_zombie_num_offset = 0xA0;             //二级僵尸数量偏移
    const uintptr_t sec_zombie_object_sequence_offsec = 0x90; //二级僵尸数组偏移

    uintptr_t checkpoint_address;             //关卡地址
    uintptr_t zombie_obiect_sequence_address; //僵尸数组地址
    uintptr_t sunshine_num_address;           //阳光数量地址

    std::vector<int> plant_cd; //植物冷却时间
    static bool is_zombie_weak;
    static bool is_auto_pick;

protected:
    static void zombie_weak();
    static void auto_pick();

public:
    Function();

    static int get_sunshine_num();  //返回阳光数量
    static int get_zombie_num();    //返回场上僵尸数量
    static int get_game_status();   //返回游戏状态(0.主界面1.选卡界面2.战斗界面)
    static void change_sunshine_num(int); //改变阳光数量
    static void open_zombie_weak();       //开启一击必杀
    static void close_zombie_weak();      //关闭一击必杀
    // static void open_no_plant_cd();       //开启植物无冷却
    // static void close_no_plant_cd();      //关闭植物无冷却
    static void open_auto_pick();         //开启自动拾取
    static void close_auto_pick();        //关闭自动拾取
    static void open_no_plant_cost();     //开启植物无冷却无消耗
    static void close_no_plant_cost();    //关闭植物无冷却无消耗
};
