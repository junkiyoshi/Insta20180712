#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor line_color;
	int rect_len = 144;
	for (int x = rect_len / 2; x <= ofGetWidth() - rect_len / 2; x += rect_len) {

		for (int y = rect_len / 2; y <= ofGetHeight() - rect_len / 2; y += rect_len) {

			float random_value = ofRandom(1000);

			ofBeginShape();
			for (int deg = 0; deg < 360; deg += 1) {

				ofPoint rect_point = this->make_rect_point(rect_len, deg);
				int noise_value = ofNoise(random_value, rect_point.x * 0.001, rect_point.y * 0.001, ofGetFrameNum() * 0.005) * 10;
				ofPoint point = this->make_rect_point(rect_len * noise_value * 0.1, deg) + ofPoint(x, y);

				ofVertex(point);
			}
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg, int z) {

	int half_len = len * 0.5;
	int param = (deg + 45) / 90;
	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(half_len, ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), z);
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), half_len, z);
	case 2:

		return ofPoint(-half_len, ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), z);
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), -half_len, z);
	default:

		return ofPoint(0, 0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}