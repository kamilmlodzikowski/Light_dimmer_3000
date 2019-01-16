#include "Connection_settings.h"

//(*InternalHeaders(Connection_settings)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(Connection_settings)
const long Connection_settings::ID_TEXTCTRL1 = wxNewId();
const long Connection_settings::ID_STATICTEXT1 = wxNewId();
const long Connection_settings::ID_STATICTEXT2 = wxNewId();
const long Connection_settings::ID_TEXTCTRL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Connection_settings,wxDialog)
	//(*EventTable(Connection_settings)
	//*)
END_EVENT_TABLE()

Connection_settings::Connection_settings(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(Connection_settings)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,217));
	baud = new wxTextCtrl(this, ID_TEXTCTRL1, _("9600"), wxPoint(112,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Baud Rate"), wxPoint(32,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Port"), wxPoint(56,104), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	port = new wxTextCtrl(this, ID_TEXTCTRL2, _("24"), wxPoint(112,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(this, wxID_OK, _("OK"), wxPoint(160,160), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Connection_settings::OnTextCtrl1Text);
	//*)
}

Connection_settings::~Connection_settings()
{
	//(*Destroy(Connection_settings)
	//*)
}


void Connection_settings::OnTextCtrl1Text(wxCommandEvent& event)
{
}
