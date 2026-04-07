#include <iostream>
using namespace std;

class Contact{
public:

    string name;
    Contact* next;

    // constructor
    Contact(string name){
        this->name = name;
        next = NULL;
    }
};

class ContactList{
public:

    Contact* head;

    // constructor
    ContactList(){
        head = NULL;
    }

    // Insert contact
    void insert(string name){

        Contact* nn = new Contact(name);

        if(head == NULL){
            head = nn;
        }
        else{

            Contact* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    // Remove duplicate contacts
    void removeDuplicates(){

        Contact* current = head;

        while(current != NULL){

            Contact* runner = current;

            while(runner->next != NULL){

                if(runner->next->name == current->name){

                    Contact* dup = runner->next;
                    runner->next = runner->next->next;
                    delete dup;
                }
                else{
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    // Display contacts
    void display(){

        Contact* temp = head;

        while(temp != NULL){
            cout << temp->name << " --> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){

    ContactList cl;

    cl.insert("Ali");
    cl.insert("Sara");
    cl.insert("Ahmed");
    cl.insert("Ali");
    cl.insert("Bilal");
    cl.insert("Sara");

    cout << "Original Contact List:\n";
    cl.display();

    cl.removeDuplicates();

    cout << "\nAfter Removing Duplicates:\n";
    cl.display();

}