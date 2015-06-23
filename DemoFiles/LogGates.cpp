//
//  main.cpp
//  LogicGates
//
//  Created by Jose Annunziato on 6/23/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Gate {
public:
    string name;
    Gate* input1;
    Gate* input2;
    virtual bool eval() = 0;
    Gate(string n) {
        name = n;
    }
};

class OrGate : public Gate {
public:
    bool eval() {
        return input1->eval() || input2->eval();
    }
    OrGate(string n, Gate* i1, Gate* i2) : Gate(n)
    {
        input1 = i1; input2 = i2;
    }
};

class AndGate : public Gate {
public:
    string name;
    bool eval() {
        return input1->eval() && input2->eval();
    }
    AndGate(string n, Gate* i1, Gate* i2) : Gate(n)
    {
        input1 = i1, input2 = i2;
    }
};

class NotGate : public Gate {
public:
    bool eval()
    {
        return !input1->eval();
    }
    NotGate(string n, Gate* input) : Gate(n)
    {
        input1 = input;
    }
};

class InputGate : public Gate {
public:
    bool value;
    bool eval() {
        return value;
    }
    void setValue(char value)
    {
        if(value == '0')
            this->value = false;
        else if(value == '1')
            this->value = true;
    }
    InputGate(string n, bool v) : Gate(n)
    {
        this->value = v;
    }
};

string toBinary(int n)
{
    return bitset<8>(n).to_string();
}

int main(int argc, const char * argv[]) {
    
    InputGate* A = new InputGate("A", true);
    InputGate* B = new InputGate("B", false);
    AndGate* aAndB = new AndGate("A AND B", A, B);
    cout << aAndB->eval() << endl;
    
    InputGate* C = new InputGate("C", true);
    InputGate* D = new InputGate("D", false);
    OrGate* cOrD = new OrGate("C OR D", C, D);
    cout << cOrD->eval() << endl;
    
    OrGate* result = new OrGate("Result", aAndB, cOrD);
    
    NotGate* notResult = new NotGate("Not Result", result);
    
    cout << "ABCD" << endl;
    for(int i=0; i<=15; i++)
    {
//        cout << toBinary(i) << endl;
        string bin = toBinary(i);
        A->setValue(bin[4]);
        B->setValue(bin[5]);
        C->setValue(bin[6]);
        D->setValue(bin[7]);
        cout << A->value << B->value << C->value << D->value << "\t" << aAndB->eval() << "\t" << cOrD->eval() << "\t" << result->eval() << "\t" << notResult->eval() << endl;
    }
}
