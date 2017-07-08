#ifndef BASKET_HH
#define BASKET_HH

#include <iostream>
#include <memory>
#include <set>

#include "quote.hh"

namespace cpp_primer {

class Basket {
 public:
  void add_item(const Quote&);
  void add_item(Quote&&);
  double total_receipt(std::ostream&) const;
 private:
  static bool compare(const std::shared_ptr<Quote>& lhs,
                      const std::shared_ptr<Quote>& rhs);
  std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items_{compare};
};

} // cpp_primer

#endif
