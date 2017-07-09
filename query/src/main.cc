#include <iostream>
#include <fstream>
#include <string>

#include "text_query.hh"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using namespace cpp_primer;

void run_queries(ifstream& in_file) {
  TextQuery tq(in_file);
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q") { break; }
    print(cout, tq.query(s)) << endl;
  }
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
