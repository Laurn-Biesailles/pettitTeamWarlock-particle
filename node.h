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
	Particle getP () const {return p;}
	void setP (Particle newP) {p = newP;}
	// next link getter/setter
	node getNext () const {return *next;}
	void setNext (node *newNext = nullptr) {next = newNext;}
	// previous link getter/setter
	node getPrev () const {return *prev;}
	void setPrev (node *newPrev = nullptr) {prev = newPrev;}
};