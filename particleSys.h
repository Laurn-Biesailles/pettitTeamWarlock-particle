#pragma once
#include <iostream>
#include "node.h"
#include "ParticleGraphics.h"


class particleSystem{
	auto row = 480;
	auto colm = 360;
	List particles;	
	public:
	void add_particle(Particle particle){
		particles.push_back(particle);
	}
	int numParticles(){
		return particles.getSize();
	}
	void moveParticles(){
		return;
	}
	void drawParticles(ParticleGraphics g){
		return;
	}


	void partSysTest(){
		ParticleSystem ps;
		int size = ps.numParticles();
		if(size != 0){
			cout << "Incorrectly created particle system" << endl;
		}
		particle a;
		ps.add_particle(a);
		size = ps.numParticles();
		if(size !> 0){
			cout << "Did not add particle" << endl;
		}
		else{
			cout << "Added Particle" << endl;
		}
	}
	

};
