#include <iostream>

using namespace std;

int main()
{
    int i , j , m=0;

    cin >>i;

    int money[i];

    for (j=0;j<i;++j){
        cin >> money[j];
    }


    int num;
    for (j=0;j<i;++j){
        num = money[j];
        int k = 0;
        while(num!=0){

            if (k == 0){
                int d = num/100;
                num %= 100;
                m += d;
            }
            else if (k == 1){
                int d = num/50;
                num %= 50;
                m += d;
            }
            else if (k == 2){
                int d = num/10;
                num %= 10;
                m += d;
            }
            else if (k == 3){
                int d = num/5;
                num %= 5;
                m += d;
            }
            else if (k == 4){
                int d = num/2;
                num %= 2;
                m += d;
            }
            else{
                m += num;
                num %= 1;
            }
            k++;
        }
    }

        cout << m << endl;

        int u = 0;
        for (j=0;j<i;++j){
            u += money[j];
        }
        for (j=2;j<u;++j){
            if (u%j == 0){
                cout << u << " " << "is not a prime number" <<endl;
                break;
            }
        }
        if (j == u)
            cout << u << " " << "is a prime number" <<endl;


    return 0;
}
