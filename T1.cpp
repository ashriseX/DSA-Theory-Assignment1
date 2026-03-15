//SP25-BCT-001
//ABDUL SABOOR HASAN
//DSA assignment task 1 singly linked list

/* You are designing a logging system where recent log entries are 
stored in a singly linked list, with the oldest log at the head and the newest
log at the end. For troubleshooting, your manager wants to view the logs in reverse
order (latest first, oldest last) without actually modifying the structure of the 
linked list. Write a function to display the elements of the linked list in reverse 
order*/


#include <iostream>
#include <ctime>
using namespace std;

//logs class
class Logs{
    public:
        time_t logTime;

        Logs(){
            logTime = ctime(); 
        }
        
};





int main(){

    return 0;
}