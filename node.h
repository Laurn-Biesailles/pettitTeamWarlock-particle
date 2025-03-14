#include <>
using namespace std;

class node {
	particle p;
	node *next = nullptr;
	node *prev = nullptr;
	public:
	node (particle newP, node *newNext = nullptr, node *newPrev = nullptr) {
		p = newP;
		next = newNext;
		prev = newPrev;
	}
	particle getP () const {
		return p;
	}
	void setP (particle newP) {
		p = newP;
	}
	node getNext () const {
		return next;
	}
	void setNext (node *newNext = nullptr) {
		next = newNext;
	}
	node getPrev () const {
		return prev;
	}
	void setPrev (node *newPrev = nullptr) {
		prev = newPrev;
	}
};
