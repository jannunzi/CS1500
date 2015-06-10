//
//  main.cpp
//  Quiz2Review
//
//  Created by Jose Annunziato on 6/10/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct IntegerNode
{
    int value = 0;
    IntegerNode* next = NULL;
    IntegerNode(int value)
    {
        this->value = value;
    }
    IntegerNode(){}
};

IntegerNode* findLast(IntegerNode* haystack, int needle)
{
    IntegerNode* last = NULL;
    IntegerNode* current = haystack;

    while(current != NULL)
    {
        if(current->value == needle)
            last = current;
        current = current->next;
    }
    
    return last;
}

IntegerNode* findMax(IntegerNode* values)
{
    IntegerNode* max = NULL;
    IntegerNode* current = values;
    int maxValue = 0;
    
    while(current != NULL)
    {
        if(current->value > maxValue)
        {
            max = current;
            maxValue = current->value;
        }
        current = current->next;
    }
    
    return max;
}
IntegerNode* findMin(IntegerNode* values)
{
    IntegerNode* min = NULL;
    return min;
}

IntegerNode* findAllValues(IntegerNode* values, int value)
{
    IntegerNode* result = NULL;
    IntegerNode* current = values;
    
    while(current != NULL)
    {
        if(current->value == value)
        {
            IntegerNode* d = new IntegerNode(current->value);
            d->next = result;
            result = d;
        }
        current = current->next;
    }
    
    
    return result;
}

IntegerNode* mergeIntegerLists(IntegerNode* l1, IntegerNode* l2)
{
    IntegerNode* l3 = NULL;
    IntegerNode* t3 = NULL;
    
    IntegerNode* c1 = l1;
    IntegerNode* c2 = l2;
    IntegerNode* nd;
    
    while(c1 != NULL && c2 != NULL)
    {
        if(c1->value < c2->value)
        {
            // copy from l1
            nd = new IntegerNode(c1->value);
            c1 = c1->next;
        }
        else if(c2->value < c1->value)
        {
            // copy from l2
            nd = new IntegerNode(c2->value);
            c2 = c2->next;
        }
        else
        {
            // copy from both - LTR
            nd = new IntegerNode(c1->value);
            if(l3 == NULL) {
                l3 = nd;
                t3 = nd;
                continue;
            }
            nd = new IntegerNode(c2->value);
        }
        if(l3 == NULL) {
            l3 = nd;
            t3 = nd;
            continue;
        }
        t3->next = nd;
        t3 = nd;
    }
    
    while(c1 != NULL)
    {
        nd = new IntegerNode(c1->value);
        c1 = c1->next;
        if(l3 == NULL)
        {
            l3 = nd;
            t3 = nd;
            continue;
        }
        t3->next = nd;
        t3 = nd;
    }
    
    while(c2 != NULL)
    {
        nd = new IntegerNode(c2->value);
        c2 = c2->next;
        if(l3 == NULL)
        {
            l3 = nd;
            t3 = nd;
            continue;
        }
        t3->next = nd;
        t3 = nd;
        
    }
    
    return l3;
}


int main(int argc, const char * argv[]) {
    
    IntegerNode* d = new IntegerNode(2);
    
    IntegerNode* h = d;
    
    d = new IntegerNode(4);
    d->next = h;
    h = d;
    
    d = new IntegerNode(6);
    d->next = h;
    h = d;
    
    d = new IntegerNode(4);
    d->next = h;
    h = d;
    
    d = new IntegerNode(8);
    d->next = h;
    h = d;
    
    findLast(h, 4);
}
