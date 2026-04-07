#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class List{
public:

    Node* head;

    List(){
        head = NULL;
    }

    void insert(int data){

        Node* nn = new Node(data);

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

    Node* reverse(Node* start){

        Node* prev = NULL;
        Node* curr = start;
        Node* nextNode = NULL;

        while(curr != NULL){

            nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    void reverseHalves(){

        Node* slow = head;
        Node* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = slow->next;
        slow->next = NULL;

        Node* firstHalf = head;

        firstHalf = reverse(firstHalf);
        secondHalf = reverse(secondHalf);

        head = firstHalf;

        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = secondHalf;
    }

    void display(){

        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " --> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main(){

    List l;

    for(int i=1;i<=8;i++){
        l.insert(i);
    }

    cout << "Original List:\n";
    l.display();

    l.reverseHalves();

    cout << "\nAfter Reversing Halves:\n";
    l.display();
}