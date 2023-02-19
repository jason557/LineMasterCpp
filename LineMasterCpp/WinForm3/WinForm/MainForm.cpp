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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::ofstream file;
path createSubDir(const path& sub_dir_name, const path& file_name);
std::filesystem::path getOutputPath(const std::filesystem::path& file_name);
//bool DragTest();

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

void WinForm::MainForm::outputAllLine()
{
	
	for (int i = 0; i <= 2; i++)
	{
		WinForm::Line^ myLine = gcnew WinForm::Line();
		// set its properties
		myLine->X1 = 10 * i;
		myLine->Y1 = 20 * i;
		myLine->X2 = 30 * i;
		myLine->Y2 = 40 * i;
		myLine->LineWidth = 2;
		myLine->color = Color::Red;
		file << "X1= " << myLine->X1 << "  Y1= " << myLine->Y1 << endl;
		myList->AddLine(myLine);
	}	
	file << "Count = " << myList->Size();
	file << endl; 
	// access the Line object using the [] operator
	
	for (int i = 0; i <= 2; i++) {
		WinForm::Line^ myLine = myList[i];
		file << "X1= " << myLine->X1 << "  Y1= " << myLine->Y1 << "  X2= " << myLine->X2 << "  Y2= " << myLine->Y2 << endl;
	}
	file << endl;
	//// access the Line object using the GetLines method
	//List<WinForm::Line^>^ lines = myList->GetLines();
	//for (int i = 0; i <= 2; i++) {
	//	WinForm::Line^ myLine = lines[i];
	//	file << "X1= " << myLine->X1 << "  Y1= " << myLine->Y1 << "  X2= " << myLine->X2 << "  Y2= " << myLine->Y2 << endl;
	//}
	
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

