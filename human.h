// human.h
// Header file for Human class.

#ifndef CPS_HUMAN_H
#define CPS_HUMAN_H

#include "shapes.h"
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// Class: Human
// Object draws a randomized human figure out of CPS Shapes.
class Human : public Shape {
public:
    Human(double, double);
    double getHeight() const override;
    double getObesity() const;
    void initializeHead();
    void initializeTorso();
    void initializeArms();
    void initializeLegs();
    string getHeadPSCode() const;
    string getPostScriptCode() const override;
    int getRandomInt(unsigned int, unsigned int) const;

private:
    unique_ptr<Shape> _head;
    unique_ptr<Shape> _torso;
    vector<unique_ptr<Shape>> _arms;
    vector<unique_ptr<Shape>> _legs;

    double _height;     // Total height of figure.
    double _obesity;    // Skinny < 1 < Fat

};


#endif //CPS_HUMAN_H
