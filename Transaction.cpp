#include "transaction.h"

Transaction::Transaction()
{
    this->transactionType =' ';
    this->customerID = 0;
    this->movieType = ' ';
    this->mediaType = ' ';
    this->movieTitle = "";
    this->movieDirector = "";
    this->movieActor = "";
    this->movieYear = 0;
    this->movieMonth = 0;

}
char Transaction::getTransactionType() const{
    return transactionType;
}

int Transaction::getCustomerID() const{
    return customerID;
}

char Transaction::getMediaType() const{
    return mediaType;
}

char Transaction::getMovieType() const{
    return movieType;
}

string Transaction::getMovieTitle() const{
    return movieTitle;
}

string Transaction::getMovieDirector() const {
    return movieDirector;
}

string Transaction::getMovieActor() const {
    return movieActor;
}

int Transaction::getMovieYear() const {
    return movieYear;
}

int Transaction::getMovieMonth() const {
    return movieMonth;
}


void Transaction::setForComedy(char transactionType, int ID, char mediaType, char movieType, string title, int year)
{
    this->transactionType = transactionType;
    this->customerID = ID;
    this->mediaType = mediaType;
    this->movieType = movieType;
    this->movieTitle = title;
    this->movieYear = year;

}
void Transaction::setForDramas(char transactionType, int ID, char mediaType, char movieType, string director, string title)
{
    this->transactionType = transactionType;
    this->customerID = ID;
    this->mediaType = mediaType;
    this->movieType = movieType;
    this->movieDirector = director;
    this->movieTitle = title;
}

//this method is not correct for title
void Transaction::setForClassics(char transactionType, int ID, char mediaType, char movieType, int month, int year, string actor){
    this->transactionType = transactionType;
    this->customerID = ID;
    this->mediaType = mediaType;
    this->movieType = movieType;
    this->movieMonth = month;
    this->movieYear = year;
    this->movieActor = actor;
}

bool Transaction::operator==(const Transaction &other) const 
{
    return movieType == other.movieType &&
           mediaType == other.mediaType &&
           movieTitle == other.movieTitle &&
           movieDirector == other.movieDirector &&
           movieActor == other.movieActor &&
           movieYear == other.movieYear &&
           movieMonth == other.movieMonth;
}