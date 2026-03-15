#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Linked List class
class List
{
private:
    Node* head;

public:

    List()
    {
        head = NULL;
    }

    // Insert node at end
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display list
    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Swap nodes in pairs
    void swapPairs()
    {
        Node dummy(0);
        dummy.next = head;

        Node* prev = &dummy;

        while(prev->next != NULL && prev->next->next != NULL)
        {
            Node* first = prev->next;
            Node* second = first->next;

            // Swapping links
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move pointer to next pair
            prev = first;
        }

        head = dummy.next;
    }
};


// Main method to test program
int main()
{
    List tasks;

    tasks.insert(1);
    tasks.insert(2);
    tasks.insert(3);
    tasks.insert(4);
    tasks.insert(5);
    tasks.insert(6);

    cout << "Original Task List:" << endl;
    tasks.display();

    tasks.swapPairs();

    cout << "After Swapping Pairs:" << endl;
    tasks.display();

    return 0;
}