/***************************************************************
 * Name:      Light_dimmerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mlodzikowski&Muszynski ()
 * Created:   2019-01-16
 * Copyright: Mlodzikowski&Muszynski ()
 * License:
 **************************************************************/

#ifndef LIGHT_DIMMERMAIN_H
#define LIGHT_DIMMERMAIN_H

//(*Headers(Light_dimmerFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)

class Light_dimmerFrame: public wxFrame
{
    public:

        Light_dimmerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Light_dimmerFrame();
        void setSlider(int wartosc);
        bool is_connectd=false;
        unsigned char buff;
        int odczyt=0;
        int cport_nr=24,
            bdrate=57600;
        unsigned char stary_odczyt=0;

    private:

        //(*Handlers(Light_dimmerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void LightOn_click(wxCommandEvent& event);
        void LightOff_click(wxCommandEvent& event);
        void OnsliderCmdScroll(wxScrollEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnCustom1Paint(wxPaintEvent& event);
        void OnMenuItemConnection(wxCommandEvent& event);
        void OnButton_connectClick(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(Light_dimmerFrame)
        static const long ID_SLIDER1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_Connect;
        static const long idConnection;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(Light_dimmerFrame)
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxTimer Timer1;
        wxStaticText* vallig;
        wxMenuItem* MenuItem3;
        wxSlider* slider;
        wxButton* Button_connect;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LIGHT_DIMMERMAIN_H
