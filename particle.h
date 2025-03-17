#include <iostream>
using namespace std;

class Particle {
	double x, y, vX, vY;
	int lifetime;
	//Color color;
	
	enum particleType {
		STREAMER = 's', BALLISTIC = 'b', FIREWORK = 'f'
	};
	
	particleType type;

	public:

	Particle (double newX = 0.0,double newY = 0.0, double newVX = 0.0, double newVY = 0.0, int newLife = 0, particleType newType = STREAMER) :
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
