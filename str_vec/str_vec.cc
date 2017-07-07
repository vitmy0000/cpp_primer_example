#include "str_vec.hh"
#include <memory>
#include <string>
#include <utility> // pair

using std::allocator;
using std::string;
using std::pair;

namespace cpp_primer {

allocator<string> StrVec::alloc; // default init; call default constructor

StrVec::StrVec() : elements_{nullptr}, first_free_{nullptr}, cap_{nullptr} {}

StrVec::StrVec(const StrVec& s) {
  auto new_data = alloc_and_copy(s.begin(), s.end());
  elements_ = new_data.first;
  first_free_ = cap_ = new_data.second;
}

StrVec::StrVec(StrVec&& s) noexcept
    : elements_{s.elements_}, first_free_{s.first_free_}, cap_{s.cap_} {
  s.elements_ = s.first_free_ = s.cap_ = nullptr;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
  auto data = alloc_and_copy(rhs.begin(), rhs.end());
  free();
  elements_ = data.first;
  first_free_ = cap_ = data.second;
  return *this;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept {
  // direct test for self-assignment
  if (this != &rhs) {
    free();
    elements_ = rhs.elements_;
    first_free_ = rhs.first_free_;
    cap_ = rhs.cap_;
    // leave rhs in a destructible state
    rhs.elements_ = rhs.first_free_ = rhs.cap_ = nullptr;
  }
  return *this;
}

StrVec::~StrVec() {
  free();
}

size_t StrVec::size() const {
  return first_free_ - elements_;
}

size_t StrVec::capacity() const {
  return cap_ - elements_;
}

string* StrVec::begin() const {
  return elements_;
}

string* StrVec::end() const {
  return first_free_;
}

void StrVec::push_back(const string& s) {
  check_and_alloc(); // ensure that there is room for another element
  alloc.construct(first_free_++, s);
}

void StrVec::push_back(string&& s) {
  check_and_alloc();
  alloc.construct(first_free_++, std::move(s));
}

void StrVec::check_and_alloc() {
  if (size() == capacity()) {
    reallocate();
  }
}

pair<string*, string*> StrVec::alloc_and_copy(const string* b,
                                              const string* e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  // may not pass deallocate a 0 pointer;
  if (elements_) {
    for (auto p = first_free_; p != elements_; --p) {
      alloc.destroy(p);
    }
    alloc.deallocate(elements_, cap_ - elements_);
  }
}

void StrVec::reallocate() {
  // we'll allocate space for twice as many elements as the current size
  auto new_capacity = size() ? 2 * size() : 1;
  auto new_data = alloc.allocate(new_capacity);
  // move the elements
  auto last = uninitialized_copy(make_move_iterator(begin()),
                                 make_move_iterator(end()),
                                 new_data);
  free();
  elements_ = new_data;
  first_free_ = last;
  cap_ = elements_ + new_capacity;
}

} // cpp_primer

