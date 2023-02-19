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
}

