#include "or_query.hh"

#include <memory>
#include <set>

namespace cpp_primer {

QueryResult OrQuery::eval(const TextQuery& text) const {
  auto right = rhs_.eval(text);
  auto left = lhs_.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(),
                                                       left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.get_file());
}

} // namespace: cpp_primer
