#pragma once

#include "world.h"
#include "Result.h"
#include <msclr\marshal_cppstd.h>

world *country;
vector<firm*> firms;

namespace firm_household {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			country = new world(int::Parse(number_firm->Text), int::Parse(number_household->Text), float::Parse(money->Text));
			firms = country->get_firms();
			country->init(float::Parse(money->Text), float::Parse(labor_productivity->Text), float::Parse(salary_coefficient->Text));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::CheckedListBox^  parameters;






	private: System::Windows::Forms::Label^  label3;



































































































private: System::Windows::Forms::Button^  button1;



private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  iterations;
private: System::Windows::Forms::TextBox^  salary_coefficient;





private: System::Windows::Forms::TextBox^  consumption_need;

private: System::Windows::Forms::TextBox^  number_household;


private: System::Windows::Forms::TextBox^  labor_productivity;

private: System::Windows::Forms::TextBox^  money;

private: System::Windows::Forms::TextBox^  number_firm;



private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;

private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Button^  test;
private: System::Windows::Forms::TextBox^  price_value;
private: System::Windows::Forms::TextBox^  production_value;
private: System::Windows::Forms::TextBox^  sold_value;
private: System::Windows::Forms::TextBox^  storage_value;
private: System::Windows::Forms::TextBox^  plan_value;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label13;
private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape1;
private: System::Windows::Forms::TextBox^  salary_value;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::TextBox^  profit_value;
private: System::Windows::Forms::Label^  label14;







	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->parameters = (gcnew System::Windows::Forms::CheckedListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->iterations = (gcnew System::Windows::Forms::TextBox());
			this->salary_coefficient = (gcnew System::Windows::Forms::TextBox());
			this->consumption_need = (gcnew System::Windows::Forms::TextBox());
			this->number_household = (gcnew System::Windows::Forms::TextBox());
			this->labor_productivity = (gcnew System::Windows::Forms::TextBox());
			this->money = (gcnew System::Windows::Forms::TextBox());
			this->number_firm = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->test = (gcnew System::Windows::Forms::Button());
			this->price_value = (gcnew System::Windows::Forms::TextBox());
			this->production_value = (gcnew System::Windows::Forms::TextBox());
			this->sold_value = (gcnew System::Windows::Forms::TextBox());
			this->storage_value = (gcnew System::Windows::Forms::TextBox());
			this->plan_value = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->rectangleShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
			this->salary_value = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->profit_value = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// parameters
			// 
			this->parameters->CheckOnClick = true;
			this->parameters->FormattingEnabled = true;
			this->parameters->Items->AddRange(gcnew cli::array< System::Object^  >(22) {L"total sales", L"price", L"salary", L"plan", 
				L"storage", L"workers", L"labor_capacity", L"capital_capacity", L"raw_capacity", L"capital_investments", L"raw_investments", 
				L"sales", L"sold", L"profit", L"money", L"margin", L"share", L"production", L"expected", L"exp_price", L"exp_sales", L"exp_price_growth"});
			this->parameters->Location = System::Drawing::Point(658, 20);
			this->parameters->Name = L"parameters";
			this->parameters->Size = System::Drawing::Size(141, 289);
			this->parameters->TabIndex = 1;
			this->parameters->TabStop = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(619, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Output";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(524, 311);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(275, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label41->Location = System::Drawing::Point(521, 22);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(76, 17);
			this->label41->TabIndex = 27;
			this->label41->Text = L"Iterations";
			// 
			// iterations
			// 
			this->iterations->Location = System::Drawing::Point(524, 45);
			this->iterations->Name = L"iterations";
			this->iterations->Size = System::Drawing::Size(75, 20);
			this->iterations->TabIndex = 26;
			this->iterations->Text = L"150";
			// 
			// salary_coefficient
			// 
			this->salary_coefficient->Location = System::Drawing::Point(302, 42);
			this->salary_coefficient->Name = L"salary_coefficient";
			this->salary_coefficient->Size = System::Drawing::Size(143, 20);
			this->salary_coefficient->TabIndex = 40;
			this->salary_coefficient->Text = L"0,8";
			// 
			// consumption_need
			// 
			this->consumption_need->Location = System::Drawing::Point(73, 235);
			this->consumption_need->Name = L"consumption_need";
			this->consumption_need->Size = System::Drawing::Size(143, 20);
			this->consumption_need->TabIndex = 38;
			this->consumption_need->Text = L"0,1";
			// 
			// number_household
			// 
			this->number_household->Location = System::Drawing::Point(73, 187);
			this->number_household->Name = L"number_household";
			this->number_household->Size = System::Drawing::Size(143, 20);
			this->number_household->TabIndex = 36;
			this->number_household->Text = L"200";
			// 
			// labor_productivity
			// 
			this->labor_productivity->Location = System::Drawing::Point(72, 132);
			this->labor_productivity->Name = L"labor_productivity";
			this->labor_productivity->Size = System::Drawing::Size(143, 20);
			this->labor_productivity->TabIndex = 32;
			this->labor_productivity->Text = L"5";
			// 
			// money
			// 
			this->money->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->money->Location = System::Drawing::Point(73, 84);
			this->money->Name = L"money";
			this->money->Size = System::Drawing::Size(143, 20);
			this->money->TabIndex = 30;
			this->money->Text = L"1000";
			// 
			// number_firm
			// 
			this->number_firm->Location = System::Drawing::Point(77, 42);
			this->number_firm->Name = L"number_firm";
			this->number_firm->Size = System::Drawing::Size(143, 20);
			this->number_firm->TabIndex = 28;
			this->number_firm->Text = L"5";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(256, 26);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(88, 13);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Salary coefficient";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(27, 219);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(95, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"Consumption need";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(27, 171);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 13);
			this->label8->TabIndex = 37;
			this->label8->Text = L"Households";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 116);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Labor productivity";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Money";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Firms";
			// 
			// test
			// 
			this->test->Location = System::Drawing::Point(12, 285);
			this->test->Name = L"test";
			this->test->Size = System::Drawing::Size(248, 68);
			this->test->TabIndex = 42;
			this->test->Text = L"Test";
			this->test->UseVisualStyleBackColor = true;
			this->test->Click += gcnew System::EventHandler(this, &Form1::test_Click);
			// 
			// price_value
			// 
			this->price_value->Location = System::Drawing::Point(328, 293);
			this->price_value->Name = L"price_value";
			this->price_value->Size = System::Drawing::Size(143, 20);
			this->price_value->TabIndex = 51;
			this->price_value->Text = L"5";
			// 
			// production_value
			// 
			this->production_value->Location = System::Drawing::Point(328, 245);
			this->production_value->Name = L"production_value";
			this->production_value->Size = System::Drawing::Size(143, 20);
			this->production_value->TabIndex = 49;
			this->production_value->Text = L"200";
			// 
			// sold_value
			// 
			this->sold_value->Location = System::Drawing::Point(327, 190);
			this->sold_value->Name = L"sold_value";
			this->sold_value->Size = System::Drawing::Size(143, 20);
			this->sold_value->TabIndex = 47;
			this->sold_value->Text = L"5";
			// 
			// storage_value
			// 
			this->storage_value->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->storage_value->Location = System::Drawing::Point(328, 142);
			this->storage_value->Name = L"storage_value";
			this->storage_value->Size = System::Drawing::Size(143, 20);
			this->storage_value->TabIndex = 45;
			this->storage_value->Text = L"1000";
			// 
			// plan_value
			// 
			this->plan_value->Location = System::Drawing::Point(332, 100);
			this->plan_value->Name = L"plan_value";
			this->plan_value->Size = System::Drawing::Size(143, 20);
			this->plan_value->TabIndex = 43;
			this->plan_value->Text = L"10";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(282, 277);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 52;
			this->label2->Text = L"price";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(282, 229);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 13);
			this->label7->TabIndex = 50;
			this->label7->Text = L"production";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(281, 174);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(26, 13);
			this->label10->TabIndex = 48;
			this->label10->Text = L"sold";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(282, 126);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(42, 13);
			this->label12->TabIndex = 46;
			this->label12->Text = L"storage";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(282, 84);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(27, 13);
			this->label13->TabIndex = 44;
			this->label13->Text = L"plan";
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(0, 0);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->rectangleShape1});
			this->shapeContainer1->Size = System::Drawing::Size(805, 358);
			this->shapeContainer1->TabIndex = 53;
			this->shapeContainer1->TabStop = false;
			// 
			// rectangleShape1
			// 
			this->rectangleShape1->Location = System::Drawing::Point(271, 77);
			this->rectangleShape1->Name = L"rectangleShape1";
			this->rectangleShape1->Size = System::Drawing::Size(228, 254);
			// 
			// salary_value
			// 
			this->salary_value->Location = System::Drawing::Point(537, 109);
			this->salary_value->Name = L"salary_value";
			this->salary_value->Size = System::Drawing::Size(82, 20);
			this->salary_value->TabIndex = 54;
			this->salary_value->Text = L"200";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(507, 87);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(34, 13);
			this->label15->TabIndex = 55;
			this->label15->Text = L"salary";
			// 
			// profit_value
			// 
			this->profit_value->Location = System::Drawing::Point(537, 164);
			this->profit_value->Name = L"profit_value";
			this->profit_value->Size = System::Drawing::Size(82, 20);
			this->profit_value->TabIndex = 56;
			this->profit_value->Text = L"200";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(507, 142);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(30, 13);
			this->label14->TabIndex = 57;
			this->label14->Text = L"profit";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 358);
			this->Controls->Add(this->profit_value);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->salary_value);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->price_value);
			this->Controls->Add(this->production_value);
			this->Controls->Add(this->sold_value);
			this->Controls->Add(this->storage_value);
			this->Controls->Add(this->plan_value);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->test);
			this->Controls->Add(this->salary_coefficient);
			this->Controls->Add(this->consumption_need);
			this->Controls->Add(this->number_household);
			this->Controls->Add(this->labor_productivity);
			this->Controls->Add(this->money);
			this->Controls->Add(this->number_firm);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->iterations);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->parameters);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->shapeContainer1);
			this->Name = L"Form1";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 srand(1);
				 Result^ result = gcnew Result();				 
				 country = new world(int::Parse(number_firm->Text), int::Parse(number_household->Text), float::Parse(money->Text));
				 firms = country->get_firms();
				 country->init(float::Parse(money->Text), float::Parse(labor_productivity->Text), float::Parse(salary_coefficient->Text));				 
				 vector<firm*> values;
				 values = country->get_firms();
				 for (int i = 0; i < parameters->CheckedItems->Count; i++)
				 {
					if (parameters->CheckedItems[i]->ToString() == "total sales")
					{
						result->chart->Series->Add("total sales");
						result->chart->Series["total sales"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
						continue;
					}
					for (int j = 0; j < values.size(); j++)
					{						
						

						result->chart->Series->Add(parameters->CheckedItems[i]->ToString() + "_firm_" + j);
						result->chart->Series[parameters->CheckedItems[i]->ToString() + "_firm_" + j]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					}
				 }
				 for (int l = 0; l < int::Parse(iterations->Text); l++)
				 {
					 country->step();
					 for (int i = 0; i < parameters->CheckedItems->Count; i++)
					 {
						 if (parameters->CheckedItems[i]->ToString() == "total sales")
						 {
							 result->chart->Series["total sales"]->Points->AddY(country->stats->sales);
							 continue;
						 }
						 for (int j = 0; j < values.size(); j++)
						 {
							 string value = msclr::interop::marshal_as<std::string>(parameters->CheckedItems[i]->ToString());
							 result->chart->Series[parameters->CheckedItems[i]->ToString() + "_firm_" + j]->Points->AddY(values[j]->get(value));
						 }
					 }
				 }
/*				 country->change_tax(0.3);
				 for (int i = 0; i < 200; i++)
				 {
					 country->step();
				 }//*/
				 result->Show();
			 }

private: System::Void test_Click(System::Object^  sender, System::EventArgs^  e) {
			 country->step(float::Parse(plan_value->Text), float::Parse(price_value->Text));
			 sold_value->Text = (System::Convert::ToString(firms[0]->get("sold")));
			 storage_value->Text = (System::Convert::ToString(firms[0]->get("storage")));
			 production_value->Text = (System::Convert::ToString(firms[0]->get("production")));
			 plan_value->Text = (System::Convert::ToString(firms[0]->get("plan")));
			 price_value->Text = (System::Convert::ToString(firms[0]->get("price")));
			 salary_value->Text = (System::Convert::ToString(firms[0]->get("salary")));
			 profit_value->Text = (System::Convert::ToString(firms[0]->get("profit")));
		 }
};
}

