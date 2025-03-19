#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"
#include "particleSys.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Particle System Testing Phase" << endl;

	cout << "Checking particle class" << endl;
	particleTests();

	cout << "Checking node class" << endl;
	nodeTest();

	cout << "Checking particle system class" << endl;
	partSysTest();

	cout << "Checking particle graphics class" << endl;
	ParticleGraphics_test();

}
