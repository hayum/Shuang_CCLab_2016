#include "ParticleSystem.h"



//ParticleSystem::ParticleSystem()
//{
//}

//
//ParticleSystem::~ParticleSystem()
//{
//}

ParticleSystem::ParticleSystem(ofVec2f position)
	: mPosition(position)
	, mEmitRate(2)
	, mIsAddingParticles(true)
	, singleX(position.x)
	, singleY((float)ofGetWindowHeight())
	,orinY(position.y)
{
	m.load("images/m.jpg");
}



//--------------------------
void ParticleSystem::update(ofVec2f force) {
	singleY = singleY - 4;
	if (ofGetFrameNum() % 10 == 0) {
		
		if (mIsAddingParticles) {
			// pushing particles into the array
			for (int i = 0; i < mEmitRate; i++) {
				Particle particle(mPosition);

				mParticleList.push_back(particle);

			}
		}
		
		for (int i = 0; i < mParticleList.size(); i++) {

			// calculating the difference between center and particle position
			ofVec2f diff = ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x), abs(mParticleList[i].mPosition.y - mPosition.y));

			mParticleList[i].resetForces();
			// force in here is passed from ofapp
			mParticleList[i].applyForce(force);
			// this apply to the random velocity to the particle
			mParticleList[i].update(ofMap(diff.length(), 0, 200, 4, 1));


			if (diff.length() >= ofRandom(200, 400)) {
				// stop adding particle if the any particle's diff is higher than a certain number
				mIsAddingParticles = false;
				// erase the particle if it is too far from the center
				if (mParticleList.size() > 0) {
					mParticleList.erase(mParticleList.begin() + i);

				}
			}
		}
	}
}


//--------------------------
void ParticleSystem::draw() {
	if (singleY+5 > orinY) {
		m.draw(singleX, singleY, 50,80);
		
	}
	else{
		for (int i = 0; i < mParticleList.size(); i++) {
			ofSetColor(mColors[i % 6]);
			mParticleList[i].draw();
		}
	}
}