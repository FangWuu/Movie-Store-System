#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Movie
{
public:
    Movie(char movieType);
    //~Movie();
    virtual bool increaseStock(int);
    virtual bool decreaseStock(int);
    virtual int checkStock();
    virtual char checkMovieType();
    virtual void setData(string, string, int, int);
    virtual void print();
    virtual bool operator<(const Movie& other) const = 0;
    virtual bool operator>(const Movie& other) const = 0;
    

protected:
    string title, director, actor;
    int stock, month, year;
    char mediaType, movieType;
    
};