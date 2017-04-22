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

struct Lines_window : Window // Lines_window inherits from Window
{
	Lines_window(Point xy, int w, int h, const string& title); // declare
	Open_polyline lines;
	private:
		Button next_button; // declare some buttons – type Button
		Button quit_button;
		Button button_1;
		Button button_2;
		Button button_3;
		Button button_4;
		Button button_5;
		Button button_6;
		Button button_7;
		Button button_8;
		Button button_9;
		In_box next_x; // declare some i/o boxes
		In_box next_y;
		Out_box xy_out;
		Out_box ans_out;
		void next(); // what to do when next_button is pushed
		void quit(); // what to do when quit_botton is pushed
		static void cb_next(Address, Address window); // callback for next_button
		static void cb_quit(Address, Address window); // callback for quit_button
}; 
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy,w,h,title),
	// construct/initialize the parts of the window:
	// location size name action
	next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next),
	quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit), // quit button
	button_1(Point(0,200), 100, 100, "1", cb_next),
	button_2(Point(100,200), 100, 100, "2", cb_next),
	button_3(Point(200,200), 100, 100, "3", cb_next),
	button_4(Point(0,300), 100, 100, "4", cb_next),
	button_5(Point(100,300), 100, 100, "5", cb_next),
	button_6(Point(200,300), 100, 100, "6", cb_next),
	button_7(Point(0,400), 100, 100, "7", cb_next),
	button_8(Point(100,400), 100, 100, "8", cb_next),
	button_9(Point(200,400), 100, 100, "9", cb_next),
	next_x(Point(x_max()-310,0), 50, 20, "next x:"), // io boxes
	next_y(Point(x_max()-210,0), 50, 20, "next y:"),
	xy_out(Point(100,0), 100, 20, "current (x,y):"),
	ans_out(Point(100,100), 400, 100, "Answer:")
{
		attach(next_button); // attach the parts to the window
		attach(quit_button);
		attach(button_1);
		attach(button_2);
		attach(button_3);
		attach(button_4);
		attach(button_5);
		attach(button_6);
		attach(button_7);
		attach(button_8);
		attach(button_9);
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		attach(lines); // attach the open_polylines to the window
		attach(ans_out);
}
void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point(x,y));
	// update current position readout:
	stringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	ans_out.put(ss.str());
	redraw(); // now redraw the screen
} 
void Lines_window::quit()
{
	// here we can do just about anything with the Lines_window
	hide(); // peculiar FLTK idiom for “get rid of this window”
}
void Lines_window::cb_quit(Address, Address pw)// Call Lines_window::quit() for the window located at address pw
{
	reference_to<Lines_window>(pw).quit(); // now call our function
} 
void Lines_window::cb_next(Address,Address pw)
{
	reference_to<Lines_window>(pw).next();
}

int main()
{
	Lines_window win(Point(100,100),500,500,"calculator");
	return gui_main(); // an “infinite loop”
}
