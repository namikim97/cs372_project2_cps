// page.h
// Header file for Page class.

#ifndef CPS_PAGE_H
#define CPS_PAGE_H

#include "shapes.h"
#include <string>
#include <vector>

// postscript output

class Page
{
public:
    void drawToPage(const Shape &s, int x, int y);
    std::string getPostScriptCode();

private:
    std::string _postScriptCode;
};

class PSOutput
{
public:
    void addPage(const Page &p);
    void PSOutput_File(std::string filename);

private:
    std::string _postScriptCode;
    std::vector<Page> pages;
};


#endif //CPS_PAGE_H
