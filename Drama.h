#pragma once
#include <string>
#include "Movie.h"
using namespace std;

class Drama : public Movie 
{
public:
    Drama();
    Drama(int stock, string director, string title, int year);
    //~
    void setData(int, string, string, int);
    string getKey();
    void print();
    bool operator<(const Movie& other) const override;
    bool operator>(const Movie& other) const override;

protected:
    
    
};