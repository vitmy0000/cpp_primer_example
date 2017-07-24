#include <iostream>
#include <fstream>
#include <string>

#include "query.hh"
#include "word_query.hh"
#include "not_query.hh"
#include "binary_query.hh"
#include "and_query.hh"
#include "or_query.hh"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using namespace cpp_primer;

std::ostream& operator<<(std::ostream& os, const Query& query) {
  return os << query.rep();
}

void run_queries(ifstream& in_file) {
  TextQuery tq(in_file);
  // while (true) {
  //   cout << "enter word to look for, or q to quit: ";
  //   string s;
  //   if (!(cin >> s) || s == "q") { break; }
  //   print(cout, tq.query(s)) << endl;
  // }
  Query q1 = Query("Daddy");
  cout << "Executing Query for: " << q1 << endl;
  print(cout, q1.eval(tq));
  Query q2 = ~Query("Alice");
  cout << "Executing Query for: " << q2 << endl;
  print(cout, q2.eval(tq));
  Query q3 = Query("hair") | Query("Alice");
  cout << "Executing Query for: " << q3 << endl;
  print(cout, q3.eval(tq));
  Query q4 = Query("hair") & Query("Alice");
  cout << "Executing Query for: " << q4 << endl;
  print(cout, q4.eval(tq));
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "usage: "<< argv[0] <<" <filename>\n";
  } else {
    // We assume argv[1] is a filename to open
    ifstream in_file{argv[1]};
    if (in_file.is_open()) {
      run_queries(in_file);
      in_file.close();
    } else {
      cout << "Unable to open file";
    }
  }
  return 0;
}
