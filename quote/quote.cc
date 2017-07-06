#include "quote.hh"

#include <string>

using std::string;
using std::size_t;

Quote::Quote(const string& book_isbn, double sale_price)
    : book_isbn_{book_isbn}, sale_price_{sale_price} {}

string Quote::isbn() const {
  return book_isbn_;
}

double Quote::net_price(size_t n) const {
  return n * sale_price_;
}
