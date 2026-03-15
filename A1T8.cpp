#include <iostream>
using namespace std;

class Stamp {
public:
    string design;
    Stamp* next;

    // constructor
    Stamp(string design){
        this->design = design;
        next = NULL;
    }
};

class StampCollection {
public:
    Stamp* head;

    // constructor
    StampCollection(){
        head = NULL;
    }

    // insert stamp at end
    void addStamp(string design){

        Stamp* newStamp = new Stamp(design);

        if(head == NULL){
            head = newStamp;
        }
        else{
            Stamp* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newStamp;
        }
    }

    // remove duplicate designs
    void removeDuplicateDesigns(){

        Stamp* current = head;

        while(current != NULL){

            Stamp* runner = current;

            while(runner->next != NULL){

                if(runner->next->design == current->design){

                    Stamp* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                }
                else{
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    // display collection
    void displayCollection(){

        Stamp* temp = head;

        while(temp != NULL){
            cout << temp->design << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){

    StampCollection album;

    album.addStamp("Eagle");
    album.addStamp("Lotus");
    album.addStamp("Tiger");
    album.addStamp("Eagle");
    album.addStamp("Rose");
    album.addStamp("Lotus");

    cout << "Original Stamp Collection:\n";
    album.displayCollection();

    album.removeDuplicateDesigns();

    cout << "\nAfter Removing Duplicate Designs:\n";
    album.displayCollection();

    return 0;
}