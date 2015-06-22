//
//  main.cpp
//  Q2Review
//
//  Created by Jose Annunziato on 6/22/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
using namespace std;

struct Coefficient {
    float value = 0;
	Coefficient* next = NULL;
};

struct Polynomial {
    Coefficient* coefficients = NULL;
    void display();
    void append() {
        ///
    }
};

void append()
{
///
}

Polynomial* addPolynomials(Polynomial* p1, Polynomial* p2)
{
    if(p1 == NULL && p2 == NULL)
        return NULL;
    
    Polynomial* p3 = new Polynomial();
    Coefficient* t = NULL;
    Coefficient* c3 = NULL;
    Coefficient* c1 = p1->coefficients;
    Coefficient* c2 = p2->coefficients;
    
    while(c1 != NULL && c2 != NULL)
    {
        // create new coefficient
        c3 = new Coefficient();
        c3->value = c1->value + c2->value;

        // handle first coefficient
        if(t == NULL)
        {
            // this is the first coefficient
            p3->coefficients = c3;
            
            // this is also the last coefficient for now
            t = c3;
        }
        else
        {
            // steady state
            t->next = c3;
            t = c3;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    
    while(c1 != NULL)
    {
        c3 = new Coefficient();
        c3->value = c1->value;
        t->next = c3;
        t = c3;
        c1 = c1->next;
    }
    
    while(c2 != NULL)
    {
        c3 = new Coefficient();
        c3->value = c2->value;
        t->next = c3;
        t = c3;
        c2 = c2->next;
    }

    return p3;
}

void Polynomial::display()
{
    Coefficient* c = this->coefficients;
    int i = 0;
    while(c != NULL)
    {
        cout << c->value << " * X ^ " << i << " + ";
        c = c->next;
        i++;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Polynomial* p1 = new Polynomial();
    Polynomial* p2 = new Polynomial();
    Coefficient* t = NULL;
    
    Coefficient* c2 = new Coefficient();
    c2->value = 1;
    t = c2;
    p2->coefficients = c2;
    
    c2 = new Coefficient();
    c2->value = 3;
    t->next = c2;
    t = c2;
    
    c2 = new Coefficient();
    c2->value = 5;
    t->next = c2;
    t = c2;
    
    p2->display();
    
    
    Coefficient* c1 = new Coefficient();
    c1->value = 2;
    t = c1;
    p1->coefficients = c1;
    
    c1 = new Coefficient();
    c1->value = 4;
    t->next = c1;
    t = c1;
    
    c1 =  new Coefficient();
    c1->value = 6;
    t->next = c1;
    t = c1;
    
    c1 =  new Coefficient();
    c1->value = 8;
    t->next = c1;
    t = c1;
    
    c1 =  new Coefficient();
    c1->value = 10;
    t->next = c1;
    t = c1;
    
    p1->display();
    
    Polynomial* p3 = addPolynomials(p1, p2);
    p3->display();
}
