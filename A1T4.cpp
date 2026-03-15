#include <iostream>
using namespace std;

class Node{
public:

    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class SensorBuffer{
public:

    Node* head;

    // constructor
    SensorBuffer(){
        head = NULL;
    }

    // Insert reading
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

    // Detect loop
    bool detectLoop(){

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true; // loop found
            }
        }

        return false; // no loop
    }
};

int main(){

    SensorBuffer buffer;

    buffer.insert(10);
    buffer.insert(20);
    buffer.insert(30);
    buffer.insert(40);

    // creating a loop for testing
    buffer.head->next->next->next->next = buffer.head->next;

    if(buffer.detectLoop()){
        cout << "Loop detected in sensor buffer" << endl;
    }
    else{
        cout << "No loop detected" << endl;
    }

}