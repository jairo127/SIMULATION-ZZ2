#pragma once



#include <msclr\marshal_cppstd.h>


#include <sstream>
#include <Systeme.h>
#include <Resultat.h>

namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace msclr::interop;

	/// <summary>
	/// Description résumée de form_main
	/// </summary>
	public ref class form_main : public System::Windows::Forms::Form
	{
	public:
		form_main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~form_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^ sim_span;
	private: System::Windows::Forms::TextBox^ sim_client_span;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^ sim_proc_span;

	private: System::Windows::Forms::Button^ simulation_button;
	private: System::Windows::Forms::Button^ button_quit;
	private: System::Windows::Forms::RichTextBox^ console_box;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::Button^ console_clear;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ sim_piece_number;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;






	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sim_span = (gcnew System::Windows::Forms::TextBox());
			this->sim_client_span = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->sim_proc_span = (gcnew System::Windows::Forms::TextBox());
			this->simulation_button = (gcnew System::Windows::Forms::Button());
			this->button_quit = (gcnew System::Windows::Forms::Button());
			this->console_box = (gcnew System::Windows::Forms::RichTextBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->console_clear = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->sim_piece_number = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 25);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"durée simulation";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 63);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"durée interclient";
			// 
			// sim_span
			// 
			this->sim_span->Location = System::Drawing::Point(176, 25);
			this->sim_span->Margin = System::Windows::Forms::Padding(4);
			this->sim_span->Name = L"sim_span";
			this->sim_span->Size = System::Drawing::Size(132, 22);
			this->sim_span->TabIndex = 2;
			this->sim_span->Text = L"100";
			// 
			// sim_client_span
			// 
			this->sim_client_span->Location = System::Drawing::Point(176, 60);
			this->sim_client_span->Margin = System::Windows::Forms::Padding(4);
			this->sim_client_span->Name = L"sim_client_span";
			this->sim_client_span->Size = System::Drawing::Size(132, 22);
			this->sim_client_span->TabIndex = 3;
			this->sim_client_span->Text = L"4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 97);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"durée traitement client";
			// 
			// sim_proc_span
			// 
			this->sim_proc_span->Location = System::Drawing::Point(176, 94);
			this->sim_proc_span->Margin = System::Windows::Forms::Padding(4);
			this->sim_proc_span->Name = L"sim_proc_span";
			this->sim_proc_span->Size = System::Drawing::Size(132, 22);
			this->sim_proc_span->TabIndex = 5;
			this->sim_proc_span->Text = L"6";
			// 
			// simulation_button
			// 
			this->simulation_button->Location = System::Drawing::Point(316, 18);
			this->simulation_button->Margin = System::Windows::Forms::Padding(4);
			this->simulation_button->Name = L"simulation_button";
			this->simulation_button->Size = System::Drawing::Size(216, 134);
			this->simulation_button->TabIndex = 6;
			this->simulation_button->Text = L"Lancer la simulation";
			this->simulation_button->UseVisualStyleBackColor = true;
			this->simulation_button->Click += gcnew System::EventHandler(this, &form_main::simulation_start);
			// 
			// button_quit
			// 
			this->button_quit->Location = System::Drawing::Point(1156, 541);
			this->button_quit->Name = L"button_quit";
			this->button_quit->Size = System::Drawing::Size(75, 23);
			this->button_quit->TabIndex = 7;
			this->button_quit->Text = L"Quitter";
			this->button_quit->UseVisualStyleBackColor = true;
			this->button_quit->Click += gcnew System::EventHandler(this, &form_main::quit_window);
			// 
			// console_box
			// 
			this->console_box->Location = System::Drawing::Point(1075, 12);
			this->console_box->Name = L"console_box";
			this->console_box->ReadOnly = true;
			this->console_box->Size = System::Drawing::Size(524, 523);
			this->console_box->TabIndex = 8;
			this->console_box->Text = L"";
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(12, 158);
			this->chart->Name = L"chart";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series1->Legend = L"Legend1";
			series1->Name = L"Entrées";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series2->Legend = L"Legend1";
			series2->Name = L"Sorties";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(520, 369);
			this->chart->TabIndex = 9;
			this->chart->Text = L"Entrées et Sorties";
			// 
			// console_clear
			// 
			this->console_clear->Location = System::Drawing::Point(1075, 541);
			this->console_clear->Name = L"console_clear";
			this->console_clear->Size = System::Drawing::Size(75, 23);
			this->console_clear->TabIndex = 10;
			this->console_clear->Text = L"Clear";
			this->console_clear->UseVisualStyleBackColor = true;
			this->console_clear->Click += gcnew System::EventHandler(this, &form_main::console_clear_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"nombre de piéces";
			// 
			// sim_piece_number
			// 
			this->sim_piece_number->Location = System::Drawing::Point(176, 130);
			this->sim_piece_number->Name = L"sim_piece_number";
			this->sim_piece_number->Size = System::Drawing::Size(132, 22);
			this->sim_piece_number->TabIndex = 12;
			this->sim_piece_number->Text = L"10";
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(538, 158);
			this->chart1->Name = L"chart1";
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"Séjour Moyen Système";
			series4->BorderWidth = 3;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->Name = L"Séjour Moyen File";
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(531, 369);
			this->chart1->TabIndex = 13;
			this->chart1->Text = L"chart1";
			// 
			// form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1611, 844);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->sim_piece_number);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->console_clear);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->console_box);
			this->Controls->Add(this->button_quit);
			this->Controls->Add(this->simulation_button);
			this->Controls->Add(this->sim_proc_span);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->sim_client_span);
			this->Controls->Add(this->sim_span);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"form_main";
			this->Text = L"form_main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		
		System::String^ s_nb_1 = textBox1->Text;
		System::String^ s_nb_2 = textBox2->Text;

		msclr::interop::marshal_context context;
		std::string chaine1 = context.marshal_as<std::string>(s_nb_1);
		std::string chaine2 = context.marshal_as<std::string>(s_nb_2);


		// autre sol
		int nb1 = -1;
		int nb2 = -1;
		std::istringstream(chaine1) >> nb1;
		std::istringstream(chaine2) >> nb2;
		int nb_res = nb1 + nb2;


		// le res. en string
		std::stringstream chaine_res;
		chaine_res << nb_res;
		std::string chaine_res_string = chaine_res.str();

		System::String^ s_nb_res = marshal_as<String^>(chaine_res_string);

		textBox3->Text = s_nb_res;
		
	}*/

private: System::Void quit_window(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

	   
private: System::Void simulation_start(System::Object^ sender, System::EventArgs^ e) {
	// Récupération des valeurs de durée, intervale interclient et durée de traitement d'un client
	System::String^ s_sim_span = sim_span->Text;
	System::String^ s_sim_client_span = sim_client_span->Text;
	System::String^ s_sim_proc_span = sim_proc_span->Text;
	System::String^ s_sim_piece_number = sim_piece_number->Text;
	msclr::interop::marshal_context context;
	std::string chaine1 = context.marshal_as<std::string>(s_sim_span);
	std::string chaine2 = context.marshal_as<std::string>(s_sim_client_span);
	std::string chaine3 = context.marshal_as<std::string>(s_sim_proc_span);
	std::string chaine4 = context.marshal_as<std::string>(s_sim_piece_number);
	int duree = 0, interclient = 0, traitement = 0, nb_piece = 0;
	std::istringstream(chaine1) >> duree;
	std::istringstream(chaine2) >> interclient;
	std::istringstream(chaine3) >> traitement;
	std::istringstream(chaine4) >> nb_piece;

	// Affichage initialisation
	this->console_box->AppendText("Lancement de la simulation\n");
	this->console_box->AppendText("Durée = " + duree + ", Interclient = " + interclient + ", Traitement = " + traitement + "\n");
	this->simulation_button->Enabled = false;

	Systeme s(nb_piece, interclient, traitement, duree);
	Resultat r = s.Simuler();
	this->console_box->AppendText(context.marshal_as<String^>(r.log));
	//r.CalculerStats();

	this->simulation_button->Enabled = true;
	
	// Remplissage des courbes
	chart->Series[0]->Points->AddXY(0,0);
	chart->Series[1]->Points->AddXY(0,0);
	chart1->Series[0]->Points->AddXY(0, 0);
	chart1->Series[1]->Points->AddXY(0, 0);
	for (int i = 1; i <= nb_piece; i++)
	{
		chart->Series[0]->Points->AddXY(r.date_in[i], i);
		chart->Series[1]->Points->AddXY(r.date_out[i], i);
		chart1->Series[0]->Points->AddXY(i, r.sejour_sys[i]);
		chart1->Series[1]->Points->AddXY(i, r.sejour_file[i]);
	}
}

private: System::Void console_clear_Click(System::Object^ sender, System::EventArgs^ e) {
	this->console_box->Text = Text->Empty;
	chart->Series[0]->Points->Clear();
	chart->Series[1]->Points->Clear();
	chart1->Series[0]->Points->Clear();
	chart1->Series[1]->Points->Clear();
}

};
}
