#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // added for min and max functions

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
        Color LineColor;
        String^ LineType, ^ Text, ^ SelectPoint;

        bool Selected;

        Line() : X1(0), Y1(0), X2(0), Y2(0), Width(0), Height(0), LineWidth(0), LineColor(Color::Lime), LineType("NULL"), Text(""), SelectPoint("NULL"), Selected(false)
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
        
        int GetWidth(int _X1, int _X2)
        {
            return abs(_X1 - _X2);
        }

        int GetHeight(int _Y1, int _Y2)
        {
            return abs(_Y1 - _Y2);
        }

        bool SelectLineTest(Point Pt)
        {
            Boolean inBoundary;
            //inBoundary = min(X1, X2) <= Pt.X && Pt.X <= Math.Max(X1, X2) && Math.Min(Y1, Y2) <= Pt.Y && Pt.Y <= Math.Max(Y1, Y2);
            inBoundary = std::minmax({ X1, X2 }).first <= Pt.X && Pt.X <= std::minmax({ X1, X2 }).second && std::minmax({ Y1, Y2 }).first <= Pt.Y && Pt.Y <= std::minmax({ Y1, Y2 }).second;

            if (inBoundary == false) return false;

            double slope = ((double)(Y2 - Y1)) / (X2 - X1);
            double intercept = Y1 - (slope * X1);
            double tolerance = 10;
            double distance = abs(slope * Pt.X - Pt.Y + intercept) / sqrt(slope * slope + 1);
            if (distance <= tolerance)
            {
                Selected = true;
            }
            else
            {
                Selected = false;
            }
            return Selected;
        }
        bool SelectRectangleTest(Point Pt)
        {
            Boolean inBoundary;
            //inBoundary = min(X1, X2) <= Pt.X && Pt.X <= Math.Max(X1, X2) && Math.Min(Y1, Y2) <= Pt.Y && Pt.Y <= Math.Max(Y1, Y2);
            inBoundary = std::minmax({ X1, X2 }).first <= Pt.X && Pt.X <= std::minmax({ X1, X2 }).second && std::minmax({ Y1, Y2 }).first <= Pt.Y && Pt.Y <= std::minmax({ Y1, Y2 }).second;
            if (inBoundary)
            {
                Selected = true;
            }
            else
            {
                Selected = false;
            }
            return Selected;
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

        void Clear()
        {
            lines->Clear();
        }

        property Line^ default[int]
        {
            Line^ get(int index)
            {
                if (index < 0 || index > lines->Count-1) {
                    //std::cerr << "Index out of bounds: " << index << std::endl;
                    return nullptr;
                }
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
