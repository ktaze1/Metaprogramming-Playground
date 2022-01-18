#include <iostream>
#include <utility>

template<unsigned int n>
struct factorial {
    enum {
        value = n * factorial<n-1>::value
    };
};

template<>
struct factorial<0>
{
    enum { value = 1 };
};


// ---------------

// constexpr version : > C++14
constexpr long long factorial(int n) {
    long long result = 1;
    for(auto i{1}; i<=n; i++){
        result *= i;
    }
    return result;
}


// -------------------

// fold expressions for c++17 and greater

template<class T, T N, class II = std::make_integer_sequence<T, N>>
struct factorial;

template <class T, T N, T... Is>
struct factorial<T, N, std::index_sequence<T, Is...>> {
    static constexpr T value = (static_cast<T>(1) * ... * (Is + 1));
}

int main() {
    std::cout << factorial<7>::value << '\n';
}