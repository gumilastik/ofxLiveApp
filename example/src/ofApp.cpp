#include "ofApp.h" 

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	timeLastUpdate = 0.0;

	reinit();
}

//--------------------------------------------------------------
void ofApp::reinit() {
	cout << "reinit" << endl;

	timeLastUpdate = ofGetElapsedTimef();

	// change this
	particles.resize(200);
}

//-------------------------------------------------------------- 
void ofApp::update() {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofClear(80, 80, 80);

	ofPushStyle();
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
	ofPopStyle();

	ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);

	ofDrawBitmapStringHighlight("app updated...", 10, ofMap(ofGetElapsedTimef(), timeLastUpdate, timeLastUpdate + 1.0, 20, -10, true), ofColor::black, ofColor::red);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
