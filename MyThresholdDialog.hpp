#ifndef MYTHRESHOLDDIALOG_H
#define MYTHRESHOLDDIALOG_H
#include "wx/dialog.h"
#include "wx/button.h"
#include "wx/slider.h"

class MyThresholdDialog : public wxDialog
{
private:
	wxButton* m_okButton;
public:
	wxSlider* m_threshold;
	MyThresholdDialog( wxWindow* parent, wxWindowID id = wxID_ANY,
		const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

};
#endif // MYTHRESHOLDDIALOG_H
