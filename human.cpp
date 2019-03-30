// human.cpp

#include "human.h"

Human::Human(double height, double obesity)
    : _height(height),
      _obesity(obesity) {}

double Human::getHeight() const {
    return _height;
}

double Human::getObesity() const {
    return _obesity;
}

// Head can be a CPS circle or polygon.
void Human::initializeHead() {

}

void Human::initializeTorso() {

}

void Human::initializeArms() {

}

void Human::initializeLegs() {

}

string getPostScriptCode() {
    return "dummy";
}