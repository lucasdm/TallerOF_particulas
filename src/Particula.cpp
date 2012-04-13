#include "Particula.h";

Particula::Particula(){
	tamanio = ofRandom(8);
	color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	pos.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
	vel.set(ofRandom(-1,1),ofRandom(-1,1));
	acc.set(ofRandom(-1,1),ofRandom(-1,1));
    
    vida = 100;
    bVive = true;
}

Particula::Particula(int _x, int _y){
	tamanio = ofRandom(8);
	color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	pos = ofVec2f(_x,_y);
    
	vel.set(ofRandom(-1,1),ofRandom(-1,1));
	acc.set(ofRandom(-1,1),ofRandom(-1,1));
    
    vida = 100;
    bVive = true;
}

Particula::Particula( Particula &_padre, Particula &_madre ){
    tamanio = _padre.tamanio;
	color = _padre.color*0.5 + _madre.color*0.5;
    
    pos = (_padre.pos + _madre.pos)*0.5;
	vel.set(ofRandom(-1,1),ofRandom(-1,1));
	acc.set(ofRandom(-1,1),ofRandom(-1,1));
    
    vida = 100;
    bVive = true;
}


void Particula::agregarFuerza(ofVec2f fuerza){
	acc += fuerza;
}

void Particula::update(){
	vel += acc;
	pos += vel;
	acc *= 0;
    
    vida = vida - 1;
    
    if ( vida <= 0)
        bVive = false;
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