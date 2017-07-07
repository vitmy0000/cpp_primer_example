#ifndef BULK_QUOTE_HH
#define BULK_QUOTE_HH

#include "quote.hh"

namespace cpp_primer {

class BulkQuote : public Quote {
 public:
  BulkQuote() = default;
  BulkQuote(const std::string&, double, std::size_t, double);
  virtual double net_price(std::size_t) const override;
 private:
  std::size_t min_qty_ = 0;
  double discount_ = 0.0;
};

} // cpp_primer

#endif /* ifndef BULK_QUOTE_HH */
