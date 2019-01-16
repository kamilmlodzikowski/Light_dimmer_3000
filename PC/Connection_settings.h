#ifndef CONNECTION_SETTINGS_H
#define CONNECTION_SETTINGS_H

//(*Headers(Connection_settings)
#include <wx/dialog.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Connection_settings: public wxDialog
{
	public:

		Connection_settings(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Connection_settings();

		//(*Declarations(Connection_settings)
		wxTextCtrl* port;
		wxButton* Button1;
		wxTextCtrl* baud;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(Connection_settings)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		//*)

	private:

		//(*Handlers(Connection_settings)
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
