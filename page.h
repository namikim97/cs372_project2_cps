// page.h
// Header file for Page class.

#ifndef CPS_PAGE_H
#define CPS_PAGE_H

#include "shapes.h"

// postscript output

class Page
{
public:
    void drawToPage(const Shape &s, int x, int y);
    string getPostScriptCode();

private:
    string _postScriptCode;
};

class PSOutput
{
public:
    void addPage(const Page &p);
    void PSOutput_File(string filename);

private:
    string _postScriptCode;
    vector<Page> pages;
};


#endif //CPS_PAGE_H
