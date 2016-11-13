#pragma once
#include "ofMain.h"

class Particle
{
public:
	Particle(ofVec2f pos);
	//~Particle();
	void setup();
	void update(float multiplier);
	void draw();
	void resetForce();
	void applyForce(ofVec2f force);
	ofVec2f mPosition, mVelocity, mAcceleration;
	float mLifeSpan;
};

