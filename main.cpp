/*
ID: 515051910048
PROG: LAB1
DATE: 3/25
*/
#include <iostream>
#include <cmath>

using namespace std;

struct DATA{
    double num = 0;
    char op = 0;
    bool status = 0;
    int level = 0;
    int b_level = 0;
};

int amount;
DATA d[100000] ;
bool check = true;
int brackets = 0;
int memory = 0;
bool cont = true;
bool see = true;

//functions
void trans (char str[]);
void num_of_char (char str[]);
void op(int k);
void test();
void arrange();
void go2();
void counting(int k,int m);

int main()
{
    char input[10000] = {0};

    cout << "input Q to quit." <<endl;
    cout << "input M+ or M- to save in memory." <<endl;
    cout << "input MC to clean memory." <<endl;
    cout << "input MR to see the number in the memory." <<endl;

    cout << "> ";
    cin >> input;

    num_of_char (input);
    trans (input);
    arrange();
    go2();

    if (input[0] == 'Q'){
        cont = false;
        see = false;
        return 0;
    }
    else if (input[0] == 'M' && input[1] == '+' && check){
        memory += d[0].num;
        see = false;
    }
    else if (input[0] == 'M' && input[1] == '-' && check){
        memory -= d[0].num;
        see = false;
    }
    else if (input[0] == 'M' && input[1] == 'C'){
        memory = 0;
        see = false;
    }
    else if (input[0] == 'M' && input[1] == 'R'){
        cout << memory << endl;
        see = false;
    }
    else
        see = true;

    if (check && see) cout << "= " << d[0].num <<endl;
    if (!check && see)
        cout << "error" <<endl;

    if (cont && see){
        for (int i=0;i<100000;++i){
            d[i].num = 0;
            d[i].op = 0;
            d[i].status = 0;
            d[i].level = 0;
            d[i].b_level = 0;
        }
        check = true;
    }

    main();

    return 0;
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

void test()
{
    for (int i = 0;i<amount;++i){
        if (d[i].status)
            cout <<d[i].num ;
        if (!d[i].status)
            cout <<d[i].op ;
    }
    cout <<endl;
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
