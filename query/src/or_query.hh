#ifndef OR_QUERY_HH
#define OR_QUERY_HH

#include "binary_query.hh"

namespace cpp_primer {

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "|") {}
  QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
  return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

} // namespace: cpp_primer

#endif //OR_QUERY_HH
