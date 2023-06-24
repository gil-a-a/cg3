#include "picture5.h"
#include "line.h"
#include "polygon.h"
#include "point2D.h"
#include "rotationInArbitraryAxis.h"
#include "translation3D.h"
#include "rotation3D.h"
#include "scale3D.h"
#include "scaleWithFixedPoint.h"

Picture5::Picture5() {
	l1 = new Line(Point2D(0, 350), Point2D(700, 350), RED);
    l2 = new Line(Point2D(350, 0), Point2D(350, 700), RED);
    pol = new Polygon(true, RED, true, Color(255, 255, 0));
    p1 = new Point2D(400, 400, BLACK);
    pol->addVertex(p1);
    p2 = new Point2D(500, 450, BLACK);
    pol->addVertex(p2);
    p3 = new Point2D(450, 500, BLACK);
    pol->addVertex(p3);
}

Picture5::~Picture5() {
	delete l1;
	delete l2;
	delete p1, p2, p3;
	delete pol;
}

void Picture5::draw(Screen &screen){
	RotationInArbitraryAxis T(Point3D(350, 350, 0, RED), Point3D(350, 350, 1, RED), M_PI * count / 180);
        
    count += 10;
    if (count >= 360)
    	count = 0;
            
    Polygon *pol2 = pol->transform(&T);
       
    clear();
    
    add(l1);
	add(l2);
	add(pol);
	add(pol2);
	
	Picture::draw(screen);
	
	delete pol2;
}