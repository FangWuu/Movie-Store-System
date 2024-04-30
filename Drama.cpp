#include "Drama.h"

Drama::Drama() : Movie('D')
{
}

Drama::Drama(int stock, string director, string title, int year) : Movie('D')
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}


void Drama::setData(int stock, string director, string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

string Drama::getKey()
{
    return this->director + " " + this->title;
}

void Drama::print()
{
    cout << movieType << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

bool Drama::operator<(const Movie& other) const
{
    const Drama& otherDrama = dynamic_cast<const Drama&>(other);
    if (director < otherDrama.director) 
    {
        return true;
    } 
    else if (director == otherDrama.director) 
    {
        return title < otherDrama.title;
    } 
    else 
    {
        return false;
    }
}

bool Drama::operator>(const Movie& other) const
{
    const Drama& otherDrama = dynamic_cast<const Drama&>(other);
    if (director > otherDrama.director) 
    {
        return true;
    } 
    else if (director == otherDrama.director) 
    {
        return title > otherDrama.title;
    } 
    else 
    {
        return false;
    }
}