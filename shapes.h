// shapes.h
// Header file for Shape classes.

#ifndef CPS_SHAPES_H
#define CPS_SHAPES_H

#include <string>
using std::string;
using std::to_string;
#include <math.h>
#include <vector>
using std::vector;
#include <cmath>
using std::sin;
using std::cos;
using std::abs;
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ofstream;

// Nami
class Shape
{
public:
    virtual double getHeight() const;
    virtual double getWidth() const;
    virtual string getPostScriptCode() const = 0;
    virtual ~Shape() = default;

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

// Nami
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
public:
    //Square(double sideLength) : _sideLength{ sideLength } {};

    /*  #not sure if this fucn should return a vector<string> a stream, or something else.
     std::vector<std::string> generatePS() {
     std::vector<std::string> psCode[6];
     psCode->push_back("newpath");
     psCode->push_back()

     }
     */
private:
    double _sideLength;
};

// Alex
class Triangle : public Polygon
{
    // TO DO
};

#endif //CPS_SHAPES_H
