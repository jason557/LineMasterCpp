#include "MainForm.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <vector>
#include <list>

using namespace System;
using namespace System::Windows::Forms;
using namespace std::filesystem;
using namespace System::Drawing;
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);	
	WinForm::MainForm form;
	Application::Run(% form);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsMouseDown = false;
bool IsMouseDrag = false;
Point StartDownLocation, Point1, Point2, SelectPoint;
Point MouseDownLocation;
int StartX, StartY, CurX, CurY;
int VX1, VY1, VX2, VY2, HX1, HY1, HX2, HY2;
int SelectWidth = 100, SelectHeight = 100;
enum DrawAction {
	Draw, FreeHand, Coping, Moving, CrossLine
};
DrawAction DrawActionChoice = Draw;
enum LineType {
	_Line, _HLine, _VLine, _V3Line, _Rectangle, _Ellipse, _CrossLine_Text
};
LineType LineTypeChoice = _Line;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::ofstream file;
path createSubDir(const path& sub_dir_name, const path& file_name);
std::filesystem::path getOutputPath(const std::filesystem::path& file_name);
bool DragTest();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WinForm::MainForm::openfile()
{
	std::filesystem::path path = getOutputPath("000.txt");
	file.open(path);
	System::String^ pathString = gcnew System::String(path.generic_u8string().c_str());
	WinForm::MainForm::Text = pathString;
	file << path << endl;
}

void WinForm::MainForm::closefile()
{
	file.close();
}



void WinForm::MainForm::mouseClick(System::Windows::Forms::MouseEventArgs^ e) {
	file << "Mouse Click" << endl;
}

void WinForm::MainForm::mouseDown(System::Windows::Forms::MouseEventArgs^ e) {
	file << "Mouse Dwon" << endl;
	IsMouseDown = true;
	StartX = e->X;
	StartY = e->Y;
	CurX = e->X;
	CurY = e->Y;
	StartDownLocation = e->Location;
}


void WinForm::MainForm::mouseMove(System::Windows::Forms::MouseEventArgs^ e) {
	if (IsMouseDown == true)
	{
		CurX = e->X;
		CurY = e->Y;

		switch (DrawActionChoice) {
		case Draw:
			break;
		case FreeHand:
			file << "Drawing a freehand" << std::endl;
			break;
		case Coping:
			file << "Copy" << std::endl;
			break;
		case Moving:
			file << "Move" << std::endl;
			break;
		case CrossLine:
			file << "Drawing a CrossLine" << std::endl;
			break;
		}
		IsMouseDrag = DragTest();
		pictureBox1->Invalidate();
	}
}
bool DragTest()
{
	double length = (StartX - CurX) * (StartX - CurX) + (StartY - CurY) * (StartY - CurY);
	length = std::sqrt(length);

	if (length >= 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void WinForm::MainForm::mouseUp(System::Windows::Forms::MouseEventArgs^ e) {
	file << "Mouse Up" << endl << endl;

	if (e->Button == System::Windows::Forms::MouseButtons::Left && IsMouseDrag == true)
	{
		WinForm::Line^ DrawLine = gcnew WinForm::Line();

		switch (DrawActionChoice) {
		case Draw:
			switch (LineTypeChoice) {

			case _Line:
				DrawLine->X1 = StartX;
				DrawLine->Y1 = StartY;
				DrawLine->X2 = CurX;
				DrawLine->Y2 = CurY;
				break;
			case _Rectangle:
				DrawLine->X1 = StartX;
				DrawLine->Y1 = StartY;
				DrawLine->X2 = CurX;
				DrawLine->Y2 = CurY;
				break;
			}
			break;
		}				
		myList->AddLine(DrawLine);
	}
	IsMouseDrag = false;
	IsMouseDown = false;
	pictureBox1->Invalidate();
}

void WinForm::MainForm::outputExample()
{
	for (int i = 0; i <= 2; i++)
	{
		WinForm::Line^ DrawLine = gcnew WinForm::Line();
		DrawLine->X1 = 10 * i;
		DrawLine->Y1 = 20 * i;
		DrawLine->Y2 = 40 * i;
		DrawLine->LineWidth = 2;
		DrawLine->color = Color::Red;
		file << "X1= " << DrawLine->X1 << "  Y1= " << DrawLine->Y1 << endl;
		myList->AddLine(DrawLine);
	}
	file << "Count = " << myList->Size();
	file << endl;

	// access the Line object using the [] operator	
	for (int i = 0; i <= 2; i++) {
		WinForm::Line^ DrawLine = myList[i];
		file << "X1= " << DrawLine->X1 << "  Y1= " << DrawLine->Y1 << "  X2= " << DrawLine->X2 << "  Y2= " << DrawLine->Y2 << endl;
	}
	file << endl;
}
void WinForm::MainForm::outputAllLine()
{
	for (int i = 0; i <= myList->Size() - 1; i++)
	{
		WinForm::Line^ DrawLine = myList[i];
		file << "X1= " << DrawLine->X1 << "  Y1= " << DrawLine->Y1 << "  X2= " << DrawLine->X2 << "  Y2= " << DrawLine->Y2 << endl;
	}
}

// the function get user's documents directory and create a subdirectory
std::filesystem::path createSubDir(const path & sub_dir_name, const path & file_name) {
	path document_dir = path(getenv("USERPROFILE")) / "Documents";
	path sub_dir = document_dir / sub_dir_name;

	if (!exists(sub_dir)) {
		create_directory(sub_dir);
	}
	path file_path = sub_dir / file_name;

	return file_path;
}


// this function create a file right under exe file directory
std::filesystem::path getOutputPath(const std::filesystem::path& file_name) {
	TCHAR exe_path_buf[MAX_PATH];
	DWORD ret = GetModuleFileName(NULL, exe_path_buf, MAX_PATH);
	if (ret != 0) {
		std::filesystem::path exe_path = exe_path_buf;
		std::filesystem::path exe_dir = exe_path.parent_path();
		std::filesystem::path file_path = exe_dir / file_name;

		return file_path;
	}
	else {
		return NULL;
	}
}

