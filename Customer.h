#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <list>
#include "transaction.h"
using namespace std;

class Customer{
public:
    Customer();
    void AddTransaction(Transaction t);
    void PrintTransactionHistory();
    int getKey();
    void setData(int, string, string);
    int getID();
    bool multipleBorrowCheck(const Transaction&);

private:
    int customerID;
    string firstName;
    string lastName;
    list<Transaction> transactionHistory;
};
#endif