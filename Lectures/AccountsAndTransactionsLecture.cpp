#include <iostream>
#include <string>
using namespace std;

enum TransactionType {
    DEPOSIT, WITHDRAW, TRANSFER
};

string labels[] = {
    "Deposit", "Withdraw", "Transfer"
};

class Transaction {
private:
    double amount = 0.0;
    double balance = 0.0;
    TransactionType type = DEPOSIT;
public:
    double* max = NULL;
    Transaction(){}
    Transaction(const Transaction &original)
    {
        this->amount  = original.amount;
        this->balance = original.balance;
        this->type    = original.type;
        this->max     = new double;
        *(this->max)  = *(original.max);
    }
    Transaction(double a)
    {
        amount = a;
    }
    Transaction(double a, double b, TransactionType t, double* max)
    {
        amount = a;
        balance = b;
        type = t;
        this->max = max;
    }

    void display(string message)
    {
        cout << "Hello " << message << endl;
    }
    void display()
    {
        cout << "Type: " << labels[type] << " Amount: $" << amount << " " << " Max: " << *max << endl;
    }
};

class BankAccount {
private:
    double balance;
};

void deposit() { cout << "Deposit" << endl; }
void withdraw() { cout << "Withdraw" << endl; }
void transfer() { cout << "Transfer" << endl; }
void unkonwnOperation() { cout << "Unknown" << endl; }

int main()
{
    double maxValue = 5000.0;
    
    Transaction openAccount(1000.0, 1000.0, DEPOSIT, &maxValue);
    openAccount.display();
    
    Transaction paycheck = openAccount;
    paycheck.display();
    
    *(paycheck.max) = 6000;
    paycheck.display();
    openAccount.display();

    
    
    TransactionType transactionType;
    
    transactionType = DEPOSIT;
    cout << labels[transactionType] << endl;

    cout << DEPOSIT << endl;
    cout << WITHDRAW << endl;
    cout << TRANSFER << endl;
    cout << transactionType << endl;

    transactionType = TRANSFER;
    cout << transactionType << endl;

    cout << labels[transactionType] << endl;

    switch(transactionType)
    {
        case DEPOSIT:
            deposit();
            break;
        case WITHDRAW:
            withdraw();
            break;
        case TRANSFER:
            transfer();
            break;
        default:
            unkonwnOperation();
    }

    return 0;
}
