//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_DISTINCT_HPP_INCLUDED
#define FCPPT_MPL_LIST_DISTINCT_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
#if defined(FCPPT_CONFIG_MSVC_COMPILER)
namespace distinct_impl
{
template <typename... Types>
struct distinct;

template <>
struct distinct<>
{
  using type = std::true_type;
};

template <typename T>
struct distinct<T>
{
  using type = std::true_type;
};

template <typename T, typename... Types>
struct distinct<T, Types...>
{
  using type = std::conjunction<std::negation<std::is_same<T, Types...>>>;
};
}
template<typename T>
struct distinct;

template <typename... Types>
struct distinct<fcppt::mpl::list::object<Types...>>
{
  using type = typename distinct_impl::distinct<Types...>::type;
};
#else
namespace distinct_impl
{
template<typename T>
struct base {};

template<typename... Ts>
struct derived;

template<>
struct derived<>
{};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Winaccessible-base)
FCPPT_PP_DISABLE_VC_WARNING(4584)
template<typename T, typename... Ts>
struct derived<T,Ts...> : base<T>, derived<Ts...>
{
};
FCPPT_PP_POP_WARNING
}

template<typename T>
struct distinct;

template <typename... Types>
struct distinct<fcppt::mpl::list::object<Types...>>
{
  using type = std::conjunction<
      std::is_convertible<distinct_impl::derived<Types...>, distinct_impl::base<Types>>...>;
};
#endif

}

template<fcppt::mpl::list::object_concept List>
using distinct = typename fcppt::mpl::list::detail::distinct<List>::type;

}

#endif
