#pragma once

#include<iostream>
#include<string>
#include<fstream>



namespace Assignment_3 {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	


	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
			

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(240, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 26);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(99, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Find What :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(461, 54);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 26);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(103, 119);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(134, 17);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"match whole word only";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(103, 155);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(81, 17);
			this->checkBox2->TabIndex = 4;
			this->checkBox2->Text = L"match case";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 261);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Assignment 3";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion

		String ^ pattern =" ";
		String ^ paragrapgh =" ";
		int patsize=0;
		int parsize=0;
		int s=0;
		int e=0;
		String ^R=" ";
		String ^C=" ";
		bool found=false;

		void getPattern()
		{
			pattern = textBox1->Text;
			patsize = pattern->Length;

			//MessageBox::Show("Lenght: "
			//	+ patsize);
		}
		void Filereader()
		{
			ifstream rfile;
			char character;
			rfile.open("Research#1.txt");
			if (!(rfile))
			{
			MessageBox::Show( "There's something wrong. File can't be open." );
				exit(0);
			}
			else
			{
				while (!(rfile.eof()))
				{
					rfile.get(character);
					paragrapgh += (Char)character;
				}
				rfile.close();
				parsize =  paragrapgh->Length;
			//	MessageBox::Show("Lenght: "
				//	+ paragrapgh);
			}
		}

		void BF_Compare_NCS()
		{
			int count = 0;
			found = false;
			int upto = parsize - patsize;
			for (int i = 0; i <= upto; i++)
			{
				s = i;
				for (int j = 0; j < patsize; j++)
				{
					if (tolower(pattern[j]) == tolower(paragrapgh[i + j]))
					{
						count++;
					}
					if (tolower(pattern[j]) != tolower(paragrapgh[i + j]))
					{
						count = 0;
						break;
					}
				}
				if (count == patsize)
				{
					found = true;
					break;
				}
			}
			if (found == true)
			{
				e = s + patsize;
				String ^ data;
				//	cout << "Here it is : ";
				for (int i = s; i < e; i++)
				{
					
						data+= paragrapgh[i];
				}

				String^ msg = "Word/s: " + data+ "\n Found At Row :"+R+"Column : "+C;
				String^ title = "Match found!";
				MessageBox::Show(msg, title);

			}
			else
			{
			
				String^ title = "Error!";
				MessageBox::Show("no such data found" , title);
			}
		}

		void position()
		{
			int cnt = 0;
			bool check = true;
			int row = 1, coloum = 1;
			for (int a = 0; a != parsize; a++)
			{
				coloum++;
				if (paragrapgh[a] == '\n')
				{
					row++;
					coloum = 0;
					
				}
				else
				{
					int c = a;
					if (paragrapgh[a] == pattern[0])
					{
						
						for (int b = 0; b != patsize; b++)
						{
							if (paragrapgh[c] == pattern[b])
							{
								c++;
								cnt++;
							}
							else cnt = 0;
						}
					}
				}
				if (cnt == patsize  )
				{
					R += System::Convert::ToString( row);
					C += System::Convert::ToString( coloum);
				//	String^ msg = "Rows  " + R + "  Col " + C;
				//	String^ title = "Text Found At!";
				//	MessageBox::Show(msg, title);
					break;
				}
				
			}
			
		}
		void retun_word()
		{
			fstream file;
			int cnt = 0;
			String ^   word;
			String ^ W;
			int x = 0;
			file.open("Research#1.txt");
			if(!(file))
			{
				for (int a = 0; a != word->Length; a++)
				{
                  
					cnt = 0;
					if (word[a] == pattern[0])
					{
						int c = a;
						for (int b = 0; b != patsize; b++)
						{
							if (word[c] == pattern[b])
							{
								c++;
								cnt++;
							}
							else c = 0;
						}
					}
					if (cnt == patsize)
					{
						
						String^ msg = word;
						String^ title = "Text Found At!";
						MessageBox::Show(msg, title);
						W += word;
						W += " , ";
					}
				}
			}

			String^ msg =  W;
			String^ title = "Text Found At!";
			MessageBox::Show(msg, title);
		}
		void BF_Compare_CS()
		{
			int count = 0;
			found = false;
			int upto = parsize - patsize;
			for (int i = 0; i <= upto; i++)
			{
				s = i;
				for (int j = 0; j < patsize; j++)
				{
					if (pattern[j] == paragrapgh[i + j])
					{
						count++;
					}
					if (pattern[j] != paragrapgh[i + j])
					{
						count = 0;
						break;
					}
				}
				if (count == patsize)
				{
					found = true;
					break;
				}
				else
				{
					continue;
				}
			}
			if (found == true)
			{
				e = s + patsize;
				String ^data;
				for (int i = s; i < e; i++)
				{
					data+=paragrapgh[i];
				}
				String^ msg = "Word/s: " + data + "\n Found At Row :" + R + "Column : " + C;
				String^ title = "Match found!";
				MessageBox::Show(msg, title);
			}
			else
			{
				String^ title = "Error!";
				MessageBox::Show("no such data found", title);
			}
		}


		


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				// BruteForce obj;
				 String ^ d = textBox1->Text;
                
				Filereader();
				getPattern();
				position();
				if (checkBox1->Checked == true && checkBox2->Checked == true)
				{
                 BF_Compare_CS();
				}
				else if (checkBox1->Checked == true && checkBox2->Checked == false)
				{
					BF_Compare_NCS();
				}

				else if (checkBox1->Checked == true && checkBox2->Checked == true)
				{
					BF_Compare_CS();
				}
				else if (checkBox1->Checked == false && checkBox2->Checked == false)
				{
					BF_Compare_NCS();
				}

				//retun_word();
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			
}
};
}
