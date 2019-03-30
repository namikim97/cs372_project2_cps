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
	Polygon hexagon1(6, 20);
	Rectangle rect(144, 72);
	// Hey Alex you can uncomment the last two shapes when you're done writing them!
	//Triangle tri(3, 20);
	//Square sq(20, 20);

	Page basicShapes;
	basicShapes.drawToPage(circle1, 40, 40);
	basicShapes.drawToPage(pentagon1, 144, 144);
	basicShapes.drawToPage(hexagon1, 100, 100);
	basicShapes.drawToPage(rect, 200, 200);
	// basicShapes.drawToPage(tri, 200, 200);
	// basicShapes.drawToPage(sq, 300, 300);

	Rotated rotPent(pentagon1, 20);
	Rotated rotHex(hexagon1, 15);
	Rotated rotRec(rect, 50);
	
	Page rotatedShapes;
	rotatedShapes.drawToPage(rotPent, 55, 55);
	rotatedShapes.drawToPage(rotHex, 120, 120);
	rotatedShapes.drawToPage(rotRec, 250, 250);

	Scaled scaCirc(circle1, 2, 1);
	Scaled scaPenta(pentagon1, 3, 2);
	Scaled scaRec(rect, 0.5, 0.25);

	Page scaledShapes;
	scaledShapes.drawToPage(scaCirc, 55, 55);
	scaledShapes.drawToPage(scaPenta, 120, 120);
	scaledShapes.drawToPage(scaRec, 220, 220);
	
	PSOutput output;
	output.addPage(basicShapes);
	output.addPage(rotatedShapes);
	output.addPage(scaledShapes);
	cout << "Testing file output" << endl;
	output.PSOutput_File("testShapes.ps");
}


int main()
{
	testShapes();
    return 0;
}
