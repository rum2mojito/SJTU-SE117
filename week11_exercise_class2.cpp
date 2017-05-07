#include <iostream>

using namespace std;

class String
{
private:
    char *head;
    int SIZE;
public:
    String()
    {
        head = NULL;
        SIZE = 0;
    }

    String (int i)
    {
        SIZE = i;
        head = new char [SIZE];
        *head = '\0';
    }

    String operator+(const String &obj)const
    {
        String tmp;

        tmp.SIZE = SIZE+obj.SIZE;
        tmp.head = new char [SIZE+obj.SIZE];
        char *p1 , *p2 , *p3;
        p1 = head;
        p2 = obj.head;
        p3 = tmp.head;

        for (int i=0;i<SIZE;i++){
            *p3 = *p1;
            p1++;
            p3++;
        }
        for (int i=0;i<obj.SIZE;i++){
            *p3 = *p2;
            p3++;
            p2++;
        }

        return tmp;
    }

    String operator=(const String &obj)const
    {
        String tmp;

        tmp.head = obj.head;
        tmp.SIZE = obj.SIZE;

        return tmp;
    }

    friend bool operator<(const String &s1 , const String &s2)
    {
        return s1.SIZE<s2.SIZE;
    }

    friend bool operator>(const String &s1 , const String &s2)
    {
        return s1.SIZE>s2.SIZE;
    }

    friend bool operator==(const String &s1 , const String &s2)
    {
        return s1.SIZE==s2.SIZE;
    }

    friend bool operator>=(const String &s1 , const String &s2)
    {
        return s1.SIZE>=s2.SIZE;
    }

    friend bool operator<=(const String &s1 , const String &s2)
    {
        return s1.SIZE<=s2.SIZE;
    }

    friend bool operator!=(const String &s1 , const String &s2)
    {
        return s1.SIZE!=s2.SIZE;
    }

    friend ostream & operator<<(ostream &os , const String &obj)
    {
        char *p;
        p = obj.head;

        if (*p!='\0'){
            os << *p;
            p++;
        }
        return os;
    }

    friend istream & operator>>(istream &in , const String &obj)
    {
        char *p , *m;
        char str[1000];
        p = obj.head;

        in >> str;
        m = str;
        if (*m!='\0'){
            *p = *m;
            p++;
            m++;
        }
        *p = '\0';

        return in;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
