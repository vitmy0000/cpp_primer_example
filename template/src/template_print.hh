#ifndef TEMPLATE_PRINT
#define TEMPLATE_PRINT

template<int Value>
struct Print {
  operator char() {
    return Value + 0xFF; // INVOKE OVERFLOW WARNNING LOG !
  }
};

#define __DO_JOIN(symbol1, symbol2) symbol1##symbol2
#define _JOIN(symbol1, symbol2) __DO_JOIN(symbol1, symbol2)

#define UNIQUE_NAME(prefix) _JOIN(prefix, __LINE__)
#define __print(...) char UNIQUE_NAME(print_value_) = Print<__VA_ARGS__>()


#endif /* ifndef TEMPLATE_PRINT */

