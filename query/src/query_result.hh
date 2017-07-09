#ifndef QUERY_RESULT
#define QUERY_RESULT

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace cpp_primer {

class QueryResult {
  using line_no = std::vector<std::string>::size_type;
  friend std::ostream& print(std::ostream&, const QueryResult&);
 public:
  QueryResult(std::string,
              std::shared_ptr<std::set<line_no>>,
              std::shared_ptr<std::vector<std::string>>);
 private:
  std::string sought_;
  std::shared_ptr<std::set<line_no>> lines_;
  std::shared_ptr<std::vector<std::string>> file_;
};

std::ostream& print(std::ostream&, const QueryResult&);

inline std::string make_plural(std::size_t ctr, const std::string& word,
                          const std::string& ending) {
  return (ctr > 1) ? word + ending : word;
}

} // cpp_primer

#endif
