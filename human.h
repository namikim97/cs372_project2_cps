// human.h
// Header file for Human class.

#ifndef CPS_HUMAN_H
#define CPS_HUMAN_H

#include "shapes.h"

// Class: Human
// Object draws a randomized human figure out of CPS Shapes.
class Human {
public:
    Human(double, double);
    double getHeight() const;
    double getObesity() const;
    void initializeHead();
    void initializeTorso();
    void initializeArms();
    void initializeLegs();
    string getPostScriptCode();

private:
    unique_ptr<Shape> _head;
    unique_ptr<Shape> _torso;
    vector<unique_ptr<Shape>> _arms;
    vector<unique_ptr<Shape>> _legs;

    double _height;     // Total heeight of figure.
    double _obesity;    // Skinny < 1 < Fat
};


#endif //CPS_HUMAN_H
