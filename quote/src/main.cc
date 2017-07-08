#include <iostream>

#include "basket.hh"
#include "bulk_quote.hh"
#include "quote.hh"
#include "utility.hh"

using namespace cpp_primer;

int main(void) {
  Quote base("0-201-82470-1", 50);
  std::cout << "Quote: ";
  print_total(std::cout, base, 10);
  BulkQuote derived("0-201-82470-1", 50, 5, .19);
  std::cout << "Quote: ";
  print_total(std::cout, derived, 10);
  Basket bsk;
  bsk.add_item(base);
  bsk.add_item(derived);
  std::cout << "Basket: ";
  bsk.total_receipt(std::cout);
  return 0;
}
