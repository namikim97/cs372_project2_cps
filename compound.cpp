// compound.cpp
// Source file for Compound Shape classes.

#include "compound.h"
#include <string>
using std::string;
using std::to_string;


Rotated::Rotated(const Shape &s, double rotation):_rotation(rotation),
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

    retPSCode = to_string((int)_rotation) + " rotate \n" + _postScriptCode;

    return retPSCode;
}

Scaled::Scaled(const Shape &s, double horScale, double verScale)
                :_horScale(horScale), _verScale(verScale), 
                _origWidth(s.getWidth()), _origHeight(s.getHeight()),
                _postScriptCode(s.getPostScriptCode())
{
    setWidth(_origWidth * horScale);
    setHeight(_origHeight * verScale);
}

string Scaled::getPostScriptCode() const
{
    string retPSCode;

    retPSCode = to_string(_horScale) + " " + to_string(_verScale) +
                " scale\n" + _postScriptCode;

    return retPSCode;
}

Layered::Layered(std::initializer_list<shared_ptr<Shape>> Shapes)
{
    for(auto i : Shapes)
    {
        if(getWidth() < i->getWidth())
        {
            setWidth(i->getWidth());
        }
        if(getHeight() < i->getHeight())
        {
            setHeight(i->getHeight());
        }
        else
        {}
    }

    std::vector<shared_ptr<Shape>> vecShapes(Shapes.begin(), Shapes.end());

    std::string retPSCode;
    double xCenterCoord = getWidth() / 2.0;
    xCenterCoord += (72*2);
    double yCenterCoord = getHeight() / 2.0;
    yCenterCoord += (72+2);

    for(auto i=0; i<vecShapes.size(); ++i)
    {
        xCenterCoord -= (vecShapes[i]->getWidth()) / 2.0;
        yCenterCoord -= (vecShapes[i]->getHeight()) / 2.0;
        //retPSCode += drawToPage(*vecShapes[i], 0, 0);
    }

    _postScriptCode = retPSCode;
}

std::string Layered::getPostScriptCode() const
{
    return _postScriptCode;;
}



