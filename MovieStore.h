#pragma once
#include <string>
#include <queue>
#include <iostream>
#include "HashTable.h"
#include "HashNode.h"
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MovieStore
{
public:
    ~MovieStore();
    void parsingMovies(string fileName);
    void parsingCustomers(string fileName);
    void executeTransactions(string fileName);

private:
    string fileName;
    HashTable<string, Movie*> movies;
    HashTable<int, Customer*> customers;

};