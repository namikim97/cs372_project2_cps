// shapes.cpp
// Source file for Shape classes.

#include "shapes.h"

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
    string retPSCode = R"(
    newpath
    0 0 RAD 0 360 arc
    )";

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
        )";

    double SIDESMINUSONE = getNumOfSides() - 1;
    double ROTATIONANGLE = 180 - getInnerAngle();

    return retPSCode;
}