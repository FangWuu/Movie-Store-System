#pragma once
#include <string>
#include "Movie.h"
using namespace std;

class Classic : public Movie 
{
public:
    Classic();
    Classic(int stock, string director, string title, string actor, int month, int year);
    //~
    void setData(int, string, string, string, int, int);
    string getKey();
    void print();
    bool operator<(const Movie& other) const override;
    bool operator>(const Movie& other) const override;

protected:
    string actor;
    int month;
    
};