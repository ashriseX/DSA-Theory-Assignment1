#include <iostream>
using namespace std;

// Item Node
class Item
{
public:
    string name;
    Item* next;

    Item(string n)
    {
        name = n;
        next = NULL;
    }
};

// Section Node
class Section
{
public:
    string name;
    Item* itemHead;
    Section* next;

    Section(string n)
    {
        name = n;
        itemHead = NULL;
        next = NULL;
    }
};

// Store Node
class Store
{
public:
    string name;
    Section* sectionHead;
    Store* next;

    Store(string n)
    {
        name = n;
        sectionHead = NULL;
        next = NULL;
    }
};

class Inventory
{
private:
    Store* storeHead;

public:

    Inventory()
    {
        storeHead = NULL;
    }

    // Add Store
    void addStore(string name)
    {
        Store* newStore = new Store(name);
        newStore->next = storeHead;
        storeHead = newStore;
    }

    // Find Store
    Store* findStore(string name)
    {
        Store* temp = storeHead;

        while(temp != NULL)
        {
            if(temp->name == name)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    // Add Section
    void addSection(string storeName, string sectionName)
    {
        Store* store = findStore(storeName);

        if(store == NULL)
        {
            cout<<"Store not found\n";
            return;
        }

        Section* newSection = new Section(sectionName);
        newSection->next = store->sectionHead;
        store->sectionHead = newSection;
    }

    // Find Section
    Section* findSection(Store* store, string sectionName)
    {
        Section* temp = store->sectionHead;

        while(temp != NULL)
        {
            if(temp->name == sectionName)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    // Add Item
    void addItem(string storeName, string sectionName, string itemName)
    {
        Store* store = findStore(storeName);
        if(store == NULL) return;

        Section* section = findSection(store, sectionName);
        if(section == NULL) return;

        Item* newItem = new Item(itemName);
        newItem->next = section->itemHead;
        section->itemHead = newItem;
    }

    // Remove Item
    void removeItem(string storeName, string sectionName, string itemName)
    {
        Store* store = findStore(storeName);
        if(store == NULL) return;

        Section* section = findSection(store, sectionName);
        if(section == NULL) return;

        Item* temp = section->itemHead;
        Item* prev = NULL;

        while(temp != NULL)
        {
            if(temp->name == itemName)
            {
                if(prev == NULL)
                    section->itemHead = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    // Display Items of a Section
    void displaySectionItems(string storeName, string sectionName)
    {
        Store* store = findStore(storeName);
        if(store == NULL) return;

        Section* section = findSection(store, sectionName);
        if(section == NULL) return;

        Item* temp = section->itemHead;

        cout<<"Items in "<<sectionName<<" section:\n";

        while(temp != NULL)
        {
            cout<<temp->name<<endl;
            temp = temp->next;
        }
    }

    // Display Items of a Store
    void displayStoreItems(string storeName)
    {
        Store* store = findStore(storeName);
        if(store == NULL) return;

        Section* sec = store->sectionHead;

        while(sec != NULL)
        {
            cout<<"Section: "<<sec->name<<endl;

            Item* item = sec->itemHead;

            while(item != NULL)
            {
                cout<<"  "<<item->name<<endl;
                item = item->next;
            }

            sec = sec->next;
        }
    }
};

int main()
{
    Inventory inv;

    inv.addStore("Karachi");
    inv.addSection("Karachi","Grocery");
    inv.addSection("Karachi","Fruits");

    inv.addItem("Karachi","Grocery","Rice");
    inv.addItem("Karachi","Grocery","Oil");
    inv.addItem("Karachi","Fruits","Apple");

    cout<<"Items in Grocery Section\n";
    inv.displaySectionItems("Karachi","Grocery");

    cout<<"\nAll Items in Karachi Store\n";
    inv.displayStoreItems("Karachi");

    return 0;
}