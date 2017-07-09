#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "query_result.hh"

using std::endl;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

namespace cpp_primer {

QueryResult::QueryResult(string sought,
                         shared_ptr<set<line_no>> lines,
                         shared_ptr<vector<string>> file)
    : sought_{sought}, lines_{lines}, file_{file} {}

ostream& print(ostream& os, const QueryResult& qr) {
  os << qr.sought_ << " occurs " << qr.lines_->size() << " "
      << make_plural(qr.lines_->size(), "time", "s") << endl;
  for (auto num : *qr.lines_) {
    os << "\t(line " << num + 1 << ") "
        << *(qr.file_->begin() + num) << endl;
  }
  return os;
}

} // cpp_primer
