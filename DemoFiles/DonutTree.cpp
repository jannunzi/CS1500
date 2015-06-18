//
//  main.cpp
//  DonutTree
//
//  Created by Jose Annunziato on 6/17/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Donut
{
public:
    string name;
    Donut* left = NULL;
    Donut* right = NULL;
    Donut(){}
    Donut(string name) { this->name = name; }
    void display() { cout << name << endl; }
};

void traversePreOrder(Donut* root)
{
    if(root != NULL)
    {
        root->display();
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

void traverseInOrder(Donut* root)
{
    if(root != NULL)
    {
        traverseInOrder(root->left);
        root->display();
        traverseInOrder(root->right);
    }
}

void traversePostOrder(Donut* root)
{
    if(root != NULL)
    {
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        root->display();
    }
}

Donut* binSearchByName(Donut* root, string name)
{
    if(root == NULL)
        return NULL;
    else if(name == root->name)
        return root;
    else if(name < root->name)
        return binSearchByName(root->left, name);
    else if(name > root->name)
        return binSearchByName(root->right, name);
    return NULL;
}

void binInsertByName(Donut* *root, Donut* newDonut)
{
    if(*root == NULL)
    {
        *root = newDonut;
    }
    else if(newDonut->name > (*root)->name)
    {
        if((*root)->right == NULL)
            (*root)->right = newDonut;
        else
            binInsertByName(&((*root)->right), newDonut);
    }
    else if(newDonut->name < (*root)->name)
    {
        if((*root)->left == NULL)
            (*root)->left = newDonut;
        else
            binInsertByName((&(*root)->left), newDonut);
    }
}

Donut* binMinByName(Donut* root)
{
    if(root == NULL)
        return NULL;
    Donut* current = root;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Donut* binMaxByName(Donut * root)
{
    if(root == NULL)
        return NULL;
    Donut* current = root;
    while(current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

int main(int argc, const char * argv[])
{
    Donut* d10 = new Donut("d10");
    Donut* d20 = new Donut("d20");
    Donut* d30 = new Donut("d30");
    Donut* d40 = new Donut("d40");
    Donut* d50 = new Donut("d50");
    Donut* d60 = new Donut("d60");
    Donut* d70 = new Donut("d70");
    
//    d20->left = d10;
//    d20->right = d30;
//    
//    d60->left = d50;
//    d60->right = d70;
//    
//    d40->left = d20;
//    d40->right = d60;
//    
//    Donut* root = d40;

    Donut* root = NULL;
    
    binInsertByName(&root, d40);
    binInsertByName(&root, d20);
    binInsertByName(&root, d60);
    binInsertByName(&root, d10);
    binInsertByName(&root, d30);
    binInsertByName(&root, d50);
    binInsertByName(&root, d70);
    
//    traversePreOrder(root);
    traverseInOrder(root);
//    traversePostOrder(root);
    
    Donut* d = binSearchByName(root, "d50");
    if(d != NULL)
        d->display();
    else
        cout << "Not Found" << endl;
    
    Donut* d55 = new Donut("d55");
    binInsertByName(&root, d55);
    
    traverseInOrder(root);
    
    d = binMinByName(root);
    if(d != NULL)
        d->display();
    else
        cout << "Not Found" << endl;
    
    
    d = binMaxByName(root);
    if(d != NULL)
        d->display();
    else
        cout << "Not Found" << endl;
    
}
