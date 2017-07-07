#include "bulk_quote.hh"

#include <string>

using std::string;
using std::size_t;

namespace cpp_primer {

BulkQuote::BulkQuote() = default;

BulkQuote::BulkQuote(const string& book_isbn, double sale_price,
                     size_t min_qty, double discount)
    : Quote{book_isbn, sale_price}, min_qty_{min_qty}, discount_{discount} {}

double BulkQuote::net_price(size_t n) const {
  if (n >= min_qty_) {
    return n * (1 - discount_) * sale_price_;
  } else {
    return n * sale_price_;
  }
}

} // cpp_primer
