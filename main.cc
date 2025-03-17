#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"
#include "particleSys.h"
#include <iostream>

int main () {
    cout << "Particle System Testing Phase" << endl;
    cout << "Checking particle class" << endl;
    cout << "Checking linked list node class" << endl;
    nodeTest();
    cout << "All tests passed." << endl;
    cout << "Checking particle system class" << endl;
    cout << "Checking particle graphics class" << endl;
	ParticleGraphics_test();
}
