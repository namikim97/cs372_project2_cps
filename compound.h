// compound.h
// Header file for Compound Shape classes.

#ifndef CPS_COMPOUND_H
#define CPS_COMPOUND_H

#include "shapes.h"

// Compound Shapes

class Rotated : public Shape
{
public:
    Rotated(const Shape &s, double rotation);
    string getPostScriptCode() const override;

private:
    double _origWidth;
    double _origHeight;
    double _rotation;
    string _postScriptCode;
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

#endif //CPS_COMPOUND_H