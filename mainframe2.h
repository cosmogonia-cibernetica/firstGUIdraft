#include <wx/wx.h>

class MainFrame : public wxFrame{
public:
	MainFrame(const wxString& title);
private:
	//evento declarado pro click no botao
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);

	//macro para tabela de eventos, essa declaracao sera iniciada em MainFrame.cpp
	wxDECLARE_EVENT_TABLE();
};
