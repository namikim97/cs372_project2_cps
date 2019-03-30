// shapes.cpp
// Source file for Shape classes.

#include "shapes.h"
#include <string>
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

Circle::Circle(double radius):_radius(radius)
{
    setHeight(radius * 2);
    setWidth(radius * 2);
}

double Circle::getRadius() const
{
    return _radius;
}

string Circle::getPostScriptCode() const
{
    string radius = to_string(getRadius());
    string retPSCode = "newpath\n"
                       "0 0 " + radius + " 0 360 arc\n"
                       "stroke\n";

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
    return getTriHypot() * cos(M_PI/getNumOfSides());
}

double Polygon::calcTriHypot()
{
    return ( (getSideLength()/2) / (sin(M_PI/getNumOfSides())) );
}

double Polygon::calcHeight()
{
    int sides = getNumOfSides();

    if(sides % 2 == 0)
    {
        return getTriHeight() * 2;
    }
    else
    {
        return getTriHeight() + getTriHypot();
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
        return getTriHeight() * 2;
    }

    else if(sides % 2 == 0)
    {
        return getTriHypot() * 2;
    }

    else // number of sides is odd and it's not a triangle
    {
        double bigTriAngle = (360/sides) * ((sides - 1)/2);
        return 2 * getTriHypot() * sin((bigTriAngle/2) * (M_PI/180));
    }
}

double Polygon::calcInnerAngle()
{
    int sides = getNumOfSides();
    return ((sides - 2) * 180) / sides;
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
    string retPSCode = R"(
    newpath
    XDRAW YDRAW moveto
    1 1 SIDESMINUSONE {
        SIDELENGTH 0 rlineto
        ROTATIONANGLE rotate
    } for
        closepath
        stroke
        )";

    double SIDESMINUSONE = getNumOfSides() - 1;
    double ROTATIONANGLE = 180 - getInnerAngle();

    return retPSCode;
}

Rectangle::Rectangle(double width, double height) {
    setWidth(width);
    setHeight(height);
}

string Rectangle::getPostScriptCode() const {
    double halfWidth = getWidth()/2, halfHeight = getHeight()/2;
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
                            "closepath\n" +
                            "stroke\n";

    return PostScriptCode;
}

Spacer::Spacer(double width, double height) {
    setWidth(width);
    setHeight(height);
}

string Spacer::getPostScriptCode() const {
    double halfWidth = getWidth()/2, halfHeight = getHeight()/2;
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
