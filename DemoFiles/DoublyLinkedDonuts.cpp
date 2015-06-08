//
//  main.cpp
//  LinkedDonuts2
//
//  Created by Jose Annunziato on 6/3/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Donut
{
    string name;
    float price;
    Donut * next = NULL;
    Donut * prev = NULL;
    
    // overriding default constructor
    Donut() // default constructor, aka the no argument constructor
    {
        cout << "Hello from Donut" << endl;
    }
    // overloading contructors
    Donut(string name, float price)
    {
        cout << "Constructor for " << name << endl;
        setName(name);
        setPrice(price);
    }
    ~Donut()
    {
        cout << "Good Bye from: " << name << endl;
    }
    void display()
    {
        cout << name << "\t$" << price << endl;
    }
    // API - Application Programming Interface
    // setters and getters
    // mutators
    void setName(string name)
    {
        this->name = name;
    }
    // accessors
    string getName()
    {
        return name;
    }
    void setPrice(float price)
    {
        if(price > 0)
        {
            this->price = price;
        }
    }
    // accessors
    float getPrice()
    {
        return price;
    }
};

struct DonutTray
{
    Donut* head = NULL;
    Donut* tail = NULL;
    int count = 0; // how many donuts in the tray
    void display()
    {
        Donut* current = head;
        while(current != NULL)
        {
            current->display();
            current = current->next;
        }
    }
    void appendDonut(Donut* newDonut)
    {
        count++;
        if(head == NULL && tail == NULL)
        {
            head = newDonut;
            tail = newDonut;
            return;
        }
        
        newDonut->prev = tail;
        tail->next = newDonut;
        tail = newDonut;
    }
    void prependDonut(Donut* newDonut)
    {
        count++;
        if(head == NULL && tail == NULL)
        {
            head = newDonut;
            tail = newDonut;
            return;
        }
        
        newDonut->next = head;
        head->prev = newDonut;
        head = newDonut;
    }
    Donut* findDonutByFlavor(string flavor)
    {
        if(count==0) return NULL;
        
        Donut* current = head;
        while(current != NULL && current->name != flavor)
        {
            current = current->next;
        }
        
        return current;
    }
    Donut* findDonutByPrice(float price)
    {
        
        return NULL;
    }
    Donut* get(int index)
    {
        if(count == 0)
            return NULL;
        if(index >= count)
            return NULL;
        Donut* current = head;
        for(int i=0; i<index; i++)
        {
            current = current->next;
        }
        return current;
    }
    
    
    void insertAt(Donut* newDonut, int index)
    {
        if(count == 0 && index == 0)
        {
            head = newDonut;
            tail = newDonut;
            return;
        }
        if(index == 0)
        {
            prependDonut(newDonut);
            return;
        }
        if(index == count)
        {
            appendDonut(newDonut);
            return;
        }
        
        Donut* current = get(index);
        
        newDonut->next = current;
        newDonut->prev = current->prev;
        
        current->prev->next = newDonut;
        current->prev = newDonut;
    }
    
    void removeAt(int index)
    {
        // deal with all the edge conditions !!!
        
        Donut* current = get(index);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    
    DonutTray(){}
    DonutTray(const DonutTray* other)
    {
        cout << "Hello" << endl;
        
        Donut* current = other->head;
        while(current != NULL)
        {
            Donut* copy = new Donut();
            copy->name = current->name;
            copy->price = current->price;
            
            this->appendDonut(copy);
            
            current = current->next;
        }
    }
};

int main(int argc, const char * argv[])
{
    Donut * d1 = new Donut("d1", 1.23);
    Donut * d2 = new Donut("d2", 1.33);
    Donut * d3 = new Donut("d3", 1.43);
    Donut * d4 = new Donut("d4", 1.53);
    
    DonutTray* tray1 = new DonutTray();
    tray1->appendDonut(d1);
    tray1->appendDonut(d2);
    tray1->appendDonut(d3);
    tray1->appendDonut(d4);
    
    tray1->display();
    
    Donut * d0 = new Donut("d0", 1.23);
    Donut * d_1 = new Donut("d-1", 1.33);
    Donut * d_2 = new Donut("d-2", 1.43);
    Donut * d_3 = new Donut("d-3", 1.53);
    
    tray1->prependDonut(d0);
    tray1->prependDonut(d_1);
    tray1->prependDonut(d_2);
    tray1->prependDonut(d_3);
    
    tray1->display();
    
    cout<<"--- testing get(int index)"<<endl;
    Donut* d = tray1->get(2);
    if(d != NULL)
    {
        d->display();
    }
    else
    {
        cout << "not found" << endl;
    }
    
    cout<<"--- testing findDonutByFlavor()"<<endl;
    d = tray1->findDonutByFlavor("d23454");
    if(d != NULL)
    {
        d->display();
    }
    else
    {
        cout << "not found" << endl;
    }

    cout<<"--- testing insertAt()"<<endl;
    d = new Donut("dA", 2.33);
    tray1->insertAt(d, 3);
    tray1->display();
    
    cout<<"--- testing insertAt()"<<endl;
    tray1->removeAt(3);
    tray1->display();
    
    DonutTray* t2 = new DonutTray(tray1);

    cout<<"--- testing t2->display()"<<endl;
    t2->display();
    
    
    cout<<"--- testing insert into t2"<<endl;
    d = new Donut("dB", 2.33);
    t2->insertAt(d, 3);
    t2->display();
    tray1->display();

//    d1->display();
//    d2->display();
//    d3->display();
//    d4->display();
//    
//    d1->next = d2;
//    d2->next = d3;
//    d3->next = d4;
//    d4->next = NULL;
//    
//    cout << "====" << endl;
//    Donut * head = d1;
//
//    Donut * current = head;
//    current->display();
//    current = current->next;
//    current->display();
//    current = current->next;
//    current->display();
//    current = current->next;
//    current->display();
//    
//    cout << "====" << endl;
//    current = head;
//    while(current != NULL)
//    {
//        current->display();
//        current = current->next;
//    }
}
