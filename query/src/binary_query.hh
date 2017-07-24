#ifndef BINARY_QUERY_HH
#define BINARY_QUERY_HH

#include "query_base.hh"
#include "query.hh"

namespace cpp_primer {

class BinaryQuery : public QueryBase {
 protected:
  BinaryQuery(const Query& l, const Query& r, std::string s)
      : lhs_(l), rhs_(r), opSym_(s) {}
  std::string rep() const {
    return "(" + lhs_.rep() + " " + opSym_ + " " + rhs_.rep() + ")";
  }
  Query lhs_, rhs_;
  std::string opSym_;
 private:
};

} // namespace: cpp_primer

#endif //BINARY_QUERY_HH
