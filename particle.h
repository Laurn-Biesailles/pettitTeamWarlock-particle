#pragma once
#include <iostream>
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
// #include "particleSys.h"

//using namespace std;


//enum class particleType { STREAMER, BALLISTIC, FIREWORK };

void die (std::string s = "") {
	if (s == "") {std::cout << "BAD INPUT" << std::endl;}
	else {std::cout << s << std::endl;}
}

class Particle {
	double x, y, vX, vY;
	int lifetime;
	char type;

	public:

	Particle (double newX = 0.0, double newY = 0.0, double newVX = 0.0, double newVY = 0.0, int newLife = 0, char newType = 's') :
		x(newX),
		y(newY),
		vX(newVX), 
		vY(newVY),
		lifetime(std::max(0, newLife)),
		type(newType) {}

	// copy constructor
	Particle (const Particle &temp) : 
		x(temp.getX()),
		y(temp.getY()),
		vX(temp.getVX()),
		vY(temp.getVY()),
		lifetime(temp.getLife()),
		type(temp.getType()) {}



	// position
	double getX() const { return x; }
	
	void setX(double newX) {
		x = newX;
	}

	double getY() const { return y; }
	
	void setY(double newY) {
		y = newY;
	}


	// velocity
	double getVX() const { return vX; }
	
	void setVX(double newVX) {
		vX = newVX;
	}

	double getVY() const { return vY; }
	
	void setVY(double newVY) {
		vY = newVY;
	}


	// lifetime
	int getLife() const { return lifetime; }

	void setLife(int newLife) {
		if (newLife < 0) lifetime = 0;
		else { lifetime = newLife; }
	}


	// particle type
	char getType() const { return type; }

	void setType(char newType) {
		if (newType == 's' || newType == 'b' || newType == 'f') type = newType;
		else newType = 's';
	}


	// physics method (calculate velocity and direction)

	// move firework to particleSys and the color effects for fireworks to particleGraphics
	// to make the 50 small particles make 50 unique lists and delete them after
	void physics() {
		// always do this, any type
			
		// updates x, y and life
		x += vX;
		y += vY;
	    lifetime--;

		if (type == 'b' or type == 'f') { // ballistic and firework
			vY++;
		}

	
	}

	// boolean operator function
	bool operator!=(const Particle& temp) const {return ( (x != temp.getX()) or (y != temp.getY()) or (vX != temp.getVX()) or (vY != temp.getVY()) or (lifetime != temp.getLife()) or (type != temp.getType()) );}


};

void particleTests () {
	Particle a;
	if (a.getX() != 0.0 || a.getY() != 0.0 || a.getVX() != 0.0 || a.getVY() != 0.0 || a.getLife() != 0 || a.getType() != 's') die("Your default constructor or get functions aren't working properly. Please fix");
	
	Particle b(1.1,2.2,3.3,4.4,-2,'b');
	if (b.getX() != 1.1 || b.getY() != 2.2 || b.getVX() != 3.3 || b.getVY() != 4.4 || b.getLife() != 0 || b.getType() != 'b') die("Your constructor isn't working properly. Please fix");
	
	Particle c;
	c.setX(1.5);
	c.setY(2.0);
	c.setVX(2.5);
	c.setVY(3.0);
	c.setLife(3);
	c.setType('f');
	if (c.getX() != 1.5 || c.getY() != 2.0 || c.getVX() != 2.5 || c.getVY() != 3.0 || c.getLife() != 3 || c.getType() != 'f') die("Your set functions aren't working properly. Please fix");
	
	
	else { std::cout << "All Tests Passed" << std::endl; }
	
	Particle d(1.0, 1.0, 1.0, 1.0, -1, 's');
	d.physics();
	
}
