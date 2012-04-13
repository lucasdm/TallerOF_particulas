#include "Particula.h";

Particula::Particula(){
	tamanio = ofRandom(8);
	color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	pos.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
	vel.set(ofRandom(-1,1),ofRandom(-1,1));
	acc.set(ofRandom(-1,1),ofRandom(-1,1));
}

void Particula::agregarFuerza(ofVec2f fuerza){
	acc += fuerza;
}

void Particula::update(){
	vel += acc;
	pos += vel;
	acc *= 0;
}

void Particula::draw(){
	ofSetColor(color);
	ofCircle(pos.x, pos.y, tamanio);
}

bool Particula::pasoElBorde(){
	bool rta = false;   
	if ( pos.x < 0 || pos.y < 0 || pos.x > ofGetWindowWidth() || pos.y > ofGetWindowHeight())
		rta = true;
	
	return rta;
}