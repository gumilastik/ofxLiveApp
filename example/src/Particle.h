#pragma once

#include "ofMain.h"

class Particle
{
	ofVec2f pos;
	ofVec2f vel;
	ofColor col;

public:
	Particle();

	void update();
	void draw();
};
