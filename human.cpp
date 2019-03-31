// human.cpp

#include "human.h"

Human::Human(double height, double obesity)
    : _height(height), _obesity(obesity), _bodyUnit(height/8) {
    initializeHead();
    initializeTorso();
    initializeArms();
    initializeLegs();
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

// Head can be a CPS circle or [6-12] sided polygon.
void Human::initializeHead() {
    auto headType = getRandomInt(5, 12);
    if(headType == 5)
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

    _leftArm = unique_ptr<Shape>
                (new Rotated(Rectangle(0.5*getUnit(), 2*getUnit()), 90));
    _rightArm = unique_ptr<Shape>
                (new Rotated(Rectangle(0.5*getUnit(), 2*getUnit()), 270));
}

void Human::initializeLegs() {
    auto legType = getRandomInt(1, 2);

    _leftLeg = unique_ptr<Shape>
                (new Rotated(Rectangle(0.5*getUnit(), 2*getUnit()), 180));
    _rightLeg = unique_ptr<Shape>
                (new Rotated(Rectangle(0.5*getUnit(), 2*getUnit()), 180));
}

string Human::getHeadPSCode() const {
    string PostScriptCode = "gsave\n" +
                            _head->getPostScriptCode() +
                            "stroke\ngrestore\n";
    return PostScriptCode;
}

string Human::getTorsoPSCode() const {
    double headToTorso = -1.5*getUnit();
    string PostScriptCode = "gsave\n0 " + to_string(headToTorso) + " translate\n" +
                            _torso->getPostScriptCode() +
                            "stroke\ngrestore\n";
    return PostScriptCode;
}

string Human::getArmsPSCode() const {
    double torsoToArmX = -getUnit();
    double headToArmY = -.25*getUnit();
    string PostScriptCode = "gsave\n" +
                            to_string(torsoToArmX) + " " + to_string(headToArmY) +
                            " translate\n" +
                            _leftArm->getPostScriptCode() +
                            "stroke\ngrestore\n";
    torsoToArmX = getUnit();
    PostScriptCode += "gsave\n" +
                      to_string(torsoToArmX) + " " + to_string(headToArmY) +
                      " translate\n" +
                      _rightArm->getPostScriptCode() +
                      "stroke\ngrestore\n";

    return PostScriptCode;
}

string Human::getLegsPSCode() const {
    // TODO
    double torsoToLegX = -getUnit();
    double torsoToLegY = -3*getUnit();

    string PostScriptCode = "gsave\n" +
                            to_string(torsoToLegX) + " " + to_string(torsoToLegY) +
                            " translate\n" +
                            _leftLeg->getPostScriptCode() +
                            "stroke\ngrestore\n";
    torsoToLegX = getUnit();
    PostScriptCode += "gsave\n" +
                      to_string(torsoToLegX) + " " + to_string(torsoToLegY) +
                      " translate\n" +
                      _rightLeg->getPostScriptCode() +
                      "stroke\ngrestore\n";

    return PostScriptCode;
}

string Human::getPostScriptCode() const {
    string PostScriptCode = getHeadPSCode() +
                            getTorsoPSCode() +
                            getArmsPSCode() +
                            getLegsPSCode();
    return PostScriptCode;
}

int Human::getRandomInt(unsigned int min, unsigned int max) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    mt19937 rng(seed);
    uniform_int_distribution<mt19937::result_type> dist(min, max);
    return dist(rng);
}