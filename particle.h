#include <iostream>
using namespace std;

void die (string s = "") {
	if (s == "") cout << "BAD INPUT" << endl;
	else cout << s << endl;
}


enum class particleType {
	STREAMER = 's', BALLISTIC = 'b', FIREWORK = 'f'
};


class Particle {
	double x, y, vX, vY;
	int lifetime;
	
	
	
	particleType type;

	public:

	Particle (double newX = 0.0,double newY = 0.0, double newVX = 0.0, double newVY = 0.0, int newLife = 0, particleType newType = particleType::STREAMER) :
		x(newX),
		y(newY),
		vX(newVX), 
		vY(newVY),
		lifetime(newLife),
		type(newType)
		{
			if (newLife < 0) lifetime = 0;
		}


	// position
	double getX() const { return x; }
	
	void setX(double newX) {
		x = newX;
	}

	double getY() const { return y; }
	
	void setY(double newY) {
		x = newY;
	}


	// velocity
	double getVX() const { return vX; }
	
	void setVX(double newVX) {
		vX = newVX;
	}

	double getVY() const { return vY; }
	
	void setVY(double newVY) {
		vX = newVY;
	}


	// lifetime
	int getLife() const { return lifetime; }

	void setLife(int newLife) {
		if (newLife < 0) lifetime = 0;
		else { lifetime = newLife; }
	}


	// particle type
	particleType getType() const { return type; }

	void setType(particleType newType) {
		type = newType;
	}

	// TODO: physics method (calculate velocity and direction) and draw method
	void drawParticle(Particle temp) {
		return;
	}

	void moveParticle() {
		return;	
	}
	


};

void particleTests () {
	Particle a;
	if (a.getX() != 0.0 || a.getY() != 0.0 || a.getVX() != 0.0 || a.getVY() != 0.0 || a.getLife() != 0 || a.getType() != particleType::STREAMER) die("Your default constructor or get functions aren't working properly. Please fix");
	Particle b(1.1,2.2,3.3,4.4,-2,particleType::BALLISTIC);
	if (b.getX() != 1.1 || b.getY() != 2.2 || b.getVX() != 3.3 || b.getVY() != 4.4 || b.getLife() != 0 || b.getType() != particleType::FIREWORK) die("Your constructor isn't working properly. Please fix");
	a.setX(2.2);
	a.setY(2.2);
	a.setVX(2.2);
	a.setVY(2.2);
	a.setLife(5.5);
	a.setType(particleType::FIREWORK);
	if (a.getX() != 2.2 || a.getY() != 2.2 || a.getVX() != 2.2 || a.getVY() != 2.2 || a.getLife() != 5.5 || a.getType() != particleType::BALLISTIC) die("Your set functions aren't working properly. Please fix");
}
