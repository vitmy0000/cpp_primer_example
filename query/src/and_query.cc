#include "and_query.hh"

#include <algorithm>

namespace cpp_primer {

QueryResult AndQuery::eval(const TextQuery& text) const {
  auto left = lhs_.eval(text);
  auto right = rhs_.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  set_intersection(left.begin(), left.end(),
                   right.begin(), right.end(),
                   inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.get_file());
}

} // namespace: cpp_primer
