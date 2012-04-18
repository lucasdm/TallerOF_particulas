#include "Particula.h";

Particula::Particula(){
	/*tamanio = ofRandom(8);
	color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	pos.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
	vel.set(ofRandom(-1,1),ofRandom(-1,1));
	acc.set(ofRandom(-1,1),ofRandom(-1,1));
    
    vida = 100;
    bVive = true;*/
	inicializar(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
}

Particula::Particula(int _x, int _y){
	inicializar(_x,_y);
}

Particula::Particula( Particula &_padre, Particula &_madre ){
	//inicializar(_padre.pos.x,_madre.pos.y);
	
    tamanio = (_padre.tamanio+_madre.tamanio)*0.5;
	color = ofColor(255);
    
    pos.x = (_padre.pos.x + _madre.pos.x)*0.5;
    pos.y = (_padre.pos.y + _madre.pos.y)*0.5;

	vel = 1;
	acc = 1;
    _padre.vel *= -1;
	_madre.vel *= -1;

    vida = 1000;
    bVive = true;
	bChocando = true;
	
}

void Particula::inicializar(int _x, int _y){
	//define las propiedades iniciales de las particulas
	tamanio = ofRandom(8);
	color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	pos = ofVec2f(_x,_y);
    
	vel.set(ofRandom(-1,1),ofRandom(-1,1));
	acc.set(ofRandom(-2,2),ofRandom(-1,1));
    
    vida = ofRandom(500,1000);//tiempo de vida
    bVive = true;
	bChocando = false;	
}


void Particula::agregarFuerza(ofVec2f fuerza){
	acc += fuerza;
}

void Particula::update(){
	vel += acc;
	pos += vel;
	acc *= 0;
    
    vida = vida - 1;
	
    if(vida <= 0)
        bVive = false;
}

void Particula::draw(){
	ofSetColor(color);
	ofCircle(pos.x, pos.y, tamanio);
}

bool Particula::tocandoCon( Particula &_otra){
	bool rta = false;
	
	if (pos.distance(_otra.pos) < (tamanio+_otra.tamanio)*0.5){
		//cout << "TOCA";
		rta = true;
	}
	
	return rta;
};

ofVec2f Particula::getPosicion(){ 
	return pos;
};

bool Particula::isChocando(){ 
	return bChocando;
};

void Particula::setChocando(bool _choca){ 
	bChocando = _choca;
};

int Particula::getTamanio(){ 
	return tamanio;
};

bool Particula::pasoElBorde(){
	bool rta = false;   
	if ( pos.x < 0 || pos.y < 0 || pos.x > ofGetWindowWidth() || pos.y > ofGetWindowHeight())
		rta = true;
	
	return rta;
}