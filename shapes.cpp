// shapes.cpp
// Source file for Shape classes.

#include "shapes.h"
#include <string>
#include <cmath>
using std::string;

double Shape::getHeight() const
{
    return _height;
}

double Shape::getWidth() const
{
    return _width;
}

void Shape::setHeight(double height)
{
    _height = height;
}

void Shape::setWidth(double width)
{
    _width = width;
}

string Shape::drawShape(const Shape &s, int x, int y)
{
    string retPSCode;
//TODO: The problem with heights for polygons with odd numbers of sides is in the to_string(y) below.
    retPSCode = "gsave\n" + to_string(x) + " " + to_string(y) +
                " translate\n" + s.getPostScriptCode() + 
                "\nstroke\ngrestore\n";

    return retPSCode;
}


Circle::Circle(double radius)
{
    _radius = radius;
    setHeight(radius * 2.0);
    setWidth(radius * 2.0);
}

double Circle::getRadius() const
{
    return _radius;
}

string Circle::getPostScriptCode() const
{
    string radius = to_string(getRadius());
    string retPSCode = "newpath\n"
                       "0 0 " + radius + " 0 360 arc\n";

    return retPSCode;
}

Polygon::Polygon(int numOfSides, double sideLength)
{
    _numOfSides = numOfSides;
    _sideLength = sideLength;
    _triHeight = calcTriHeight();
    _triHypot = calcTriHypot();
    _innerAngle = calcInnerAngle();
    setHeight(calcHeight());
    setWidth(calcWidth());
}

double Polygon::calcTriHeight()
{
    return getTriHypot() * std::cos(M_PI/getNumOfSides());
}

double Polygon::calcTriHypot()
{
    return ( (getSideLength()/2.0) / (std::sin(M_PI/getNumOfSides())) );
}

double Polygon::calcHeight()
{
    int sides = getNumOfSides();
    if(sides % 2 == 0)
    {
        return getTriHeight() * 2.0;
    }
    else
    {
        auto h = (getTriHeight() + getTriHypot());
        if (h < 0.001 && h > -0.001){
            h = 0.0;
        }
        return h;
    }
}

double Polygon::calcWidth()
{
    int sides = getNumOfSides();

    if(sides == 3)
    {
        return getSideLength();
    }

    else if(sides % 4 == 0)
    {
        return getTriHeight() * 2.0;
    }

    else if(sides % 2 == 0)
    {
        return getTriHypot() * 2.0;
    }

    else // number of sides is odd and it's not a triangle
    {
        double bigTriAngle = (360.0/sides) * ((sides - 1.0)/2.0);
        return 2.0 * getTriHypot() * sin((bigTriAngle/2.0) * (3.14/180));
    }
}

double Polygon::calcInnerAngle()
{
    int sides = getNumOfSides();
    return ((sides - 2.0) * 180) / sides;
}

int Polygon::getNumOfSides() const
{
    return _numOfSides;
}

double Polygon::getSideLength() const
{
    return _sideLength;
}

double Polygon::getTriHeight() const
{
    return _triHeight;
}

double Polygon::getTriHypot() const
{
    return _triHypot;
}

double Polygon::getInnerAngle() const
{
    return _innerAngle;
}


string Polygon::getPostScriptCode() const
{
    double sideminusone = getNumOfSides() - 1.0;
    string SideMinusOne = to_string(sideminusone);
    double roationangle = 180.0 - getInnerAngle();
    string RotationAngle = to_string(roationangle);
    string draw_X = to_string(-getSideLength()/2.0);
    //string draw_Y = to_string((float) -getHeight() / 2.0);
    string draw_Y;
    if ((float)-getHeight()/2.0 < 0.0001){
        draw_Y = "0.0";
    }
    else {
        draw_Y = to_string((float) -getHeight() / 2.0);
    }
    string SideLength = to_string(getSideLength());

    string retPSCode = 
        "newpath\n" + 
        draw_X + " " + draw_Y + " moveto\n" +
        "1 1 " + SideMinusOne + " {\n" +
        SideLength + " 0 rlineto\n" + 
        RotationAngle + " rotate\n" +
        "} for\n" + 
        "closepath\n";

    return retPSCode;
}

Rectangle::Rectangle(double width, double height) {
    setWidth(width);
    setHeight(height);
}

string Rectangle::getPostScriptCode() const {
    // double halfWidth = getWidth()/2, halfHeight = getHeight()/2;
    // string originX = "x " + to_string(halfWidth) + " sub";
    // string originY = "y " + to_string(halfHeight) + " sub";
    // string strWidth = to_string(getWidth()), strHeight = to_string(getHeight());
    // string originXWidthAdd = originX + " " + strWidth + " add ";
    // string originYHeightAdd = originY + " " + strHeight + " add ";

    // string PostScriptCode = "newpath\n" +
    //                         originX + " " + originY + " moveto\n" +
    //                         originXWidthAdd + originY + " lineto\n" +
    //                         originXWidthAdd + originYHeightAdd + " lineto\n" +
    //                         originX + " " + originYHeightAdd + " lineto\n" +
    //                         "closepath\n";

    double halfWidth = -getWidth()/2.0;
    double halfHeight = -getHeight()/2.0;
    string HalfWidth = to_string(halfWidth);
    string HalfHeight = to_string(halfHeight);
    string Width = to_string(getWidth());
    string Height = to_string(getHeight());

    string retPSCode = "newpath\n" +
                        HalfWidth + " " + HalfHeight + " moveto\n" +
                        Width + " 0 rlineto\n" +
                        "0 " + Height + " rlineto\n" +
                        "0 " + Width + " sub 0 rlineto\n" +
                        "closepath\n";

    return retPSCode;
}

//due to shape complexity, a radius < 35.0 will be converted to 35.0
RainbowSnowman::RainbowSnowman(double radius) : _radius{radius}{
    if (_radius < 35.0){
        _radius = 35.0;
    }
    setHeight(radius * 2.0 * 1.75);
    setWidth(radius * 2.0);
}

string RainbowSnowman::getPostScriptCode() const {
    string retPsCode = "newpath\n"
            "/snowY 325 def\n"
            "/s " + to_string((int)_radius) + " def\n" +
            "3 {\n"
            "        /r1 0 def\n"
            "        /g1 0.15 def\n"
            "        /b1 0.5 def\n"
            "        gsave\n"
            "        425 snowY translate\n"
            "        0 30 360 {\n"
            "        /r1 r1 0.1 add def\n"
            "        g1 g1 0.1 sub def\n"
            "        b1 b1 0.05 add def\n"
            "                gsave\n"
            "                rotate\n"
            "                r1 g1 b1 setrgbcolor\n"
            "                s 3 s 0 360 arc closepath stroke\n"
            "                grestore\n"
            "        } for\n"
            "        grestore\n"
            "        /oldPlusNewRadius s s add def\n"
            "        /s s 15 sub def\n"
            "        2 {\n"
            "                /oldPlusNewRadius oldPlusNewRadius s add def\n"
            "        } repeat\n"
            "        /snowY snowY oldPlusNewRadius add def\n"
            "} repeat\n";

    return retPsCode;

}


Spacer::Spacer(double width, double height) {
    setWidth(width);
    setHeight(height);
}

string Spacer::getPostScriptCode() const {
    double halfWidth = getWidth()/2.0, halfHeight = getHeight()/2.0;
    string originX = "x " + to_string(halfWidth) + " sub";
    string originY = "y " + to_string(halfHeight) + " sub";
    string strWidth = to_string(getWidth()), strHeight = to_string(getHeight());
    string originXWidthAdd = originX + " " + strWidth + " add ";
    string originYHeightAdd = originY + " " + strHeight + " add ";

    string PostScriptCode = "newpath\n" +
                            originX + " " + originY + " moveto\n" +
                            originXWidthAdd + originY + " lineto\n" +
                            originXWidthAdd + originYHeightAdd + " lineto\n" +
                            originX + " " + originYHeightAdd + " lineto\n" +
                            "closepath\n";

    return PostScriptCode;
}

