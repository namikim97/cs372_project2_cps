// cppToPSTests.cpp
// Catch2 Tests for C++ to PostScript Program

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "page.h"
#include "shapes.h"
#include "compound.h"


TEST_CASE( "Can make a polygons", "[Polygon]" ) {
    class Polygon poly(5, 6);
    REQUIRE( (poly.getNumOfSides()) == 5 );

}