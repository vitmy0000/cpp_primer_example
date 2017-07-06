#include "quote.hh"
#include "bulk_quote.hh"

#include <iostream>

using std::ostream;
using std::size_t;
using std::cout;
using std::endl;

double print_total(ostream& os, const Quote& item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
      << " # sold: " << n
      << " total due: " << ret << endl;
  return ret;
}

int main(void) {
  Quote base("0-201-82470-1", 50);
  print_total(cout, base, 10);
  BulkQuote derived("0-201-82470-1", 50, 5, .19);
  print_total(cout, derived, 10);
  return 0;
}
