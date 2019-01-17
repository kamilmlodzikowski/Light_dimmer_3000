#include "Connection_settings.h"

//(*InternalHeaders(Connection_settings)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(Connection_settings)
const long Connection_settings::ID_TEXTCTRL1 = wxNewId();
const long Connection_settings::ID_STATICTEXT1 = wxNewId();
const long Connection_settings::ID_STATICTEXT2 = wxNewId();
const long Connection_settings::ID_CHOICE1 = wxNewId();
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
	Button1 = new wxButton(this, wxID_OK, _("OK"), wxPoint(160,160), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	ChoicePort = new wxChoice(this, ID_CHOICE1, wxPoint(112,96), wxSize(168,31), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ChoicePort->Append(_("/dev/ttyS0"));
	ChoicePort->Append(_("/dev/ttyS1"));
	ChoicePort->Append(_("/dev/ttyS2"));
	ChoicePort->Append(_("/dev/ttyS3"));
	ChoicePort->Append(_("/dev/ttyS4"));
	ChoicePort->Append(_("/dev/ttyS5"));
	ChoicePort->Append(_("/dev/ttyS6"));
	ChoicePort->Append(_("/dev/ttyS7"));
	ChoicePort->Append(_("/dev/ttyS8"));
	ChoicePort->Append(_("/dev/ttyS9"));
	ChoicePort->Append(_("/dev/ttyS10"));
	ChoicePort->Append(_("/dev/ttyS11"));
	ChoicePort->Append(_("/dev/ttyS12"));
	ChoicePort->Append(_("/dev/ttyS13"));
	ChoicePort->Append(_("/dev/ttyS14"));
	ChoicePort->Append(_("/dev/ttyS15"));
	ChoicePort->Append(_("/dev/ttyUSB0"));
	ChoicePort->Append(_("/dev/ttyUSB1"));
	ChoicePort->Append(_("/dev/ttyUSB2"));
	ChoicePort->Append(_("/dev/ttyUSB3"));
	ChoicePort->Append(_("/dev/ttyUSB4"));
	ChoicePort->Append(_("/dev/ttyUSB5"));
	ChoicePort->Append(_("/dev/ttyAMA0"));
	ChoicePort->Append(_("/dev/ttyAMA1"));
	ChoicePort->SetSelection( ChoicePort->Append(_("/dev/ttyACM0")) );
	ChoicePort->Append(_("/dev/ttyACM1"));
	ChoicePort->Append(_("/dev/rfcomm0"));
	ChoicePort->Append(_("/dev/rfcomm1"));
	ChoicePort->Append(_("/dev/ircomm0"));
	ChoicePort->Append(_("/dev/ircomm1"));
	ChoicePort->Append(_("/dev/cuau0"));
	ChoicePort->Append(_("/dev/cuau1"));
	ChoicePort->Append(_("/dev/cuau2"));
	ChoicePort->Append(_("/dev/cuau3"));
	ChoicePort->Append(_("/dev/cuaU0"));
	ChoicePort->Append(_("/dev/cuaU1"));
	ChoicePort->Append(_("/dev/cuaU2"));
	ChoicePort->Append(_("/dev/cuaU3"));

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
