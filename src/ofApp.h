#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ParticleSystem.h"
#include "ParticleUpdater.h"
#include "ParticleEmitter.h"
#include "ParticleRenderer.h"
#include "ParticleGenerator_Acc.h"
#include "ParticleGenerator_Vel.h"
#include "ParticleGenerator_Positions.h"
#include "ParticleGenerator_Time.h"
#include "ParticleGenerator_Color.h"
#include "ParticleGenerator_Flag.h"
#include "ParticleUpdater_Collision.h"
#include "ParticleUpdater_Gravity.h"
#include "ParticleUpdater_Time.h"

class ofApp : public ofBaseApp{
	std::shared_ptr<ParticleUpdater_Gravity> Gravity;
	std::shared_ptr<ParticleUpdater_Collision> Collsiion;
	
	ParticleSystem system;
	ParticleRenderer render;
	ofEasyCam cam;

	ofxPanel gui;
	ofxFloatSlider G_X;
	ofxFloatSlider G_Y;
	ofxFloatSlider G_Z;
	ofxFloatSlider dt;
	ofxFloatSlider R;
	ofxToggle addButton;

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


		
};
