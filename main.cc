#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"
#include "particleSys.h"
#include <iostream>
#include "/public/read.h"
using namespace std;

void runTests();

int main() {
	cout.flush();
	int runType = read("Choose which program to run:\n0- Tests\n1- First program\n");
	if (runType == 0) {
		runTests();
	} else if (runType == 1) {
		cout << "Working on it :3" << endl;
	} else if (runType == 2) {
		cout << "Working on it :3" << endl;
	} else if (runType == 3) {
		cout << "Working on it :3" << endl;
	} else {
		cout << "BAD INPUT" << endl;
	}
}

void runTests () {
	cout << "Testing Particle Class:" << endl;
	particleTests();

	cout << "Testing Node Class:" << endl;
	nodeTest();

	cout << "Testing Particle System Class:" << endl;
	partSysTest();

	cout << "Checking Particle Graphics Class:" << endl;
	ParticleGraphics_test();
}
