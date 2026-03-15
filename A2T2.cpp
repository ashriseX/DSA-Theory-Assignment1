#include <iostream>
using namespace std;

// Song node
class Song
{
public:
    string title;
    Song* next;
    Song* prev;

    Song(string t)
    {
        title = t;
        next = NULL;
        prev = NULL;
    }
};

// Playlist class
class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:

    Playlist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    // Add song to playlist
    void addSong(string title)
    {
        Song* newSong = new Song(title);

        if(head == NULL)
        {
            head = tail = newSong;
            current = head;
            return;
        }

        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }

    // Display playlist
    void display()
    {
        Song* temp = head;

        while(temp != NULL)
        {
            cout << temp->title;

            if(temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }

    // Play current song
    void playCurrent()
    {
        if(current != NULL)
            cout << "Now playing: " << current->title << endl;
    }

    // Next song
    void nextSong()
    {
        if(current != NULL && current->next != NULL)
        {
            current = current->next;
            playCurrent();
        }
        else
        {
            cout << "End of playlist\n";
        }
    }

    // Previous song
    void prevSong()
    {
        if(current != NULL && current->prev != NULL)
        {
            current = current->prev;
            playCurrent();
        }
        else
        {
            cout << "Start of playlist\n";
        }
    }
};


// Main method
int main()
{
    Playlist player;

    player.addSong("Shape of You");
    player.addSong("Blinding Lights");
    player.addSong("Perfect");
    player.addSong("Levitating");

    cout << "Playlist:\n";
    player.display();

    cout << endl;

    player.playCurrent();
    player.nextSong();
    player.nextSong();
    player.prevSong();

    return 0;
}