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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ drawingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lineMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ rectangleMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ crossLineMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ outputMenu;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->drawingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->crossLineMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->outputMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->drawingToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(824, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			this->drawingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->lineMenu,
					this->rectangleMenu, this->crossLineMenu, this->outputMenu
			});
			this->drawingToolStripMenuItem->Name = L"drawingToolStripMenuItem";
			this->drawingToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->drawingToolStripMenuItem->Text = L"Drawing";
			this->lineMenu->Name = L"lineMenu";
			this->lineMenu->Size = System::Drawing::Size(180, 22);
			this->lineMenu->Text = L"Line";
			this->rectangleMenu->Name = L"rectangleMenu";
			this->rectangleMenu->Size = System::Drawing::Size(180, 22);
			this->rectangleMenu->Text = L"Rectangle";
			this->crossLineMenu->Name = L"crossLineMenu";
			this->crossLineMenu->Size = System::Drawing::Size(180, 22);
			this->crossLineMenu->Text = L"CrossLine";
			this->outputMenu->Name = L"outputMenu";
			this->outputMenu->Size = System::Drawing::Size(180, 22);
			this->outputMenu->Text = L"Output";
			this->outputMenu->Click += gcnew System::EventHandler(this, &MainForm::outputMenu_Click);
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(824, 423);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseUp);
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 447);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	WinForm::LineList^ myList = gcnew WinForm::LineList();
	public: void openfile();
	public: void closefile();
	public: void outputAllLine();
	public: void outputExample();
	public: void mouseClick(System::Windows::Forms::MouseEventArgs^ e);
	public: void mouseDown(System::Windows::Forms::MouseEventArgs^ e);
	public: void mouseMove(System::Windows::Forms::MouseEventArgs^ e);
	public: void mouseUp(System::Windows::Forms::MouseEventArgs^ e);
    public: void rePaint(System::Windows::Forms::PaintEventArgs^ e);
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		openfile();
		//outputExample();
	}
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		closefile();
	}
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		mouseClick(e);
	}
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		mouseDown(e);
	}
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		mouseMove(e);
	}
	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		mouseUp(e);
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		rePaint(e);
	}
	private: System::Void outputMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		outputAllLine();
	}
};
}
