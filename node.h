#include <iostream>
#include <iomanip>
#include <sstream>
#include "particle.h"
using namespace std;

class node {
	Particle p;
	node *next = nullptr;
	node *prev = nullptr;
	public:
	node (Particle newP, node *newNext = nullptr, node *newPrev = nullptr) {
		p = newP;
		next = newNext;
		prev = newPrev;
	}
	Particle getP () const {
		return p;
	}
	void setP (Particle newP) {
		p = newP;
	}
	node getNext () const {
		return *next;
	}
	void setNext (node *newNext = nullptr) {
		next = newNext;
	}
	node getPrev () const {
		return *prev;
	}
	void setPrev (node *newPrev = nullptr) {
		prev = newPrev;
	}
};
