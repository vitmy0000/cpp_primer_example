#ifndef WORD_QUERY_HH
#define WORD_QUERY_HH

#include "query_base.hh"
#include "query.hh"
#include "text_query.hh"
#include "query_result.hh"

namespace cpp_primer {

class WordQuery : public QueryBase {
  friend class Query;
  WordQuery(const std::string& s) : query_word_(s) {}
  virtual QueryResult eval(const TextQuery& t) const override {
    return t.query(query_word_);
  }
  virtual std::string rep() const override { return query_word_; }
  std::string query_word_;
};

inline Query::Query(const std::string& s) : query_(new WordQuery(s)) {}

} // namespace: cpp_primer

#endif //WORD_QUERY_HH
