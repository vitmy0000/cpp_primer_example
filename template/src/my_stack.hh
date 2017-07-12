#ifndef MY_STACK_HH
#define MY_STACK_HH

#include <vector>
#include <stdexcept>

namespace my_template {

template <typename T,
          template<typename Elem,
                   typename Allocator = std::allocator<Elem>>
          class Container = std::vector>
class MyStack {
 public:
  void push(const T& elem) {
    elems_.push_back(elem);
  }

  T pop() {
    if (empty()) { throw std::out_of_range("Stack<>::pop: empty!"); }
    auto elem = elems_.back();
    elems_.pop_back();
    return elem;
  }

  bool empty() const {
    return elems_.empty();
  }
 private:
  Container<T> elems_;
};

} // my_template

#endif
