#include <iostream>

using namespace std;

class solution
{
private:
    int n;
    int ammount;
public:
    solution(int k)
    {
        n = k;
        ammount = 0;
        ammount = boom();
        cout << ammount << endl;
    }

    int boom()
    {
        int ans = 0 , step , a ;

        step = a = n;

        while (a > 0){
            ans += combination(step,a);
            step--;
            a -= 2;
        }
        if (a == 0)
            ans++;

        return ans;
    }

    int combination(int a , int b) //C a b
    {
        int num1 = 1 , num2 = 1 , ans;

        for (int i = 0;i<b;++i){
            num1 *= (a-i);
        }

        for (int i = 1;i<=b;++i){
            num2 *= i;
        }

        ans = num1/num2;

        return ans;
    }
};

int main()
{
    int m;

    cin >> m;
    solution mom(m);

    return 0;
}
