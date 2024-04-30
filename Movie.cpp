#include "Movie.h"

Movie::Movie(char movie)
{
    this->title = "";
    this->director = "";
    this->stock = 0;
    this->year = 0;
    this->actor = "";
    this->month = 0;
    this->mediaType = 'D';
    this->movieType = movie;
}


bool Movie::increaseStock(int n)
{
    this->stock += n;
    return true;
}

bool Movie::decreaseStock(int n)
{
    if (this->stock - n < 0)
    {
        return false;
    }
    this->stock -= n;
    return true;
}

int Movie::checkStock()
{
    return this->stock;
}

char Movie::checkMovieType()
{
    return this->movieType;
}

void Movie::setData(string title, string director, int stock, int year)
{
    this->title = title;
    this->director = director;
    this->stock = stock;
    this->year = year;
}

void Movie::print()
{
    cout << "Title: " << stock <<  title << ", Director: " << director << ", Stock: " << endl;
}

bool Movie::operator<(const Movie& other) const
{
    if (title < other.title) {
        return true;
    } else if (title == other.title) {
        return year < other.year;
    } else {
        return false;
    }
}

bool Movie::operator>(const Movie& other) const
{
    if (title > other.title) {
        return true;
    } else if (title == other.title) {
        return year > other.year;
    } else {
        return false;
    }
}