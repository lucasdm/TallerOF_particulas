
#ifndef	PARTICULA
#define PARTICULA

#include "ofMain.h"

class Particula {
public:	
	Particula();
    Particula(Particula &_padre , Particula &_madre);
    Particula(int _x, int _y);
	
	
    bool tocandoCon( Particula &_otra);
    
	bool pasoElBorde();
    bool estaViva(){ return bVive; };
	bool isChocando();
    ofVec2f getPosicion();
    int getTamanio();
    void irAdondeMouse(int _x, int _y){pos.set(_x,_y);};
	void agregarFuerza(ofVec2f fuerza);
    void setChocando(bool _choca);
	
    void update();
    void draw();
	
private:
	ofColor color;
	ofVec2f pos, vel, acc;
	
	int     tamanio;
    int     vida;
    bool    bVive;
	bool	bChocando;
	void inicializar(int _x, int _y); //define los atributos iniciales de las particulas
	
	
};
#endif