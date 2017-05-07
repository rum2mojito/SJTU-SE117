#include <iostream>

using namespace std;

class Vector
{
private:
    int SIZE;
    int *head , *p;
public:
    Vector()
    {
        SIZE = 0;
        head = p = NULL;
    }

    Vector(int i)
    {
        SIZE = i;
        head = new int [SIZE];
    }

    bool insert(int site , int num)
    {
        p = head;
        for (int i=1;i<site;++i){
            p++;
        }
        *p = num;
        return SIZE>=site;
    }

    friend ostream & operator<<(ostream &os , const Vector & obj)
    {
        int *k;
        k = obj.head;
        for (int i=0;i<obj.SIZE;++i){
            os << *k << '\t';
            k++;
        }

        return os;
    }

    friend istream & operator>>(istream &in , const Vector &obj)
    {
        int *k;
        int m;
        k = obj.head;
        for (int i=0;i<obj.SIZE;++i){
            in >> m;
            *k = m;
            ++k;
        }
        return in;
    }

    Vector operator+(const Vector &obj)const
    {
        Vector tmp;
        int *k , *m;

        tmp.head = new int [SIZE+obj.SIZE];
        tmp.SIZE = SIZE+obj.SIZE;
        k = tmp.head;
        m = head;
        for (int i=0;i<SIZE;++i){
            *k = *m;
            k++;
            m++;
        }
        k++;
        m = obj.head;
        for (int i=0;i<obj.SIZE;++i){
            *k = *m;
            k++;
            m++;
        }

        return tmp;
    }

    Vector operator-(const Vector &obj)const
    {
        Vector tmp;
        int *k , *u , *y;

        tmp.head = new int [SIZE];
        tmp.SIZE = SIZE;
        k = tmp.head;
        u = obj.head;
        y = head;
        for (int i=0;i<SIZE;++i){
            *k = *y-*u;
            k++;
            y++;
            u++;
        }

        return tmp;
    }

    Vector operator*(const Vector &obj)const
    {
        Vector tmp;
        int *x , *y , *z;

        tmp.SIZE = SIZE;
        tmp.head = new int [SIZE];
        x = head;
        y = obj.head;
        z = tmp.head;

        for (int i=0;i<SIZE;++i){
            *z = *x * *y;
            z++;
            x++;
            y++;
        }

        return tmp;
    }
};



int main()
{

    return 0;
}
