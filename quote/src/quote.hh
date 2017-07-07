#ifndef QUOTE_HH
#define QUOTE_HH

#include <string>

namespace cpp_primer {

class Quote {
 public:
  Quote() = default;
  Quote(const std::string&, double);
  virtual ~Quote() = default;

  std::string isbn() const;
  virtual double net_price(std::size_t n) const;
 private:
  std::string book_isbn_; // ISBN number of this item
 protected:
  double sale_price_ = 0.0;  // normal, undiscounted price
};

} // cpp_primer

#endif /* ifndef QUOTE_HH */
