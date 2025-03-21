#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "particle.h"
using namespace std;

class node {
	// particle variable
	Particle p;
	// linking variables
	node *next,*prev = nullptr;

	public:
	// constructor
	node (Particle newP, node *newNext = nullptr, node *newPrev = nullptr) {
		p = newP;
		next = newNext;
		prev = newPrev;
	}
	// particle getter/setter
	Particle getPart() const {return p;}
	void setPart(Particle newP) {p = newP;}
	// next link getter/setter
	node* getNext() const {return next;}
	void setNext(node *newNext = nullptr) {next = newNext;}
	// previous link getter/setter
	node* getPrev() const {return prev;}
	void setPrev(node *newPrev = nullptr) {prev = newPrev;}
};

void nodeTest() {
	// creates new node w/ default values
	Particle p;
	node *a = new node(p);
	if (a->getPart() != p || a->getNext() != nullptr || a->getPrev() != nullptr) die("Your default constructor or get functions don't work. Please fix");
	// creates nodes to insert as next and previous
	node *c = new node(p,nullptr,a);
	node *d = new node(p,a,nullptr);
	// creates new particle to insert
	Particle b(1.0,2.0,3.0,4.0,5,'f');
	a->setNext(c);
	a->setPrev(d);
	a->setPart(b);
	if (a->getPart() != b || a->getNext() != c || a->getPrev() != d) die("Your set functions aren't working properly. Please fix");
	delete (a);
	delete (c);
	delete (d);
	cout << "All Tests Passed" << endl;
}
