#include "customer.h"
#include "transaction.h"
#include <iostream>
#include <list>

using namespace std;
Customer::Customer()
{
    this->customerID = 0;
    this->lastName = "";
    this->firstName = "";
}
void Customer::AddTransaction(Transaction t)
{
    transactionHistory.push_back(t);
}

void Customer::setData(int ID, string last, string first)
{
    this->customerID = ID;
    this->lastName = last;
    this->firstName = first;
}

void Customer::PrintTransactionHistory() {
    for(auto it = transactionHistory.rbegin(); it != transactionHistory.rend(); ++it) 
    {
        const Transaction &transaction = *it;
        cout << transaction.getTransactionType() << " ";
        cout << transaction.getCustomerID() << " ";
        cout << transaction.getMediaType() << " ";
        cout << transaction.getMovieType() << " ";
        
        switch (transaction.getMovieType()){
            case 'C':
                cout << transaction.getMovieMonth() << " ";
                cout << transaction.getMovieYear() << " ";
                cout << transaction.getMovieActor() << endl;
                break;
            case 'F':
                cout << transaction.getMovieTitle() << ", ";
                cout << transaction.getMovieYear() << endl;
                break;
            case 'D':
                cout << transaction.getMovieDirector() << ", ";
                cout << transaction.getMovieTitle() << ", " << endl;
                break;
            default:
                cout << "Invalid movie type" << endl;
        }
    }
}

int Customer::getID()
{
    return this->customerID;
}

int Customer::getKey()
{
    return this->customerID;
}

bool Customer::multipleBorrowCheck(const Transaction& T) {
    int borrowCount = 0;
    int returnCount = 0;
    
    for (const auto& transaction : transactionHistory) {
        if (transaction == T) {
            if (transaction.getTransactionType() == 'B') 
            {
                borrowCount++;
            }
            else if (transaction.getTransactionType() == 'R') 
            {
                returnCount++;
            }
        }
    }
    
    return borrowCount > returnCount;
}