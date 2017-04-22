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

void trans (char str[]);
void num_of_char (char str[]);
void op(int k);
void arrange();
void go2();
void counting(int k,int m);
double answer(char input[10000]);

struct Lines_window : Window // Lines_window inherits from Window
{
	Lines_window(Point xy, int w, int h, const string& title); // declare
	Open_polyline lines;
	private:
		// declare char
		char input[10000];
		char *p ;
		// declare some buttons – type Button 
		Button quit_button;
		//number button
		Button button_0;
		Button button_1;
		Button button_2;
		Button button_3;
		Button button_4;
		Button button_5;
		Button button_6;
		Button button_7;
		Button button_8;
		Button button_9;
		//function button
		Button button_add;
		Button button_diminish;
		Button button_plus;
		Button button_divide;
		Button button_remainder;
		Button button_factorial;
		Button button_top_bracket;
		Button button_low_bracket;
		Button button_dot;
		Button button_C;
		Button button_equal;
		// declare some i/o boxes
		Out_box ans_out;
		Out_box equation_out;
		void quit(); // what to do when quit_botton is pushed
		// number function
		void one();
		void two();
		void three();
		void four();
		void five();
		void six();
		void seven();
		void eight();
		void nine();
		void zero();
		// operator function
		void add();
		void diminish();
		void plus();
		void divide();
		void C();
		void top_bracket();
		void low_bracket();
		void remainder();
		void factorial();
		void dot();
		void equal();
		void clean();
		// information
		Text t1;
		Text t2;
		Text t3;
		// callback function
		static void cb_one(Address, Address window);
		static void cb_two(Address, Address window);
		static void cb_three(Address, Address window);
		static void cb_four(Address, Address window);
		static void cb_five(Address, Address window);
		static void cb_six(Address, Address window);
        static void cb_seven(Address, Address window);
		static void cb_eight(Address, Address window);
		static void cb_nine(Address, Address window);
		static void cb_zero(Address, Address window);
		static void cb_add(Address, Address window);
		static void cb_diminish(Address, Address window);
		static void cb_plus(Address, Address window);
		static void cb_divide(Address, Address window);
		static void cb_C(Address, Address window);
		static void cb_remainder(Address, Address window);
		static void cb_top_bracket(Address, Address window);
		static void cb_low_bracket(Address, Address window);
		static void cb_factorial(Address, Address window);
		static void cb_dot(Address, Address window);
		static void cb_equal(Address, Address window);
		static void cb_clean(Address, Address window);
		static void cb_quit(Address, Address window); // callback for quit_button
}; 

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy,w,h,title),
	// construct/initialize the parts of the window:
	// information
	t1 (Point (500,50),"Author:   SHI,YU-WEI"),
	t2 (Point (500,75),"Date:     2017/4/23"),
	t3 (Point (500,100),"Version: 1.0"),
	// location size name action
	quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit), // quit button
	// number button
	button_0(Point(300,200), 100, 100, "0", cb_zero),
	button_1(Point(0,200), 100, 100, "1", cb_one),
	button_2(Point(100,200), 100, 100, "2", cb_two),
	button_3(Point(200,200), 100, 100, "3", cb_three),
	button_4(Point(0,300), 100, 100, "4", cb_four),
	button_5(Point(100,300), 100, 100, "5", cb_five),
	button_6(Point(200,300), 100, 100, "6", cb_six),
	button_7(Point(0,400), 100, 100, "7", cb_seven),
	button_8(Point(100,400), 100, 100, "8", cb_eight),
	button_9(Point(200,400), 100, 100, "9", cb_nine),
	// function button
	button_add(Point(600,200), 100, 100, "+", cb_add),
	button_dot(Point(600,300), 100, 100, ".", cb_dot),
	button_diminish(Point(400,200), 100, 100, "-", cb_diminish),
	button_plus(Point(500,200), 100, 100, "*", cb_plus),
	button_divide(Point(300,300), 100, 100, "/", cb_divide),
	button_remainder(Point(400,300), 100, 100, "%", cb_remainder),
	button_factorial(Point(500,300), 100, 100, "!", cb_factorial),
	button_top_bracket(Point(300,400), 100, 100, "(", cb_top_bracket),
	button_low_bracket(Point(400,400), 100, 100, ")", cb_low_bracket),
	button_C(Point(500,400), 100, 100, "C", cb_clean),
	button_equal(Point(600,400), 100, 100, "=", cb_equal),
	// io boxes
	ans_out(Point(100,100), 400, 100, "Answer:"),
	equation_out(Point(100,0), 400, 100, "Equation:")
{
	    // information
	    
	    // initialize pointer
	    p = input;
		// attach the parts to the window
		attach(t1);
		attach(t2);
		attach(t3);
		attach(quit_button);
		attach(button_0);
		attach(button_1);
		attach(button_2);
		attach(button_3);
		attach(button_4);
		attach(button_5);
		attach(button_6);
		attach(button_7);
		attach(button_8);
		attach(button_9);
		attach(button_add);
		attach(button_diminish);
		attach(button_plus);
		attach(button_divide);
		attach(button_remainder);
		attach(button_C);
		attach(button_dot);
		attach(button_top_bracket);
		attach(button_low_bracket);
		attach(button_factorial);
		attach(button_equal);
		attach(ans_out);
		attach(equation_out);
}
void Lines_window::quit()
{
	// here we can do just about anything with the Lines_window
	hide(); // peculiar FLTK idiom for “get rid of this window”
}
// number button callback
void Lines_window::one()
{
    *p = '1';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::two()
{
    *p = '2';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::three()
{
    *p = '3';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::four()
{
    *p = '4';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::five()
{
    *p = '5';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::six()
{
    *p = '6';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::seven()
{
    *p = '7';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::eight()
{
    *p = '8';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::nine()
{
    *p = '9';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::zero()
{
    *p = '0';
	p++;
	*p = '\0';
	equation_out.put(input);
}
// operator callback function
void Lines_window::add()
{
    *p = '+';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::diminish()
{
    *p = '-';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::plus()
{
    *p = '*';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::divide()
{
    *p = '/';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::top_bracket()
{
    *p = '(';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::low_bracket()
{
    *p = ')';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::dot()
{
    *p = '.';
	p++;
	*p = '\0';
	equation_out.put(input);
}
void Lines_window::remainder()
{
    *p = '%';
	p++;
	*p = '\0';
	equation_out.put(input);

}
void Lines_window::factorial()
{
    *p = '!';
	p++;
	*p = '\0';
	equation_out.put(input);

}
void Lines_window::equal()
{
	double ans;
    ans = answer(input);
	if (ans == -99999999999999){
		ans_out.put("error");
	}
	else{
		stringstream ss;
		string str;
		ss<<ans;
		ss>>str;
	    ans_out.put(str);
	}

}
void Lines_window::clean()
{
    p = input;
	*p = '\0';
	equation_out.put(input);
	ans_out.put("");
}

// call function
void Lines_window::cb_one(Address,Address pw)
{
	reference_to<Lines_window>(pw).one();
}
void Lines_window::cb_two(Address,Address pw)
{
	reference_to<Lines_window>(pw).two();
}
void Lines_window::cb_three(Address,Address pw)
{
	reference_to<Lines_window>(pw).three();
}
void Lines_window::cb_four(Address,Address pw)
{
	reference_to<Lines_window>(pw).four();
}
void Lines_window::cb_five(Address,Address pw)
{
	reference_to<Lines_window>(pw).five();
}
void Lines_window::cb_six(Address,Address pw)
{
	reference_to<Lines_window>(pw).six();
}
void Lines_window::cb_seven(Address,Address pw)
{
	reference_to<Lines_window>(pw).seven();
}
void Lines_window::cb_eight(Address,Address pw)
{
	reference_to<Lines_window>(pw).eight();
}
void Lines_window::cb_nine(Address,Address pw)
{
	reference_to<Lines_window>(pw).nine();
}
void Lines_window::cb_zero(Address,Address pw)
{
	reference_to<Lines_window>(pw).zero();
}
void Lines_window::cb_quit(Address, Address pw)// Call Lines_window::quit() for the window located at address pw
{
	reference_to<Lines_window>(pw).quit(); // now call our function
} 
// call operator function
void Lines_window::cb_dot(Address,Address pw)
{
	reference_to<Lines_window>(pw).dot();
}
void Lines_window::cb_add(Address,Address pw)
{
	reference_to<Lines_window>(pw).add();
}
void Lines_window::cb_diminish(Address,Address pw)
{
	reference_to<Lines_window>(pw).diminish();
}
void Lines_window::cb_plus(Address,Address pw)
{
	reference_to<Lines_window>(pw).plus();
}
void Lines_window::cb_divide(Address,Address pw)
{
	reference_to<Lines_window>(pw).divide();
}
void Lines_window::cb_top_bracket(Address,Address pw)
{
	reference_to<Lines_window>(pw).top_bracket();
}
void Lines_window::cb_low_bracket(Address,Address pw)
{
	reference_to<Lines_window>(pw).low_bracket();
}
void Lines_window::cb_remainder(Address,Address pw)
{
	reference_to<Lines_window>(pw).remainder();
}
void Lines_window::cb_factorial(Address,Address pw)
{
	reference_to<Lines_window>(pw).factorial();
}
void Lines_window::cb_equal(Address,Address pw)
{
	reference_to<Lines_window>(pw).equal();
}
void Lines_window::cb_clean(Address,Address pw)
{
	reference_to<Lines_window>(pw).clean();
}

int main()
{
	Lines_window win(Point(100,100),700,500,"calculator");
	return gui_main(); // an “infinite loop”
}

struct DATA{
    double num ;
    char op ;
    bool status ;
    int level ;
    int b_level ;
};

int amount;
DATA d[100000] ;
bool check = true;
int brackets = 0;
int memory = 0;
bool cont = true;

double answer(char input[10000])
{
	check = true;
    cout << input <<endl;
    for(int h=0;h<10000;++h){
        if (input [h]>='0' && input[h] <= '9')
            continue;
        else if (input[h] == '.' || input[h] == 'M' || input[h] == 'C' || input[h] == 'R' || input[h] == '+' || input[h] == '-')
            continue;
        else if (input[h] == '*' || input[h] == '/' || input[h] == '(' || input[h] == ')' || input[h] == '!' || input[h] == '%')
            continue;
        else if (input[h] == '\0')
            break;
        else
            check = false;
    }

    num_of_char (input);
    trans (input);
    arrange();
    go2();

    if (check){
        double ans = d[0].num;
		for (int i=0;i<100000;++i){
			d[i].num = 0;
			d[i].op = 0;
			d[i].status = 0;
			d[i].level = 0;
			d[i].b_level = 0;
        }
        check = true;
		return ans;
    }
    if (!check){
		for (int i=0;i<100000;++i){
			d[i].num = 0;
			d[i].op = 0;
			d[i].status = 0;
			d[i].level = 0;
			d[i].b_level = 0;
        }
        check = true;
		return -99999999999999;
	}

}

//count the amount of the string
void num_of_char (char str[])
{
    int i;

    for (i=0;;i++){
        if (str[i] == '\0'){
            amount = i;
            break;
        }
    }
}

//trans char to number and specify the operator's level
void trans (char str[])
{
    int i , j , order , k = 0;
    bool top = false;

    for (i=0;i<=amount;++i){
        int keep = i;
        if (str[i]>='0' && str[i]<= '9'){
            order = 0;
            for (j=i+1;j<=amount;++j){
                if (str[j]<'0' || str[j]> '9'){
                    order = j - i -1;
                    i = j - 1;
                    break;
                }
            }
            if (str[i+1] == '.'){
                for (j=i+2;j<=amount;++j){
                    if (str[j]<'0' || str[j]> '9'){
                        i = j - 1;
                        break;
                    }
                    double q = str[j] - '0';
                    for (int y=1;y<=j-i-1;++y){
                        q *= 0.1;
                    }
                    d[k].num += q;
                }
            }
            for (j=0;j<=order;++j){
                int q = str[keep+j] - '0';
                int c = 1;
                for (int d=order-j;d>0;--d){
                    c *= 10;
                }
                int g = q * c;
                d[k].num += g;
                d[k].status = true;
            }
            ++k;
        }
        else{
            d[k].op = str[i];
            d[k].status = false;
            if (d[k].op == '+' || d[k].op == '-'){
                d[k].level = 1;
                d[k].b_level = brackets;
            }
            if (d[k].op == '*' || d[k].op == '/' || d[k].op == '%'){
                d[k].level = 2;
                d[k].b_level = brackets;
            }
            if (d[k].op == '!'){
                d[k].level = 3;
                d[k].b_level = brackets;
            }
            if (d[k].op == '(' || d[k].op == ')'){
                d[k].level = -1;
                if (d[k].op == '('){
                    brackets++;
                }
                if (d[k].op == ')'){
                    brackets--;
                }
            }
            ++k;
        }
    }

    amount = k+1;
    for (int h=0;h<=amount;++h){
        if (d[h].op == '(' || d[h].op == ')'){
            for (i=h;i<amount;++i){
                d[i] = d[i+1];
            }
            amount --;
            h--;
        }
    }

    if (brackets != 0){
        check = false;
    }
	if (check)
		cout <<"ok" <<endl;
}

//count the num of chars
void counting(int k,int m)
{
    int i;

    for (i=0;i<amount;++i){
        if (d[i].b_level == k && d[i].level == m){
            op(i);
            --i;
            if (!check)
                break;
        }
    }
}

void go2()
{
    int i , j;

    for (i=15;i>=0;--i){
        for (j=3;j>0;--j){
            counting (i,j);
        }
    }
}

//identify op
void op(int k)
{
    int i;
    DATA tmp;

    void arrange();
    if (k == 0){
        if (d[0].op == '+')
            d[0].num = 0+d[1].num;
        if (d[0].op == '-')
            d[0].num = 0-d[1].num;
        if (d[0].op == '*')
            check = false;
        if (d[0].op == '/')
            check = false;
        d[k].level = 0;
        d[k].status = true;
        for (int l=1;l<=amount;++l){
            d[l] = d[l+1];
        }

    }
    else if (d[k].op == '+'){
        d[k-1].num += d[k+1].num;
        for (i=k;i<amount;++i){
            d[i] = d[i+2];
        }
    }

    else if (d[k].op == '-'){
        d[k-1].num -= d[k+1].num;
        for (i=k;i<amount;++i){
            d[i] = d[i+2];
        }
    }

    else if (d[k].op == '*'){
        if (!d[k+1].status || !d[k-1].status)
            check = false;
        d[k-1].num *= d[k+1].num;
        for (i=k;i<amount;++i){
            d[i] = d[i+2];
        }
    }

    else if (d[k].op == '/'){
        if (!d[k+1].status || !d[k-1].status)
            check = false;
        if (d[k+1].num == 0)
            check = false;
        else{
            d[k-1].num /= d[k+1].num;
            for (i=k;i<amount;++i){
                d[i] = d[i+2];
            }
        }
    }

    else if (d[k].op == '!'){
        int a = d[k-1].num;
        if (d[k-1].num < 0)
            check = false;
        if (a == d[k-1].num){
            for (int j = d[k-1].num - 1;j>0;--j){
                d[k-1].num *= j;
            }
        }
        else
            check = false;
        for (i=k;i<amount;++i){
            d[i] = d[i+1];
        }
    }

    else if (d[k].op == '%'){
        if (d[k+1].num == 0)
            check = false;
        else{
            int a = d[k-1].num;
            int b = d[k+1].num;
            if (a == d[k-1].num && b == d[k+1].num){
                a %= b;
                d[k-1].num = a;
                for (i=k;i<amount;++i){
                    d[i] = d[i+2];
                }
            }
            else
                check = false;
        }
    }
}

//arrange +-
void arrange()
{
    int i , j;

    for (i=0;i<amount;++i){
        if (d[i].op == '-'){
            if (d[i+1].status && i!=0){
                if (d[i-1].op == '+'){
                    d[i].op = '+';
                    d[i+1].num = -d[i+1].num;
                    for (int j=i;j<=amount;++j){
                        d[j] = d[j+1];
                    }
                    i--;
                }
                if (d[i-1].op == '*' || d[i-1].op == '/' || d[i-1].op == '%'){
                    d[i+1].num = -d[i+1].num;
                    for (int j=i;j<=amount;++j){
                        d[j] = d[j+1];
                    }
                }
            }
            else if (i==0 && d[1].status && d[2].op != '!'){
                d[1].num *= -1;
                for (int j=i;j<=amount;++j){
                    d[j] = d[j+1];
                }
            }
            else if (!d[i+1].status){
                if (d[i+1].op == '+'){
                    d[i+1].op = '-';
                    for (int j=i;j<amount;++j){
                        d[j] = d[j+1];
                    }
                }
                else if (d[i+1].op == '-'){
                    d[i+1].op = '+';
                    for (int j=i;j<amount;++j){
                        d[j] = d[j+1];
                    }
                }
            }
        }
    }

    for (i=0;i<amount;++i){
        if (d[i].op == '+'){
            bool flag = true;
            while (flag){
                if (d[i+1].op == '+'){
                    for (int j=i;j<amount;++j){
                        d[j] = d[j+1];
                    }
                }
                else
                    flag = false;
            }
        }
    }
}
