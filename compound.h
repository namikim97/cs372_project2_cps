#include <utility>

// compound.h
// Header file for Compound Shape classes.

#ifndef CPS_COMPOUND_H
#define CPS_COMPOUND_H

#include "shapes.h"
#include <string>
#include <initializer_list>
#include <memory> //for std::unique_ptr

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
    // TO DO
};

// Simeon

class Vertical : public Shape
{
public:
    template <typename T>
    Vertical( std::initializer_list<shared_ptr<T>> list) : _shapes(std::move(list)){};

    string getPostScriptCode() const override {
        return "dummy";
    }


    double getWidth() const override;

    double getHeight() const override;

private:
    vector<std::shared_ptr<Shape>> _shapes;

};

class Horizontal : public Shape
{
public:
    template <typename T>
    Horizontal( std::initializer_list<shared_ptr<T>> list) : _shapes(std::move(list)){};

    string getPostScriptCode() const override {
        return "dummy";
    }

    double getWidth() const override;

    double getHeight() const override;

private:
    vector<std::shared_ptr<Shape>> _shapes;
};

#endif //CPS_COMPOUND_H
