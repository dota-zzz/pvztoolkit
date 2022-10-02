#include "myframe.h"

MyFrame::MyFrame(const wxString&title):wxFrame(NULL, -wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
    Center();
    wxPanel * panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);
    
    // wxGridSizer* gridbox = new wxGridSizer(3,2,3,3);


    wxButton *on_auto_pick_button = new wxButton(panel,wxID_ANY,wxT("开启自动拾取阳光"));
    wxButton *down_auto_pick_button= new wxButton(panel,wxID_ANY,wxT("关闭自动拾取阳光"));
    wxButton *on_zombie_weak_button= new wxButton(panel,wxID_ANY,wxT("开启僵尸虚弱"));
    wxButton *down_zombie_weak_button = new wxButton(panel,wxID_ANY,wxT("关闭僵尸虚弱"));
    wxButton *on_no_plant_cost_button = new wxButton(panel,wxID_ANY,wxT("开启免费用卡"));
    wxButton *down_no_plant_cost_button = new wxButton(panel,wxID_ANY,wxT("关闭免费用卡"));

    // gridbox->Add(on_auto_pick_button,0,wxEXPAND);
    // gridbox->Add(down_auto_pick_button,0,wxEXPAND);
    // gridbox->Add(on_zombie_weak_button,0,wxEXPAND);
    // gridbox->Add(down_zombie_weak_button,0,wxEXPAND);
    // gridbox->Add(on_no_plant_cost_button,0,wxEXPAND);
    // gridbox->Add(down_no_plant_cost_button,0,wxEXPAND);

    hbox1->Add(on_auto_pick_button,1,wxEXPAND|wxALL,20);
    hbox1->Add(down_auto_pick_button,1,wxEXPAND|wxALL,20);
    hbox2->Add(on_zombie_weak_button,1,wxEXPAND|wxALL,20);
    hbox2->Add(down_zombie_weak_button,1,wxEXPAND|wxALL,20);
    hbox3->Add(on_no_plant_cost_button,1,wxEXPAND|wxALL,20);
    hbox3->Add(down_no_plant_cost_button,1,wxEXPAND|wxALL,20);

    // vbox->Add(gridbox,1,wxEXPAND|wxALL,20);
    vbox->Add(hbox1,1,wxEXPAND);
    vbox->Add(hbox2,1,wxEXPAND);
    vbox->Add(hbox3,1,wxEXPAND);

    panel->SetSizer(vbox);
    
    // button1->Connect(ID_B1,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::on_open_auto_pick));
    f = new Function;
    on_auto_pick_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::on_auto_pick));
    down_auto_pick_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::down_auto_pick));
    on_zombie_weak_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::on_zombie_weak));
    down_zombie_weak_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::down_zombie_weak));
    on_no_plant_cost_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::on_no_plant_cost));
    down_no_plant_cost_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::down_no_plant_cost));
    
}

MyFrame::~MyFrame()
{
    delete f;
}

void MyFrame::on_auto_pick(wxCommandEvent &event)
{
    Function::open_auto_pick();
}

void MyFrame::down_auto_pick(wxCommandEvent &)
{
    Function::close_auto_pick();
}
void MyFrame::on_zombie_weak(wxCommandEvent &)
{
    Function::open_zombie_weak();
}
void MyFrame::down_zombie_weak(wxCommandEvent &)
{
    Function::close_zombie_weak();
}
void MyFrame::on_no_plant_cost(wxCommandEvent &)
{
    Function::open_no_plant_cost();
}
void MyFrame::down_no_plant_cost(wxCommandEvent &)
{
    Function::close_no_plant_cost();
}