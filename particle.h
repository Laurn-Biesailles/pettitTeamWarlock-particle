#include <iostream>
using namespace std;

class Particle {
	double position, velocity;
	int lifetime;
	
	enum particleType {
		STREAMER, BALLISTIC, FIREWORK
	}
	
	particleType type;

	Particle (double newPos, double newVel, int newLife, particleType newType) :
		position(newPos),
		velocity(newVel), 
		lifetime(newLife),
		type(newType),
		{
			if (newLife < 0) lifetime = 0;
		}

	public:

	double getPos() const { return position; }
	
	void setPos(double newPos) {
		position = newPos;
	}


	double getVel() const { return velocity; }

	void setVel(double newVel) {
		velocity = newVel;
	}
	

	int getLife() const { return lifetime; }

	void setLife(int newLife) {
		if (newLife < 0) lifetime = 0;
		else { lifetime = newLife; }
	}


	particleType getType() const { return type; }

	void setType(particleType newType) {
		type = newType;
	}

	// TODO: physics method (calculate velocity and direction) and draw method

	


};
