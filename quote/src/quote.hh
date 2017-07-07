#ifndef QUOTE_HH
#define QUOTE_HH

#include <string>

namespace cpp_primer {

class Quote {
 public:
  Quote();
  Quote(const std::string&, double);
  virtual ~Quote();
  virtual double net_price(std::size_t n) const;
  // getters & setters
  std::string isbn() const;
 private:
  std::string book_isbn_; // ISBN number of this item
 protected:
  double sale_price_ = 0.0;  // normal, undiscounted price
};

inline std::string Quote::isbn() const { return book_isbn_; }

} // cpp_primer

#endif
