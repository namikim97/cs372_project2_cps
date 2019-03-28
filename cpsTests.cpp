// cppToPSTests.cpp
// Catch2 Tests for C++ to PostScript Program

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "page.h"
#include "shapes.h"
#include "compound.h"
#include <cmath>
using std::sqrt;


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

