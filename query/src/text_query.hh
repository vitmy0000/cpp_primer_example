#ifndef TEXT_QUERY_HH
#define TEXT_QUERY_HH

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>

#include "query_result.hh"

namespace cpp_primer {

class TextQuery {
 public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream&);
  QueryResult query(const std::string&) const;
 private:
  std::shared_ptr<std::vector<std::string>> file_; // input file
  // map of each word to the set of lines in which that word appears
  std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map_;
};

} // cpp_primer

#endif
