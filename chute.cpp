#include "chute.h"
#include "line.h"
#include "polygon.h"
#include "point2D.h"
#include "rotationInArbitraryAxis.h"
#include "translation3D.h"
#include "rotation3D.h"
#include "scale3D.h"
#include "scaleWithFixedPoint.h"

/*
TO-DO:
-Ajustar coordenadas pra parecer uma perna
-Fazer a bola
-Fazer o movimento
*/
Chute::Chute() {
	p_quadril = new Point2D(100, 100, BLACK);
	p_joelho = new Point2D(300, 200, BLACK);
	p_tornozelo = new Point2D(350, 250, GREEN);
	p_pe = new Point2D(375, 275, RED);
	
	l_coxa = new Line(*p_quadril, *p_joelho, BLACK);
	l_canela = new Line(*p_joelho, *p_tornozelo, GREEN);
	l_pe = new Line(*p_tornozelo, *p_pe, RED);
	
	/*
	l1 = new Line(Point2D(0, 350), Point2D(700, 350), RED);
    l2 = new Line(Point2D(350, 0), Point2D(350, 700), RED);
    pol = new Polygon(true, RED, true, Color(255, 255, 0));
    p1 = new Point2D(400, 400, BLACK);
    pol->addVertex(p1);
    p2 = new Point2D(500, 450, BLACK);
    pol->addVertex(p2);
    p3 = new Point2D(450, 500, BLACK);
    pol->addVertex(p3);
	*/
}

Chute::~Chute() {
	delete l_coxa, l_canela, l_pe;
	delete pol;
	delete p_quadril, p_joelho, p_tornozelo, p_pe;
}

void Chute::draw(Screen &screen){
//	RotationInArbitraryAxis T(Point3D(350, 350, 0, RED), Point3D(350, 350, 1, RED), M_PI * count / 180);
        
//    count += 10;
//    if (count >= 360)
//    	count = 0;
            
//    Polygon *pol2 = pol->transform(&T);
       
    clear();
    
    /*
	add(l1);
	add(l2);
	add(pol);
	add(pol2);
	*/
	
	add(l_coxa);
	add(l_canela);
	add(l_pe);
	
	Picture::draw(screen);
	
//	delete pol2;
}