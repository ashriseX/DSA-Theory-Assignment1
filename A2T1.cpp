#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n)
    {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList
{
private:
    Node* head;
    Node* tail;

public:

    DoublyList()
    {
        head = NULL;
        tail = NULL;
    }

    // Insert desk
    void insert(string name)
    {
        Node* newNode = new Node(name);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Display desks
    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->name;

            if(temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }

    // Swap first with last, second with second-last etc
    void swapEnds()
{
    Node* left = head;
    Node* right = tail;

    while(left != right && left->next != right)
    {
        // swap names
        string temp = left->name;
        left->name = right->name;
        right->name = temp;

        left = left->next;
        right = right->prev;
    }

    // For even number of nodes, swap the final pair
    if(left->next == right)
    {
        string temp = left->name;
        left->name = right->name;
        right->name = temp;
    }
}
};

int main()
{
    DoublyList desks;

    desks.insert("Alice");
    desks.insert("Bob");
    desks.insert("Charlie");
    desks.insert("Dana");
    desks.insert("Eva");
    desks.insert("Frank");

    cout << "Original arrangement:\n";
    desks.display();

    desks.swapEnds();

    cout << "\nAfter swapping pattern:\n";
    desks.display();

    return 0;
}