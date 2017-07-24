#ifndef QUERY_HH
#define QUERY_HH

#include "query_base.hh"
#include "query_result.hh"
#include "text_query.hh"

namespace cpp_primer {

class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
 public:
  Query(const std::string&);
  QueryResult eval(const TextQuery& t) const { return query_->eval(t); }
  std::string rep() const { return query_->rep(); }
 private:
  Query(std::shared_ptr<QueryBase> query) : query_(query) {}
  std::shared_ptr<QueryBase> query_;
};

} // namespace: cpp_primer

#endif //QUERY_HH
