#pragma once
#include <iostream>
#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"
#include <sys/ioctl.h>
#include <utility>
#include <unistd.h>

class particleSystem{
	int row = 0 ;
	int colm = 0;
	node *head;
	node *tail;
	int size = 0;
	public:

	particleSystem(){}

	~particleSystem(){
		node *temp = head;
		while(temp){
			node *temp2 = temp->getNext();
			delete temp;
			temp = temp2;
		}
	}

	//get size for row and colm
	// auto [rows,cols] = get_terminal_size();


	void add_particle(Particle particle){
		node *temp = new node(particle);
		if (!size) {
			tail = head = temp;
		} else {
			temp->setPrev(tail);
			tail->setNext(temp);
			tail = temp;
		}
		size++;

	}
	int numParticles(){
		return size;
	}
	void moveParticles(){
		node *temp = head;
		while(temp){
			Particle temp2 = temp->getPart();
			temp2.physics(temp2);
			temp->setPart(temp2);
			temp = temp->getNext();
		}

	}
	void cull(){
		node *temp = head;
		while(temp){
			if(temp->getPart().getX() > row || temp->getPart().getY() > colm ||
					temp->getPart().getX() < 0 || temp->getPart().getY() < 0 ||
					temp->getPart().getLife() <= 0 ){
				if(size == 1){
					head = tail = nullptr;
					delete temp;
					temp = nullptr;
					size--;
				}
				else if(temp == head){
					head = temp->getNext();
					head->setPrev(nullptr);
					delete temp;
					temp = head;
					size--;
				}
				else if(temp == tail){
					tail = temp->getPrev();
					tail->setNext(nullptr);
					delete temp;
					temp = tail;
					size--;
				}
				else{
					node *temp2 = temp->getPrev();
					node *temp3 = temp->getNext();
					temp2->setNext(temp3);
					temp3->setPrev(temp2);
					delete temp;
					temp = temp3;
					size--;
				}


			}
			else{
				temp = temp->getNext();
			}
		}
	}
//normal draw
	void drawParticles(ParticleGraphics g) {
		node *temp = head;
		while(temp){
			g.drawPoint(temp->getPart().getX(),temp->getPart().getY());
			cout << "Drawing at (" << temp->getPart().getX() << ", " << temp->getPart().getY() << ")\n";//
			temp = temp->getNext();
		}
	}
	void updateBounds() {
		auto [r, c] = get_terminal_size();
		row = r;
		colm = c;
	}


	void runFrame(ParticleGraphics& g) {
		while(size >= 1){
		clearscreen();
	    updateBounds();        // Make sure rows and cols are fresh
		moveParticles();       // Step 1: Apply physics
		cull();                // Step 2: Remove dead/out-of-bounds
		drawParticles(g);      // Step 3: Draw remaining
		usleep(100090);
		}
	}

//This function is for program C
	void runFrameC(ParticleGraphics& g) {
		std::cout << "\033[?25l"; // 👈 Hide cursor        
        clearscreen();
        updateBounds();        // Make sure rows and cols are fresh
        moveParticles();       // Step 1: Apply physics
        cull();                // Step 2: Remove dead/out-of-bounds
        drawParticles(g);      // Step 3: Draw remaining
        usleep(100090);
        
    }




};




//TESTING


void partSysTest(){
	particleSystem ps;
	int size = ps.numParticles();
	if(size != 0){
		cout << "Incorrectly created particle system" << endl;
	}
	Particle a;
	ps.add_particle(a);
	size = ps.numParticles();
	if(size <= 0){
		cout << "Did not add particle" << endl;
	}
	else{
		cout << "Added Particle" << endl;
	}
}























