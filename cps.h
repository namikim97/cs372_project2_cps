// cps.h
// Project 2 for CS372
// Alex L, Simeon N, Nami K
// Created: 20 Mar 2019
// Modified: 20 Mar 2019
//
// Header for CPS

#ifndef CPS_H_INCLUDED
#define CPS_H_INCLUDED

// Nami 
class Shape {
	// TO DO
};

// Basic Shapes

// Nami
class Circle : public Shape
{
	// TO DO
}; 

// Nami
class Polygon : public Shape
{
	// TO DO
};

// Simeon
class Rectangle : public Shape
{

	// TO DO
}; 

// Simeon
class Spacer : public Shape
{
	// TO DO
};


// Alex
class Square : public Polygon
{
	// TO DO
;

// Alex
class Triangle : public Polygon
{
	// TO DO
};


// Compound Shapes

class Rotated : public Shape
{
	// TO DO
};

class Scaled : public Shape
{
	// TO DO
};

class Layered : public Shape
{
	// TO DO
};

class Vertical : public Shape
{
	// TO DO
};

class Horizontal : public Shape
{
	// TO DO
};


// postscript output

class ps_output
{	
	// TODO
};

#endif //CPS_H_INCLUDED