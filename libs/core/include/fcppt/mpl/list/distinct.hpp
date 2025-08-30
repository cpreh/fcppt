//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_DISTINCT_HPP_INCLUDED
#define FCPPT_MPL_LIST_DISTINCT_HPP_INCLUDED

#include <fcppt/config/compiler.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#ifdef FCPPT_CONFIG_MSVC_COMPILER
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#else
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
#ifdef FCPPT_CONFIG_MSVC_COMPILER
template<typename T>
struct distinct;

template<>
struct distinct<fcppt::mpl::list::object<>>
{
  using type = std::true_type;
};

template<typename T, typename... Ts>
struct distinct<fcppt::mpl::list::object<T,Ts...>>
{
  using rest = fcppt::mpl::list::object<Ts...>;
  using type = std::conjunction<
    typename fcppt::mpl::list::detail::distinct<rest>::type,
    fcppt::mpl::list::all_of<
      rest,
      fcppt::mpl::bind<
        fcppt::mpl::lambda<std::negation>,
        fcppt::mpl::bind<fcppt::mpl::lambda<std::is_same>,fcppt::mpl::arg<1>,fcppt::mpl::constant<T>>>>>;
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
struct derived<T,Ts...> : base<T>, derived<Ts...> // NOLINT(fuchsia-multiple-inheritance)
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

/**
\brief Checks if all elements of a list are pairwise disjoint.
\ingroup fcpptmpl
Let <code>List = list::object<L_1,...,L_n></code>. If <code>L_i != L_j</code>
for all <code>1 <= i != j <= n</code> then the result is <code>std::true_type</code>.
Otherwise, it is <code>std::false_type</code>.
*/
template<fcppt::mpl::list::object_concept List>
using distinct = typename fcppt::mpl::list::detail::distinct<List>::type;

}

#endif
