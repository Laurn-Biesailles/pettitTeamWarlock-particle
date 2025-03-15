#pragma once
#include <iostream>
#include "ll.h"
#include "particle.h"
#include "ParticleGraphics.h"
class particleSystem{
	auto row = 480;
	auto colm = 360;
	List particles;	
	public:
	void add_particle(Particle  particle){
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

	

};
