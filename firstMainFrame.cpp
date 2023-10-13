//construtor da classe mainframe
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//ponto de entrada do main frame (topo da janela)

	//criando um painel para preencher toda a janela, caso contrário, seria o botão que a preencheria
	//o primeiro parametro do wxPanel é o parente, nos queremos q seja o MainFrame entao usamos "this"
	wxPanel* panel = new wxPanel(this);
	
	//o primeiro parametro do wxButton é o parente, nos queremos q seja o painel entao usamos "panel"
	//o segundo é o identificador
	//"Botao" é a string que vai aparecer no botao
	//wxPoint é o ponto onde o botao ira se localizar
	//wxSize é o tamanho, x = largura y = altura
	wxButton* button = new wxButton(panel, wxID_ANY, "Botao", wxPoint(150, 50), wxSize(100, 35));

	//checkbox (fixed size control entao eu deixo default)
	wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, 
		"CheckBox", wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER); //wxCHK... esses dois sao estilos, pra usar mais de um é necessário o operador " | "

	//texto estatico, tamanho default seta o tamanho suficiente para o texto estar 100% visivel
	//wxSize(200, -1) torna a altura default
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NAO editavel", wxPoint(120, 190), wxSize(200, -1));
	staticText->SetBackgroundColour(*wxGREEN);

	//cntrole de texto, pro usuario digitar
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl -  editavel", wxPoint(500, 200), wxSize(200, -1), wxTE_PASSWORD); //estilo para senhas

	//slider
	wxSlider* slider = new wxSlider(panel, wxID_ANY, /*valor inicial*/ 25, /*minimo*/ 0, /*maximo*/ 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL); //value label mostrar o valor atual do slider

	//gauge, barra que mostra uma quantidade, usado nas interfaces de armazenamento ou download de dados)
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, /*valor maximo*/ 100, wxPoint(500, 230), wxSize(200, -1));
	gauge->SetValue(50);

	//caixa de escolhas
	wxArrayString choices;
	choices.Add("TND");
	choices.Add("TND");
	choices.Add("TND");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 300), wxSize(200, -1), choices, wxCB_SORT); //cb sort é ordem alfabetica
	choice->Select(0); //item padrao ao abrir o app

	//spin control (necessita do include) caixa com numeros e setas pra aumenta-los ou diminui-los
	wxSpinCtrl* sprinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(500, 380), wxSize(100, -1));

	//caixa de lista tipo a de escolhas mas nessa todas aparecem ao mesmo tempo e mais de uma podem ser selecionadas usando styles
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	//caixa de radio
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Caixa de Radio", wxPoint(485, 475), wxDefaultSize, choices, 1); //"1" é o major dim, apenas 1 escolha em cada linha
}
