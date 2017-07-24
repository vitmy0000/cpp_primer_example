#ifndef NOT_QUERY_HH
#define NOT_QUERY_HH

#include "query_base.hh"
#include "query.hh"

namespace cpp_primer {

class NotQuery : public QueryBase {
  friend Query operator~(const Query&);
  NotQuery(const Query& query) : query_(query) {}
  std::string rep() const { return "~(" + query_.rep() + ")"; }
  QueryResult eval(const TextQuery&) const;
  Query query_;
};

inline Query operator~(const Query& operand) {
  return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

} // namespace: cpp_primer

#endif //NOT_QUERY_HH
