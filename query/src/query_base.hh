#ifndef QUERY_BASE_HH
#define QUERY_BASE_HH

#include "text_query.hh"
#include "query_result.hh"

namespace cpp_primer {

class QueryBase {
  friend class Query;
 protected:
  using line_no = TextQuery::line_no;
  virtual ~QueryBase() = default;
 private:
  virtual QueryResult eval(const TextQuery&) const = 0;
  virtual std::string rep() const = 0;
};

} // namespace: cpp_primer

#endif //QUERY_BASE_HH
