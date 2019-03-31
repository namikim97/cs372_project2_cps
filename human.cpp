// human.cpp

#include "human.h"

Human::Human(double height, double obesity)
    : _height(height), _obesity(obesity), _bodyUnit(height/8) {
    initializeHead();
    initializeTorso();
}

double Human::getHeight() const {
    return _height;
}

double Human::getWidth() const {
    return _width;
}

void Human::setHeight() {}

void Human::setWidth() {}

double Human::getUnit() const {
    return _bodyUnit;
}

double Human::getObesity() const {
    return _obesity;
}

// Head can be a CPS circle or [3-8] sided polygon.
void Human::initializeHead() {
    auto headType = getRandomInt(2, 8);
    if(headType == 2)
        _head = unique_ptr<Shape>
                (new Scaled(Circle(0.5*getUnit()), getObesity(), 1));
    else
        _head = unique_ptr<Shape>
                (new Scaled(Polygon(headType, 0.5*getUnit()), getObesity(), 1));
}

// Torso can be circular or rectangular.
void Human::initializeTorso() {
    auto torsoType = getRandomInt(1, 2);
    if(torsoType == 1)
        _torso = unique_ptr<Shape>
                 (new Scaled(Circle(1.5*getUnit()), getObesity(), 1));
    else
        _torso = unique_ptr<Shape>
                 (new Scaled(Rectangle(1.5*getUnit(), 3*getUnit()), getObesity(), 1));
}

void Human::initializeArms() {
    auto armType = getRandomInt(1, 2);
    // TODO
}

void Human::initializeLegs() {
    // TODO
}

string Human::getHeadPSCode() const {
    return _head->getPostScriptCode();
}

string Human::getTorsoPSCode() const {
    return _torso->getPostScriptCode();
}

string Human::getPostScriptCode() const {
    string PostScriptCode = "gsave\n" + getHeadPSCode() + "fill\ngrestore\n";
    double headToTorso = -2*getUnit();
    PostScriptCode += "gsave\n0 " + to_string(headToTorso) + " translate\n" +
                      getTorsoPSCode() + "fill\ngrestore\n";

    return PostScriptCode;
}

int Human::getRandomInt(unsigned int min, unsigned int max) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    mt19937 rng(seed);
    uniform_int_distribution<mt19937::result_type> dist(min, max);
    return dist(rng);
}