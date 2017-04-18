#ifndef WEEK8_515051910048_H_INCLUDED
#define WEEK8_515051910048_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Node{
    public:
        int value;
        Node *next;
    };

    class List:public Node
    {
    private:
        Node *head , *p , *rear;
    public:
        List (int arr[] , int arr_size)
        {
            int i;
            head = rear = new Node;

            for (i=0;i<arr_size;++i){
                p = new Node;
                p->value = arr[i];
                rear->next = p;
                rear = p;
            }
            rear->next = NULL;
        }

        int length()
        {
            int i = 0;

            p = head;
            p = p->next;
            while (p != NULL){
                p = p->next;
                i++;
            }

            return i;
        }

        bool insert(int pos , int value)
        {
            int i;
            Node *pp;
            p = head;

            for (i=0;i<3;++i){
                p = p->next;
                if (p == NULL){
                    return false;
                    break;
                }
            }

            pp = new Node;
            pp->value = value;
            pp->next = p->next;
            p->next = pp;

            return true;
        }

        int find(int value)
        {
            int i = 0;
            p = head;
            while(! (p->value == value)){
                if (p->next == NULL){
                    return -1;
                    break;
                }
                p = p->next;
                i++;
            }
            return i;
        }

        int remove(int value)
        {
            int i = 0;
            Node *p2;
            p = head;
            while(p!=NULL){
                if (p->value == value){
                    p2 = p->next;
                    p->value = p2->value;
                    p->next = p2->next;
                    i++;
                }
                else{
                    p = p->next;
                }
            }
            return i;
        }

        bool split(int pos , List *new_list)
        {
            int i;
            Node *p2;
            p = head;
            for (i=0;i<pos;++i){
                p = p->next;
                if (p == NULL)
                    return false;
            }
            p2 = new_list->head;
            p2->next = p;
            p = NULL;
            return true;
        }

        void combine(List *append_list)
        {
            Node *p2;
            p2 = append_list->head;
            p = head;
            while (p!=NULL){
                p = p->next;
            }
            p = p2->next;
        }

        void printAll()
        {
            p = head;
            p = p->next;
            while(p!=NULL){
                cout << p->value << " ";
                p = p->next;
            }
            cout << endl;
        }

    };




#endif // WEEK8_515051910048_H_INCLUDED
