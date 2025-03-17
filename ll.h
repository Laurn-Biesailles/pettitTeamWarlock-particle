#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

// kill function
/*void die(string s = "") {
    if (s == "") cout << "BAD INPUT" << endl;
    else cout << s << endl;
}*/

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
        return "Node inserted at front\n";
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
        return "Node inserted at end\n";
    }
    // deleters
    string deleteByXY (double x, double y, int choice = 0, double error = 0) {
        // delete based on position
        // x/y are position of target
        // choice var determines which part(s) of the target are important
        // 0: x and y must both be true
        // 1: x must be true
        // 2: y must be true
        // error determines how close the point can be to the target
        if (choice < 0 || choice > 2) die();

        if (size == 0) return "Nothing deleted\n";
        else if (size == 1) {
            if (choice == 0) {
                if (fabs(x - head->getX()) <= error && fabs(y - head->getY()) <= error) {
                    node *temp = head;
                    delete temp;
                    head = tail = nullptr;
                    size--;
                    return "Node deleted\n";
                }
            } else if (choice == 1) {
                if (fabs(x - head->getX()) <= error) {
                    node *temp = head;
                    delete temp;
                    head = tail = nullptr;
                    size--;
                    return "Node deleted\n";
                }
            } else if (choice == 2) {
                if (fabs(y - head->getY()) <= error) {
                    node *temp = head;
                    delete temp;
                    head = tail = nullptr;
                    size--;
                    return "Node deleted\n";
                }
            }
        } else {
            for (node *temp = head; temp; temp = temp->getNext()) {
                if (choice == 0) {
                    if (fabs(x - head->getX()) <= error && fabs(y - head->getY()) <= error) {
                        if (temp == head) {
                            head = temp->getNext();
                            temp->getNext()->setPrev(nullptr);
                        } else if (temp == tail) {
                            tail = temp->getPrev();
                            temp->getPrev()->setNext(nullptr);
                        } else {
                            temp->getPrev()->setNext(temp->getNext());
                            temp->getNext()->setPrev(temp->getPrev());
                        }
                        delete temp;
                        size--;
                        return "Node deleted\n";
                    }
                } else if (choice == 1) {
                    if (fabs(x - head->getX()) <= error) {
                        if (temp == head) {
                            head = temp->getNext();
                            temp->getNext()->setPrev(nullptr);
                        } else if (temp == tail) {
                            tail = temp->getPrev();
                            temp->getPrev()->setNext(nullptr);
                        } else {
                            temp->getPrev()->setNext(temp->getNext());
                            temp->getNext()->setPrev(temp->getPrev());
                        }
                        delete temp;
                        size--;
                        return "Node deleted\n";
                    }
                } else if (choice == 2) {
                    if (fabs(y - head->getY()) <= error) {
                        if (temp == head) {
                            head = temp->getNext();
                            temp->getNext()->setPrev(nullptr);
                        } else if (temp == tail) {
                            tail = temp->getPrev();
                            temp->getPrev()->setNext(nullptr);
                        } else {
                            temp->getPrev()->setNext(temp->getNext());
                            temp->getNext()->setPrev(temp->getPrev());
                        }
                        delete temp;
                        size--;
                        return "Node deleted\n";
                    }
                }
            }
        }
        return "Nothing deleted\n";
    }
};
