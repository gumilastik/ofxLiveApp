#include "Particle.h" 

Particle::Particle() {
	pos = ofVec2f(ofRandom(ofGetWidth() / 2 - 100, ofGetWidth() / 2 + 100), ofRandom(ofGetHeight() / 2 - 200, ofGetHeight() / 2 + 200));
	vel = ofVec2f(ofRandom(-0.2, 0.2), ofRandom(-0.2, 0.2));
	col = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Particle::update() {
	// change this
	pos += 10 * vel;
	if (pos.x < 0 || pos.y < 0 || pos.x > ofGetWidth() || pos.y > ofGetHeight()) vel = -vel;
}

void Particle::draw() {
	ofSetColor(col);

	// change this
	ofDrawCircle(pos, 2);
}
