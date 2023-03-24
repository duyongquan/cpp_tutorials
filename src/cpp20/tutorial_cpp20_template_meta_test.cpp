#include <iostream>
#include <concepts>


namespace tutorials{
namespace cpp20 {

template<typename T>
concept Comparable = requires(T a, T b)
{
    {a, b} -> std::same_as<bool>;
};

template<typename T>
requires Comparable<T>
T max(T a, T b)
{
    return a > b ? a : b;
}

struct Foo {};

void test()
{
    max(Foo{}, Foo{});
}

}  // 
}  // namespace tutorial

int main(int argc, char** argv)
{
    std::cout << "Hello Template meta" << std::endl;
    return 0;
}