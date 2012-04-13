
#ifndef	PARTICULA
#define PARTICULA

#include "ofMain.h"

class Particula {
public:	
	Particula();
	
	void update();
	void draw();
	bool pasoElBorde();
	void agregarFuerza(ofVec2f fuerza);
	
	ofColor color;
	ofVec2f pos, vel, acc;
	
	int tamanio;
	
};
#endif