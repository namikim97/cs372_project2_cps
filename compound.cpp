// compound.cpp
// Source file for Compound Shape classes.

#include "compound.h"
#include <string>
using std::string;
using std::to_string;

Rotated::Rotated(const Shape&s, double rotation):_rotation(rotation),
                                                 _postScriptCode(s.getPostScriptCode())
{
    const double radians = (_rotation * 2.0 * M_PI)/360.0;

    _origWidth = s.getWidth();
    _origHeight = s.getHeight();

    setWidth(abs(_origWidth * cos(radians) + _origHeight * sin(radians)));
    setHeight(abs(_origWidth * sin(radians) + _origHeight * cos(radians)));
}

string Rotated::getPostScriptCode() const
{
    string retPSCode;

    retPSCode = to_string((int)_rotation);
    retPSCode += " rotate \n";
    retPSCode += _postScriptCode;

    return retPSCode;
}