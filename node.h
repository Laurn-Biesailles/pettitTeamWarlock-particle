#include <iostream>
#include <iomanip>
#include <sstream>
#include "particle.h"
using namespace std;

void die (string s = "") {
	if (s == "") cout << "BAD INPUT" << endl;
	else cout << s << endl;
}

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
	Particle getPart () const {return p;}
	void setPart (Particle newP) {p = newP;}
	// next link getter/setter
	node getNext () const {return *next;}
	void setNext (node *newNext = nullptr) {next = newNext;}
	// previous link getter/setter
	node getPrev () const {return *prev;}
	void setPrev (node *newPrev = nullptr) {prev = newPrev;}
};

void nodeTest() {
	// creates new node w/ default values
	node a;
	Particle p;
	if (a.getNext() != nullptr || a.getPrev() != nullptr) die("Your default constructor or get functions don't work. Please fix");
	node *c = new node;
	node *d = new node;
	a.setNext(c);
	a.setPrev(d);
	if (a.getNext() != c || a.getPrev() != d) die("Your set functions aren't working properly. Please fix");
	delete (c);
	delete (d);
}