#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem
{
public:
	//ParticleSystem();
	//~ParticleSystem();

	/*void setup();
	void update();
	void draw();*/

	ParticleSystem(ofVec2f position);
	void update(ofVec2f force);
	void draw();

	ofColor mColors[6] = { ofColor(33,3,7) ,ofColor(239, 69, 1),ofColor(8, 128, 216),ofColor(255,254,20),ofColor(227,37,8),ofColor(0,174,29) };
	vector<Particle>    mParticleList;
	ofVec2f             mPosition;
	int                 mEmitRate;
	bool                mIsAddingParticles;
	float				singleX,singleY,orinY;
	ofImage             m;

};

