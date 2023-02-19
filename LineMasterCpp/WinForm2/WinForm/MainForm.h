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
		int X1, Y1, X2, Y2, Width, Height, LineWidth;
		Color color;
		String^ lineType, ^ Text, ^ SelectPoint;
		bool Selected;

		Line() : X1(0), Y1(0), X2(0), Y2(0), Width(0), Height(0), LineWidth(0), color(Color::Lime), lineType("NULL"), Text(""), SelectPoint("NULL"), Selected(false)
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

		void RemoveLine(Line^ line)
		{
			lines->Remove(line);
		}
		// myList->RemoveAt(0); 
		void RemoveAt(int index)
		{
			if (index >= 0 && index < lines->Count) {
				lines->RemoveAt(index);
			}
		}
		// use the statement in mian()
		//LineList^ myList = gcnew LineList();		
		//int X1 = myList[0]->X1;

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

		bool IsEmpty()
		{
			return lines->Count == 0;
		}
		bool HasLine()
		{
			return lines->Count > 0;
		}
		int Size()
		{
			return lines->Count;
		}
	};
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			//WinForm::LineList^ myList = gcnew WinForm::LineList();
			
			WinForm::Line^ myLine = gcnew WinForm::Line();
			// set its properties
			myLine->X1 = 10;
			myLine->Y1 = 20;
			myLine->X2 = 30;
			myLine->Y2 = 40;
			myLine->LineWidth = 2;
			myLine->color = Color::Red;

			myList->AddLine(myLine);

			// access the Line object using the [] operator
			WinForm::Line^ myLine1 = myList[0];

			// access the Line object using the GetLines method
			List<WinForm::Line^>^ lines = myList->GetLines();
			WinForm::Line^ myLine2 = lines[0];

		}
	};
}
