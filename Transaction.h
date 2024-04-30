#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <iostream>
using namespace std;

class Transaction{
public: 
    Transaction();
    char getTransactionType() const;
    int getCustomerID() const;
    char getMediaType() const;
    char getMovieType() const;
    string getMovieTitle() const;
    string getMovieDirector() const;
    string getMovieActor() const;
    int getMovieYear() const;
    int getMovieMonth() const;
    void setForComedy(char transactionType, int ID, char mediaType, char movieType, string title, int year);
    void setForDramas(char transactionType, int ID, char mediaType, char movieType, string director, string title);
    void setForClassics(char transactionType, int ID, char mediaType, char movieType, int month, int year, string actor);
    bool operator==(const Transaction &other) const;

private:
    char transactionType;
    char movieType;
    char mediaType;
    string movieTitle;
    string movieDirector;
    string movieActor;
    int customerID;
    int movieYear;
    int movieMonth;

};
#endif