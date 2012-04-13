#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetCircleResolution(200);
	ofEnableSmoothing();
	ofSetVerticalSync(true);	
	//ofHideCursor();	
	//ofSetFullscreen(true);	
	
    for(int i = 0; i < TOTAL; i++){
        Particula nueva = Particula( ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()) );
        
        particulas.push_back(nueva);
	}	
}

//--------------------------------------------------------------
void testApp::update(){
	ofSetWindowTitle("fps: " + ofToString(ofGetFrameRate()));
	
    int totalDeParticulas = particulas.size();
    
	for(int i = 0; i < totalDeParticulas; i++){
		particulas[i].agregarFuerza(ofVec2f(0,0.0098));
		particulas[i].update();

        
        for(int j = 0; j < totalDeParticulas; j++){
            if ( j != i ){
                if (particulas[i].tocandoCon(particulas[j])){
                    Particula nueva = Particula( particulas[i], particulas[j] );
                    
                    particulas.push_back(nueva);
                }
                
            }
        }
	}
    
    for(int i = particulas.size(); i >= 0 ; i--){
        if ( !particulas[i].estaViva() ){
            particulas.erase( particulas.begin() + i ); // Como si fuera un 0 + i
        }
        if (particulas[i].pasoElBorde()){
			particulas.erase( particulas.begin() + i ); // Como si fuera un 0 + i
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);

	for(int i = 0; i < particulas.size() ; i++){
		particulas[i].draw();
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