#include <iostream>
using namespace std;

class Node{
public:

    int price;
    Node* next;

    // constructor
    Node(int price){
        this->price = price;
        next = NULL;
    }
};

class Cart{
public:

    Node* head;

    // constructor
    Cart(){
        head = NULL;
    }

    // insert fruit price
    void insert(int price){

        Node* nn = new Node(price);

        if(head == NULL){
            head = nn;
        }
        else{

            Node* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    // divide carts into even and odd price lists
    void divideEvenOdd(){

        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* temp = head;

        while(temp != NULL){

            if(temp->price % 2 == 0){

                if(evenHead == NULL){
                    evenHead = evenTail = temp;
                }
                else{
                    evenTail->next = temp;
                    evenTail = temp;
                }
            }
            else{

                if(oddHead == NULL){
                    oddHead = oddTail = temp;
                }
                else{
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }

            temp = temp->next;
        }

        if(evenTail != NULL)
            evenTail->next = NULL;

        if(oddTail != NULL)
            oddTail->next = NULL;

        cout << "Even price line:\n";
        display(evenHead);

        cout << "Odd price line:\n";
        display(oddHead);
    }

    // display list
    void display(Node* node){

        while(node != NULL){
            cout << node->price << " -> ";
            node = node->next;
        }

        cout << "NULL\n";
    }
};

int main(){

    Cart c;

    c.insert(12);
    c.insert(7);
    c.insert(4);
    c.insert(9);
    c.insert(6);
    c.insert(3);

    c.divideEvenOdd();

}