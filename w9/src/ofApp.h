#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofImage mali;
		ofImage mushroom;
		float scale;
		ofVec2f maPos;
		ofVec2f muPos;
		ofVec2f pillar;
		ofVec2f ellipse;
		ofVec2f text;
		int space;//Space press judge
		int maH;
		int angle;
		int dead;
		int state;//Death Animation up and down
		//ofPath pillar;
};
