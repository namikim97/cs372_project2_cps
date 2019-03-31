// human.h
// Header file for Human class.

#ifndef CPS_HUMAN_H
#define CPS_HUMAN_H

#include "shapes.h"
#include "compound.h"
#include <random>
using std::mt19937;
using std::uniform_int_distribution;
#include <chrono>

// Class: Human
// Object draws a randomized human figure out of CPS Shapes.
class Human : public Shape {
public:
    Human(double, double);
    double getHeight() const override;
    double getWidth() const override;
    void setHeight();
    void setWidth();
    double getUnit() const;
    double getObesity() const;
    void initializeHead();
    void initializeTorso();
    void initializeArms();
    void initializeLegs();
    string getHeadPSCode() const;
    string getTorsoPSCode() const;
    string getArmsPSCode() const;
    string getLegsPSCode() const;
    string getPostScriptCode() const override;
    int getRandomInt(unsigned int, unsigned int);

private:
    unique_ptr<Shape> _head;
    unique_ptr<Shape> _torso;
    unique_ptr<Shape> _leftArm;
    unique_ptr<Shape> _rightArm;
    unique_ptr<Shape> _leftLeg;
    unique_ptr<Shape> _rightLeg;

    double _height;
    double _width;
    double _bodyUnit;
    double _obesity;    // Skinny < 1 < Fat

};


#endif //CPS_HUMAN_H
