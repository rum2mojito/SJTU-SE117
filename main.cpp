#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct DATA
{
    double num = 0;
    char op;
    bool status;
};

DATA d[3];

void trans(char str[],int amount);
int num_of_char (char str[]);

int main()
{
    char str[10000] ;
    int i , time = 0;

    ifstream fin("C:\\Users\\YU-WEI\\Desktop\\task.txt",ios::in);
    ofstream fout("C:\\Users\\YU-WEI\\Desktop\\task2.txt",ios::out);

    for (i=0;i<8;++i){
        int check = 0;
        bool flag = true;
        bool check2 = false;
        double time = 0.000;
        string c;
        while (flag){
            fin >> str;
            trans(str,num_of_char (str));
            check++;
            if (d[1].op == 'h')
                time += d[0].num * 3600;
            else if (d[1].op == 's')
                time += d[0].num;
            else if (d[1].op == 'm' && d[2].op == 'i')
                time += d[0].num *60;
            else if (d[1].op == 'm' && d[2].op == 's'){
                cout << "ok" <<endl;
                time += d[0].num /1000;
            }
            else if (str[0] == '|' || str[1] == '|')
                flag = false;
            else
                check2 = true;

            if (check>20 || check == 0){
                flag = false;
                check2 = true;
            }
            for (int t=0;t<4;++t){
                d[t].num=0;
                d[t].op = 0;
            }
        }

        fin.get();

        if (!(getline(fin,c)) || check2)
            fout << "Invalid input!" <<endl;
        else{
            fout << c;
            fout << ": " << fixed <<setprecision(3) <<time << "s" << endl;
        }
    }

    return 0;
}

void trans(char str[],int amount)
{
    int i , j , order , k = 0;

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
            ++k;
        }
    }
}

int num_of_char (char str[])
{
    int i;

    for (i=0;;i++){
        if (str[i] == '\0'){
            break;
        }
    }

    return i;
}
