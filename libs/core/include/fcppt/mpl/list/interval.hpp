//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INTERVAL_HPP_INCLUDED
#define FCPPT_MPL_LIST_INTERVAL_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename Seq, typename Type, Type Begin>
struct interval;

template<typename Type, Type... Values, Type Begin>
struct interval<std::integer_sequence<Type,Values...>,Type,Begin>
{
  using type = fcppt::mpl::list::object<std::integral_constant<Type,Begin + Values>...>;
};
}
// TODO(concepts)
template <typename Type, Type Begin, Type End>
using interval = typename fcppt::mpl::list::detail::
    interval<std::make_integer_sequence<Type, End - Begin>, Type, Begin>::type;
}

#endif
