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


    double getWidth() const override {
        double max = 0.0;
        for(auto const & shape : _shapes) {
            if (shape->getWidth() >= max)
                max = shape->getWidth();
        }
        return max;
    }

    double getHeight() const override {
        double total = 0.0;
        for(auto const & shape : _shapes) {
            total += shape->getHeight();
        }
        return total;
    }

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

    double getWidth() const override {
        double total = 0.0;
        for(auto const & shape : _shapes) {
            total += shape->getWidth();
        }
        return total;
    }

    double getHeight() const override {
        double max = 0.0;
        for(auto const & shape : _shapes) {
            if (shape->getHeight() >= max)
                max = shape->getHeight();
        }
        return max;
    }

private:
    vector<std::shared_ptr<Shape>> _shapes;
};

#endif //CPS_COMPOUND_H
