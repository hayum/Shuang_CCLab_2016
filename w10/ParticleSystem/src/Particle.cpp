#include "Particle.h"
Particle::Particle(ofVec2f position)
	:mPosition(position)
	, mVelocity(ofRandom(-8.f, 8.f), ofRandom(-8.f, 8.f))
	, mAcceleration(ofVec2f(0))
	, mLifeSpan(255.f)
{
	myfont.loadFont("Chunkfive.otf", 20);
}


//Particle::Particle()
//{
//}


//Particle::~Particle()
//{
//}

//-------------------------------------
void Particle::resetForces()
{
	// reset the acceleration
	mAcceleration *= 0;
}

//-------------------------------------
void Particle::applyForce(ofVec2f force)
{
	// adding force to acceleration
	mAcceleration += force;
}

//-------------------------------------
void Particle::update(float multiplier)
{
	// apply accelearation to velocity
	mVelocity += mAcceleration;
	mPosition += mVelocity * multiplier;

	// decreasing the particle life
	if (mLifeSpan > 0) {
		mLifeSpan -= 2.f;
	}
}


//-------------------------------------
void Particle::draw()
{
	//if (mLifeSpan > 100) {
	//	// new born partilce will be brighter
	//	ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255),255);
	//		//,mLifeSpan);
	//}
	//else if (mLifeSpan <= 100) {
	//	// do some sparkle!
	//	//ofSetColor(ofRandom(0, 255));
	//	ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255),255);
	//		//, ofRandom(0, 255));
	//}

	//ofSetColor(mColors[(int)ofRandom(0, 5)]);
	// closer particle is smaller
	float scale;
	scale= ofMap(mLifeSpan, 0, 255.f, 0, 1.f);
	ofDrawCircle(mPosition, 18.f * scale);
	
	//Draw M
	ofPushMatrix();
	  ofSetColor(255);
	  ofScale(scale,scale);
	  ofTranslate(-myfont.stringWidth("m")/2, myfont.stringHeight("m")/2);
	  if (scale > 0.5) {
		myfont.drawString("m", mPosition.x/scale, mPosition.y/scale);
	  }
	ofPopMatrix();
	
}