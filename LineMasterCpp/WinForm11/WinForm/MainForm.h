#pragma once
#include "LineList.h"
#//include <msclr/marshal_cppstd.h>
namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace std;
	
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
	private: System::Windows::Forms::ToolStripMenuItem^ colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ redColorMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ blueColorMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ yellowColorMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ greenColorMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ FuchsiaColorMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ copyMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ moveMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ clearAllMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ screenCopyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ display1Menu;
	private: System::Windows::Forms::ToolStripMenuItem^ display2Menu;
	private: System::Windows::Forms::ToolStripMenuItem^ display3Menu;
	private: System::Windows::Forms::ToolStripMenuItem^ display4Menu;
	private: System::Windows::Forms::ToolStripMenuItem^ savePictureMenu;


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
			this->copyMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redColorMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueColorMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->yellowColorMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenColorMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FuchsiaColorMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->screenCopyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->display1Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->display2Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->display3Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->display4Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->savePictureMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->drawingToolStripMenuItem,
					this->colorToolStripMenuItem, this->screenCopyToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1240, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// drawingToolStripMenuItem
			// 
			this->drawingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->lineMenu,
					this->rectangleMenu, this->crossLineMenu, this->outputMenu, this->copyMenu, this->moveMenu, this->clearAllMenu, this->deleteMenu
			});
			this->drawingToolStripMenuItem->Name = L"drawingToolStripMenuItem";
			this->drawingToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->drawingToolStripMenuItem->Text = L"Drawing";
			// 
			// lineMenu
			// 
			this->lineMenu->Name = L"lineMenu";
			this->lineMenu->Size = System::Drawing::Size(180, 22);
			this->lineMenu->Text = L"Line";
			this->lineMenu->Click += gcnew System::EventHandler(this, &MainForm::lineMenu_Click);
			// 
			// rectangleMenu
			// 
			this->rectangleMenu->Name = L"rectangleMenu";
			this->rectangleMenu->Size = System::Drawing::Size(180, 22);
			this->rectangleMenu->Text = L"Rectangle";
			this->rectangleMenu->Click += gcnew System::EventHandler(this, &MainForm::rectangleMenu_Click);
			// 
			// crossLineMenu
			// 
			this->crossLineMenu->Name = L"crossLineMenu";
			this->crossLineMenu->Size = System::Drawing::Size(180, 22);
			this->crossLineMenu->Text = L"CrossLine";
			this->crossLineMenu->Click += gcnew System::EventHandler(this, &MainForm::crossLineMenu_Click);
			// 
			// outputMenu
			// 
			this->outputMenu->Name = L"outputMenu";
			this->outputMenu->Size = System::Drawing::Size(180, 22);
			this->outputMenu->Text = L"Output";
			this->outputMenu->Click += gcnew System::EventHandler(this, &MainForm::outputMenu_Click);
			// 
			// copyMenu
			// 
			this->copyMenu->Name = L"copyMenu";
			this->copyMenu->Size = System::Drawing::Size(180, 22);
			this->copyMenu->Text = L"Copy";
			this->copyMenu->Click += gcnew System::EventHandler(this, &MainForm::copyMenu_Click);
			// 
			// moveMenu
			// 
			this->moveMenu->Name = L"moveMenu";
			this->moveMenu->Size = System::Drawing::Size(180, 22);
			this->moveMenu->Text = L"Move";
			this->moveMenu->Click += gcnew System::EventHandler(this, &MainForm::moveMenu_Click);
			// 
			// clearAllMenu
			// 
			this->clearAllMenu->Name = L"clearAllMenu";
			this->clearAllMenu->Size = System::Drawing::Size(180, 22);
			this->clearAllMenu->Text = L"ClearAll";
			this->clearAllMenu->Click += gcnew System::EventHandler(this, &MainForm::clearAllMenu_Click);
			// 
			// deleteMenu
			// 
			this->deleteMenu->Name = L"deleteMenu";
			this->deleteMenu->Size = System::Drawing::Size(180, 22);
			this->deleteMenu->Text = L"Delete";
			this->deleteMenu->Click += gcnew System::EventHandler(this, &MainForm::deleteMenu_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->redColorMenu,
					this->blueColorMenu, this->yellowColorMenu, this->greenColorMenu, this->FuchsiaColorMenu
			});
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->colorToolStripMenuItem->Text = L"Color";
			// 
			// redColorMenu
			// 
			this->redColorMenu->Name = L"redColorMenu";
			this->redColorMenu->Size = System::Drawing::Size(180, 22);
			this->redColorMenu->Text = L"Red";
			this->redColorMenu->Click += gcnew System::EventHandler(this, &MainForm::redColorMenu_Click);
			// 
			// blueColorMenu
			// 
			this->blueColorMenu->Name = L"blueColorMenu";
			this->blueColorMenu->Size = System::Drawing::Size(180, 22);
			this->blueColorMenu->Text = L"Blue";
			this->blueColorMenu->Click += gcnew System::EventHandler(this, &MainForm::blueColorMenu_Click);
			// 
			// yellowColorMenu
			// 
			this->yellowColorMenu->Name = L"yellowColorMenu";
			this->yellowColorMenu->Size = System::Drawing::Size(180, 22);
			this->yellowColorMenu->Text = L"Yellow";
			this->yellowColorMenu->Click += gcnew System::EventHandler(this, &MainForm::yellowColorMenu_Click);
			// 
			// greenColorMenu
			// 
			this->greenColorMenu->Name = L"greenColorMenu";
			this->greenColorMenu->Size = System::Drawing::Size(180, 22);
			this->greenColorMenu->Text = L"Green";
			this->greenColorMenu->Click += gcnew System::EventHandler(this, &MainForm::greenColorMenu_Click);
			// 
			// FuchsiaColorMenu
			// 
			this->FuchsiaColorMenu->Name = L"FuchsiaColorMenu";
			this->FuchsiaColorMenu->Size = System::Drawing::Size(180, 22);
			this->FuchsiaColorMenu->Text = L"Fuchsia";
			this->FuchsiaColorMenu->Click += gcnew System::EventHandler(this, &MainForm::FuchsiaColorMenu_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1240, 712);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseUp);
			// 
			// screenCopyToolStripMenuItem
			// 
			this->screenCopyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->display1Menu,
					this->display2Menu, this->display3Menu, this->display4Menu, this->savePictureMenu
			});
			this->screenCopyToolStripMenuItem->Name = L"screenCopyToolStripMenuItem";
			this->screenCopyToolStripMenuItem->Size = System::Drawing::Size(82, 20);
			this->screenCopyToolStripMenuItem->Text = L"ScreenCopy";
			// 
			// display1Menu
			// 
			this->display1Menu->Name = L"display1Menu";
			this->display1Menu->Size = System::Drawing::Size(180, 22);
			this->display1Menu->Text = L"Display1";
			this->display1Menu->Click += gcnew System::EventHandler(this, &MainForm::display1Menu_Click);
			// 
			// display2Menu
			// 
			this->display2Menu->Name = L"display2Menu";
			this->display2Menu->Size = System::Drawing::Size(180, 22);
			this->display2Menu->Text = L"Display2";
			this->display2Menu->Click += gcnew System::EventHandler(this, &MainForm::display2Menu_Click);
			// 
			// display3Menu
			// 
			this->display3Menu->Name = L"display3Menu";
			this->display3Menu->Size = System::Drawing::Size(180, 22);
			this->display3Menu->Text = L"Display3";
			this->display3Menu->Click += gcnew System::EventHandler(this, &MainForm::display3Menu_Click);
			// 
			// display4Menu
			// 
			this->display4Menu->Name = L"display4Menu";
			this->display4Menu->Size = System::Drawing::Size(180, 22);
			this->display4Menu->Text = L"Display4";
			this->display4Menu->Click += gcnew System::EventHandler(this, &MainForm::display4Menu_Click);
			// 
			// savePictureMenu
			// 
			this->savePictureMenu->Name = L"savePictureMenu";
			this->savePictureMenu->Size = System::Drawing::Size(180, 22);
			this->savePictureMenu->Text = L"SavePicture";
			this->savePictureMenu->Click += gcnew System::EventHandler(this, &MainForm::savePictureMenu_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1240, 736);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
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
	public: void outputExample();
	public: void mouseClick(System::Windows::Forms::MouseEventArgs^ e);
	public: void mouseDown(System::Windows::Forms::MouseEventArgs^ e);
	public: void mouseMove(System::Windows::Forms::MouseEventArgs^ e);
	public: void mouseUp(System::Windows::Forms::MouseEventArgs^ e);
    public: void rePaint(System::Windows::Forms::PaintEventArgs^ e);
	public: void keyDownEvent(System::Windows::Forms::KeyEventArgs^ e);
	public: void keyUpEvent(System::Windows::Forms::KeyEventArgs^ e);
	public: void lineMenuItem();
	public: void rectangleMenuItem();
	public: void crossLineMenuItem();
    public: void outputAllLine();
    public: void redColorMenuItem();
    public: void blueColorMenuItem();
    public: void yellowColorMenuItem();
    public: void greenColorMenuItem();
    public: void fuchsiaColorMenuItem();
    public: void copyEvent();
    public: void moveEvent();
    public: void clearAllEvent();
    public: void deleteEvent();
	void WorkingAreaScreenCopy(int i)
	{
		if (i > Screen::AllScreens->Length - 1) { i = 0; }
	    System::Drawing::Rectangle screenBounds = Screen::AllScreens[i]->WorkingArea;
		int screenWidth = screenBounds.Width;
		int screenHeight = screenBounds.Height;
		Bitmap^ bmpScreen = gcnew Bitmap(screenWidth, screenHeight);
		Graphics^ gfxScreen = Graphics::FromImage(bmpScreen);
		gfxScreen->CopyFromScreen(screenBounds.X, screenBounds.Y, 0, 0, screenBounds.Size);
		pictureBox1->Image = bmpScreen;
	}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		openfile();
		//outputExample();
	}
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		myList->Clear();
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
	private: System::Void lineMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		lineMenuItem();
	}
	private: System::Void rectangleMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		rectangleMenuItem();
	}
	private: System::Void crossLineMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		crossLineMenuItem();
	}
	private: System::Void outputMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		outputAllLine();
	}
	private: System::Void redColorMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		redColorMenuItem();
	}
	private: System::Void blueColorMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		blueColorMenuItem();
	}
	private: System::Void yellowColorMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		yellowColorMenuItem();
	}
	private: System::Void greenColorMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	    greenColorMenuItem();
	}
	private: System::Void FuchsiaColorMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		fuchsiaColorMenuItem();
	}
	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		keyDownEvent(e);		
	}
	private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		keyUpEvent(e);
	}
	private: System::Void copyMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		copyEvent();
	}
	private: System::Void moveMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		moveEvent();
	}
	private: System::Void clearAllMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		clearAllEvent();		
	}
	private: System::Void deleteMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteEvent();
	}
	private: System::Void display1Menu_Click(System::Object^ sender, System::EventArgs^ e) {
		int display_Index = 0;		
		WorkingAreaScreenCopy(display_Index);
	}
	private: System::Void display2Menu_Click(System::Object^ sender, System::EventArgs^ e) {
		int display_Index = 1;
		WorkingAreaScreenCopy(display_Index);
	}
	private: System::Void display3Menu_Click(System::Object^ sender, System::EventArgs^ e) {
		int display_Index = 2;
		WorkingAreaScreenCopy(display_Index);
	}
	private: System::Void display4Menu_Click(System::Object^ sender, System::EventArgs^ e) {
		int display_Index = 3;
		WorkingAreaScreenCopy(display_Index);
	}
	private: System::Void savePictureMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->Image != nullptr)
		{
			Bitmap^ bmp = gcnew Bitmap(pictureBox1->Image);
			bmp->Save("screenshot.png", Imaging::ImageFormat::Png);
			delete bmp;
		}
	}
};
}
