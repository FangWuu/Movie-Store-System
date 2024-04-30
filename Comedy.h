#pragma once
#include <string>
#include "Movie.h"
using namespace std;

class Comedy : public Movie 
{
public:
    Comedy();
    Comedy(int stock, string director, string title, int year);
    //~
    void setData(int, string, string, int);
    string getKey();
    void print();
    bool operator<(const Movie& other) const override;
    bool operator>(const Movie& other) const override;
    

protected:
    
    
};