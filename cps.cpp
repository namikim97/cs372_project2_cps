// cps.cpp
// Project 2 for CS372
// Alex L, Simeon N, Nami K
// Created: 20 Mar 2019
// Modified: 20 Mar 2019
//
// Source for CPS

#include "cps.h"

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
    of << "%%Pages: " << pages.size() << endl;
    of << "%1 \n /inch {72 mul} def" << endl;
    int pageNumber = 1;
    for(auto i : pages)
    {
        of << "%%Page: " << pageNumber << " " << pageNumber << endl;
        of << i.getPostScriptCode();
        of << " \n showpage" << endl; 
        ++pageNumber;
    }
    
    of.close();
    cout << "Postscript Output Successful" << endl;
}

void testShapes(void)
{
	Circle circle(20);
	Polygon pentagon(5, 30);
	//Rectangle recta(20, 30);
	//Triangle tri(3, 20);
	//Square sq(20, 20);

	Page basicShapes;

	basicShapes.drawToPage(circle1, 40, 40);
	basicShapes.drawToPage(pentagon1, 144, 144);
	// basicShapes.drawToPage(recta, 100, 100);
	// basicShapes.drawToPage(tri, 200, 200);
	// basicShapes.drawToPage(sq, 300, 300);

	PSOutput output;
	output.addPage(basicShapes);
	cout << "Testing file output" << endl;
	output.PSOutput_File("testShapes.ps");
}


int main()
{
	testShapes();
    return 0;
}
