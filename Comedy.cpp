#include "Comedy.h"

Comedy::Comedy() : Movie('F')
{
}

Comedy::Comedy(int stock, string director, string title, int year) : Movie('F')
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}


void Comedy::setData(int stock, string director, string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

string Comedy::getKey()
{
    return this->title + " " + to_string(this->year);
}

void Comedy::print()
{
    cout << movieType << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

bool Comedy::operator<(const Movie& other) const
{
    const Comedy& otherComedy = dynamic_cast<const Comedy&>(other);
    if (title < otherComedy.title) 
    {
        return true;
    } else if (title == otherComedy.title) {
        return year < otherComedy.year;
    } else {
        return false;
    }
}

bool Comedy::operator>(const Movie& other) const
{
    const Comedy& otherComedy = dynamic_cast<const Comedy&>(other);
    if (title > otherComedy.title) 
    {
        return true;
    } else if (title == otherComedy.title) 
    {
        return year > otherComedy.year;
    } else 
    {
        return false;
    }
}