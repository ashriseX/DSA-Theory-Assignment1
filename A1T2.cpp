#include <iostream>
using namespace std;

class Song{
public:

    string title;
    Song* next;

    // constructor
    Song(string title){
        this->title = title;
        next = NULL;
    }
};

class Playlist{
public:

    Song* head;

    // constructor
    Playlist(){
        head = NULL;
    }

    // Insert song at end
    void addSong(string title){

        Song* nn = new Song(title);

        if(head == NULL){
            head = nn;
        }
        else{
            Song* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    // Reverse playlist
    void reversePlaylist(){

        Song* prev = NULL;
        Song* curr = head;
        Song* nextNode = NULL;

        while(curr != NULL){

            nextNode = curr->next; // save next node
            curr->next = prev;     // reverse link

            prev = curr;           // move prev forward
            curr = nextNode;       // move curr forward
        }

        head = prev;
    }

    // Display playlist
    void display(){

        Song* temp = head;

        while(temp != NULL){
            cout << temp->title << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){

    Playlist p;

    p.addSong("Song A");
    p.addSong("Song B");
    p.addSong("Song C");
    p.addSong("Song D");

    cout << "Original Playlist:\n";
    p.display();

    p.reversePlaylist();

    cout << "\nReversed Playlist:\n";
    p.display();

    return 0;
}