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
	Particula nueva;
	
   // int totalDeParticulas = particulas.size();
	for(int i = 0; i < particulas.size(); i++){
	
		particulas[i].agregarFuerza(ofVec2f(0,0.0098));
		particulas[i].update();
		if (!particulas[i].estaViva() ){
			particulas.erase(particulas.begin()+i);// Como si fuera un 0 + i
		}else {
			for(int j = 0; j < particulas.size(); j++){
				if ( j != i ){
					//cout << "DISTINTO";
					if (particulas[i].tocandoCon(particulas[j])&&!particulas[i].isChocando()&&!particulas[j].isChocando()){
						nueva = Particula( particulas[i], particulas[j]);
						particulas[i].setChocando(true);
						particulas[j].setChocando(true);
						//particulas.push_back(nueva);
							
						//cout << "choca " + i + " con " + j << endl;
					}else {
						if(!particulas[i].tocandoCon(particulas[j])){
							particulas[i].setChocando(false);
							particulas[j].setChocando(false);
						}
					}

					
				}

			}	

		}
			
	
	}
	//particulas.push_back(nueva);

    /*
    for(int i = particulas.size(); i >= 0 ; i--){
        if ( !particulas[i].estaViva() ){
            particulas.erase( particulas.begin() + i ); // Como si fuera un 0 + i
        }
        if (particulas[i].pasoElBorde()){
			particulas.erase( particulas.begin() + i ); // Como si fuera un 0 + i
		}
	}*/
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
    for(int i = 0; i < 20; i++){
//        Particula nueva = Particula( ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()) );
		Particula nueva = Particula( x,y );
      
        particulas.push_back(nueva);
	}	
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