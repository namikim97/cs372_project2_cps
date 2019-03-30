// compound.cpp
// Source file for Compound Shape classes.

#include "compound.h"
#include <string>
using std::string;
using std::to_string;


Rotated::Rotated(const Shape &s, double rotation):_rotation(rotation),
                                                 _postScriptCode(s.getPostScriptCode())
{
    const double radians = (_rotation * 2.0 * PI)/360.0;

    _origWidth = s.getWidth();
    _origHeight = s.getHeight();

    setWidth(abs(_origWidth * cos(radians) + _origHeight * sin(radians)));
    setHeight(abs(_origWidth * sin(radians) + _origHeight * cos(radians)));
}

string Rotated::getPostScriptCode() const
{
    string retPSCode;

    retPSCode = to_string((int)_rotation) + " rotate\n" + _postScriptCode;

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
    double yCenterCoord = getHeight() / 2.0;
    xCenterCoord += (72*2);
    yCenterCoord += (72*2);

    for(int i=0; i<vecShapes.size(); ++i)
    {   
        yCenterCoord -= vecShapes[i]->getHeight() / 2.0;
        xCenterCoord -= vecShapes[i]->getWidth() / 2.0;
        retPSCode += drawShape(*vecShapes[i], 0, 0);
    }

    _postScriptCode = retPSCode;
}

string Layered::getPostScriptCode() const
{
    return _postScriptCode;
}


double Horizontal::getWidth() const {
    double total = 0.0;
    for(auto const & shape : _shapes) {
        total += shape->getWidth();
    }
    return total;
}

double Horizontal::getHeight() const {
    double max = 0.0;
    for(auto const & shape : _shapes) {
        if (shape->getHeight() >= max)
            max = shape->getHeight();
    }
    return max;
}

double Vertical::getWidth() const {
    double max = 0.0;
    for(auto const & shape : _shapes) {
        if (shape->getWidth() >= max)
            max = shape->getWidth();
    }
    return max;
}

double Vertical::getHeight() const {
    double total = 0.0;
    for(auto const & shape : _shapes) {
        total += shape->getHeight();
    }
    return total;
}
