#ifndef CONNECTION_SETTINGS_H
#define CONNECTION_SETTINGS_H

//(*Headers(Connection_settings)
#include <wx/dialog.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class Connection_settings: public wxDialog
{
	public:

		Connection_settings(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Connection_settings();

		//(*Declarations(Connection_settings)
		wxButton* Button1;
		wxTextCtrl* baud;
		wxButton* reset_button;
		wxStaticText* StaticText1;
		wxChoice* ChoicePort;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(Connection_settings)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(Connection_settings)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void Onreset_buttonClick(wxCommandEvent& event);
		void OnbaudTextEnter(wxCommandEvent& event);
		void OnbaudTextEnter1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
                                    