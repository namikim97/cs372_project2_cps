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


void Compound::setHeightWidth() {
    for(const auto &i : _shapes)
    {
        if(_width < i->getWidth())
        {
            _width = i->getWidth();
        }
        if(_height < i->getHeight())
        {
            _height = i->getHeight();
        }
        else
        {}
    }
}

Compound::Compound(std::initializer_list<shared_ptr<Shape>> shapes){
    std::vector<shared_ptr<Shape>> vecShapes(shapes.begin(), shapes.end());
    _shapes = vecShapes;
    setHeightWidth();
}

std::string Compound::getPostScriptCode() const {
    return genPSCode();
}

std::string Layered::genPSCode() const {
   // std::vector<shared_ptr<Shape>> vecShapes(_shapes.begin(), _shapes.end());

    std::string retPSCode;
    double xCenterCoord = getWidth() / 2.0;
    double yCenterCoord = getHeight() / 2.0;

    for (auto &vecShape : _shapes) {
        yCenterCoord -= vecShape->getHeight() / 2.0;
        xCenterCoord -= vecShape->getWidth() / 2.0;
        retPSCode += drawShape(*vecShape, 0, 0);
    }
    return retPSCode;
}

std::string Vertical::genPSCode() const {
    std::string retPSCode;
    double yCenterCoord = (_shapes[0]->getHeight()/2.0);
    for(int i=0; i<_shapes.size(); ++i)
    {
        if (i > 0) {
            yCenterCoord -= ((_shapes[i]->getHeight() / 2.0) + (_shapes[i - 1]->getHeight() / 2.0));
        }
        retPSCode += drawShape(*_shapes[i], 0, (int)yCenterCoord);
    }
    return retPSCode;
}

std::string Horizontal::genPSCode() const {
    std::string retPSCode;
    double xCenterCoord = (_shapes[0]->getWidth()/2.0);
    for(int i=0; i<_shapes.size(); ++i)
    {
        if (i > 0) {
            xCenterCoord -= ((_shapes[i]->getWidth() / 2.0) + (_shapes[i - 1]->getWidth() / 2.0));
        }
        retPSCode += drawShape(*_shapes[i], (int)xCenterCoord, 0);
    }

    return retPSCode;
}
