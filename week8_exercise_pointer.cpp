#include <iostream>

using namespace std;

struct node
{
    string nation;
    int population;
    node *next ;
};

int main()
{
    string x;
    int y ;
    node *head , *p , *rear , *p2 ;
    node tmp;
    head = rear = new node;

    while(true){
        cout << "enter the country: ";
        cin >> x;
        if (x == "@"){
            break;
        }
        cout << "enter the country's population: ";
        cin >> y;
        p = new node;
        p->nation = x;
        p->population = y;
        rear->next = p;
        rear = p;
    }

    rear->next = NULL;

    p = head->next;
    for (int i=0;p!=NULL;++i){
        p2 = head->next;
        for (int k=0;p2!=NULL;++k){
            if (p2->population < p->population){
                x = p2->nation;
                y = p2->population;
                p2->nation = p->nation;
                p2->population = p->population;
                p->nation = x;
                p->population = y;
            }
            p2 = p2->next;
        }
        p = p->next;
    }
    p = head->next;
    while (p != NULL){
        if (p->next == NULL){
            break;
        }
        cout << p->nation ;
        cout << " ";
        p = p->next;
    }

    return 0;
}
