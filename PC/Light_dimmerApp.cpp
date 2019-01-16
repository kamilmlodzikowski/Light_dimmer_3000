/***************************************************************
 * Name:      Light_dimmerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mlodzikowski&Muszynski ()
 * Created:   2019-01-16
 * Copyright: Mlodzikowski&Muszynski ()
 * License:
 **************************************************************/

#include "Light_dimmerApp.h"

//(*AppHeaders
#include "Light_dimmerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Light_dimmerApp);

bool Light_dimmerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Light_dimmerFrame* Frame = new Light_dimmerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        