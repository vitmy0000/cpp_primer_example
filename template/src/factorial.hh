template<int N>
struct Factorial {
    enum { Value = N * Factorial<N - 1>::Value };
};

template<>
struct Factorial<1> {
    enum { Value = 1 };
};
