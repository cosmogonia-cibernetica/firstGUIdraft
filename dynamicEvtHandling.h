#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame{
public:
	MainFrame(const wxString& title);
private:
	//evento declarado pro click no botao
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);
};
