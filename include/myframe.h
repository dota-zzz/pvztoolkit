#pragma once
#include <wx/wx.h>
#include "function.h"


class MyFrame:public wxFrame
{
    public:
    MyFrame(const wxString&);
    virtual ~MyFrame();
    private:
    const int ID_B1 = 100;
    const int ID_B2 = 200;
    const int ID_B3 = 300;
    void on_auto_pick(wxCommandEvent &);
    void down_auto_pick(wxCommandEvent &);
    void on_zombie_weak(wxCommandEvent &);
    void down_zombie_weak(wxCommandEvent &);
    void on_no_plant_cost(wxCommandEvent &);
    void down_no_plant_cost(wxCommandEvent &);

    Function *f;
};