#ifndef STR_VEC_HH
#define STR_VEC_HH

#include <memory>
#include <string>

namespace cpp_primer {

class StrVec {
 public:
  StrVec();
  StrVec(const StrVec&);
  StrVec(StrVec&&) noexcept;
  StrVec& operator=(const StrVec&);
  StrVec& operator=(StrVec&&) noexcept;
  ~StrVec();
  void push_back(const std::string&); // copy the element
  void push_back(std::string&&); // move the element
  size_t size() const;
  size_t capacity() const;
  std::string* begin() const;
  std::string* end() const;

 private:
  static std::allocator<std::string> alloc; // allocate the elements
  void check_and_alloc(); // used by functions that add elements to a StrVec
  // return pair of pointers:
  // pointing to the beginning of the new space
  // and one pass the element it copied
  std::pair<std::string*, std::string*> alloc_and_copy(
      const std::string*, const std::string*);
  void free(); // destroy the elements and free the space
  void reallocate(); // get more space and copy the exsisting elements
  std::string* elements_; // pointer to the first element in the array
  std::string* first_free_; // pointer to the first free element in the array
  std::string* cap_; // pointer to one past the end of the array
};

} // cpp_primer

#endif
