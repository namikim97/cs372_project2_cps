// shapes.h
// Header file for Shape classes.

#ifndef CPS_SHAPES_H
#define CPS_SHAPES_H

#include <string>
using std::string;
using std::to_string;
//#include <math.h>
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

//const double PI = 4*atan(1);


// Nami
class Shape
{
public:
    virtual double getHeight() const;
    virtual double getWidth() const;
    virtual std::string getPostScriptCode() const = 0;
    virtual ~Shape() = default;

private:
    double _height;
    double _width;

protected:
    void setHeight(double height);
    void setWidth(double width);
    std::string drawShape(const Shape &s, int x, int y);
};

// Basic Shapes

// Nami
class Circle : public Shape
{
public:
    explicit Circle(double radius);
    double getRadius() const;
    std::string getPostScriptCode() const override;

private:
    double _radius;
};


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

    std::string getPostScriptCode() const override;

private:
    int _numOfSides;
    double _sideLength;
    double _triHeight;
    double _triHypot;
    double _innerAngle;
};


class Rectangle : public Shape
{
public:
    Rectangle(double, double);
    string getPostScriptCode() const override;

};


class Spacer : public Shape
{
public:
    Spacer(double, double);
    string getPostScriptCode() const override;

};


class Square : public Polygon
{
public:
    explicit Square(double sideLength): Polygon(4, sideLength){}; //4 is an int, # of sides in polygon
};


class Triangle : public Polygon
{
public:
    explicit Triangle(double sideLength): Polygon(3, sideLength){}; //3 is an int,# of sides in polygon
};

class RainbowBall : public Shape
{
public:
    explicit RainbowBall(double radius, double r, double g, double b);
    string getPostScriptCode() const override;

private:
    double _r;
    double _g;
    double _b;
    double _radius;
};



#endif //CPS_SHAPES_H
