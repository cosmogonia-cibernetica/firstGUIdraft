#include "MainFrame.h"
#include <wx/wx.h>

//criando IDs, IDs nao podem ser 0 ou 1 e devem ser positivas.
enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked) //literalmente nao sabe que o nosso botao existe, ele usa como parametro o BUTTON_ID
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged) //isso chamara nosso event handler quando o valor do slider mudar
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged) //									||
wxEND_EVENT_TABLE()

//construtor da classe mainframe
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//ponto de entrada do main frame (topo da janela)

	//criando um painel para preencher toda a janela, caso contrário, seria o botão que a preencheria
	//o primeiro parametro do wxPanel é o parente, nos queremos q seja o MainFrame entao usamos "this"
	wxPanel* panel = new wxPanel(this);
	
	//controles de evento por IDs personalizados, cada um com seu evento na header file
	wxButton* button = new wxButton(panel, BUTTON_ID, "Botao", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 375), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "TND - Digite aqui", wxPoint(300, 575), wxSize(200, -1));

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
