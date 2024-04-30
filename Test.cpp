#include <iostream>
#include "MovieStore.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Transaction.h"
#include "Customer.h"
#include <fstream>
#include <sstream>
#include "Hashtable.h"
#include "HashNode.h"
using namespace std;


int main()
{
    MovieStore Store;
    Store.parsingMovies("data4movies.txt");
    Store.parsingCustomers("data4customers.txt");
    Store.executeTransactions("data4commands.txt");
}