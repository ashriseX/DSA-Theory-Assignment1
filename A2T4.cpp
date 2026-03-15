#include <iostream>
using namespace std;

class Node
{
public:
    int seat;
    Node* next;
    Node* prev;

    Node(int s)
    {
        seat = s;
        next = NULL;
        prev = NULL;
    }
};

class SeatList
{
private:
    Node* head;
    Node* tail;

public:

    SeatList()
    {
        head = tail = NULL;
    }

    void insert(int seat)
    {
        Node* newNode = new Node(seat);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->seat;

            if(temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    // Special alternating swap
    void specialSwap()
    {
        if(head == NULL || head->next == NULL)
            return;

        Node* left = head->next;
        Node* right = tail->prev;

        bool swapFlag = true;

        while(left != right && left->prev != right)
        {
            if(swapFlag)
            {
                int temp = left->seat;
                left->seat = right->seat;
                right->seat = temp;
            }

            left = left->next;
            right = right->prev;
            swapFlag = !swapFlag;
        }
    }
};

int main()
{
    SeatList seats;

    for(int i=1;i<=9;i++)
        seats.insert(i);

    cout<<"Original Seats:\n";
    seats.display();

    seats.specialSwap();

    cout<<"\nAfter Special Pattern Swap:\n";
    seats.display();

    return 0;
}