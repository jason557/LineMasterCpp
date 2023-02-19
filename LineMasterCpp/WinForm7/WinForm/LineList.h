#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace WinForm {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    ref class Line
    {
    public:
        int X1, Y1, X2, Y2, Width, Height, LineWidth;
        Color color;
        String^ lineType, ^ Text, ^ SelectPoint;
        bool Selected;

        Line() : X1(0), Y1(0), X2(0), Y2(0), Width(0), Height(0), LineWidth(0), color(Color::Lime), lineType("NULL"), Text(""), SelectPoint("NULL"), Selected(false)
        {
        }
        int getX2(int _X, int _Width)
        {
            return _X + _Width;
        }
        int getY2(int _Y, int _Height)
        {
            return _Y + _Height;
        }
    };

    ref class LineList
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

        List<Line^>^ GetLines()
        {
            return lines;
        }
    };
}


