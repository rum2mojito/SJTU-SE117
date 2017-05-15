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
#include <cstring>

using namespace std;

class blocks
{
private:
	int x , y , L , order;
public:
	blocks (int m , int n , int o , int p)
	{
		x = m;
		y = n;
		L = o;
		order = p;
		window();
	}

	void window ()
	{
		Simple_window win1(Point(x , y),L,L,"Blocks");

		int length = L;
		int n = 0;
		Rectangle *p;

		for (int i=0;i<order;++i){
			length /= 4;

			cout << length <<endl;
			
			for (n=0;n<L;n+=length)
			{
				p = new Rectangle (Point(n,L-n-length),length,length);
				win1.attach(*p);
				cout << "ok" <<endl;
			}
		}
		

		win1.wait_for_button();
	}
};

int main ()
{
	blocks b1(100 , 100 , 640 , 3); 
	return 0;
}
