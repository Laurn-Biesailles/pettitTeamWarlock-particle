#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// kill function
void die(string s = "") {
    if (s == "") cout << "BAD INPUT" << endl;
    else cout << s << endl;
}

// Linked List node class
class node {
    // position variables
    double x = 0;
    double y = 0;
    // velocity variables
    double velX = 0;
    double velY = 0;
    // pointers to previous and next nodes in list
    node *prev = nullptr;
    node *next = nullptr;

    public:
    // constructor
    node (double newX = 0, double newY = 0, double newVelX = 0, double newVelY = 0, node *newPrev = nullptr, node *newNext = nullptr) {
        x = newX;
        y = newY;
        velX = newVelX;
        velY = newVelY;
        prev = newPrev;
        next = newNext;
    }
    // x position getter/setter
    double getX () const {
        return x;
    }
    void setX (double newX = 0) {
        x = newX;
    }
    // y position getter/setter
    double getY () const {
        return y;
    }
    void setY (double newY = 0) {
        y = newY;
    }
    // x velocity getter/setter
    double getVelX () const {
        return velX;
    }
    void setVelX (double newVelX = 0) {
        velX = newVelX;
    }
    // y velocity getter/setter
    double getVelY () const {
        return velY;
    }
    void setVelY (double newVelY = 0) {
        velY = newVelY;
    }
    // previous node getter/setter
    node *getPrev () const {
        return prev;
    }
    void setPrev (node *newPrev = nullptr) {
        prev = newPrev;
    }
    // next node getter/setter
    node *getNext () const {
        return next;
    }
    void setNext (node *newNext = nullptr) {
        next = newNext;
    }
};

// Linked List class
class List {
    // start and end references
    node *head = nullptr;
    node *tail = nullptr;
    // size variable
    int size = 0;

    public:
    // constructor
    List() {}
    // deconstructor, frees all memory in list
    ~List() {
        node *temp = head; // get first node
        while (temp) {
            node *copy = temp; // store current head
            temp = temp->getNext(); // set next node
            delete copy; // free memory from current head
        }
    }
    // size getter, no setter bc we only set through manipulation
    int getSize () const {
        return size;
    }
    // list printer
    string printList (bool forwards = true) {
        node *temp = forwards ? head : tail;
        ostringstream ss;
        if (!temp) {
            ss << "Empty List\n";
            return ss.str();
        }
        while (temp) {
            ss << "X: " << temp->getX() << ", Y: " << temp->getY() << ", velX: " << temp->getVelX() << ", velY: " << temp->getVelY() << endl;
            temp = forwards ? temp->getNext() : temp->getPrev();
        }
        return ss.str();
    }
    // inserters
    string insertAtFront (double x, double y, double velX, double velY) {
        node *temp = new node(x,y,velX,velY);
        if (!size) {
            head = tail = temp;
        } else {
            temp->setNext(head);
            head->setPrev(temp);
            head = temp;
        }
        size++;
        return "Node inserted at front";
    }
    string insertAtEnd (double x, double y, double velX, double velY) {
        node *temp = new node(x,y,velX,velY);
        if (!size) {
            tail = head = temp;
        } else {
            temp->setPrev(tail);
            tail->setNext(temp);
            tail = temp;
        }
        size++;
        return "Node inserted at end";
    }
    // deleters
    string deleteByXY (double x, double y, int choice = 0) {
        // delete based on position, choice var determines:
        // 0: x and y must both be true
        // 1: x must be true
        // 2: y must be true
    }
};