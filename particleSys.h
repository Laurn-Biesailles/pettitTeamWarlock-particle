#pragma once
#include <iostream>
#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"


class particleSystem{
	int row = 480;
	int colm = 360;
	node *head = nullptr;
	node *tail = nullptr;
	int size = 0;
	public:
	
	particleSystem(){
		const auto [rows,col] = get_terminal_size();
		row = rows;
		colm = col;
	}

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
		Particle temp2 = temp->getPart();
		temp2.physics();
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
				}

				 
			}
			else{
				temp = temp->getNext();
			}
		}
	}

	void drawParticles(ParticleGraphics g){
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < colm; i++) {
				movecursor(i,j);
				cout << "";
			}
		}
		cout.flush();
		resetcolor();

		node *temp = head;
        while(temp){
			g.drawPoint(temp->getPart().getX(),temp->getPart().getY());
            temp = temp->getNext();
        }
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























