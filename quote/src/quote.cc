#include "quote.hh"

#include <string>

using std::string;
using std::size_t;

namespace cpp_primer {

Quote::Quote() = default;

Quote::Quote(const string& book_isbn, double sale_price)
    : book_isbn_{book_isbn}, sale_price_{sale_price} {}

Quote::~Quote() = default;

double Quote::net_price(size_t n) const {
  return n * sale_price_;
}

Quote* Quote::clone() const & {
  return new Quote(*this);
}

Quote* Quote::clone() && {
  return new Quote(std::move(*this));
}

} // cpp_primer
