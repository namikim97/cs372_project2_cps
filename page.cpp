// page.cpp
// Source file for Page class.

#include "page.h"

void Page::drawToPage(const Shape &s, int x, int y)
{
    _postScriptCode += "gsave \n";
    _postScriptCode += to_string(x) + " " + to_string(y) + " translate\n";
    _postScriptCode += s.getPostScriptCode();
    _postScriptCode += "\n stroke \n grestore \n";
}

string Page::getPostScriptCode()
{
    return _postScriptCode;
}

void PSOutput::addPage(const Page &p)
{
    pages.push_back(p);
}

void PSOutput::PSOutput_File(string filename)
{
    ofstream of(filename);
    of << "%%Pages: " << pages.size() << "\n";
    of << "%1 \n /inch {72 mul} def \n";
    int pageNumber = 1;
    for(auto i : pages)
    {
        of << "%%Page: " << pageNumber << " " << pageNumber << "\n";
        of << i.getPostScriptCode();
        of << " \n showpage \n";
        ++pageNumber;
    }

    of.close();
    cout << "Postscript Output Successful\n";
}