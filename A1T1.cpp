#include <iostream>
using namespace std;

// Logs class
class Log{
public:
    static int logNum;
    int id;
    string logTime;
    Log* next;

    // constructor
    Log(string logTime){
        logNum++;
        id = logNum;
        this->logTime = logTime;
        next = NULL;
    }
};

int Log::logNum = 0;


// singly linked list class
class SinglyList{
public:

    Log* head;

    // constructor
    SinglyList(){
        head = NULL;
    }

    // Insert log at end
    void insertAtEnd(string logTime){

        Log* nn = new Log(logTime);

        if(head == NULL){
            head = nn;
        }
        else{
            Log* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    // delete first log
    void deleteAtStart(){

        if(head == NULL){
            cout << "Logs are empty" << endl;
            return;
        }

        Log* temp = head;
        head = head->next;

        delete temp;
    }

    // display logs recursively
    void display(Log* temp){

        if(temp == NULL)
            return;

        cout << temp->id << "\t" << temp->logTime << endl;

        display(temp->next);
    }
};


int main(){

    SinglyList logs;

    logs.insertAtEnd("10:00 AM");
    logs.insertAtEnd("10:05 AM");
    logs.insertAtEnd("10:10 AM");

    logs.display(logs.head);

}