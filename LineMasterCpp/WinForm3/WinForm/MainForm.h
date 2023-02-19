#pragma once

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;	
	using namespace std;

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
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		WinForm::LineList^ myList = gcnew WinForm::LineList();
		public: void openfile();
		public: void closefile();
		public: void outputAllLine();
		/*public: void mouseClick(System::Windows::Forms::MouseEventArgs^ e);
		public: void mouseDown(System::Windows::Forms::MouseEventArgs^ e);
		public: void mouseMove(System::Windows::Forms::MouseEventArgs^ e);
		public: void mouseUp(System::Windows::Forms::MouseEventArgs^ e);*/
#pragma endregion

		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {			
			openfile();
			outputAllLine();
		}
		private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			closefile();
		}
	};
}
