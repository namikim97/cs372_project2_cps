// human.cpp

#include "human.h"

Human::Human(double height, double obesity)
    : _height(height), _obesity(obesity) {
    initializeHead();
}

double Human::getHeight() const {
    return _height;
}

double Human::getObesity() const {
    return _obesity;
}

// Head can be a CPS circle or [6-10] sided polygon.
void Human::initializeHead() {
    auto headType = getRandomInt(5, 10);
    if(headType == 5)
        _head = unique_ptr<Shape>(new class Circle(getHeight()/8));
    else
        _head = unique_ptr<Shape>(new class Polygon(10, 10));
}

void Human::initializeTorso() {

}

void Human::initializeArms() {

}

void Human::initializeLegs() {

}

string Human::getHeadPSCode() const {
    return _head->getPostScriptCode();
}

string Human::getPostScriptCode() const {
    string PostScriptCode = getHeadPSCode();

    return PostScriptCode;
}

int Human::getRandomInt(unsigned int min, unsigned int max) const {
    random_device randDev;
    mt19937 rng(randDev());
    uniform_int_distribution<mt19937::result_type> dist(min, max);

    return dist(rng);
}