#include <FL/Fl.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include "Point.h"
#include "GUI.h"
#include "Graph.h"
#include "Window.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include <iostream>
#include <cmath>

using namespace std;

double domain(double a1 , double a2 , double b1 , double b2);

int main()
{
	int a[2] = {100,100};
	int b[2] = {500,100};
	int c[2] = {100,300};
	int d[2] = {150,200};
	int e[2] = {0,0};

	cout << "ok" <<endl;

	Simple_window win1(Point(100 , 100),600,400,"Calculator");

	Text t1 (Point (200,200),"convex");
	Text t2 (Point (200,200),"concave");
	t1.set_color(Color::blue);
	t2.set_color(Color::blue);

	int z , x  ;

	z = domain(b[0]-a[0] , b[1]-a[1] , e[0]-a[0] , e[1]-a[1])*domain(a[0]-b[0] , a[1]-b[1] , c[0]-b[0] , c[1]-b[1]);
	x = domain(a[0]-b[0] , a[1]-b[1] , c[0]-b[0] , c[1]-b[1])*domain(d[0]-c[0] , d[1]-c[1] , b[0]-c[0] , b[1]-c[1]);

	cout << x;
	if( z < 0)
		win1.attach(t1);
	else if( x < 0){
		win1.attach(t1);
	}
	else if(domain(d[0]-c[0] , d[1]-c[1] , b[0]-c[0] , b[1]-c[1])*domain(e[0]-d[0] , e[1]-d[1] , c[0]-d[0] , c[1]-d[1]) < 0){
		win1.attach(t1);
	}
	else if(domain(e[0]-d[0] , e[1]-d[1] , c[0]-d[0] , c[1]-d[1])*domain(d[0]-e[0] , d[1]-e[1] , a[0]-e[0] , a[1]-e[1]) < 0){
		win1.attach(t1);
	}
	else if(domain(d[0]-e[0] , d[1]-e[1] , a[0]-e[0] , a[1]-e[1])*domain(b[0]-a[0] , b[1]-a[1] , e[0]-a[0] , e[1]-a[1]) < 0){
		win1.attach(t1);
	}
	else{
		win1.attach(t2);
	}
	

    Line line1(Point(a[0],a[1]),Point(b[0],b[1]));
	Line line2(Point(b[0],b[1]),Point(c[0],c[1]));
	Line line3(Point(c[0],c[1]),Point(d[0],d[1]));
	Line line4(Point(d[0],d[1]),Point(e[0],e[1]));
	Line line5(Point(a[0],a[1]),Point(e[0],e[1]));

	win1.attach(line1);
	win1.attach(line2);
	win1.attach(line3);
	win1.attach(line4);
	win1.attach(line5);

	win1.wait_for_button();

    return 0;
}

double domain(double a1 , double a2 , double b1 , double b2)
{
	int z;

	z = a1*b2-a2*b1;
	
	return z;
}
