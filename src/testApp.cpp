#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetCircleResolution(200);
	ofEnableSmoothing();
	ofSetVerticalSync(true);	
	ofHideCursor();	
	ofSetFullscreen(true);	
	for(int i = 0; i < TOTAL; i++){
		p[i].pos.set(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
	}	
}

//--------------------------------------------------------------
void testApp::update(){
	ofSetWindowTitle("fps: " + ofToString(ofGetFrameRate()));	
	for(int i = 0; i < TOTAL; i++){
		p[i].agregarFuerza(ofVec2f(0,0.0098));
		p[i].update();
		
		if (p[i].pasoElBorde()){
			p[i] = Particula();
			p[i].pos.set(mouseX,mouseY);
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);

	for(int i = 0; i < TOTAL; i++){
		p[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}