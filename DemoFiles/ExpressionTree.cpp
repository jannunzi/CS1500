//
//  main.cpp
//  ExpressionTree
//
//  Created by Jose Annunziato on 6/23/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class ExpressionNode {
public:
    virtual float eval() = 0;
};

class Number : public ExpressionNode {
public:
    float value;
    float eval() {
        return value;
    }
    Number(float value) { this->value = value; }
};

class Operator : public ExpressionNode {
public:
    ExpressionNode* input1;
    ExpressionNode* input2;
    float eval()
    {
        return 123;
    }
};

class PlusOperator : public Operator {
public:
    float eval()
    {
        return input1->eval() + input2->eval();
    }
};

class MinusOperator : public Operator {
public:
    float eval()
    {
        return input1->eval() - input2->eval();
    }
};

class TimesOperator : public Operator {
public:
    float eval()
    {
        return input1->eval() * input2->eval();
    }
};

class DivisionOperator : public Operator {
public:
    float eval()
    {
        return input1->eval() / input2->eval();
    }
};

int main(int argc, const char * argv[]) {
    
    Number* B = new Number(3);
    
    PlusOperator* aPlusB = new PlusOperator();
    aPlusB->input1 = new Number(4);
    aPlusB->input2 = B;
    cout << aPlusB->eval() << endl;
    
    
    MinusOperator* cMinusD = new MinusOperator();
    cMinusD->input1 = new Number(7);
    cMinusD->input2 = new Number(5);
    cout << cMinusD->eval() << endl;
    
    PlusOperator* result = new PlusOperator();
    result->input1 = aPlusB;
    result->input2 = cMinusD;
    cout << result->eval() << endl;
    
    TimesOperator* times = new TimesOperator();
    times->input1 = result;
    times->input2 = B;
    cout << times->eval() << endl;
}
