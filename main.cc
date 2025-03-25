#include "node.h"
#include "particle.h"
#include "ParticleGraphics.h"
#include "particleSys.h"
#include <iostream>
#include "/public/read.h"
using namespace std;

void runTests();

int main() {
	particleSystem mainSys;
	particleSystem leadSys;
	particleSystem bSys;
	particleSystem cSys;
	particleSystem dSys;

	ParticleGraphics mainGraphics(20,55,167);

	cout.flush();
	//gets row and cols for terminal size
	auto [rows, cols] = get_terminal_size();
std::cout << "Terminal size: " << rows << " x " << cols << std::endl;

	while(true) {
		// ask user for input, decides which portion to run
		int runType = read("Choose which program to run:\n0- Run Tests\n1- Add Particle\n2- Draw Particle\n3- Run Physics\n4- Run ParticleSystem 1\n5- Run ParticleSystem 2\n6- Run ParticleSystem 3\n7- Run ParticleSystem 4\n8- Quit\n");
		if (runType == 0) {
			// run basic tests for each header file
			runTests();
		} else if (runType == 1) {
			// create new particle in main system
			double newX = read("Enter X position:\n");
			double newY = read("Enter Y position:\n");
			double newVX = read("Enter X velocity:\n");
			double newVY = read("Enter Y velocity:\n");
			int newLife = read("Enter lifetime:\n");
			char newType = read("Enter particle type:\n");
			Particle newParticle(newX,newY,newVX,newVY,newLife,newType);
			mainSys.add_particle(newParticle);
			cout << "Particle added to main system" << endl;
		} else if (runType == 2) {
			// output freeze frame of every particle in main system
			clearscreen();
			mainSys.updateBounds();
			mainSys.drawParticles(mainGraphics);
			cout << endl;
		} else if (runType == 3) {
			// run physics once per particle
			int i = 0;
			for (node *temp = mainSys.getHead(); temp; temp->getNext()) {
				i++;
				cout << "Previous Values of Particle " << i << endl;
				cout << "X: " << temp->getPart().getX() << ", Y: " << temp->getPart().getY() << ", vX: " << temp->getPart().getVX() << ", vY: " << temp->getPart().getVY() << endl;
				temp->getPart().physics();
				cout << "Updated Values of Particle " << i << endl;
				cout << "X: " << temp->getPart().getX() << ", Y: " << temp->getPart().getY() << ", vX: " << temp->getPart().getVX() << ", vY: " << temp->getPart().getVY() << endl << endl;
			}
			cout << "Particle physics updated!" << endl;
		} else if (runType == 4) {
			// Justus' final product
			cout << "Working on it :3" << endl;
		} else if (runType == 5) {
			// Noah's final product
			cout << "Working on it :3" << endl;
		} else if (runType == 6) {
			//this is Daniels testing for his program dont touch unless its breaking things
			cout << "Now running program C" << endl;
			double newX = 20;
            double newY = 20;
            double newVX = 1;
            double newVY = -1;
            int newLife = 1000;
            char newType = 'C';
			int sizeC = 0;
			
			while(sizeC <= 100){
			//creates particle
            Particle newParticle(newX,newY,newVX,newVY,newLife,newType);
			//adds particle to cSys
            cSys.add_particle(newParticle);
			//draws particles in cSys
			cSys.runFrameC(mainGraphics);
			cSys.cull();
			
			//if(newX < rows){newX++;}

			if(newY < cols){newY++;}
			
			sizeC++;
			 
			}
			std::cout << "\033[?25h";
			
		} else if (runType == 7) {
			// Ella's final product
			cout << "Working on it :3" << endl;
		} else if (runType == 8) {
			// stop program when user decides
			return 0;
		} else {
			// spit back on bad input, just in case
			cout << "BAD INPUT" << endl;
		}
	}
}

void runTests () {
	// call tests for each class from each header
	cout << "Testing Particle Class:" << endl;
	particleTests();

	cout << "Testing Node Class:" << endl;
	nodeTest();

	cout << "Testing Particle System Class:" << endl;
	partSysTest();

	cout << "Checking Particle Graphics Class:" << endl;
	ParticleGraphics_test();
}
