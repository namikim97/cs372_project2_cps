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
class shape {
	// TO DO
};

// Basic Shapes

// Nami
class circle : public shape
{
	// TO DO
}; 

// Nami
class polygon : public shape
{
	// TO DO
};

// Simeon
class rectangle : public shape
{
	// TO DO
}; 

// Simeon
class spacer : public shape
{
	// TO DO
};

// Alex
class square : public polygon
{
	// TO DO
};

// Alex
class triangle : public polygon
{
	// TO DO
};


// Compound Shapes

class rotated : public shape
{
	// TO DO
};

class scaled : public shape
{
	// TO DO
};

class layered : public shape
{
	// TO DO
};

class vertical : public shape
{
	// TO DO
};

class horizontal : public shape
{
	// TO DO
};


// postscript output

class ps_output
{	
	// TODO
};

#endif //CPS_H_INCLUDED