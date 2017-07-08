#ifndef UTILITY_HH
#define UTILITY_HH

#include <iostream>

#include "quote.hh"

namespace cpp_primer {

inline double print_total(std::ostream& os, const Quote& item, std::size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
      << " # sold: " << n
      << " total due: " << ret << std::endl;
  return ret;
}

} // cpp_primer

#endif
