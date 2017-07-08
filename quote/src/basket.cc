#include "basket.hh"

#include <iostream>
#include <memory>

#include "quote.hh"
#include "utility.hh"

using std::shared_ptr;
using std::ostream;

namespace cpp_primer {
// -- public
void Basket::add_item(const Quote& sale) {
  items_.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote&& sale) {
  items_.insert(shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt(ostream& os) const {
  double sum = 0.0;
  for (auto iter = items_.cbegin();
       iter != items_.cend();
       iter = items_.upper_bound(*iter)) {
    sum += print_total(os, **iter, items_.count(*iter));
  }
  os << "Total Sale: " << sum << std::endl;
  return sum;
}

// -- private
bool Basket::compare(const shared_ptr<Quote>& lhs,
             const shared_ptr<Quote>& rhs) {
  return lhs->isbn() < rhs->isbn();
}

} // cpp_primer
