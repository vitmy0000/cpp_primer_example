#include "template_print.hh"

template<int X, int Y>
struct PrintTest {
    enum { Value = X + Y };
};

__print(PrintTest<3, 4>::Value);
