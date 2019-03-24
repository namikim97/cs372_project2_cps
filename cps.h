// cps.h
// Project 2 for CS372
// Alex L, Simeon N, Nami K
// Created: 20 Mar 2019
// Modified: 20 Mar 2019
//
// Header for CPS

#ifndef CPS_H_INCLUDED
#define CPS_H_INCLUDED

#include <string>
using std::string;
#include <math.h>

// Nami 
class Shape
{
public:

	virtual double getHeight() const;
	virtual double getWidth() const;
	virtual string getPostScriptCode() const = 0;

private:

	double _height;
	double _width;

protected:

	void setHeight(double height);
	void setWidth(double width);

	//for testing later
	//string drawShape(const shape &s, int x, int y);
};

// Basic Shapes

class Circle : public Shape
{
public:

	Circle(double radius);
	double getRadius() const;
	string getPostScriptCode() const override;

private:

	double _radius;
}; 

// Nami
class Polygon : public Shape
{
public:

	Polygon(int numOfSides, double sideLength);
	double calcTriHeight();
	double calcTriHypot();
	double calcHeight();
	double calcWidth();
	double calcInnerAngle();
	int getNumOfSides() const;
	double getSideLength() const;
	double getTriHeight() const;
	double getTriHypot() const;
	double getInnerAngle() const;

	string getPostScriptCode() const override;

private:

	int _numOfSides;
	double _sideLength;
	double _triHeight;
	double _triHypot;
	double _innerAngle;

};

// Simeon
class Rectangle : public Shape
{
	// TO DO
}; 

// Simeon
class Spacer : public Shape
{
	// TO DO
};

// Alex
class Square : public Polygon
{
	// TO DO
};

// Alex
class Triangle : public Polygon
{
	// TO DO
};


// Compound Shapes

class Rotated : public Shape
{
	// TO DO
};

class Scaled : public Shape
{
	// TO DO
};

class Layered : public Shape
{
	// TO DO
};

class Vertical : public Shape
{
	// TO DO
};

class Horizontal : public Shape
{
	// TO DO
};


// postscript output

class PS_Output
{	
	// TODO
};

#endif //CPS_H_INCLUDED