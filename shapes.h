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
#include<memory>
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

// Nami
class Shape
{
public:
    virtual double getHeight() const;
    virtual double getWidth() const;
    virtual std::string getPostScriptCode(int x, int y) const = 0;
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
    explicit Circle(double radius);
    double getRadius() const;
    std::string getPostScriptCode(int x, int y) const override;

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

    std::string getPostScriptCode(int x, int y) const override;

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
public:
    Rectangle(double, double);
    string getPostScriptCode(int x, int y) const override;

};

// Simeon
class Spacer : public Shape
{
public:
    Spacer(double, double);
    string getPostScriptCode(int x, int y) const override;

};


// Alex
class Square : public Polygon
{
public:
    Square(int sideLength): Polygon(4, sideLength){};
};

// Alex
class Triangle : public Polygon
{
public:
    Triangle(int sideLength): Polygon(3, sideLength){};
};

#endif //CPS_SHAPES_H
