#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

int josephus(int n, int m)
{
    Node* head = new Node(1);
    Node* prev = head;

    for(int i=2;i<=n;i++)
    {
        prev->next = new Node(i);
        prev = prev->next;
    }

    prev->next = head;

    Node* ptr = head;
    Node* temp;

    while(ptr->next != ptr)
    {
        for(int i=1;i<m-1;i++)
            ptr = ptr->next;

        temp = ptr->next;
        ptr->next = temp->next;
        delete temp;

        ptr = ptr->next;
    }

    return ptr->data;
}


    


#include <iostream>
using namespace std;

class Task
{
public:
    string name;
    int priority;
    string status;
    Task* next;

    Task(string n,int p,string s)
    {
        name = n;
        priority = p;
        status = s;
        next = NULL;
    }
};

class TaskScheduler
{
private:
    Task* head;

public:

    TaskScheduler()
    {
        head = NULL;
    }

    // Add Task
    void addTask(string name,int priority,string status)
    {
        Task* newTask = new Task(name,priority,status);

        if(head == NULL)
        {
            head = newTask;
            newTask->next = head;
            return;
        }

        Task* temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = newTask;
        newTask->next = head;
    }

    // Remove Task
    void removeTask(string name)
    {
        if(head == NULL)
            return;

        Task* curr = head;
        Task* prev = NULL;

        do
        {
            if(curr->name == name)
            {
                if(prev == NULL)
                {
                    Task* last = head;

                    while(last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                }
                else
                {
                    prev->next = curr->next;
                }

                delete curr;
                cout<<"Task Removed\n";
                return;
            }

            prev = curr;
            curr = curr->next;

        }while(curr != head);
    }

    // Get Next Task
    void getNextTask()
    {
        if(head == NULL)
            return;

        Task* temp = head;

        do
        {
            if(temp->status == "pending")
            {
                cout<<"Next Task: "<<temp->name<<endl;
                return;
            }

            temp = temp->next;

        }while(temp != head);

        cout<<"No pending tasks\n";
    }

    // Display Tasks
    void displayTasks()
    {
        if(head == NULL)
            return;

        Task* temp = head;

        cout<<"Task List\n";

        do
        {
            cout<<"Name: "<<temp->name
                <<" Priority: "<<temp->priority
                <<" Status: "<<temp->status<<endl;

            temp = temp->next;

        }while(temp != head);
    }

    // Update Task Status
    void updateStatus(string name,string newStatus)
    {
        Task* temp = head;

        if(head == NULL)
            return;

        do
        {
            if(temp->name == name)
            {
                temp->status = newStatus;

                cout<<"Updated "<<name<<" to "<<newStatus<<endl;
                return;
            }

            temp = temp->next;

        }while(temp != head);
    }
};

int main()
{
    //josephus problem
    cout << " Josephus Problem:" << endl;
    cout << " number of persons present: 7" << endl;
    cout << " number of persons skipped: 2" << endl;
    int n = 7;
    int m = 3;

    cout<<"Safe Position: "<<josephus(n,m);

    //rest of question
    TaskScheduler scheduler;

    scheduler.addTask("Design",1,"pending");
    scheduler.addTask("Coding",2,"pending");
    scheduler.addTask("Testing",3,"pending");

    scheduler.displayTasks();

    scheduler.getNextTask();

    scheduler.updateStatus("Design","completed");

    scheduler.getNextTask();

    scheduler.removeTask("Coding");

    scheduler.displayTasks();

    return 0;
}