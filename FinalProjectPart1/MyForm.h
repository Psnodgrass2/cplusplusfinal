#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>
using namespace System::IO;
namespace FinalProjectPart1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		cli::array<System::String^>^ htmlArray;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			htmlArray = gcnew cli::array<System::String^>(30);
			htmlArray[0] = "<!doctype html>";
			htmlArray[1] = "<html>";
			htmlArray[2] = "<title>Congratulations!</title>";
			htmlArray[3] = "<style>";
			htmlArray[4] = "h1 {";
			htmlArray[5] = "";//append to htmlArray4 to set the style of the header
			htmlArray[6] = "text-align: center;}";
			htmlArray[7] = "p {";
			htmlArray[8] = ""; //append to htmlArray8 to set the style of the paragraph
			htmlArray[9] = "text-align: center;}";
			htmlArray[10] = "body {";
			htmlArray[11] = ""; //Modify body, including background color.
			htmlArray[12] = "}";
			htmlArray[15] = "</style>";
			htmlArray[16] = "";
			htmlArray[17] = "<header><h1>";
			htmlArray[18] = "PlaceHolder Text";//Modify htmlArray8 to set the title text
			htmlArray[19] = "</h1></header>";
			htmlArray[20] = "<body><p>";
			htmlArray[21] = "PlaceHolder Text";// Modify htmlArray11 to set the paragraph text
			htmlArray[22] = "</p></body></html>";

		}
		void updateHTMLFile()
		{
			// Generate the updated HTML content
			String^ fileName = "card.html";

			try
			{
				//Set the paragraph and title to their proper values
				if (titleForm->Text == "" || titleForm->Text == " ")
				{
					htmlArray[18] = "Placeholder Text";
				}
				else
				{
					htmlArray[18] = titleForm->Text;
				}
				if (paragraphForm->Text == "" || titleForm->Text == " ")
				{
					htmlArray[21] = "Placeholder Text";
				}
				else
				{
					String^ paragraphText = paragraphForm->Text;
					paragraphText = paragraphText->Replace("\n", "<br>");
					htmlArray[21] = paragraphText;
				}


				// Open the file for writing
				System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(fileName);

				// Write each line of the htmlArray to the file
				for (int i = 0; i < htmlArray->Length; i++)
				{
					writer->WriteLine(htmlArray[i]);
				}

				// Close the writer to flush and release the resources
				writer->Close();

				// Update the displayLabel text to show the file path
				displayLabel->Text = "File saved at: " + System::IO::Path::GetFullPath(fileName);
				webBrowser1->Navigate(System::IO::Path::GetFullPath(fileName));

				
			}
			catch (Exception^ ex)
			{
				// Handle any exceptions that occur during the file writing process
				MessageBox::Show("Error occurred while creating the card: " + ex->Message);
			}
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
	private: System::Windows::Forms::Button^ headerFontSelectorButton;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ writeToFileButton;

	private: System::Windows::Forms::WebBrowser^ webBrowser1;
	private: System::Windows::Forms::Label^ displayLabel;
	private: System::Windows::Forms::Button^ paragraphFontSelectorButton;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ titleForm;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RichTextBox^ paragraphForm;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ backgroundColorButton;
	private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label2;

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
			this->headerFontSelectorButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->writeToFileButton = (gcnew System::Windows::Forms::Button());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->displayLabel = (gcnew System::Windows::Forms::Label());
			this->paragraphFontSelectorButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->titleForm = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->paragraphForm = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->backgroundColorButton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// headerFontSelectorButton
			// 
			this->headerFontSelectorButton->Location = System::Drawing::Point(146, 6);
			this->headerFontSelectorButton->Name = L"headerFontSelectorButton";
			this->headerFontSelectorButton->Size = System::Drawing::Size(75, 23);
			this->headerFontSelectorButton->TabIndex = 0;
			this->headerFontSelectorButton->Text = L"Change";
			this->headerFontSelectorButton->UseVisualStyleBackColor = true;
			this->headerFontSelectorButton->Click += gcnew System::EventHandler(this, &MyForm::headerFontSelectorButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select Header Font:";
			// 
			// writeToFileButton
			// 
			this->writeToFileButton->Location = System::Drawing::Point(252, 6);
			this->writeToFileButton->Name = L"writeToFileButton";
			this->writeToFileButton->Size = System::Drawing::Size(120, 23);
			this->writeToFileButton->TabIndex = 2;
			this->writeToFileButton->Text = L"Save";
			this->writeToFileButton->UseVisualStyleBackColor = true;
			this->writeToFileButton->Click += gcnew System::EventHandler(this, &MyForm::writeToFileButton_Click);
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(392, 6);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(521, 351);
			this->webBrowser1->TabIndex = 4;
			// 
			// displayLabel
			// 
			this->displayLabel->AutoEllipsis = true;
			this->displayLabel->BackColor = System::Drawing::SystemColors::Menu;
			this->displayLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayLabel->Location = System::Drawing::Point(12, 327);
			this->displayLabel->Name = L"displayLabel";
			this->displayLabel->Size = System::Drawing::Size(357, 33);
			this->displayLabel->TabIndex = 5;
			this->displayLabel->Text = L"Information will appear here.";
			// 
			// paragraphFontSelectorButton
			// 
			this->paragraphFontSelectorButton->Location = System::Drawing::Point(146, 35);
			this->paragraphFontSelectorButton->Name = L"paragraphFontSelectorButton";
			this->paragraphFontSelectorButton->Size = System::Drawing::Size(75, 23);
			this->paragraphFontSelectorButton->TabIndex = 6;
			this->paragraphFontSelectorButton->Text = L"Change";
			this->paragraphFontSelectorButton->UseVisualStyleBackColor = true;
			this->paragraphFontSelectorButton->Click += gcnew System::EventHandler(this, &MyForm::paragraphFontSelectorButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(116, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Select Paragraph Font:";
			// 
			// titleForm
			// 
			this->titleForm->Location = System::Drawing::Point(48, 121);
			this->titleForm->Name = L"titleForm";
			this->titleForm->Size = System::Drawing::Size(324, 20);
			this->titleForm->TabIndex = 8;
			this->titleForm->TextChanged += gcnew System::EventHandler(this, &MyForm::titleForm_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Title:";
			// 
			// paragraphForm
			// 
			this->paragraphForm->Location = System::Drawing::Point(48, 165);
			this->paragraphForm->Name = L"paragraphForm";
			this->paragraphForm->Size = System::Drawing::Size(324, 124);
			this->paragraphForm->TabIndex = 10;
			this->paragraphForm->Text = L"";
			this->paragraphForm->TextChanged += gcnew System::EventHandler(this, &MyForm::paragraphForm_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Text:";
			// 
			// backgroundColorButton
			// 
			this->backgroundColorButton->Location = System::Drawing::Point(146, 64);
			this->backgroundColorButton->Name = L"backgroundColorButton";
			this->backgroundColorButton->Size = System::Drawing::Size(75, 23);
			this->backgroundColorButton->TabIndex = 12;
			this->backgroundColorButton->Text = L"Change";
			this->backgroundColorButton->UseVisualStyleBackColor = true;
			this->backgroundColorButton->Click += gcnew System::EventHandler(this, &MyForm::backgroundColorButton_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 69);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Select Background Color:";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(249, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 83);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Preview will update as you change settings or type.";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(925, 369);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->backgroundColorButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->paragraphForm);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->titleForm);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->paragraphFontSelectorButton);
			this->Controls->Add(this->displayLabel);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->writeToFileButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->headerFontSelectorButton);
			this->Name = L"MyForm";
			this->Text = L"Greeting Card Creator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	
	private: System::Void headerFontSelectorButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		FontDialog^ fontDialog = gcnew FontDialog();
		fontDialog->MinSize = 30;
		fontDialog->ShowColor = true;

		// Display the font dialog and capture the result
		System::Windows::Forms::DialogResult result = fontDialog->ShowDialog();

		// If the user selects a font and clicks OK
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			// Get the selected font and store its attributes
			System::Drawing::Font^ selectedFont = fontDialog->Font;
			System::Drawing::Color selectedColor = fontDialog->Color;
			System::Drawing::FontStyle selectedStyle = selectedFont->Style;
			bool isUnderline = selectedFont->Underline;
			bool isStrikeout = selectedFont->Strikeout;

			// Store the font attributes in variables
			String^ fontName = selectedFont->Name;
			int fontSize = static_cast<int>(selectedFont->Size);
			String^ fontColor = "#" + selectedColor.R.ToString("X2") + selectedColor.G.ToString("X2") + selectedColor.B.ToString("X2");

			// Generate the CSS code string
			String^ cssCode = "font-family: " + fontName + "; font-size: " + fontSize + "px; color: " + fontColor + ";";

			// Handle font style separately
			if (selectedStyle == System::Drawing::FontStyle::Italic || selectedStyle.ToString() == "Bold, Italic")
			{
				cssCode += "font-style: italic;";
			}
			if (selectedStyle == System::Drawing::FontStyle::Bold || selectedStyle.ToString() == "Bold, Italic")
			{
				cssCode += "font-weight: bold;";
			}

			// Add text-decoration attributes
			if (isUnderline)
			{
				cssCode += "text-decoration: underline;";
			}
			if (isStrikeout)
			{
				cssCode += "text-decoration: line-through;";
			}

			// Set htmlArray[5] to the CSS code
			htmlArray[5] = cssCode;

			// Example: Display the CSS code in the displayLabel
			displayLabel->Text = "CSS Code: " + cssCode;
			updateHTMLFile();
		}
	}
	private: System::Void writeToFileButton_Click(System::Object^ sender, System::EventArgs^ e)
	{

		try
		{
			// Generate the updated HTML content
			String^ fileName = "card.html";
				//Set the paragraph and title to their proper values
				if (titleForm->Text == "" || titleForm->Text == " ")
				{
					htmlArray[18] = "Placeholder Text";
				}
				else
				{
					htmlArray[18] = titleForm->Text;
				}
				if (paragraphForm->Text == "" || titleForm->Text == " ")
				{
					htmlArray[21] = "Placeholder Text";
				}
				else
				{
					String^ paragraphText = paragraphForm->Text;
					paragraphText = paragraphText->Replace("\n", "<br>");
					htmlArray[21] = paragraphText;
				}

				SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
				saveFileDialog->Filter = "HTML Files (*.html)|*.html|All Files (*.*)|*.*";
				saveFileDialog->Title = "Save As";
				saveFileDialog->RestoreDirectory = true;

				if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					String^ filePath = saveFileDialog->FileName;
					// Use the file path to save the file or perform other operations
					System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filePath);

					// Write each line of the htmlArray to the file
					for (int i = 0; i < htmlArray->Length; i++)
					{
						writer->WriteLine(htmlArray[i]);
					}


					// Close the writer to flush and release the resources
					writer->Close();
				}
				// Open the file for writing
				

				// Update the displayLabel text to show the file path
				displayLabel->Text = "File saved at: " + System::IO::Path::GetFullPath(fileName);

				// Handle any exceptions that occur during the file writing process
			
			// Show a success message or perform any other actions
			MessageBox::Show("Card created successfully!");
		}
		catch (Exception^ ex)
		{
			// Handle any exceptions that occur during the file writing process
			MessageBox::Show("Error occurred while creating the card: " + ex->Message);
		}
	}
private: System::Void paragraphFontSelectorButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	FontDialog^ fontDialog = gcnew FontDialog();
	fontDialog->MinSize = 8;
	fontDialog->ShowColor = true;

	// Display the font dialog and capture the result
	System::Windows::Forms::DialogResult result = fontDialog->ShowDialog();

	// If the user selects a font and clicks OK
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		// Get the selected font and store its attributes
		System::Drawing::Font^ selectedFont = fontDialog->Font;
		System::Drawing::Color selectedColor = fontDialog->Color;
		System::Drawing::FontStyle selectedStyle = selectedFont->Style;
		bool isUnderline = selectedFont->Underline;
		bool isStrikeout = selectedFont->Strikeout;

		// Store the font attributes in variables
		String^ fontName = selectedFont->Name;
		int fontSize = static_cast<int>(selectedFont->Size);
		String^ fontColor = "#" + selectedColor.R.ToString("X2") + selectedColor.G.ToString("X2") + selectedColor.B.ToString("X2");

		// Generate the CSS code string
		String^ cssCode = "font-family: " + fontName + "; font-size: " + fontSize + "px; color: " + fontColor + ";";

		// Handle font style separately
		if (selectedStyle == System::Drawing::FontStyle::Italic || selectedStyle.ToString() == "Bold, Italic")
		{
			cssCode += "font-style: italic;";
		}
		if (selectedStyle == System::Drawing::FontStyle::Bold || selectedStyle.ToString() == "Bold, Italic")
		{
			cssCode += "font-weight: bold;";
		}

		// Add text-decoration attributes
		if (isUnderline)
		{
			cssCode += "text-decoration: underline;";
		}
		if (isStrikeout)
		{
			cssCode += "text-decoration: line-through;";
		}

		// Set htmlArray[8] to the CSS code
		htmlArray[8] = cssCode;

		// Example: Display the CSS code in the displayLabel
		displayLabel->Text = "CSS Code: " + cssCode;
		updateHTMLFile();
	}
}

private: System::Void backgroundColorButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ColorDialog^ colorDialog = gcnew ColorDialog();

	// Display the color dialog and capture the result
	System::Windows::Forms::DialogResult result = colorDialog->ShowDialog();

	// If the user selects a color and clicks OK
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		// Get the selected color
		Color selectedColor = colorDialog->Color;

		// Convert the color to its hexadecimal representation
		String^ backgroundColor = "#" + selectedColor.R.ToString("X2") + selectedColor.G.ToString("X2") + selectedColor.B.ToString("X2");

		// Set the background color of the HTML document's body
		htmlArray[11] = "background-color: " + backgroundColor + ";";
	}
	updateHTMLFile();
}

private: System::Void paragraphForm_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	updateHTMLFile();
}
private: System::Void titleForm_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	updateHTMLFile();
}
};
}
