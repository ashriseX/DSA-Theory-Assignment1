#include <iostream>
using namespace std;

class Node{
public:

    string name;
    Node* next;

    // constructor
    Node(string name){
        this->name = name;
        next = NULL;
    }
};

class FriendList{
public:

    Node* head;

    // constructor
    FriendList(){
        head = NULL;
    }

    // insert friend
    void insert(string name){

        Node* nn = new Node(name);

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

    // find middle friend (left middle if even)
    Node* findMiddle(){

        if(head == NULL)
            return NULL;

        Node* slow = head;
        Node* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    //display friendlist
    void display(){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
};

int main(){

    FriendList friends;

    friends.insert("Ali");
    friends.insert("Sara");
    friends.insert("Ahmed");
    friends.insert("Bilal");
    friends.insert("Ayesha");
    friends.insert("Hamza");


    Node* middle = friends.findMiddle();
    friends.display();

    if(middle != NULL)
        cout << "Middle friend: " << middle->name << endl;

}