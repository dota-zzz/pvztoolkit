#include "myapp.h"
#include "myframe.h"

IMPLEMENT_APP(MyApp)
bool MyApp::OnInit()
{
    MyFrame* mf = new MyFrame(wxT("pvztoolkit"));
    mf->Show(true);

    return true;
}

