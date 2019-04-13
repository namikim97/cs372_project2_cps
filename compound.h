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

class Compound : public Shape
{
public:
    Compound(std::initializer_list<shared_ptr<Shape>> shapes);;
    void setHeightWidth();
    std::string getPostScriptCode() const override;

    virtual std::string genPSCode() const = 0;

protected:
    //std::initializer_list<shared_ptr<Shape>> _shapes;
    std::vector<shared_ptr<Shape>> _shapes;
    std::string _postScriptCode;
private:
    double _height = 0;
    double _width = 0;
};


class Layered : public Compound
{
public:
    using Compound::Compound;

    std::string genPSCode() const override;
};


class Vertical : public Compound
{
public:
    using Compound::Compound;

    std::string genPSCode() const override;
};

class Horizontal : public Compound
{
public:
    using Compound::Compound;

    std::string genPSCode() const override;
};

#endif //CPS_COMPOUND_H
