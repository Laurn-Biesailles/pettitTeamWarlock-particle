#pragma once
#include <iostream>
#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"


class particleSystem{
	auto row = 480;
	auto colm = 360;
	node *head = nullptr;
	node *tail = nullptr;
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
			temp.getPart().physics();
            temp = temp->getNext();
         }

	}
	void drawParticles(ParticleGraphics g){
		 node *temp = head;
         while(temp){
			g.drawPoint(temp.getPart().getX(),temp.getPart().getY());
            temp = temp->getNext();
         }

	}
};



//TESTING


    void partSysTest(){
        ParticleSystem ps;
        int size = ps.numParticles();
        if(size != 0){
            cout << "Incorrectly created particle system" << endl;
        }
        Particle a;
        ps.add_particle(a);
        size = ps.numParticles();
        if(size !> 0){
            cout << "Did not add particle" << endl;
        }
        else{
            cout << "Added Particle" << endl;
        }
    }























