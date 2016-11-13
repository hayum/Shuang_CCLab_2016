#pragma once
#include "ofMain.h"

class Particle
{
public:
	//Particle();
	//~Particle();
	Particle(ofVec2f pos);

	void resetForces();
	void applyForce(ofVec2f force);
	void update(float multiplier);
	void draw();

	ofVec2f mPosition, mVelocity, mAcceleration;
	float mLifeSpan;
	ofTrueTypeFont myfont;

};

