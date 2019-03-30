// compound.h
// Header file for Compound Shape classes.

#ifndef CPS_COMPOUND_H
#define CPS_COMPOUND_H

#include "shapes.h"
#include <string>
#include <initializer_list>
using std::initializer_list;

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
    // TO DO
};

class Layered : public Shape
{
    // TO DO
};

// Simeon
template <class T>
class Vertical : public Shape
{
public:
    Vertical(initializer_list<T> list) : _shapes(list) {}

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
    vector<T> _shapes;

};

class Horizontal : public Shape
{
    // TO DO
};

#endif //CPS_COMPOUND_H
