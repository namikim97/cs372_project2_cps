#include <utility>

// compound.h
// Header file for Compound Shape classes.

#ifndef CPS_COMPOUND_H
#define CPS_COMPOUND_H

#include "shapes.h"
#include <string>
#include <initializer_list>
#include <memory> //for std::unique_ptr
#include <vector>

// Compound Shapes

class Rotated : public Shape
{
public:
    Rotated(const Shape &s, double rotation);
    std::string getPostScriptCode() const override;

private:
    double _origWidth;
    double _origHeight;
    double _rotation;
    std::string _postScriptCode;
};

class Scaled : public Shape
{
public:
    Scaled(const Shape &s, double horScale, double verScale);
    std::string getPostScriptCode() const override;

private:
    double _origWidth;
    double _origHeight;
    double _horScale;
    double _verScale;
    std::string _postScriptCode;
};

class Layered : public Shape
{
public:
    Layered(std::initializer_list<shared_ptr<Shape>> Shapes);

    string getPostScriptCode() const override;

private:
    std::string _postScriptCode;
};




class Vertical : public Shape
{
public:
    Vertical(std::initializer_list<shared_ptr<Shape>> Shapes);
    virtual string getPostScriptCode() const override;
private:
    std::string _postScriptCode;
};

class Horizontal : public Shape
{
public:
    Horizontal(std::initializer_list<shared_ptr<Shape>> Shapes);
    virtual string getPostScriptCode() const override;
private:
    std::string _postScriptCode;
};

#endif //CPS_COMPOUND_H
