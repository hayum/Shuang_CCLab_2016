#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	space = 0;
	maH = ofGetWindowHeight() * 2 / 3 - 60;
	maPos = ofVec2f(100,maH);
	muPos = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight()*2/3-25);
	mali.load("images/mali.png");
	mushroom.load("images/m.png");
	pillar = ofVec2f(300, 430);
	ofSetCircleResolution(50.f);
	ellipse = ofVec2f(100, 100);
	text = ofVec2f(20, 50);
	dead = 0;
	state = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	//Move Cloud, Pillar and Star
	if (ofGetFrameNum() % 30 == 0) {
		if (ellipse.x > 0) {
			ellipse.x -= 10;
		}
		else ellipse.x = ofGetWindowWidth();
		angle += 5;
		if (pillar.x > 0) {
			pillar.x -= 10;
		}
		else pillar.x = ofGetWindowWidth();
	}
	
    //Change Mushroom
	if (ofGetFrameNum() % 60 == 0) {
		if (scale > 0.8) {
			scale = scale - 0.1f;
		}
		else {
			scale = 1.f;
		}
		muPos.x -= 30;
		if (muPos.x < 0) {
			muPos.x = ofGetWindowWidth();
		}
		muPos.y = ofGetWindowHeight() * 2 / 3 - 25 * scale;
	}

	//mario jump and death judgement
	if (((maPos.x + 30) >(muPos.x - 20)) && ((maPos.x + 30) < (muPos.x + 20)) && (maPos.y + 60>muPos.y - 25 * scale)) {
		dead = 1;
	}
	if (dead == 1) {
		mali.load("images/mali2.png");
		if (ofGetFrameNum() % 20 == 0) {
			//Rising
			if (state == 0) {
				if (maPos.y > maH - 60) {
					maPos.y = maPos.y - 20;
				}
				if (maPos.y <= maH - 60) {
					state = 1;
				}
			}
			//Falling
			if (state == 1) {
				maPos.y = maPos.y + 10;
			}
		}
	}
	//Jump
	else if (ofGetFrameNum() % 5 == 0) {
		//Rising
		if (space == 1) {
			//maPos.y = maH - 100; 
			if (maPos.y > maH - 150) {
				maPos.y -= 5;
			}
			if (maPos.y <= maH - 150) {
				space = 2;
			}
		}
		//Falling
		if (space == 2) {
			if (maPos.y < maH) {
				maPos.y += 5;
			}
			if (maPos.y == maH) {
				space = 0;
			}
		}
	}

	cout << maPos.y+60 << endl;
	cout << muPos.y-25 << endl;
	cout << "-------" << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
	//Sky
	ofSetBackgroundColor(94,178,216);
	
	//Star
	ofSetColor(255, 241, 121);
	ofPushMatrix();
	ofTranslate(200, 55, 0);
	ofRotate(angle);
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofVertex(400, 135);
	ofVertex(215, 135);
	ofVertex(365, 25);
	ofVertex(305, 200);
	ofVertex(250, 25);
	ofEndShape();
	ofPopMatrix();
	
	//Ground
	ofSetColor(148, 104, 89);
	ofDrawRectangle(0, ofGetWindowHeight()*2/3 , ofGetWindowWidth(), ofGetWindowHeight() / 3);
	
	//Pillar
	ofSetColor(79, 171, 82);
	ofDrawRectRounded(pillar, 60, 70,5 );
	
	//Mario
	ofSetColor(255, 255, 255);
	mali.draw(maPos, 60, 60);

	//Mushroom
	ofSetColor(255, 255, 255);
	mushroom.setAnchorPercent(0.5, 0.5);
	mushroom.draw(muPos, 50*scale, 50*scale);

	//Cloud
	ofDrawEllipse(ellipse, 200, 120);


    //Text
	ofSetColor(255, 255, 255);
	ofDrawBitmapStringHighlight(ofToString(ofGetElapsedTimef()),text.x,text.y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a') {
		if (maPos.x > 0) {
			maPos.x -= 30;
		}
	}
	else if (key == 'd') {
		if (maPos.x < ofGetWindowWidth()) {
			maPos.x += 30;
		}
	}
	else if (key == ' ') {
		space = 1;
		maPos.x += 10;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
