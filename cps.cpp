// cps.cpp
// Project 2 for CS372
// Alex L, Simeon N, Nami K
// Created: 20 Mar 2019
// Modified: 31 Mar 2019
//
// Description of this project can be found at:
// https://github.com/namikim97/cs372_project2_cps
// CPS Main


#include "page.h"
#include "shapes.h"
#include "compound.h"
#include "human.h"

#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ofstream;
#include <memory>
using std::make_shared;
#include <initializer_list>

void testShapes(void)
{
	Circle circle1(20);
	Polygon pentagon1(5, 30);
	Polygon hexagon1(6, 20);
	Rectangle rect(144, 72);
	Triangle tri(20);
	Square sq(20);

	Page basicShapes;
	basicShapes.drawToPage(circle1, 40, 40);
	basicShapes.drawToPage(pentagon1, 144, 144);
	basicShapes.drawToPage(hexagon1, 100, 100);
	basicShapes.drawToPage(rect, 200, 200);
	basicShapes.drawToPage(tri, 200, 200);
	basicShapes.drawToPage(sq, 300, 300);

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

    auto a = make_shared<Rectangle>(30, 30);
    auto b = make_shared<Rotated>(pentagon1, 60);
    auto c = make_shared<Circle>(20);
    auto d = make_shared<Polygon>(5, 20);

    auto vTri = make_shared<Triangle>(10);
	auto vCir = make_shared<Circle>(10);
	auto vRec = make_shared<Rectangle>(40, 20);

	auto hTri = make_shared<Triangle>(10);
	auto hCir = make_shared<Circle>(10);
	auto hRec = make_shared<Rectangle>(40, 20);


	auto layTri = make_shared<Triangle>(50);
	auto layCir = make_shared<Circle>(20);
	auto layRec = make_shared<Rectangle>(40, 20);
	auto layPent = make_shared<Polygon>(5, 20);
	auto layHex = make_shared<Polygon>(6, 25);

	RainbowSnowman sm(60.0);
	Page snowMan;
	snowMan.drawToPage(sm, 40, 40);


	Page layeredShapes;
	Layered layer{ layCir, layRec };
	Layered layer2{ layRec, layCir };
	Layered layer3{ layHex, layTri };
	layeredShapes.drawToPage(layer, 144, 144);
	layeredShapes.drawToPage(layer2, 4*72, 4*72);
	layeredShapes.drawToPage(layer3, 6*72, 6*72);
	Page verticalShapes;
	Vertical vert{ vRec, vCir, vCir, vRec };
	verticalShapes.drawToPage(vert, 100, 200);
	cout << vert.getPostScriptCode() << endl;


	Page horizShapes;
	Horizontal horiz{ hRec, hCir, hCir, hCir, hRec };
	horizShapes.drawToPage(horiz, 200, 200);
	cout << horiz.getPostScriptCode() << endl;


	Human human(360, 1);
	Page humanShapes;
	humanShapes.drawToPage(human, 288, 648);

	PSOutput output;
	output.addPage(basicShapes);
    output.addPage(snowMan);
	output.addPage(rotatedShapes);
	output.addPage(scaledShapes);
	output.addPage(layeredShapes);
	output.addPage(verticalShapes);
	output.addPage(horizShapes);
	output.addPage(humanShapes);
	cout << "Testing file output" << endl;
	output.PSOutput_File("testShapes.ps");
}


int main()
{
	testShapes();
    return 0;
}
