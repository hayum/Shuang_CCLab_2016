#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem
{
public:
	ParticleSystem(ofVec2f position);
	//~ParticleSystem();

	/*void setup();*/
	void update(ofVec2f force);
	void draw();

	vector<Particle> mParticleList;
	//Particle mParticle;
	ofVec2f mPosition;
	int mEmitRate;
	bool mIsAddingParticles;
};

