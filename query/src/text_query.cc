#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

#include <boost/algorithm/string.hpp>

#include "text_query.hh"
#include "query_result.hh"

using std::ifstream;
using std::istringstream;
using std::vector;
using std::shared_ptr;
using std::string;
using std::set;

namespace cpp_primer {

TextQuery::TextQuery(ifstream& is) : file_{new vector<string>} {
  string text;
  while (getline(is, text)) {
    file_->push_back(text);
    int index = file_->size() - 1;
    istringstream line(text);
    string word;
    while (line >> word) {
      boost::trim_if(word, boost::is_punct());
      auto& lines = word_map_[word];
      if (!lines) {
        lines.reset(new set<line_no>);
      }
      lines->insert(index);
    }
  }
}

QueryResult TextQuery::query(const std::string& sought) const {
  static shared_ptr<set<line_no>> no_data(new set<line_no>);
  auto loc = word_map_.find(sought);
  if (loc == word_map_.end()) {
    return QueryResult(sought, no_data, file_);
  } else {
    return QueryResult(sought, loc->second, file_);
  }
}

} // cpp_primer
