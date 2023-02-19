#pragma once

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	ref class MainForm;

	public ref class Line
	{
	public:
		int X1, Y1, X2, Y2;
		Color color;
		String^ lineType, ^ Text, ^ SelectPoint;
		bool Selected;

		Line() : X1(0), Y1(0), X2(0), Y2(0), color(Color::Lime)
		{
		}
	};
	public ref class LineList
	{
	private:
		List<Line^>^ lines;

	public:
		LineList()
		{
			lines = gcnew List<Line^>();
		}

		void AddLine(Line^ line)
		{
			lines->Add(line);
		}
	
		property Line^ default[int]
		{
			Line^ get(int index)
			{
				return lines[index];
			}
		}

		List<Line^>^ GetLines()
		{
			return lines;
		}		
	};
	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();			
		}

	protected:
		
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 447);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		WinForm::LineList^ myList = gcnew WinForm::LineList();
		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			WinForm::Line^ myLine = gcnew WinForm::Line();			
			myLine->X1 = 10;
			myLine->Y1 = 20;
			myLine->X2 = 30;
			myLine->Y2 = 40;			
			myLine->color = Color::Red;		
			myList->AddLine(myLine);			
			WinForm::Line^ myLine1 = myList[0];
		}
	};
}
