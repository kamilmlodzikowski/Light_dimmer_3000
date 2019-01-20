/***************************************************************
 * Name:      Light_dimmerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mlodzikowski&Muszynski ()
 * Created:   2019-01-16
 * Copyright: Mlodzikowski&Muszynski ()
 * License:
 **************************************************************/

#include "Light_dimmerMain.h"
#include "Light_dimmerApp.h"
#include <wx/msgdlg.h>
#include "rs232.h"
#include "Connection_settings.h"





//(*InternalHeaders(Light_dimmerFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Light_dimmerFrame)
const long Light_dimmerFrame::ID_SLIDER1 = wxNewId();
const long Light_dimmerFrame::ID_BUTTON1 = wxNewId();
const long Light_dimmerFrame::ID_BUTTON2 = wxNewId();
const long Light_dimmerFrame::ID_STATICTEXT1 = wxNewId();
const long Light_dimmerFrame::ID_STATICTEXT2 = wxNewId();
const long Light_dimmerFrame::ID_Connect = wxNewId();
const long Light_dimmerFrame::idMenuQuit = wxNewId();
const long Light_dimmerFrame::idConnection = wxNewId();
const long Light_dimmerFrame::idMenuAbout = wxNewId();
const long Light_dimmerFrame::ID_STATUSBAR1 = wxNewId();
const long Light_dimmerFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Light_dimmerFrame,wxFrame)
    //(*EventTable(Light_dimmerFrame)
    //*)
END_EVENT_TABLE()

Light_dimmerFrame::Light_dimmerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Light_dimmerFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(384,301));
    slider = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxPoint(24,224), wxSize(328,27), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Light on"), wxPoint(40,120), wxSize(117,53), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Light off"), wxPoint(232,120), wxSize(112,53), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("LIGHT DIMMER 3000"), wxPoint(56,16), wxSize(272,42), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(22,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Latin Modern Sans Demi Cond"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    vallig = new wxStaticText(this, ID_STATICTEXT2, _("0"), wxPoint(176,192), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    Button_connect = new wxButton(this, ID_Connect, _("Connect"), wxPoint(-32,-24), wxSize(448,344), 0, wxDefaultValidator, _T("ID_Connect"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, idConnection, _("Connection Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);

    Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Light_dimmerFrame::OnsliderCmdScroll);
    Connect(ID_SLIDER1,wxEVT_SCROLL_TOP,(wxObjectEventFunction)&Light_dimmerFrame::OnsliderCmdScroll);
    Connect(ID_SLIDER1,wxEVT_SCROLL_BOTTOM,(wxObjectEventFunction)&Light_dimmerFrame::OnsliderCmdScroll);
    Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Light_dimmerFrame::OnsliderCmdScroll);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&Light_dimmerFrame::OnsliderCmdScroll);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Light_dimmerFrame::LightOn_click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Light_dimmerFrame::LightOff_click);
    Connect(ID_Connect,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Light_dimmerFrame::OnButton_connectClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Light_dimmerFrame::OnQuit);
    Connect(idConnection,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Light_dimmerFrame::OnMenuItemConnection);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Light_dimmerFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&Light_dimmerFrame::OnTimer1Trigger);
    //*)
}

Light_dimmerFrame::~Light_dimmerFrame()
{
    //(*Destroy(Light_dimmerFrame)
    //*)
}

void Light_dimmerFrame::OnQuit(wxCommandEvent& event)
{
    RS232_CloseComport(cport_nr);
    is_connectd=false;
    Close();
}

void Light_dimmerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Welcome to Light Dimmer 3000!\n \n Brought for your pleasure by Mlodzikowski&Muszynski";
    wxMessageBox(msg, _("About"));
}

void Light_dimmerFrame::LightOn_click(wxCommandEvent& event)
{
    if(!RS232_SendByte(cport_nr, 100))
    {
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(1000);
        #endif
            slider->SetValue(100);
            vallig->SetLabel("100");
    }
    else
    {
        Button_connect->SetLabel("             ERROR\n\nTry connecting again");
        is_connectd=false;
        RS232_CloseComport(cport_nr);
        Button_connect->Show();
    }
}

void Light_dimmerFrame::LightOff_click(wxCommandEvent& event)
{
    if(!RS232_SendByte(cport_nr, 0))
    {
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(1000);
        #endif
            slider->SetValue(0);
            vallig->SetLabel("0");
    }
    else
    {
        Button_connect->SetLabel("             ERROR\n\nTry connecting again");
        is_connectd=false;
        RS232_CloseComport(cport_nr);
        Button_connect->Show();
    }
}

void Light_dimmerFrame::OnsliderCmdScroll(wxScrollEvent& event)
{
    int tmp=slider->GetValue();
    if(!RS232_SendByte(cport_nr, tmp))
    {
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(1000);
        #endif
            wxString lalaa;
            lalaa<<tmp;
            vallig->SetLabel(lalaa);
    }
    else
    {
        Button_connect->SetLabel("             ERROR\n\nTry connecting again");
        is_connectd=false;
        RS232_CloseComport(cport_nr);
        Button_connect->Show();
    }
}

//void Light_dimmerFrame::OnButton3Click(wxCommandEvent& event)
//{
//    char mode[]={'8','N','1',0};
//    if(RS232_OpenComport(cport_nr, bdrate, mode))
//    {
//        printf("Can not open comport\n");
////        Button3->SetLabel("ERROR");
//    }
//    else
//    {
////        Button3->SetLabel("DONE");
////        Button3->Hide();
//        while(!MultiChoiceDialog1->Show())
//        {
//
//        };
//        wxString tmp;
//        //tmp<<MultiChoiceDialog1->GetSelections()[1];
//        Button1->SetLabel(tmp);
//    }
//}



void Light_dimmerFrame::OnMenuItemConnection(wxCommandEvent& event)
{
    Connection_settings tmp_dlg(this);
    wxString tymczas;
    tymczas<<bdrate;
    tmp_dlg.baud->SetValue(tymczas);
    tmp_dlg.ChoicePort->SetSelection(cport_nr);
    int dlg=tmp_dlg.ShowModal();
    if(dlg==wxID_OK)
    {
        RS232_CloseComport(cport_nr);
        is_connectd=false;
        Button_connect->SetLabel("Connect");
        Button_connect->Show();
        //cport_nr=wxAtoi(tmp_dlg.port->GetValue());
        cport_nr=tmp_dlg.ChoicePort->GetSelection();
        int bdr_tmp=wxAtoi(tmp_dlg.baud->GetValue());
        if(bdr_tmp>0)
        {
            bdrate=bdr_tmp;
        }
    }
}

void Light_dimmerFrame::OnButton_connectClick(wxCommandEvent& event)
{
    char mode[]={'8','N','1',0};
    if(RS232_OpenComport(cport_nr, bdrate, mode))
    {
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(1000);
        #endif
        Button_connect->SetLabel("             ERROR\n\nTry connecting again");
        RS232_CloseComport(cport_nr);
        is_connectd=false;
    }
    else
    {
        Button_connect->Hide();
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(1000);
        #endif
        if(!RS232_SendByte(cport_nr, 0))
        {
            #ifdef _WIN32
                Sleep(100);
            #else
                usleep(1000);
            #endif
                is_connectd=true;
                slider->SetValue(0);
                vallig->SetLabel("0");
        }
        else
        {
            Button_connect->SetLabel("             ERROR\n\nTry connecting again");
            is_connectd=false;
            RS232_CloseComport(cport_nr);
            Button_connect->Show();
        }
    }
}

void Light_dimmerFrame::setSlider(int wartosc)
{
        slider->SetValue(wartosc);
        wxString tmp;
        tmp<<wartosc;
        vallig->SetLabel(tmp);
}



void Light_dimmerFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    if(is_connectd==true)
    {
        odczyt = RS232_PollComport(cport_nr, &buff, 1);
        if(odczyt!=stary_odczyt)
        {
            setSlider(odczyt);
            stary_odczyt=odczyt;
        }
    }
}
