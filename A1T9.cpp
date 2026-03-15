#include <iostream>
using namespace std;

class Book{
public:
    int id;
    Book* next;

    // constructor
    Book(int id){
        this->id = id;
        next = NULL;
    }
};

class LibraryCatalog{
public:

    Book* head;

    // constructor
    LibraryCatalog(){
        head = NULL;
    }

    // add book to catalog
    void addBook(int id){

        Book* newBook = new Book(id);

        if(head == NULL){
            head = newBook;
        }
        else{
            Book* temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newBook;
        }
    }

    // delete all books with a specific identifier
    void deleteBookById(int targetId){

        // remove from beginning
        while(head != NULL && head->id == targetId){
            Book* temp = head;
            head = head->next;
            delete temp;
        }

        Book* current = head;

        // remove from middle or end
        while(current != NULL && current->next != NULL){

            if(current->next->id == targetId){

                Book* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else{
                current = current->next;
            }
        }
    }

    // display catalog
    void displayCatalog(){

        Book* temp = head;

        while(temp != NULL){
            cout << temp->id << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){

    LibraryCatalog library;

    library.addBook(101);
    library.addBook(205);
    library.addBook(101);
    library.addBook(340);
    library.addBook(101);
    library.addBook(450);

    cout << "Original Catalog:\n";
    library.displayCatalog();

    library.deleteBookById(101);

    cout << "\nAfter Removing Identifier 101:\n";
    library.displayCatalog();

}