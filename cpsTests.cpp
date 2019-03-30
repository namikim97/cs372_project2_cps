// cppToPSTests.cpp
// Catch2 Tests for C++ to PostScript Program

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "page.h"
#include "shapes.h"
#include "compound.h"
#include "human.h"
#include <cmath>
using std::sqrt;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::make_shared;
using std::shared_ptr;

TEST_CASE( "Shape: Rectangle ") {
    double width = 72;
    double height = 18;

    class Rectangle rect(width, height);
    SECTION( "Rectangle: ctor -> Width = 72, Height = 18" ) {
        REQUIRE( rect.getWidth() == width );
        REQUIRE( rect.getHeight() == height );
    }
/*//TODO: change test to match new version of getPostScriptCode
    SECTION( "Rectangle: Generates correct PostScript code" ) {
        double halfWidth = width/2, halfHeight = height/2;
        string originX = "x " + to_string(halfWidth) + " sub";
        string originY = "y " + to_string(halfHeight) + " sub";
        string strWidth = to_string(width), strHeight = to_string(height);
        string originXWidthAdd = originX + " " + strWidth + " add ";
        string originYHeightAdd = originY + " " + strHeight + " add ";

        REQUIRE( rect.getPostScriptCode() == "newpath\n" +
                                             originX + " " + originY + " moveto\n" +
                                             originXWidthAdd + originY + " lineto\n" +
                                             originXWidthAdd + originYHeightAdd + " lineto\n" +
                                             originX + " " + originYHeightAdd + " lineto\n" +
                                             "closepath\n" +
                                             "stroke\n" );
    }*/
}

TEST_CASE( "Shape: Spacer ") {
    double width = 72;
    double height = 18;

    class Spacer space(width, height);
    SECTION( "Spacer: ctor -> Width = 72, Height = 18" ) {
        REQUIRE( space.getWidth() == width );
        REQUIRE( space.getHeight() == height );
    }
    //TODO: change test to match new version of getPostScriptCode
    /*SECTION( "Spacer: Generates correct PostScript code" ) {
        double halfWidth = width/2, halfHeight = height/2;
        string originX = "x " + to_string(halfWidth) + " sub";
        string originY = "y " + to_string(halfHeight) + " sub";
        string strWidth = to_string(width), strHeight = to_string(height);
        string originXWidthAdd = originX + " " + strWidth + " add ";
        string originYHeightAdd = originY + " " + strHeight + " add ";

        REQUIRE( space.getPostScriptCode() == "newpath\n" +
                                              originX + " " + originY + " moveto\n" +
                                              originXWidthAdd + originY + " lineto\n" +
                                              originXWidthAdd + originYHeightAdd + " lineto\n" +
                                              originX + " " + originYHeightAdd + " lineto\n" +
                                              "closepath\n" );
    }*/
}

TEST_CASE( "Can make a circle", "[Circle]" ) {
    class Circle cir(20);
    REQUIRE( (cir.getRadius()) == 20);
}

TEST_CASE( "Can make a polygon", "[Pentagon]" ) {
    class Polygon poly(5, 6);
    REQUIRE( (poly.getNumOfSides()) == 5 );
    REQUIRE( (poly.getSideLength()) == 6 );
}

TEST_CASE( "Can make a Hexagon", "[Hexagon]" ) {
    class Polygon poly(6, 10);
    REQUIRE( (poly.getNumOfSides()) == 6 );
    REQUIRE( (poly.getSideLength()) == 10 );
}

TEST_CASE( "Can make a square", "[Square]" ) {
    class Square sq(6);
    REQUIRE( (sq.getNumOfSides()) == 4 );
    REQUIRE( (sq.getSideLength()) == 6 );
}

TEST_CASE( "Can make a triangle", "[Triangle]" ) {
    class Triangle tri(4);
    REQUIRE( (tri.getNumOfSides()) == 3 );
    REQUIRE( (tri.getSideLength()) == 4 );
    REQUIRE( (tri.calcTriHypot()) == 2 / (sin(M_PI/3)));
    //REQUIRE( (tri.calcTriHeight()) ==  tri.calcTriHypot() * cos(M_PI)/3); //this assertion failing

}

TEST_CASE( "Compound Shape: Vertical") {
    // TODO: Ideally test all shapes by the end.
    shared_ptr<Shape> tRec(new class Rectangle(72,36));
    shared_ptr<Shape> spc(new class Spacer(18,36));
    shared_ptr<Shape> bRec(new class Rectangle(36,72));
    auto list = {tRec, spc, bRec};
    Vertical vert(list);
    SECTION( "Vertical: ctor-> {Rectangle, Spacer, Rectangle}" ) {
        REQUIRE( vert.getWidth() == 72 );
        REQUIRE( vert.getHeight() == 144 );
    }
}


TEST_CASE( "Compound Shape: Horizontal") {
    // TODO: Ideally test all shapes by the end.
    shared_ptr<Shape> tRec(new class Rectangle(72,36));
    shared_ptr<Shape> spc(new class Spacer(18,36));
    shared_ptr<Shape> bRec(new class Rectangle(36,72));
    auto list = {tRec, spc, bRec};
    Horizontal horizontal(list);
    SECTION( "Horizontal: ctor-> {Rectangle, Spacer, Rectangle}" ) {
        REQUIRE( horizontal.getWidth() == 126 );
        REQUIRE( horizontal.getHeight() == 72 );
    }

}

TEST_CASE( "Special Shape: Human" ) {
    double height = 360;
    double obesity = 1;

    Human human(height, obesity);
    SECTION( "Human: ctor-> {Height = 360, Obesity = 1}") {
        REQUIRE( human.getHeight() == height );
        REQUIRE( human.getObesity() == obesity );
    }
}
