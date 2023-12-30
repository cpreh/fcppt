//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INTERVAL_HPP_INCLUDED
#define FCPPT_MPL_LIST_INTERVAL_HPP_INCLUDED

#include <fcppt/mpl/list/object.hpp>
#include <fcppt/type_traits/integral_constant_concept.hpp> // IWYU pragma: keep
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename Seq, typename Begin>
struct interval;

template<typename Type, Type... Values, Type Begin>
struct interval<std::integer_sequence<Type,Values...>,std::integral_constant<Type,Begin>>
{
  using type = fcppt::mpl::list::object<std::integral_constant<Type,Begin + Values>...>;
};
}
/**
\brief Return the interval between two numbers.
\ingroup fcpptmpl
If <code>Begin = std::integral_constant<Type,B></code> and
<code>End = std::integral_constant<Type,E></code> then the result is
\code
list::object<std::integral_constant<Type,B>, std::integral_constant<Type,B+1>,...,std::integral_constant<Type,E-1>>
\endcode
\note <code>End</code> is not included in the range but <code>Begin</code> is.
*/
template <
    fcppt::type_traits::integral_constant_concept Begin,
    fcppt::type_traits::integral_constant_concept End>
requires std::
    is_same_v<fcppt::type_traits::value_type<Begin>, fcppt::type_traits::value_type<End>> &&
    (Begin::value <= End::value)
using interval = typename fcppt::mpl::list::detail::interval<
        std::make_integer_sequence<fcppt::type_traits::value_type<Begin>, End::value - Begin::value>,
        Begin>::type;
}

#endif
