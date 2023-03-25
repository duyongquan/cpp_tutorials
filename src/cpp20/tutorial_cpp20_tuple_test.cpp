#include <iostream>
#include <concepts>
#include <vector>
#include <tuple>

#include <Eigen/Core>
#include "tutorial_cpp20_tuple_type_traits.hpp"

namespace tutorials{
namespace cpp20 {


struct State {
  
};

struct A : public State {};
struct B : public State {};
struct C : public State {};
struct D : public State {};

template<typename T>
struct  is_state : std::conditional_t<
    std::is_base_of<State, T>::value, std::true_type, std::false_type> {};


template<typename ScalarT, typename ... VariableTs>
class GenericState 
{
    static_assert(conjunction<is_state<VariableTs>...>::value,
        "\n\nState can only be generated from is_state, i.e. types that inherit from State.\n\n");
    static_assert(
        sizeof...(VariableTs) > 0, "\n\nCannot create state without states.\n\n");
    // Hide this under private to make sure it is never ODR-used.
    constexpr static std::int32_t kSize = sizeof...(VariableTs);

public:
    using Variables = std::tuple<VariableTs...>;
    using Vector = Eigen::Matrix<ScalarT, kSize, 1>;

    GenericState() = default;

    explicit GenericState(const Vector & vector)
    : m_state{vector} {}

    template<typename VariableT>
    inline ScalarT & at(const VariableT) noexcept
    {
        static_assert(is_state<VariableT>::value, "Type is not a Variable.");
        return m_state[index<VariableT, Variables>::value];
    }

    template<typename VariableT>
    inline ScalarT & at() noexcept
    {
        static_assert(is_state<VariableT>::value, "Type is not a Variable.");
        return m_state[index<VariableT, Variables>::value];
    }

private:
    Vector m_state{Vector::Zero()};
};


using StateAB = GenericState<double, A, B>;         // using StateAB = GenericState<B, A>;
using StateBA = GenericState<double, B, A>;
using StateABC = GenericState<double, A, B, C>;     // using StateAB = GenericState<C, B, A>;
using StateABCD = GenericState<double, A, B, C, D>; // // using StateAB = GenericState<C, D, B, A>;


void test()
{
    // StateA a_sate{{2.0}};
    StateAB ab{{1.0, 2.0}};
    std::cout << "A: " << ab.at<A>() << std::endl;
    std::cout << "B: " << ab.at<B>() << std::endl;


    StateBA ba{{1.0, 2.0}};
    std::cout << "A: " << ba.at<A>() << std::endl;
    std::cout << "B: " << ba.at<B>() << std::endl;
}

}  // namespace cpp20
}  // namespace tutorials

int main(int argc, char** argv)
{
    std::cout << "Hello Template" << std::endl;
    tutorials::cpp20::test();
    return 0;
}