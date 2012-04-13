
#ifndef	PARTICULA
#define PARTICULA

#include "ofMain.h"

class Particula {
public:	
	Particula();
    Particula(Particula &_padre , Particula &_madre);
    Particula(int _x, int _y);
	
	
    bool tocandoCon( Particula &_otra){
        bool rta = false;
        
        if ( pos.distance( _otra.pos ) < (tamanio*0.5+_otra.tamanio*0.5) ){
            rta = true;
        }
        
        return rta;
    };
    
	bool pasoElBorde();
    bool estaViva(){ return bVive; };
    
    
    void irAdondeMouse(int _x, int _y){pos.set(_x,_y);};
	void agregarFuerza(ofVec2f fuerza);
    
    void update();
    void draw();
	
//private:
	ofColor color;
	ofVec2f pos, vel, acc;
	
	int     tamanio;
    int     vida;
    bool    bVive;
	
};
#endif