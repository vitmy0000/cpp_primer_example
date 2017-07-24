#ifndef AND_QUERY_HH
#define AND_QUERY_HH

#include "binary_query.hh"

namespace cpp_primer {

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "&") {}
  QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
  return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

} // namespace: cpp_primer

#endif //AND_QUERY_HH
