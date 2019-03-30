// cps.cpp
// Project 2 for CS372
// Alex L, Simeon N, Nami K
// Created: 20 Mar 2019
// Modified: 26 Mar 2019
//
// CPS Main


#include "page.h"
#include "shapes.h"
#include "compound.h"

#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ofstream;


void testShapes(void)
{
	Circle circle1(20);
	Polygon pentagon1(5, 30);
	//Triangle tri(3, 20);
	//Square sq(20, 20);

	Rectangle rect(144, 72);

	Page basicShapes;

	basicShapes.drawToPage(rect, 200, 200);
	basicShapes.drawToPage(circle1, 40, 40);

	basicShapes.drawToPage(pentagon1, 144, 144);
	// basicShapes.drawToPage(tri, 200, 200);
	// basicShapes.drawToPage(sq, 300, 300);

	PSOutput output;
	output.addPage(basicShapes);
	cout << "Testing file output" << endl;
	output.PSOutput_File("testShapes.ps");
}


int main()
{
	testShapes();
    return 0;
}
