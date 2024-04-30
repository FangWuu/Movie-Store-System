#include "Classic.h"

Classic::Classic() : Movie('C')
{
}

Classic::Classic(int stock, string director, string title, string actor, int month, int year) : Movie('C')
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->month = month;
    this->year = year;
    
}

void Classic::setData(int stock, string director, string title, string actor, int month, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->month = month;
    this->year = year;
}

string Classic::getKey()
{
    return to_string(this->month) + " " + to_string(this->year) + " " + this->actor;
}

void Classic::print()
{
    cout << movieType << ", " << stock << ", " << director << ", " << title << ", " << actor << ", " << month << " " << year << endl;
}

bool Classic::operator<(const Movie& other) const
{
    const Classic& otherClassic = dynamic_cast<const Classic&>(other);
    if (year < otherClassic.year) 
    {
        return true;
    } 
    else if (year == otherClassic.year) 
    {
        if (month < otherClassic.month) 
        {
            return true;
        } 
        else if (month == otherClassic.month) 
        {
            return actor < otherClassic.actor;
        }
    }
    return false;
}

bool Classic::operator>(const Movie& other) const
{
    const Classic& otherClassic = dynamic_cast<const Classic&>(other);
    if (year > otherClassic.year) 
    {
        return true;
    } 
    else if (year == otherClassic.year) 
    {
        if (month > otherClassic.month) 
        {
            return true;
        } 
        else if (month == otherClassic.month) 
        {
            return actor > otherClassic.actor;
        }
    }
    return false;
}