#ifndef CPP_TUTORIALS_TUTORIAL_CPP20_TUPLE_TYPE_TRAITS_HPP_
#define CPP_TUTORIALS_TUTORIAL_CPP20_TUPLE_TYPE_TRAITS_HPP_

#include <cstdint>
#include <tuple>
#include <type_traits>

namespace tutorials{
namespace cpp20 {

/// Find an index of a type in a tuple
template<class QueryT, class TupleT>
struct index
{
    static_assert(!std::is_same<TupleT, std::tuple<>>::value, "Could not find QueryT in given tuple");
};

/// Specialization for a tuple that starts with the HeadT type. End of recursion.
template<class HeadT, class ... Tail>
struct index<HeadT, std::tuple<HeadT, Tail...>>
  : std::integral_constant<std::int32_t, 0> {};

/// Specialization for a tuple with a type different to QueryT that calls the recursive step.
template<class QueryT, class HeadT, class ... Tail>
struct index<QueryT, std::tuple<HeadT, Tail...>> 
    : std::integral_constant<std::int32_t, 1 + index<QueryT, std::tuple<Tail...>>::value> {};

template<std::size_t I = 0UL, typename Callable, typename ... TypesT>
inline constexpr typename std::enable_if_t<I == sizeof...(TypesT)>
visit(std::tuple<TypesT...> &, Callable) noexcept {}

/// @brief      Same as the previous specialization but for const tuple.
template<std::size_t I = 0UL, typename Callable, typename ... TypesT>
inline constexpr typename std::enable_if_t<I == sizeof...(TypesT)>
visit(const std::tuple<TypesT...> &, Callable) noexcept {}

template<std::size_t I = 0UL, typename Callable, typename ... TypesT>
inline constexpr typename std::enable_if_t<I != sizeof...(TypesT)>
visit(std::tuple<TypesT...> & tuple, Callable callable) noexcept
{
    callable(std::get<I>(tuple));
    visit<I + 1UL, Callable, TypesT...>(tuple, callable);
}

/// @brief      Same as the previous specialization but for const tuple.
template<std::size_t I = 0UL, typename Callable, typename ... TypesT>
inline constexpr typename std::enable_if_t<I != sizeof...(TypesT)>
visit(const std::tuple<TypesT...> & tuple, Callable callable) noexcept
{
    callable(std::get<I>(tuple));
    visit<I + 1UL, Callable, TypesT...>(tuple, callable);
}

template<class ...>
struct conjunction : std::true_type {};

template<class TraitT>
struct conjunction<TraitT>: TraitT {};
template<class TraitT, class ... TraitsTs>
struct conjunction<TraitT, TraitsTs...>
    : std::conditional_t<static_cast<bool>(TraitT::value), conjunction<TraitsTs...>, TraitT> {};

template<typename QueryT, typename TupleT>
struct has_type;

template<typename QueryT>
struct has_type<QueryT, std::tuple<>>: std::false_type {};

template<typename QueryT, typename HeadT, typename ... TailTs>
struct has_type<QueryT, std::tuple<HeadT, TailTs...>>: has_type<QueryT, std::tuple<TailTs...>> {};

template<typename QueryT, typename ... TailTs>
struct has_type<QueryT, std::tuple<QueryT, TailTs...>>: std::true_type {};

template<typename TupleT1, typename TupleT2>
struct intersect
{
    template<std::size_t... Indices>
    static constexpr auto make_intersection(std::index_sequence<Indices...>)
    {
        return std::tuple_cat(
        std::conditional_t<
            has_type<std::tuple_element_t<Indices, TupleT1>, TupleT2>::value,
            std::tuple<std::tuple_element_t<Indices, TupleT1>>,
            std::tuple<>>{} ...);
    }

    /// The resulting tuple type.
    using type =
    decltype(make_intersection(std::make_index_sequence<std::tuple_size<TupleT1>::value> {}));
};

}  // namespace cpp20
}  // namespace tutorials

#endif  // CPP_TUTORIALS_TUTORIAL_CPP20_TUPLE_TYPE_TRAITS_HPP_