#include "MainFrame.h"
#include <wx/wx.h>


//construtor da classe mainframe
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//ponto de entrada do main frame (topo da janela)

	//criando um painel para preencher toda a janela, caso contrário, seria o botão que a preencheria
	//o primeiro parametro do wxPanel é o parente, nos queremos q seja o MainFrame entao usamos "this"
	wxPanel* panel = new wxPanel(this);
	
	//controles de evento por IDs personalizados, cada um com seu evento na header file
	wxButton* button = new wxButton(panel, wxID_ANY, "Botao", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 375), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "TND - Digite aqui", wxPoint(300, 575), wxSize(200, -1));

	//metodo de binding, ao inves da event table
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	//desbindar (unbinding)
	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	//statusbar fica na parte de baixo da janela onde podemos exibir texto
	CreateStatusBar();

}

//construção dos eventos declarados em MainFrame.h, chamando os comandos de &evt e da tabela de eventos na linha 10 e os executa
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("ESTUPRaR NEGRos"); //isso deve aparecer no statusbar
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Valor do Slider; %d", evt.GetInt()); //evt.GetInt pega o valor do slider, o wxString é a função de strings do wxwidgets
	wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Texto: %s", evt.GetString()); //mesma coisa, pegar string formatada printf papapa
	wxLogStatus(str);
}
