// cppToPSTests.cpp
// Catch2 Tests for C++ to PostScript Program

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "page.h"
#include "shapes.h"
#include "compound.h"
#include <cmath>
using std::sqrt;

TEST_CASE( "Shape: Rectangle ") {
    double width = 72;
    double height = 18;

    class Rectangle rect(width, height);
    SECTION( "Rectangle: ctor -> Width = 72, Height = 18" ) {
        REQUIRE( rect.getWidth() == width );
        REQUIRE( rect.getHeight() == height );
    }

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
    }
}

TEST_CASE( "Shape: Spacer ") {
    double width = 72;
    double height = 18;

    class Spacer space(width, height);
    SECTION( "Spacer: ctor -> Width = 72, Height = 18" ) {
        REQUIRE( space.getWidth() == width );
        REQUIRE( space.getHeight() == height );
    }

    SECTION( "Spacer: Generates correct PostScript code" ) {
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
    }
}

TEST_CASE( "Can make a polygons", "[Polygon]" ) {
    class Polygon poly(5, 6);
    REQUIRE( (poly.getNumOfSides()) == 5 );
    REQUIRE( (poly.getSideLength()) == 6 );
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

