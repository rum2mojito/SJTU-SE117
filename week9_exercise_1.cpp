#include <iostream>

using namespace std;

char* add_two_string(char *p, char *q);
char strf[600];

int main()
{
    int a , b;
    char *str;

    cin >> a >> b;

    char str1[a] , str2[b];

    cin >> str1 >> str2;

    str = add_two_string(str1,str2);

    cout << strf;

    return 0;
}

char* add_two_string(char *p, char *q)
{
    int a , b , c , d;
    char *p_str = strf;
    bool flag = false , flag2 = false;

    while(!(*p=='\0' && *q=='\0') || flag2){
        if (!flag && (*p!='\0' && *q!='\0')){
            a = *p-'0';
            b = *q-'0';
            c = a+b+'0';
        }
        else if ((*p!='\0' && *q!='\0') && flag){
            a = *p-'0';
            a += d;
            b = *q-'0';
            c = a+b+'0';
        }
        else if ((*p=='\0' && *q=='\0') && flag){
            c = d+'0';
            flag = false;
        }
        else if (!flag){
            if (*p=='\0'){
                c = *q;
            }
            else{
                c = *p;
            }
        }
        else if (flag) {
            if (*p=='\0'){
                c = *q-'0';
            }
            else{
                c = *p-'0';
            }
            c += d;
            c += '0';
        }
        if (c>'9'){
            d = 1;
            int k = c-'0';
            k -= 10;
            c = k+'0';
            flag = true;
        }
        else{
            flag = false;
        }
        *p_str = c;
        char m = c;
        ++p_str;
        if (*p != '\0'){
            ++p;
        }
        if (*q != '\0'){
            ++q;
        }
        if (*p=='\0' && *q=='\0'){
            if (flag){
                flag2 = true;
            }
            else{
                flag2 = false;
            }
        }
    }
    *p_str = '\0';

    return p_str;
}
